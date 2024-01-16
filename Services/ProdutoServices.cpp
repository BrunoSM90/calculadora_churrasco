#include "ProdutoServices.h"

#include <iostream>

#include "Produto.h"
#include "Participante.h"

/*--------------------------------------------------------------------------------*/

using namespace std;

static int idProduto = 1;

/*--------------------------------------------------------------------------------*/

void TProdutoService::CriaProdutosComprados(
    TParticipante* participante,
    const size_t nProdutosComprados
) 
{
    list<TProduto*>* const listaProdutos = new list<TProduto*>();

    for (size_t i = 0; i < nProdutosComprados; i++) {
        TProduto* const produto = &CriaProduto(nProdutosComprados, i);
        produto->SetComprador(participante);
        participante->InsereProdutoComprado(produto);
    }
}

/*--------------------------------------------------------------------------------*/

TProduto& TProdutoService::CriaProduto(
    const size_t nProdutosComprados,
    const size_t index
) 
{
    string nomeProduto = "";
    double valorTotal = 0.0;

    cout << "Nome do produto (" << index + 1 << "/" << nProdutosComprados << "): ";
    cin >> nomeProduto;

    cout << "Valor total do produto (" << index + 1 << "/" << nProdutosComprados << "): ";
    cin >> valorTotal;
    cout << "\n\n";

    auto produto = new TProduto(idProduto, nomeProduto, valorTotal);

    idProduto++;

    return *produto;
}

/*--------------------------------------------------------------------------------*/

list<TProduto*>& TProdutoService::TodosProdutos(
    const list<TParticipante*>* participantes
) 
{
    auto produtos = new list<TProduto*>();
    for (TParticipante* participante : *participantes) {
        for (TProduto* produto : participante->GetProdutosComprados()) {
            produtos->push_back(produto);
        }
    }

    return *produtos;
}

/*--------------------------------------------------------------------------------*/

void TProdutoService::ImprimeProdutos(
    const list<TProduto*>& produtos
) 
{
    for (TProduto* produto : produtos) {
        cout << produto->GetId() << ". " << produto->GetNome() << "\n\n";
    }
}

/*--------------------------------------------------------------------------------*/
