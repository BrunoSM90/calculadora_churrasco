#ifndef DIVIDASERVICE_H
#define DIVIDASERVICE_H

#include <string>
#include <list>
#include <map>

/*--------------------------------------------------------------------------------*/

class TParticipante;
class TProduto;

/*--------------------------------------------------------------------------------*/

class TDividaService {

public:
    TDividaService(
        const std::list<TParticipante*>* _participantes,
        const std::list<TProduto*>* _produtos
    );

    ~TDividaService();

    void DiscriminaConsumo();

    void CalculaDivida() const;

    void ImprimeDividas() const;

private:

    void ProcessaDividas(
        std::map<TProduto*, std::list<TParticipante*>>* dividas
    ) const;

    void ExibeListasProdutos(
        TParticipante* participante
    ) const;

    void ProcessaConsumoProdutos(
        TParticipante* participante,
        size_t& codProduto
    );

    size_t LeCodigoProduto(
        const std::string& nomeParticipante
    ) const;

    void ProcessaCodigoProduto(
        TParticipante* participante,
        size_t& codProduto
    );

    void ManipulaNaoConsumidos(
        TProduto* produto,
        TParticipante* participante
    ) const;

    void RemoveTodosDeNaoConsumidos(
        TParticipante* participante
    );

    void InsereTodosEmNaoConsumidos(
        TParticipante* participante
    ) const;

    void RemoveNaoConsumido(
        TProduto* produto,
        TParticipante* participante
    ) const;

    void CruzaDividas() const;

    const std::list<TParticipante*>* participantes;
    const std::list<TProduto*>* produtos;
};

#endif