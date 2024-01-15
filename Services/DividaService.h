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

    void DiscriminaConsumo() const;

    void CalculaDivida() const;

    void ImprimeDividas() const;

private:

    void ProcessaDividas(
        map<TProduto*, list<TParticipante*>>* dividas
    ) const;

    void ExibeListasProdutos(
        TParticipante* participante
    ) const;

    void ExibeNaoConsumidos(
        TParticipante* participante
    ) const;

    void ProcessaConsumoProdutos(
        TParticipante* participante,
        size_t& codProduto
    ) const;

    size_t LeCodigoProduto(
        const string nomeParticipante
    ) const;

    void ManipulaNaoConsumidos(
        TProduto* produto,
        TParticipante* participante
    ) const;

    void InsereTodosEmNaoConsumidos(
        TParticipante* participante
    ) const;

    void RemoveNaoConsumido(
        TProduto* produto,
        TParticipante* participante
    ) const;

    const list<TParticipante*>* participantes;
    const list<TProduto*>* produtos;
};

#endif