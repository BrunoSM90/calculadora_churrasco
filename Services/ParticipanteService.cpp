#include "ParticipanteService.h"

#include <InputValidator.h>
#include <iostream>

#include "Participante.h"

/*--------------------------------------------------------------------------------*/

static int idParticipante = 1;

using namespace std;

/*--------------------------------------------------------------------------------*/

TParticipanteService::TParticipanteService(
    TProdutoService* _prodService
) :
    prodService(_prodService)
{
}

/*--------------------------------------------------------------------------------*/


TParticipanteService::~TParticipanteService()
{
    delete prodService;
}

/*--------------------------------------------------------------------------------*/

list<TParticipante*>* TParticipanteService::CadastraParticipantes() 
{
    size_t numParticipantes = LeNumeroParticipantes();
    if (numParticipantes > 0) {
        auto participantes = new list<TParticipante*>();
        for (size_t i = 0; i < numParticipantes; i++) {
            TParticipante* participante = CriaParticipante(i, numParticipantes);
            participantes->push_back(participante);
            idParticipante++;
            system("cls");
        }

        return participantes;
    }

    return nullptr;
}

/*--------------------------------------------------------------------------------*/

size_t TParticipanteService::LeNumeroParticipantes() const
{
    size_t numParticipantes = 0;
    cout << "Insira o número de participantes: \n";
    cin >> numParticipantes;
    NumberValidator validator(cin);
    validator.ValidaInteger(numParticipantes);

    system("cls");

    return numParticipantes;
}

/*--------------------------------------------------------------------------------*/

TParticipante* TParticipanteService::CriaParticipante(
    const size_t i,
    const size_t numParticipantes
) 
{
    string nome = "";
    size_t nProdutosComprados = 0;

    cout << "Nome do participante (" << i + 1 << "/" << numParticipantes << ")" << "\n";
    cin >> nome;
    cout << "Quantos produtos " << nome << " comprou?\n";
    cin >> nProdutosComprados;
    NumberValidator validator(cin);
    validator.ValidaInteger(nProdutosComprados);

    auto participante = new TParticipante(idParticipante, nome);
    if (nProdutosComprados > 0) {
        prodService->CriaProdutosComprados(participante, nProdutosComprados);
    }

    return participante;
}

/*--------------------------------------------------------------------------------*/
