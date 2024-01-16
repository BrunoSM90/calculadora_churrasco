#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H

#include <list>
#include <map>
#include <string>
#include <set>

#include "Produto.h"

/*--------------------------------------------------------------------------------*/

using namespace std;

/*--------------------------------------------------------------------------------*/

class TParticipante {

public:
    TParticipante() = default;

    TParticipante(
        const int _id,
        const string _nome
    );

    ~TParticipante() = default;

    virtual bool operator== (
        const TParticipante& other
    );

    void SetId(
        int _id
    );

    int GetId() const;

    void SetNome(
        string _nome
    );

    string GetNome() const;

    const list<TProduto*>& GetProdutosComprados() const;

    const set<TProduto*>& GetNaoConsumidos() const;

    set<TProduto*>* GetNaoConsumidos();

    const map<TParticipante*, double>& GetDividas() const;

    map<TParticipante*, double>* GetDividas();

    bool Consome(
        TProduto* produto
    ) const;

    void InsereProdutoComprado(
        TProduto* produto
    );

    void InsereNaoConsumido(
        TProduto* produto
    );

    void RemoveNaoConsumido(
        TProduto* produtoARemover
    );

    void InsereDivida(
        TParticipante* participante,
        double valorDivida
    );

    bool ComprouProduto(
        TProduto* produto
    ) const;

private:
    int id = 0;
    string nome = "";
    list<TProduto*>* produtosComprados;
    set<TProduto*>* produtosNaoConsumidos;
    map<TParticipante*, double>* dividas;
};

#endif