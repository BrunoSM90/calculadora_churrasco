#include "Produto.h"

#include <iostream>

using namespace std;

/*--------------------------------------------------------------------------------*/

TProduto::TProduto(
    const int _id,
    const string _nome,
    const double _valorTotal
) :
  id(_id),
  nome(_nome),
  valorTotal(_valorTotal),
  comprador(nullptr)
{
}

/*--------------------------------------------------------------------------------*/

bool TProduto::operator==(
    const TProduto& other
)  
{
    return id == other.id;
}

/*--------------------------------------------------------------------------------*/

bool TProduto::operator<(
    const TProduto& other
    )
{
    return id < other.id;
}


/*--------------------------------------------------------------------------------*/

void TProduto::SetNome(
    string _nome
)
{
    nome = _nome;
}

/*--------------------------------------------------------------------------------*/

const string& TProduto::GetNome() const
{
    return nome;
}

/*--------------------------------------------------------------------------------*/

void TProduto::SetId(
    int _id
)
{
    id = _id;
}

/*--------------------------------------------------------------------------------*/

int TProduto::GetId() const
{
    return id;
}

/*--------------------------------------------------------------------------------*/

void TProduto::SetComprador(
    TParticipante* _comprador
)
{
    comprador = _comprador;
}

/*--------------------------------------------------------------------------------*/

TParticipante* TProduto::GetComprador() const
{
    return comprador;
}

/*--------------------------------------------------------------------------------*/

void TProduto::SetValorTotal(
    double _valorTotal
)
{
    valorTotal = _valorTotal;
}

/*--------------------------------------------------------------------------------*/

double TProduto::GetValorTotal() const
{
    return valorTotal;
}

/*--------------------------------------------------------------------------------*/
