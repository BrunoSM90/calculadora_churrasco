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

/* TODO
- TELA NO QT (requer refactor pesado)
- TRATAMENTO DE VALORES INV�LIDOS (fazer classe de assert?)
- ANALISAR PASSAGENS DE PONTEIROS
- VER SE ALGUM DESIGN PATTERN FACILITA
- FAZER CRUZAMENTO ENTRE PARTICIPANTE X DEVE PARA Y E PARTICIPANTE Y DEVE PARA X
- BD no SQLITE para armazenar participantes + GERAR QR CODE (pesquisar).
- VERIFICAR DESTRUTORES DAS ENTITIES (devo apagar algo?)
- VERIFICA��O DE LEAKS
- RELAT�RIO NO CONSOLE + RELAT�RIO ESCRITO EM FILE
- VER SE DEVO TROCAR AS LISTAS DE PRODUTO POR SET
- Ver como fazer minha pr�pria implementa��o de list<T*> e ter uns m�todos tipo hasMember
*/

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

        //n�o precisa receber o calcula divida, trabalhar com a lista apenas dentro do servi�o.
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
