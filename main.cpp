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

int main(int argc, char** argv) {

    setlocale(LC_ALL, "portuguese");
    
    auto prodService = new TProdutoService();
    auto participanteService = new TParticipanteService(prodService);
    list<TParticipante*>* participantes = participanteService->CadastraParticipantes();
    //delete participanteService e prodService?
    if (participantes->size() > 0) {
        auto dividaService = new TDividaService();
        dividaService->DiscriminaConsumo(participantes);

        //não precisa receber o calcula divida, trabalhar com a lista apenas dentro do serviço.
        //talvez guardar a lista de dividas e de participantes como membros
        map<TProduto*, list<TParticipante*>>* dividas = &dividaService->CalculaDivida(participantes);
        dividaService->ProcessaDividas(participantes, dividas);

        system("cls");

        dividaService->ImprimeDividas(participantes);
    }
    
    system("pause");

    return 0;
}

/*--------------------------------------------------------------------------------*/
