#ifndef PRODUTOSERVICE_H
#define PRODUTOSERVICE_H

#include <list>

/*--------------------------------------------------------------------------------*/

class TParticipante;
class TProduto;

/*--------------------------------------------------------------------------------*/

class TProdutoService {

public:
    TProdutoService() = default;

    ~TProdutoService() = default;

    void CriaProdutosComprados(
        TParticipante* participante,
        const size_t nProdutosComprados
    );

    TProduto& CriaProduto(
        const size_t nProdutosComprados,
        const size_t index
    );

    std::list<TProduto*>& TodosProdutos(
        const std::list<TParticipante*>* participantes
    );

    void ImprimeProdutos(
        const std::list<TProduto*>& produtos
    );
};

#endif