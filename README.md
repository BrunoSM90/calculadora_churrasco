# calculadora_churrasco


TO-DO list:
- TELA NO QT (requer refactor pesado)
- TRATAMENTO DE VALORES INVÁLIDOS (asserts?)
- DP?
- FAZER CRUZAMENTO ENTRE PARTICIPANTE X DEVE PARA Y E PARTICIPANTE Y DEVE PARA X
- BD no SQLITE para armazenar participantes + GERAR QR CODE (pesquisar).
- VERIFICAÇÃO DE LEAKS
- RELATÓRIO NO CONSOLE + RELATÓRIO ESCRITO EM FILE
- Custom list<T*> e ter uns métodos tipo hasMember, elementAt(), etc
- cout -> printf / cin -> scanf
- Dividir tela final em "recebe" e "paga".

Fazendo:
- FAZER CRUZAMENTO ENTRE PARTICIPANTE X DEVE PARA Y E PARTICIPANTE Y DEVE PARA X

Feitos:
- VERIFICAR DESTRUTORES DAS ENTITIES (devo apagar algo?)
- VERIFICAR PONTEIROS E DELETES
- Verificar ponteiro (ln 81 do dividasservice.cpp):
  auto produtos = make_unique<list<TProduto*>>(AuxDividas::TodosProdutos(participantes)); (removidos smart pointers do divida services)
- Opção adicionar todos de volta à lista de consumidos quando todos os produtos estiverem na lista de não consumidos (similar ao que já existe na de consumidos)
- Verificar questão do locale para trocar cout por printf
- TROCAR AS LISTAS DE PRODUTO POR SETS (feito só para a lista de nao consumidos para evitar o sort)