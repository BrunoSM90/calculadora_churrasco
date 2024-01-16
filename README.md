# calculadora_churrasco


TO-DO list:
- TELA NO QT (requer refactor pesado)
- BD no SQLITE para armazenar participantes + GERAR QR CODE (pesquisar).
- VERIFICAÇÃO DE LEAKS
- RELATÓRIO ESCRITO EM FILE
- Custom list<T*> e ter uns métodos tipo hasMember, elementAt(), etc
- Implementar cálculo a partir da leitura de um CSV ou um .txt
- Implementar um esquema de fazer cada pessoa fazer apenas um pagamento (TDividasService::OtimizaPagamento())

Próximo:
- Dividir tela final em "recebe" e "paga" ou fazer um sort no ImprimeDividas() para apresentar primeiro quem paga e depois quem não paga nada

Fazendo:
- RELATÓRIO NO CONSOLE (Opcional pro usuário)

Feitos:
- VERIFICAR DESTRUTORES DAS ENTITIES (devo apagar algo?)
- VERIFICAR PONTEIROS E DELETES
- Verificar ponteiro (ln 81 do dividasservice.cpp):
  auto produtos = make_unique<list<TProduto*>>(AuxDividas::TodosProdutos(participantes)); (removidos smart pointers do divida services)
- Opção adicionar todos de volta à lista de consumidos quando todos os produtos estiverem na lista de não consumidos (similar ao que já existe na de consumidos)
- Verificar questão do locale para trocar cout por printf
- TROCAR AS LISTAS DE PRODUTO POR SETS (feito só para a lista de nao consumidos para evitar o sort)
- FAZER CRUZAMENTO ENTRE PARTICIPANTE X DEVE PARA Y E PARTICIPANTE Y DEVE PARA X
- TRATAMENTO DE VALORES INVÁLIDOS nos cin
- Tirar using namespaces dos .h

Cancelados:
- Fazer o map carregar objetos dinâmicos de pairs para buscar à partir do TParticipante.
- Refinar e testar mais o CruzaDividas() (fazer clone da lista para evitar os erase(it++)?? ou guardar as dívidas numa lista e dar erase depois do laço)
- cout -> printf / cin -> scanf
- DP?