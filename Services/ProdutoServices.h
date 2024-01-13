#ifndef PRODUTOSERVICE_H
#define PRODUTOSERVICE_H

#include <list>

using namespace std;

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

    list<TProduto*>& TodosProdutos(
        const list<TParticipante*>* participantes
    );

    void ImprimeProdutos(
        const list<TProduto*>& produtos
    );

private:
};

#endif