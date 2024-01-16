#include "Participante.h"

#include <iostream>

using namespace std;

/*--------------------------------------------------------------------------------*/

TParticipante::TParticipante(
    const int _id,
    const string _nome
) :
    id(_id),
    nome(_nome),
    produtosComprados(new list<TProduto*>()),
    produtosNaoConsumidos(new set<TProduto*>()),
    dividas(new map<TParticipante*, double>())
{
}

/*--------------------------------------------------------------------------------*/

bool TParticipante::operator==(
    const TParticipante& other
)  
{
    return id == other.id;
}

/*--------------------------------------------------------------------------------*/

void TParticipante::SetId(
    int _id
) 
{
    id = _id;
}

/*--------------------------------------------------------------------------------*/

int TParticipante::GetId() const 
{
    return id;
}

/*--------------------------------------------------------------------------------*/

void TParticipante::SetNome(
    string _nome
)
{
    nome = _nome;
}

/*--------------------------------------------------------------------------------*/

const string& TParticipante::GetNome() const
{
    return nome;
}

/*--------------------------------------------------------------------------------*/

const list<TProduto*>& TParticipante::GetProdutosComprados() const
{
    return *produtosComprados;
}

/*--------------------------------------------------------------------------------*/

const set<TProduto*>& TParticipante::GetNaoConsumidos() const
{
    return *produtosNaoConsumidos;
}

/*--------------------------------------------------------------------------------*/

set<TProduto*>* TParticipante::GetNaoConsumidos()
{
    return produtosNaoConsumidos;
}

/*--------------------------------------------------------------------------------*/

const map<TParticipante*, double>& TParticipante::GetDividas() const
{
    return *dividas;
}

/*--------------------------------------------------------------------------------*/

map<TParticipante*, double>* TParticipante::GetDividas()
{
    return dividas;
}

/*--------------------------------------------------------------------------------*/

bool TParticipante::Consome(
    TProduto* produto
) const
{
    if (produtosNaoConsumidos->size() != 0) {
        auto end = produtosNaoConsumidos->end();
        auto result = find(produtosNaoConsumidos->begin(), end, produto);
        return result == end;
    }

    return true;
}

/*--------------------------------------------------------------------------------*/

bool TParticipante::ComprouProduto(
    TProduto* produto
) const
{
    auto end = produtosComprados->end();
    auto found = find(produtosComprados->begin(), end, produto);
    if (found != end) {
        return true;
    }

    return false;
}

/*--------------------------------------------------------------------------------*/

void TParticipante::InsereProdutoComprado(
    TProduto* produto
) 
{
    produtosComprados->push_back(produto);
}

/*--------------------------------------------------------------------------------*/

void TParticipante::InsereNaoConsumido(
    TProduto* produto
) 
{
    produtosNaoConsumidos->insert(produto);
}

/*--------------------------------------------------------------------------------*/

void TParticipante::RemoveNaoConsumido(
    TProduto* produtoARemover
) 
{
    produtosNaoConsumidos->erase(produtoARemover);
}

/*--------------------------------------------------------------------------------*/

void TParticipante::InsereDivida(
    TParticipante* participante,
    double valorDivida
) 
{
    auto result = dividas->find(participante);
    if (result != dividas->end()) {
        result->second += valorDivida;
    }
    else {
        dividas->insert(make_pair(participante, valorDivida));
    }
}

/*--------------------------------------------------------------------------------*/
