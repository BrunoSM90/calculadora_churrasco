#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

/*--------------------------------------------------------------------------------*/

using namespace std;
class TParticipante;

/*--------------------------------------------------------------------------------*/

class TProduto {

public:
    TProduto() = default;

    TProduto(
        const int _id,
        const string _nome,
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
        string _nome
    );

    string GetNome() const;

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
    string nome; //trocar para char* talvez
    double valorTotal;
};

#endif