#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

/*--------------------------------------------------------------------------------*/

class TParticipante;

/*--------------------------------------------------------------------------------*/

class TProduto {

public:
    TProduto() = default;

    TProduto(
        const int _id,
        const std::string _nome,
        const double _valorTotal
    );

    ~TProduto() = default;

    virtual bool operator== (
        const TProduto& other
    );

    virtual bool operator< (
        const TProduto& other
    );

    void SetNome(
        std::string _nome
    );

    const std::string& GetNome() const;

    void SetId(
        int _id
    );

    int GetId() const;

    void SetComprador(
        TParticipante* _comprador
    );

    TParticipante* GetComprador() const;

    void SetValorTotal(
        double _valorTotal
    );

    double GetValorTotal() const;

private:
    int id;
    TParticipante* comprador;
    std::string nome;
    double valorTotal;
};

#endif