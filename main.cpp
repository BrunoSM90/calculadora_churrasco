#include <iostream>
#include <clocale>
#include <map>
#include <list>

#include "Entities/Participante.h"
#include "Entities/Produto.h"

#include "Services/DividaService.h"
#include "Services/ParticipanteService.h"
#include "Services/ProdutoServices.h"

/*--------------------------------------------------------------------------------*/

using namespace std;

/*--------------------------------------------------------------------------------*/

list<TParticipante*>* CadastraParticipantes();
void CalculaDivida(list<TParticipante*>* participantes);

/*--------------------------------------------------------------------------------*/

int main(int argc, char** argv) {

    setlocale(LC_ALL, "portuguese");
    
    list<TParticipante*>* participantes = CadastraParticipantes();

    if (participantes->size() > 0) {
        CalculaDivida(participantes);
    }
    
    system("pause");

    return 0;
}

/*--------------------------------------------------------------------------------*/

list<TParticipante*>* CadastraParticipantes() {
    auto prodService = new TProdutoService();
    unique_ptr<TParticipanteService> participanteService =
        make_unique<TParticipanteService>(prodService);

    list<TParticipante*>* lista = participanteService->CadastraParticipantes();

    return lista;
}

/*--------------------------------------------------------------------------------*/

void CalculaDivida (
    list<TParticipante*>* participantes
) 
{
    unique_ptr<TDividaService> dividaService = make_unique<TDividaService>(participantes);
    dividaService->DiscriminaConsumo();
    dividaService->CalculaDivida();
    dividaService->ImprimeDividas();
}

/*--------------------------------------------------------------------------------*/
