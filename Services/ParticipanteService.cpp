#include "ParticipanteService.h"

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
    prodService = 0;
}

/*--------------------------------------------------------------------------------*/

list<TParticipante*>* TParticipanteService::CadastraParticipantes() {
    size_t numParticipantes;
    cout << "Insira o número de participantes: \n";
    cin >> numParticipantes;
    system("cls");

    if (numParticipantes > 0) {
        auto participantes = new list<TParticipante*>();
        for (size_t i = 0; i < numParticipantes; i++) {
            TParticipante* participante = &CriaParticipante(i, numParticipantes);
            participantes->push_back(participante);
            idParticipante++;
            system("cls");
        }

        return participantes;
    }

    return nullptr;
}

/*--------------------------------------------------------------------------------*/

TParticipante& TParticipanteService::CriaParticipante(
    const size_t i,
    const size_t numParticipantes
) 
{
    string nome;
    size_t nProdutosComprados;

    cout << "Nome do participante (" << i + 1 << "/" << numParticipantes << ")" << "\n";
    cin >> nome;
    cout << "Quantos produtos " << nome << " comprou?\n";
    cin >> nProdutosComprados;

    auto participante = new TParticipante(idParticipante, nome);
    if (nProdutosComprados > 0) {
        prodService->CriaProdutosComprados(participante, nProdutosComprados);
    }

    return *participante;
}

/*--------------------------------------------------------------------------------*/
