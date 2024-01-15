#ifndef PARTICIPANTESERVICE_H
#define PARTICIPANTESERVICE_H

#include <string>
#include <list>

#include "ProdutoServices.h"

/*--------------------------------------------------------------------------------*/

using namespace std;

class TParticipante;

/*--------------------------------------------------------------------------------*/

class TParticipanteService {

public:
    TParticipanteService(
        TProdutoService* _prodService
    );

    ~TParticipanteService();

    list<TParticipante*>* CadastraParticipantes();

    TParticipante* CriaParticipante(
        const size_t i,
        const size_t numParticipantes
    );

private:

    size_t LeNumeroParticipantes() const;

    TProdutoService* prodService;
};

#endif