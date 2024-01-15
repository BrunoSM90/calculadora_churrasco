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
        cout << "Produtos consumidos por " << participante.GetNome() << ":\n";

        for (TProduto* produto : produtos) {
            if (participante.Consome(produto)) {
                cout << produto->GetId() << ". " << produto->GetNome() << "\n";
            }
        }

        ImprimeOpcoesAuxiliares(produtos.size(), participante);
    }

    void ImprimeProdutosNaoConsumidos(const size_t nProdutos, TParticipante* participante) {
        cout << "Produtos não consumidos por " << participante->GetNome() << ":\n";
        list<TProduto*>* naoConsumidos = participante->GetNaoConsumidos();

        if (naoConsumidos->size() == 0) {
            cout << "Lista vazia.\n";
        }
        else {
            naoConsumidos->sort([](TProduto* p1, TProduto* p2) {
                return p1->GetId() < p2->GetId(); });

            for (TProduto* produto : *naoConsumidos) {
                cout << produto->GetId() << ". " << produto->GetNome() << "\n";
            }

            cout << nProdutos + 2 << ". " << "Retornar todos à lista de consumidos" << "\n";
        }
    }

    void ImprimeOpcoesAuxiliares(const size_t nProdutos, const TParticipante& participante) {
        if (participante.GetNaoConsumidos().size() == nProdutos) {
            cout << "Não houve consumo.\n";
        }
        else {
            cout << nProdutos + 1 << ". " << "Adicionar todos à lista de não consumidos" << "\n";
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
) const
{
    AuxDividas::ImprimeProdutosConsumidos(*produtos, *participante);
    cout << "\n" << "-------------------------------------------" << "\n\n";

    AuxDividas::ImprimeProdutosNaoConsumidos(produtos->size(), participante);
    cout << "\n" << "-------------------------------------------" << "\n\n";
}

/*--------------------------------------------------------------------------------*/

void TDividaService::ProcessaConsumoProdutos(
    TParticipante* participante,
    size_t& codProduto
)
{
    codProduto = LeCodigoProduto(participante->GetNome());
    if (codProduto != 0) {
        ProcessaCodigoProduto(participante, codProduto);
    }
}

/*--------------------------------------------------------------------------------*/

size_t TDividaService::LeCodigoProduto(
    const string nomeParticipante
) const
{
    size_t codProduto;
    cout << "\nDigite o código de cada produto NÃO consumido por " <<
        nomeParticipante << " (0 para finalizar.)" << "\n\n";
    cout << "Codigo do produto: " << "\n";
    cin >> codProduto;

    return codProduto;
}

/*--------------------------------------------------------------------------------*/

void TDividaService::ProcessaCodigoProduto(
    TParticipante* participante,
    size_t& codProduto
)
{
    const size_t nProdutos = produtos->size();
    if (codProduto == nProdutos + 1) {
        InsereTodosEmNaoConsumidos(participante);
    }
    else if (codProduto == nProdutos + 2) {
        RemoveTodosDeNaoConsumidos(participante);
    }
    else {
        TProduto* produto = AuxDividas::BuscaProdutoPorId(produtos, codProduto);
        ManipulaNaoConsumidos(produto, participante);
    }
}

/*--------------------------------------------------------------------------------*/

void TDividaService::ManipulaNaoConsumidos(
    TProduto* produto,
    TParticipante* participante
) const
{
    if (participante->Consome(produto)) {
        participante->InsereNaoConsumido(produto);

    }
    else {
        RemoveNaoConsumido(produto, participante);
    }
}

/*--------------------------------------------------------------------------------*/

void TDividaService::RemoveTodosDeNaoConsumidos(
    TParticipante* participante
)
{
    participante->GetNaoConsumidos()->clear();
}

/*--------------------------------------------------------------------------------*/

void TDividaService::InsereTodosEmNaoConsumidos(
    TParticipante* participante
) const
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

void TDividaService::CalculaDivida() const
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
) const
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
        cout << participante->GetNome() << " paga: ";
        const map<TParticipante*, double>* dividas = &participante->GetDividas();

        if (dividas->size() != 0) {
            for (const auto& data : *dividas) {
                cout << "\nR$" << data.second << " para " << data.first->GetNome() << "\n";
            }
            cout << "\n\n";
        }
        else {
            cout << "R$0.00\n\n";
        }
    }
}

/*--------------------------------------------------------------------------------*/
