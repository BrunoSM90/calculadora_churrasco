#include "DividaService.h"

#include <iostream>
#include <algorithm>

#include <Participante.h>

/*--------------------------------------------------------------------------------*/

using namespace std;

/*--------------------------------------------------------------------------------*/

namespace AuxDividas {
    TProduto* BuscaProdutoPorId(const list<TProduto*>* produtos, const int id) {
        for (TProduto* produto : *produtos) {
            if (produto->GetId() == id) {
                return produto;
            }
        }

        return nullptr;
    }

    void ImprimeProdutosConsumidos(const list<TProduto*>& produtos, const TParticipante& participante) {
        cout << "Produtos consumidos: \n";
        size_t count = 0;
        for (TProduto* produto : produtos) {
            if (participante.Consome(produto)) {
                cout << produto->GetId() << ". " << produto->GetNome() << "\n";
                count++;
            }
        }

        if (count == 0) {
            cout << "Não houve consumo.\n";
        }
        else {
            cout << produtos.size() + 1 << ". " << "Adicionar todos à lista de não consumidos" << "\n";
        }

        cout << "\n";
    }

    void LimpaTela() {
        system("cls");
    }
}

/*--------------------------------------------------------------------------------*/

TDividaService::TDividaService(
    const list<TParticipante*>* _participantes,
    const list<TProduto*>* _produtos
) :
    participantes(_participantes),
    produtos(_produtos)
{
}

/*--------------------------------------------------------------------------------*/

TDividaService::~TDividaService()
{
    delete participantes;
    delete produtos;
}

/*--------------------------------------------------------------------------------*/

void TDividaService::DiscriminaConsumo()
{
    for (TParticipante* participante : *participantes) {
        AuxDividas::LimpaTela();

        size_t codProduto = 1;
        while (codProduto != 0) {
            ExibeListasProdutos(participante);
            ProcessaConsumoProdutos(participante, codProduto);
            AuxDividas::LimpaTela();
        }
    }

    cout << "\n" << "-------------------------------------------" << "\n\n";
}

/*--------------------------------------------------------------------------------*/

void TDividaService::ExibeListasProdutos(
    TParticipante* participante
)
{
    AuxDividas::ImprimeProdutosConsumidos(*produtos, *participante);
    ExibeNaoConsumidos(participante);
}

/*--------------------------------------------------------------------------------*/

void TDividaService::ProcessaConsumoProdutos(
    TParticipante* participante,
    size_t& codProduto
)
{
    codProduto = LeCodigoProduto(participante->GetNome());

    if (codProduto == produtos->size() + 1) {
        InsereTodosEmNaoConsumidos(participante);
    }
    else if (codProduto != 0) {
        TProduto* produto = AuxDividas::BuscaProdutoPorId(produtos, codProduto);
        ManipulaNaoConsumidos(produto, participante);
    }
}

/*--------------------------------------------------------------------------------*/

size_t TDividaService::LeCodigoProduto(
    string nomeParticipante
)
{
    size_t codProduto;
    cout << "\nDigite o código de cada produto NÃO consumido por " <<
        nomeParticipante << " (0 para finalizar.)" << "\n\n";
    cout << "Codigo do produto: " << "\n";
    cin >> codProduto;

    return codProduto;
}

/*--------------------------------------------------------------------------------*/

void TDividaService::InsereTodosEmNaoConsumidos(
    TParticipante* participante
)
{
    list<TProduto*>* naoConsumidos = participante->GetNaoConsumidos();
    for (TProduto* produto : *produtos) {
        auto it = std::find(naoConsumidos->begin(), naoConsumidos->end(), produto);
        if (it == naoConsumidos->end()) {
            participante->InsereNaoConsumido(produto);
        }
    }
}

/*--------------------------------------------------------------------------------*/

void TDividaService::ManipulaNaoConsumidos(
    TProduto* produto,
    TParticipante* participante
)
{
    if (participante->Consome(produto)) {
        participante->InsereNaoConsumido(produto);
        
    }
    else {
        RemoveNaoConsumido(produto, participante);
    }
}

/*--------------------------------------------------------------------------------*/

void TDividaService::RemoveNaoConsumido(
    TProduto* produto,
    TParticipante* participante
) const
{
    char remove;
    cout << "\nO produto escolhido já foi registrado para este participante.\n"
        << "Deseja remover da lista de não consumidos? (s/n)\n";
    cin >> remove;
    if (remove == 's') {
        participante->RemoveNaoConsumido(produto);
    }
}

/*--------------------------------------------------------------------------------*/

void TDividaService::CalculaDivida()
{
    auto dividas = new map<TProduto*, list<TParticipante*>>();

    for (TProduto* produto : *produtos) {
        auto pagadores = new list<TParticipante*>();
        for (TParticipante* participante : *participantes) {
            if (participante->Consome(produto)) {
                pagadores->push_back(participante);
            }
        }
        dividas->insert(make_pair(produto, *pagadores));
    }

    ProcessaDividas(dividas);
}

/*--------------------------------------------------------------------------------*/

void TDividaService::ProcessaDividas(
    map<TProduto*, list<TParticipante*>>* dividas
)
{
    for (auto it = dividas->begin(); it != dividas->end(); it++) {
        TProduto* produto = it->first;
        list<TParticipante*> pagadores = it->second;

        const size_t nPagadores = pagadores.size();
        const double valorDividido = produto->GetValorTotal() / nPagadores;

        for (TParticipante* participante : pagadores) {
            if (const list<TProduto*>* produtosComprados = &participante->GetProdutosComprados()) {
                if (participante->ComprouProduto(produto)) {
                    continue;
                }
            }
            participante->InsereDivida(produto->GetComprador(), valorDividido);
        }
    }
}

/*--------------------------------------------------------------------------------*/

void TDividaService::ImprimeDividas() const
{
    system("cls");
    for (TParticipante* participante : *participantes) {
        cout << participante->GetNome() << " deve pagar: ";
        const map<TParticipante*, double>* dividas = &participante->GetDividas();

        if (dividas->size() != 0) {
            for (auto it = dividas->begin(); it != dividas->end(); it++) {
                cout << "\nR$" << it->second << " para " << it->first->GetNome() << "\n";
            }
            cout << "\n\n";
        }
        else {
            cout << "R$0.00\n\n";
        }
    }
}

/*--------------------------------------------------------------------------------*/

void TDividaService::ExibeNaoConsumidos(
    TParticipante* participante
) const
{
    cout << "Produtos não consumidos por " << participante->GetNome() << ":\n";
    list<TProduto*>* naoConsumidos = participante->GetNaoConsumidos();

    if (naoConsumidos->size() != 0) {
        naoConsumidos->sort([](TProduto* p1, TProduto* p2) {
            return p1->GetId() < p2->GetId(); });

        for (TProduto* produto : *naoConsumidos) {
            cout << produto->GetId() << ". " << produto->GetNome() << "\n";
        }
    }
    else {
        cout << "Lista vazia.\n";
    }
}

/*--------------------------------------------------------------------------------*/
