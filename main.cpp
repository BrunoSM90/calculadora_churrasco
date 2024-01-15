#include <iostream>
#include <clocale>
#include <map>
#include <list>

#include "Entities/Participante.h"
#include "Entities/Produto.h"

#include "Services/DividaService.h"
#include "Services/ParticipanteService.h"
#include "Services/ProdutoServices.h"

/*--------------------------------------------------------------------------------*/

using namespace std;

/*--------------------------------------------------------------------------------*/

const list<TParticipante*>& CadastraParticipantes();
void CalculaDivida(const list<TParticipante*>& participantes, const list<TProduto*>& produtos);
const list<TProduto*>& MontaListaProdutos(const list<TParticipante*>& participantes);

/*--------------------------------------------------------------------------------*/

int main(int argc, char** argv) {

    setlocale(LC_ALL, "portuguese");
    
    const list<TParticipante*>* participantes = &CadastraParticipantes();

    if (participantes->size() > 0) {
        const list<TProduto*>* produtos = &MontaListaProdutos(*participantes);
        CalculaDivida(*participantes, *produtos);
    }
    
    system("pause");

    return 0;
}

/*--------------------------------------------------------------------------------*/

const list<TParticipante*>& CadastraParticipantes()
{
    unique_ptr<TParticipanteService> participanteService =
        make_unique<TParticipanteService>(new TProdutoService());

    list<TParticipante*>* lista = participanteService->CadastraParticipantes();

    return *lista;
}

/*--------------------------------------------------------------------------------*/

void CalculaDivida (
    const list<TParticipante*>& participantes,
    const list<TProduto*>& produtos
) 
{   
    unique_ptr<TDividaService> dividaService = make_unique<TDividaService>(&participantes, &produtos);
    dividaService->DiscriminaConsumo();
    dividaService->CalculaDivida();
    dividaService->ImprimeDividas();
}

/*--------------------------------------------------------------------------------*/

const list<TProduto*>& MontaListaProdutos(
    const list<TParticipante*>& participantes
)
{
    auto produtos = new list<TProduto*>();
    for (TParticipante* participante : participantes) {
        for (TProduto* produto : participante->GetProdutosComprados()) {
            produtos->push_back(produto);
        }
    }

    return *produtos;
}

/*--------------------------------------------------------------------------------*/
