#ifndef DIVIDASERVICE_H
#define DIVIDASERVICE_H

#include <string>
#include <list>
#include <map>

/*--------------------------------------------------------------------------------*/

using namespace std;

class TParticipante;
class TProduto;

/*--------------------------------------------------------------------------------*/

class TDividaService {

public:
    TDividaService(
        list<TParticipante*>* _participantes
    );

    ~TDividaService() = default;

    void DiscriminaConsumo();

    void CalculaDivida();

    void InsereTodosEmNaoConsumidos(
        list<TProduto*>* produtos,
        TParticipante* participante
    );

    void ManipulaNaoConsumidos(
        TProduto* produto,
        TParticipante* participante
    );

private:

    void ProcessaDividas(
        map<TProduto*, list<TParticipante*>>* dividas
    );

    void ImprimeDividas(
        list<TParticipante*>* participantes
    );

    void ExibeNaoConsumidos(
        TParticipante* participante
    ) const;

    list<TParticipante*>* participantes;
};

#endif