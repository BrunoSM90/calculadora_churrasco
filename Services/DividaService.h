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
        const list<TParticipante*>* _participantes,
        const list<TProduto*>* _produtos
    );

    ~TDividaService();

    void DiscriminaConsumo();

    void CalculaDivida();

    void ImprimeDividas() const;

private:

    void ProcessaDividas(
        map<TProduto*, list<TParticipante*>>* dividas
    );

    void TDividaService::ExibeListasProdutos(
        TParticipante* participante
    );

    void ExibeNaoConsumidos(
        TParticipante* participante
    ) const;

    void ProcessaConsumoProdutos(
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
        TParticipante* participante
    );

    void RemoveNaoConsumido(
        TProduto* produto,
        TParticipante* participante
    ) const;

    const list<TParticipante*>* participantes;
    const list<TProduto*>* produtos;
};

#endif