#ifndef DIVIDASERVICE_H
#define DIVIDASERVICE_H

#include <string>
#include <list>
#include <map>

/*--------------------------------------------------------------------------------*/

using namespace std;

class TParticipante;
class TProduto;

/*--------------------------------------------------------------------------------*/

class TDividaService {

public:
    TDividaService(
        list<TParticipante*>* _participantes
    );

    ~TDividaService();

    void DiscriminaConsumo();

    void CalculaDivida();

    void ImprimeDividas();

private:

    void ProcessaDividas(
        map<TProduto*, list<TParticipante*>>* dividas
    );

    void TDividaService::ExibeListasProdutos(
        list<TProduto*>* produtos,
        TParticipante* participante
    );

    void ExibeNaoConsumidos(
        TParticipante* participante
    ) const;

    void ProcessaConsumoProdutos(
        list<TProduto*>* produtos,
        TParticipante* participante,
        size_t& codProduto
    );

    size_t TDividaService::LeCodigoProduto(
        string nomeParticipante
    );

    void ManipulaNaoConsumidos(
        TProduto* produto,
        TParticipante* participante
    );

    void InsereTodosEmNaoConsumidos(
        list<TProduto*>* produtos,
        TParticipante* participante
    );

    void RemoveNaoConsumido(
        TProduto* produto,
        TParticipante* participante
    ) const;

    list<TParticipante*>* participantes;
};

#endif