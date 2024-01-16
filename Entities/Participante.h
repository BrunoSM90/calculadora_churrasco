#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H

#include <list>
#include <map>
#include <string>
#include <set>

#include "Produto.h"

/*--------------------------------------------------------------------------------*/

class TParticipante {

public:
    TParticipante() = default;

    TParticipante(
        const int _id,
        const std::string _nome
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
        std::string _nome
    );

    const std::string& GetNome() const;

    const std::list<TProduto*>& GetProdutosComprados() const;

    const std::set<TProduto*>& GetNaoConsumidos() const;

    std::set<TProduto*>* GetNaoConsumidos();

    const std::map<TParticipante*, double>& GetDividas() const;

    std::map<TParticipante*, double>* GetDividas();

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
    std::string nome = "";
    std::list<TProduto*>* produtosComprados;
    std::set<TProduto*>* produtosNaoConsumidos;
    std::map<TParticipante*, double>* dividas;
};

#endif