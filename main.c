//BIBLIOTECAS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//STRUCT DO TIPO ADMINISTRADOR
typedef struct Administrador
{
    char login[20]; //variavel login para entrar no sistema
    char senha[30]; //variavel senha para entrar no sistema
    char nome[100]; //variavel nome para identificar o administrador
} Administrador;

//STRUCT DO TIPO GERENTE
typedef struct Gerente
{
    char login[20]; //variavel login para entrar no sistema
    char senha[30]; //variavel senha para entrar no sistema
    char nome[100]; //variavel nome para identificar o gerente
} Gerente;

//STRUCT DO TIPO CORRETOR
typedef struct Corretor
{
    char login[20]; //variavel login para entrar no sistema
    char senha[30]; //variavel senha para entrar no sistema
    char nome [100]; //variavel nome para identificar o corretor
    char numeroCreci[10]; //numero de registro do corretor no CRECI
} Corretor;

//STRUCT DO TIPO IMOVEL
typedef struct Imovel
{
    char proprietario[50]; //variavel para o nome do proprietario
    char telefone[30]; //variavel para o telefone do proprietario
    char modalidade[7]; //variavel para venda ou locacao.
    char endereco[200]; //variavel para endereco do imovel
    float preco;
    char descricao[2000]; //descrição do imóvel (ex.: quantidade de dormitórios, de sala, etc...)
} Imovel;

//FUNÇÕES PARA CONFIGURAR GERENTE - APENAS ADMINISTRADOR TEM PERMISSÃO
void listarGerentes();
void cadastrarGerente();
void excluirGerente();

//FUNÇÕES PARA CONFIGURAR CORRETOR - APENAS ADMINISTRADOR E GERENTE TEM PERMISSÃO
void listarCorretoresAdministrador();
void cadastrarCorretorAdministrador();
void excluirCorretorAdministrador();

void listarCorretoresGerente();
void cadastrarCorretorGerente();
void excluirCorretorGerente();

//FUNÇÕES PARA CONFIGURAR IMOVEL - MOSTRAR E EXCLUIR - APENAS ADMINISTRADOR E GERENTE TEM PERMISSÃO.
void listarImoveisAdministrador();
void excluirImovelAdministrador();

void listarImoveisGerente();
void excluirImovelGerente();

//FUNÇÃO PARA CONFIGURAR IMOVEL - CORRETOR TEM PERMISSÃO APENAS PARA VER OS IMOVEIS.
void listarImoveisCorretor();

//FUNÇÕES CADASTRAR IMOVEL - TODOS OS USUÁRIOS TEM PERMISSÃO
void cadastrarImovelAdministrador();
void cadastrarImovelGerente();
void cadastrarImovelCorretor();

//FUNÇÕES DE LOGINS DOS USUÁRIOS.
void loginAdministrador();
void loginGerente();
void loginCorretor();

//FUNÇÕES DE MENUS DOS USUÁRIOS E MENU PRINCIPAL.
void menuPrincipal();
void menuAdministrador();
void menuGerente();
void menuCorretor();

//FUNÇÕES PARA CONFIGURAR USUÁRIOS E IMÓVEIS.
void configurarGerente();
void configurarCorretorAdministrador();
void configurarCorretorGerente();
void configurarImovelAdministrador();
void configurarImovelGerente();
void configurarImovelCorretor();

//FUNÇÕES BÁSICAS DE TELA.
void logo();
void manualUsuario();
void limpar();
void sair();

//VARIAVEIS GLOBAIS
void campoSenha(char senha[30]);
FILE *arquivoAdministrador;
FILE *arquivoGerente;
FILE *arquivoCorretor;
FILE *arquivoImovel;
char opLetra;
char opNumero;

//MAIN
int main(){
    //COR DO SISTEMA
    system("color  F9");
    //LOGO DO SISTEMA
    logo();
    getche();
    limpar();
    //MENU PRINCIPAL DO SISTEMA.
    menuPrincipal();
    return 0;
}

//FUNÇÃO PARA O MENU PRINCIPAL
void menuPrincipal(void)
{
    printf("\n");
    printf("                            ______________ \n");
    printf("                           |              |\n");
    printf("                           |   ImovelUp!  |\n");
    printf("                           |______________|\n");
    printf("\n");
    printf("                           [A]DMINISTRADOR\n");
    printf("\n");
    printf("                              [G]ERENTE\n");
    printf("\n");
    printf("                             [C]ORRETOR\n");
    printf("\n");
    printf("                         [M]ANUAL DO USUARIO\n");
    printf("\n");
    printf("                              [F]ECHAR\n");
    opLetra = getch();
    switch(opLetra)
    {
        case 'A':
        case 'a':
            limpar();
            loginAdministrador();
            break;
        case 'G':
        case 'g':
            limpar();
            loginGerente();
            break;
        case 'C':
        case 'c':
            limpar();
            loginCorretor();
            break;
        case 'M':
        case 'm':
            limpar();
            manualUsuario();
            break;
        case 'F':
        case 'f':
            limpar();
            printf("Obrigado por utilizar os nossos serviços! \n");
            sair();
            break;
        default:
            limpar();
            printf("Opcao invalida. Tente novamente! \n");
            menuPrincipal();
            break;
    }
    return 0;
}

//FUNÇÃO PARA LOGIN DO USUARIO ADMINISTRADOR.
void loginAdministrador()
{
    Administrador adm;
    char login[20];
    char senha[30];
    //ABRINDO ARQUIVO EM MODO DE LEITURA
	arquivoAdministrador = fopen("loginAdministrador.txt", "r");
    printf("                            _______________\n");
    printf("                           |               |\n");
    printf("                           | ADMINISTRADOR |\n");
    printf("                           |_______________|\n");
    printf("\n");
    printf("                              USUARIO: ");
    scanf("                                   %s",adm.login);
    printf("\n");
    printf("                                SENHA: ");
    campoSenha(adm.senha);
    printf("\n\n                    [V]OLTAR  [C]ONTINUAR  [S]AIR \n");
    opLetra = getch();
    switch(opLetra)
    {
        case 'V':
        case 'v':
            limpar();
            menuPrincipal();
            break;
        case 'S':
        case 's':
            limpar();
            sair();
            break;
        case 'C':
        case 'c':
            //BUSCANDO VALOR DENTRO DO ARQUIVO E COLOCANDO NA VARIAVEL LOGIN ATÉ CHEGAR NO FINAL DO ARQUIVO
            while((fscanf(arquivoAdministrador,"\nLogin: %s ,",login) !=EOF) && (fscanf(arquivoAdministrador," Senha: %s",senha) !=EOF))
            {
                //COMPARANDO O QUE FOI DIGITADO COM O VALOR ENCONTRADO DENTRO DO ARQUIVO
                if((strcmp(adm.login,login) == 0) && (strcmp(adm.senha,senha) == 0))
                {
                    limpar();
                    menuAdministrador();
                }
                //SE NÃO FOR IGUAL RETORNA AO MENU
                else
                {
                    limpar();
                    printf("            USUARIO OU SENHA INCORRETO. TENTE NOVAMENTE. \n");
                    loginAdministrador();
                }
                fclose(arquivoAdministrador);
            }
            break;
        default:
            limpar();
            printf("            OPCAO INVALIDA. TENTE NOVAMENTE. \n");
            loginAdministrador();
            break;
    }
}

//FUNÇÃO PARA LOGIN DO USUARIO GERENTE.
void loginGerente()
{
    Gerente gerente;
    char login[20];
    char senha[30];
    //ABRINGO ARQUIVO EM MODO DE LEITURA
	arquivoGerente = fopen("loginGerente.txt", "r");
    printf("                            _______________\n");
    printf("                           |               |\n");
    printf("                           |    GERENTE    |\n");
    printf("                           |_______________|\n");
    printf("\n");
    printf("                              USUARIO: ");
    scanf("                                   %s",gerente.login);
    printf("                                SENHA: ");
    campoSenha(gerente.senha);
    printf("\n\n                    [V]OLTAR  [C]ONTINUAR  [S]AIR \n");
    opLetra = getch();
    switch(opLetra)
    {
        case 'V':
        case 'v':
            limpar();
            menuPrincipal();
            break;
        case 'S':
        case 's':
            limpar();
            sair();
            break;
        case 'C':
        case 'c':
            //BUSCANDO VALOR DENTRO DO ARQUIVO E COLOCANDO NA VARIAVEL LOGIN ATÉ CHEGAR NO FINAL DO ARQUIVO
            while((fscanf(arquivoGerente,"Login: %s ,",login) !=EOF) && (fscanf(arquivoGerente," Senha: %s",senha) !=EOF))
            {
                //COMPARANDO O QUE FOI DIGITADO COM O VALOR ENCONTRADO DENTRO DO ARQUIVO
                if((strcmp(gerente.login,login) == 0) && (strcmp(gerente.senha,senha) == 0))
                {
                    limpar();
                    menuGerente();
                }
                //SE NÃO FOR IGUAL RETORNA AO MENU
                else
                {
                    limpar();
                    printf("            USUARIO OU SENHA INCORRETO. TENTE NOVAMENTE. \n");
                    loginGerente();
                }
                fclose(arquivoGerente);
            }
            break;
        default:
            limpar();
            printf("            OPCAO INVALIDA. TENTE NOVAMENTE. \n");
            loginGerente();
            break;
    }
}

//FUNÇÃO PARA LOGIN DO USUARIO CORRETOR.
void loginCorretor()
{
    Corretor corretor;
    char login[20];
    char senha[30];
    //ABRINGO ARQUIVO EM MODO DE LEITURA
	arquivoCorretor = fopen("loginCorretor.txt", "r");
    printf("                            _______________\n");
    printf("                           |               |\n");
    printf("                           |    CORRETOR    |\n");
    printf("                           |_______________|\n");
    printf("\n");
    printf("                              USUARIO: ");
    scanf("                                   %s",corretor.login);
    printf("                                SENHA: ");
    campoSenha(corretor.senha);
    printf("\n\n                    [V]OLTAR  [C]ONTINUAR  [S]AIR \n");
    opLetra = getch();
    switch(opLetra)
    {
        case 'V':
        case 'v':
            limpar();
            menuPrincipal();
            break;
        case 'S':
        case 's':
            sair();
            break;
        case 'C':
        case 'c':
            //BUSCANDO VALOR DENTRO DO ARQUIVO E COLOCANDO NA VARIAVEL LOGIN ATÉ CHEGAR NO FINAL DO ARQUIVO
            while((fscanf(arquivoCorretor,"Login: %s ,",login) !=EOF) && (fscanf(arquivoCorretor," Senha: %s",senha) !=EOF))
            {
                //COMPARANDO O QUE FOI DIGITADO COM O VALOR ENCONTRADO DENTRO DO ARQUIVO
                if((strcmp(corretor.login,login) == 0) && (strcmp(corretor.senha,senha) == 0))
                {
                    limpar();
                    menuCorretor();
                }
                //SE NÃO FOR IGUAL RETORNA AO MENU
                else
                {
                    limpar();
                    printf("            USUARIO OU SENHA INCORRETO. TENTE NOVAMENTE. \n");
                    loginCorretor();
                }
                fclose(arquivoCorretor);
            }
            break;
        default:
            limpar();
            printf("            OPCAO INVALIDA. TENTE NOVAMENTE. \n");
            loginCorretor();
            break;
    }
}

//MENU PRINCIPAL DO ADMINISTRADOR.
void menuAdministrador()
{
    limpar();
    printf("                            ____________________\n");
    printf("                           |                    |\n");
    printf("                           | MENU ADMINISTRADOR |\n");
    printf("                           |____________________|\n");
    printf("\n");
    printf("                              CONFIGURACOES\n");
    printf("\n");
    printf("                    [G]ERENTE - [C]ORRETOR - [I]MOVEL \n");
    printf("\n");
    printf("                                [S]AIR\n");
    printf("\n");
    opLetra = getch();
    switch(opLetra)
    {
        case 'G':
        case 'g':
            limpar();
            configurarGerente();
            break;
        case 'C':
        case 'c':
            limpar();
            configurarCorretorAdministrador();
            break;
        case 'I':
        case 'i':
            limpar();
            configurarImovelAdministrador();
            break;
        case 'S':
        case 's':
            limpar();
            printf("Obrigado por utilizar nossos servicos. ");
            menuPrincipal();
            break;
        default:
            limpar();
            printf("OPCAO INVALIDA. TENTE NOVAMENTE. ");
            menuAdministrador();
            break;
    }
}

//MENU PRINCIPAL DO GERENTE.
void menuGerente()
{
    limpar();
    printf("                            ____________________\n");
    printf("                           |                    |\n");
    printf("                           |    MENU GERENTE    |\n");
    printf("                           |____________________|\n");
    printf("\n");
    printf("                              CONFIGURACOES\n");
    printf("\n");
    printf("                          [C]ORRETOR - [I]MOVEL \n");
    printf("\n");
    printf("                                 [S]AIR\n");
    printf("\n");
    opLetra = getch();
    switch(opLetra)
    {
        case 'C':
        case 'c':
            limpar();
            configurarCorretorGerente();
            break;
        case 'I':
        case 'i':
            limpar();
            configurarImovelGerente();
            break;
        case 'S':
        case 's':
            limpar();
            printf("Obrigado por utilizar nossos servicos. ");
            menuPrincipal();
            break;
        default:
            limpar();
            printf("OPCAO INVALIDA. TENTE NOVAMENTE. ");
            menuGerente();
            break;
    }
}

//MENU PRINCIPAL DO CORRETOR.
void menuCorretor()
{
    limpar();
    printf("                            ____________________\n");
    printf("                           |                    |\n");
    printf("                           |    MENU CORRETOR   |\n");
    printf("                           |____________________|\n");
    printf("\n");
    printf("                              CONFIGURACOES\n");
    printf("\n");
    printf("                               [I]MOVEL \n");
    printf("\n");
    printf("                                [S]AIR\n");
    printf("\n");
    opLetra = getch();
    switch(opLetra)
    {
        case 'I':
        case 'i':
            limpar();
            configurarImovelCorretor();
            break;
        case 'S':
        case 's':
            limpar();
            printf("Obrigado por utilizar nossos servicos. ");
            menuPrincipal();
            break;
        default:
            limpar();
            printf("OPCAO INVALIDA. TENTE NOVAMENTE. ");
            menuCorretor();
            break;
    }
}

//MENU PARA CONFIGURAR GERENTE - APENAS ADMINISTRADOR TEM PERMISSÃO
void configurarGerente()
{
    limpar();
    printf("                            ____________________\n");
    printf("                           |                    |\n");
    printf("                           | CONFIGURAR GERENTE |\n");
    printf("                           |____________________|\n");
    printf("\n");
    printf("                              [C]ADASTRAR\n");
    printf("\n");
    printf("                              [R]EMOVER \n");
    printf("\n");
    printf("                           [M]OSTRAR GERENTES \n");
    printf("\n");
    printf("                              [V]OLTAR\n");
    printf("\n");
    printf("                           [S]AIR DO SISTEMA\n");
    opLetra = getch();
    switch(opLetra)
    {
        case 'C':
        case 'c':
            limpar();
            cadastrarGerente();
            break;
        case 'R':
        case 'r':
            limpar();
            excluirGerente();
            break;
        case 'M':
        case 'm':
            limpar();
            listarGerentes();
            break;
        case 'V':
        case 'v':
            limpar();
            menuAdministrador();
            break;
        case 'S':
        case 's':
            limpar();
            printf("Obrigado por utilizar nossos servicos. ");
            menuPrincipal();
            break;
        default:
            limpar();
            printf("OPCAO INVALIDA. TENTE NOVAMENTE. ");
            configurarGerente();
            break;
    }
}

//MENU PARA ADMINISTRADOR CONFIGURAR O CORRETOR - (SEPARADAS POR CONTA DA OPÇÃO VOLTAR)
void configurarCorretorAdministrador()
{
    limpar();
    printf("                            _____________________\n");
    printf("                           |                     |\n");
    printf("                           | CONFIGURAR CORRETOR |\n");
    printf("                           |_____________________|\n");
    printf("\n");
    printf("                              [C]ADASTRAR\n");
    printf("\n");
    printf("                              [R]EMOVER \n");
    printf("\n");
    printf("                           [M]OSTRAR CORRETORES \n");
    printf("\n");
    printf("                              [V]OLTAR\n");
    printf("\n");
    printf("                           [S]AIR DO SISTEMA\n");
    opLetra = getch();
    switch(opLetra)
    {
        case 'C':
        case 'c':
            limpar();
            cadastrarCorretorAdministrador();
            break;
        case 'R':
        case 'r':
            limpar();
            excluirCorretorAdministrador();
            break;
        case 'M':
        case 'm':
            limpar();
            listarCorretoresAdministrador();
            break;
        case 'V':
        case 'v':
            limpar();
            menuAdministrador();
            break;
        case 'S':
        case 's':
            limpar();
            printf("Obrigado por utilizar nossos servicos. ");
            menuPrincipal();
            break;
        default:
            limpar();
            printf("OPCAO INVALIDA. TENTE NOVAMENTE. ");
            configurarCorretorAdministrador();
            break;
    }
}

//MENU PARA GERENTE CONFIGURAR O CORRETOR - (SEPARADAS POR CONTA DA OPÇÃO VOLTAR)
void configurarCorretorGerente()
{
    limpar();
    printf("                            _____________________\n");
    printf("                           |                     |\n");
    printf("                           | CONFIGURAR CORRETOR |\n");
    printf("                           |_____________________|\n");
    printf("\n");
    printf("                              [C]ADASTRAR\n");
    printf("\n");
    printf("                              [R]EMOVER \n");
    printf("\n");
    printf("                           [M]OSTRAR CORRETORES \n");
    printf("\n");
    printf("                              [V]OLTAR\n");
    printf("\n");
    printf("                           [S]AIR DO SISTEMA\n");
    opLetra = getch();
    switch(opLetra)
    {
        case 'C':
        case 'c':
            limpar();
            cadastrarCorretorGerente();
            break;
        case 'R':
        case 'r':
            limpar();
            excluirCorretorGerente();
            break;
        case 'M':
        case 'm':
            limpar();
            listarCorretoresGerente();
            break;
        case 'V':
        case 'v':
            limpar();
            menuGerente();
            break;
        case 'S':
        case 's':
            limpar();
            printf("Obrigado por utilizar nossos servicos. ");
            menuPrincipal();
            break;
        default:
            limpar();
            printf("OPCAO INVALIDA. TENTE NOVAMENTE. ");
            configurarCorretorGerente();
            break;
    }
}

//MENU PARA CONFIGURAR IMOVEL - ADMINISTRADOR (SEPARADAS POR CAUSA DA OPÇÃO VOLTAR)
void configurarImovelAdministrador()
{
    limpar();
    printf("                            ____________________\n");
    printf("                           |                    |\n");
    printf("                           | CONFIGURAR IMOVEL  |\n");
    printf("                           |____________________|\n");
    printf("\n");
    printf("                              [C]ADASTRAR\n");
    printf("\n");
    printf("                              [R]EMOVER \n");
    printf("\n");
    printf("                           [M]OSTRAR IMOVEIS \n");
    printf("\n");
    printf("                              [V]OLTAR\n");
    printf("\n");
    printf("                           [S]AIR DO SISTEMA\n");
    opLetra = getch();
    switch(opLetra)
    {
        case 'C':
        case 'c':
            limpar();
            cadastrarImovelAdministrador();
            break;
        case 'R':
        case 'r':
            limpar();
            excluirImovelAdministrador();
            break;
        case 'M':
        case 'm':
            limpar();
            listarImoveisAdministrador();
            break;
        case 'V':
        case 'v':
            limpar();
            menuAdministrador();
            break;
        case 'S':
        case 's':
            limpar();
            printf("Obrigado por utilizar nossos servicos. ");
            menuPrincipal();
            break;
        default:
            limpar();
            printf("OPCAO INVALIDA. TENTE NOVAMENTE. ");
            configurarImovelAdministrador();
            break;
    }
}

//MENU PARA CONFIGURAR IMOVEL - GERENTE (SEPARADAS POR CAUSA DA OPÇÃO VOLTAR)
void configurarImovelGerente()
{
    limpar();
    printf("                            ____________________\n");
    printf("                           |                    |\n");
    printf("                           | CONFIGURAR IMOVEL  |\n");
    printf("                           |____________________|\n");
    printf("\n");
    printf("                              [C]ADASTRAR\n");
    printf("\n");
    printf("                              [R]EMOVER \n");
    printf("\n");
    printf("                           [M]OSTRAR IMOVEIS \n");
    printf("\n");
    printf("                              [V]OLTAR\n");
    printf("\n");
    printf("                           [S]AIR DO SISTEMA\n");
    opLetra = getch();
    switch(opLetra)
    {
        case 'C':
        case 'c':
            limpar();
            cadastrarImovelGerente();
            break;
        case 'R':
        case 'r':
            limpar();
            excluirImovelGerente();
            break;
        case 'M':
        case 'm':
            limpar();
            listarImoveisGerente();
            break;
        case 'V':
        case 'v':
            limpar();
            menuGerente();
            break;
        case 'S':
        case 's':
            limpar();
            printf("Obrigado por utilizar nossos servicos. ");
            menuPrincipal();
            break;
        default:
            limpar();
            printf("OPCAO INVALIDA. TENTE NOVAMENTE. ");
            configurarImovelGerente();
            break;
    }
}

//MENU PARA CONFIGURAR IMOVEL - CORRETOR (SEPARADAS POR CAUSA DA OPÇÃO VOLTAR)
void configurarImovelCorretor()
{
    limpar();
    printf("                            ____________________\n");
    printf("                           |                    |\n");
    printf("                           | CONFIGURAR IMOVEL  |\n");
    printf("                           |____________________|\n");
    printf("\n");
    printf("                              [C]ADASTRAR\n");
    printf("\n");
    printf("                           [M]OSTRAR IMOVEIS \n");
    printf("\n");
    printf("                              [V]OLTAR\n");
    printf("\n");
    printf("                           [S]AIR DO SISTEMA\n");
    opLetra = getch();
    switch(opLetra)
    {
        case 'C':
        case 'c':
            limpar();
            cadastrarImovelCorretor();
            break;
        case 'M':
        case 'm':
            limpar();
            listarImoveisCorretor();
            break;
        case 'V':
        case 'v':
            limpar();
            menuCorretor();
            break;
        case 'S':
        case 's':
            limpar();
            printf("Obrigado por utilizar nossos servicos. ");
            menuPrincipal();
            break;
        default:
            limpar();
            printf("OPCAO INVALIDA. TENTE NOVAMENTE. ");
            configurarImovelCorretor();
            break;
    }
}

//MENU PARA MOSTRAR GERENTES - APENAS ADMINISTRADOR TEM PERMISSÃO
void listarGerentes()
{
	printf("                            ____________________________\n");
    printf("                           |                            |\n");
    printf("                           |    GERENTES CADASTRADOS    |\n");
    printf("                           |____________________________|\n");
    printf("\n");
    //ABRINDO ARQUIVO EM MODO DE LEITURA
    arquivoGerente = fopen("loginGerente.txt", "r");
    char *result;
    int i;
    char conteudoGerenteCadastrado[151];
    if (arquivoGerente == NULL)  // Se houve erro na abertura
    {
         printf("Problemas na abertura do arquivo\n");
         return 0;
    }
    i = 1;

    while (!feof(arquivoGerente))
    {
        // Lê uma linha (inclusive com o '\n')
        result = fgets(conteudoGerenteCadastrado, 151, arquivoGerente);  // o 'fgets' lê até 150 caracteres ou até o '\n'

        if (result != NULL)  // Se foi possível ler
        {
            printf("                \n ================================================= \n");
            printf(" Gerente %d: %s",i,conteudoGerenteCadastrado);
            printf("                \n ================================================= \n");
            i++;
        }
    }

    fclose(arquivoGerente);

    printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
    getch();
    limpar();
    menuAdministrador();
}

//MENU PARA CADASTRAR GERENTE - APENAS ADMINISTRADOR TEM PERMISSÃO
void cadastrarGerente()
{
    char login[20];
    //ABRINGO ARQUIVO EM MODO DE GRAVAÇÃO E LEITURA
    arquivoGerente = fopen("loginGerente.txt","a+");
    if (arquivoGerente == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        sair();
    }

    Gerente gerente;

    printf("                            ________________________\n");
    printf("                           |                        |\n");
    printf("                           | CADASTRAR NOVO GERENTE |\n");
    printf("                           |________________________|\n");
    printf("\n");
    printf("                              NOME COMPLETO: ");
    fflush(stdin);
    gets(gerente.nome);
    printf("\n                                 LOGIN: ");
    scanf("%s", &gerente.login);
    printf("\n                                 SENHA: ");
    scanf("%s", &gerente.senha);
    //NÃO PRECISA VERIFICAR SE USUARIO JA EXISTE, POIS TODOS OS USUARIOS CONSEGUEM VER OS IMOVEIS
    fprintf(arquivoGerente,"Login: %s ,", gerente.login);
    fprintf(arquivoGerente," Senha: %s ,", gerente.senha);
    fprintf(arquivoGerente," Nome: %s \n", gerente.nome);

    fclose(arquivoGerente);

    printf("\n                         GERENTE REGISTRADO COM SUCESSO!\n");
    printf("                     PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
    getch();
    limpar();
    menuAdministrador();
}

//MENU PARA REMOVER GERENTE - APENAS ADMINISTRADOR TEM PERMISSÃO
void excluirGerente()
{
    printf("                            _________________________\n");
    printf("                           |                         |\n");
    printf("                           |     EXCLUIR GERENTE     |\n");
    printf("                           |_________________________|\n");
    printf("\n");
    //ABRINDO ARQUIVO EM MODO DE LEITURA
    arquivoGerente = fopen("loginGerente.txt", "r");
    int *codigoGerente;
    FILE *aux = fopen("transferindoGerentes.txt", "w"); //Arquivo de saída.
    char conteudoGerente[2501]; //Uma string larga o suficiente para extrair o texto total de cada linha.
    unsigned int linha_atual = 1;
    if (arquivoGerente == NULL)  // Se houve erro na abertura
    {
         printf("Problemas na abertura do arquivo\n");
         return 0;
    }
    printf("\n");
    printf("                      DIGITE O CODIGO DO GERENTE A SER EXCLUIDO: ");
    scanf("%d", &codigoGerente);
    while(fgets(conteudoGerente, 2501, arquivoGerente) != NULL){
        if(linha_atual != codigoGerente){
            fputs(conteudoGerente, aux);
        }
        linha_atual++;
    }
    fclose(arquivoGerente);
    fclose(aux);
    remove("loginGerente.txt");
    rename("transferindoGerentes.txt", "loginGerente.txt");
    printf("\n                        GERENTE REMOVIDO COM SUCESSO.");
    printf("\n                PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
    getch();
    limpar();
    menuAdministrador();
}

//MENU PARA MOSTRAR CORRETORES - ADMINISTRADOR (SEPARADAS POR CAUSA DA OPÇÃO VOLTAR)
void listarCorretoresAdministrador()
{
	printf("                            ____________________________\n");
    printf("                           |                            |\n");
    printf("                           |   CORRETORES CADASTRADOS   |\n");
    printf("                           |____________________________|\n");
    printf("\n");
    //ABRINGO ARQUIVO EM MODO DE LEITURA
    arquivoCorretor = fopen("loginCorretor.txt", "r");
    char *result;
    int i;
    char conteudoCorretorCadastrado[161];
    if (arquivoCorretor == NULL)  // Se houve erro na abertura
    {
         printf("Nenhum corretor cadastrado. \n");
         return 0;
    }
    i = 1;

    while (!feof(arquivoCorretor))
    {
        // Lê uma linha (inclusive com o '\n')
        result = fgets(conteudoCorretorCadastrado, 161, arquivoCorretor);  // o 'fgets' lê até 160 caracteres ou até o '\n'

        if (result != NULL)  // Se foi possível ler
        {
            printf("                \n ================================================= \n");
            printf(" Corretor %d: %s",i,conteudoCorretorCadastrado);
            printf("                \n ================================================= \n");
            i++;
        }
    }

    fclose(arquivoCorretor);

    printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
    getch();
    limpar();
    menuAdministrador();
}

//MENU PARA MOSTRAR CORRETORES - GERENTE (SEPARADAS POR CAUSA DA OPÇÃO VOLTAR)
void listarCorretoresGerente()
{
	printf("                            ____________________________\n");
    printf("                           |                            |\n");
    printf("                           |   CORRETORES CADASTRADOS   |\n");
    printf("                           |____________________________|\n");
    printf("\n");
    //ABRINGO ARQUIVO EM MODO DE LEITURA
    arquivoCorretor = fopen("loginCorretor.txt", "r");
    char *result;
    int i;
    char conteudoCorretorCadastrado[161];
    if (arquivoCorretor == NULL)  // Se houve erro na abertura
    {
         printf("Nenhum corretor cadastrado. \n");
         return 0;
    }
    i = 1;

    while (!feof(arquivoCorretor))
    {
        // Lê uma linha (inclusive com o '\n')
        result = fgets(conteudoCorretorCadastrado, 161, arquivoCorretor);  // o 'fgets' lê até 160 caracteres ou até o '\n'

        if (result != NULL)  // Se foi possível ler
        {
            printf("                \n ================================================= \n");
            printf(" Corretor %d: %s",i,conteudoCorretorCadastrado);
            printf("                \n ================================================= \n");
            i++;
        }
    }

    fclose(arquivoCorretor);

    printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
    getch();
    limpar();
    menuGerente();
}

//MENU PARA CADASTRAR CORRETOR - ADMINISTRADOR (SEPARADAS POR CAUSA DA OPÇÃO VOLTAR)
void cadastrarCorretorAdministrador()
{
    char login[20];
    //ABRINDO ARQUIVO EM MODO DE GRAVAÇÃO E LEITURA
    arquivoCorretor = fopen("loginCorretor.txt","a+");
    if (arquivoCorretor == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        sair();
    }

    Corretor corretor;

    printf("                            _________________________\n");
    printf("                           |                         |\n");
    printf("                           | CADASTRAR NOVO CORRETOR |\n");
    printf("                           |_________________________|\n");
    printf("\n");
    printf("                              NOME COMPLETO: ");
    fflush(stdin);
    gets(corretor.nome);
    printf("\n                                 CRECI: ");
    scanf("%s", &corretor.numeroCreci);
    printf("\n                                 LOGIN: ");
    scanf("%s", &corretor.login);
    printf("\n                                 SENHA: ");
    scanf("%s", &corretor.senha);

    //INSERIDO O QUE FOI DIGITADO PELO USUARIO AO ARQUIVO COM UM PADRÃO
    fprintf(arquivoCorretor,"Login: %s ,", corretor.login);
    fprintf(arquivoCorretor," Senha: %s ,", corretor.senha);
    fprintf(arquivoCorretor," Nome: %s ,", corretor.nome);
    fprintf(arquivoCorretor," CRECI: %s \n", corretor.numeroCreci);

    fclose(arquivoCorretor);

    printf("\nRegistrado com sucesso!\n");
    printf("PRESSIONE QUALQUER TECLA PARA CONTINUAR.");
    getch();
    limpar();
    menuAdministrador();
}

//MENU PARA CADASTRAR CORRETOR - GERENTE (SEPARADAS POR CAUSA DA OPÇÃO VOLTAR)
void cadastrarCorretorGerente()
{
    char login[20];
    //ABRINDO ARQUIVO EM MODO DE GRAVAÇÃO E LEITURA
    arquivoCorretor = fopen("loginCorretor.txt","a+");
    if (arquivoCorretor == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        sair();
    }
    Corretor corretor;

    printf("                            _________________________\n");
    printf("                           |                         |\n");
    printf("                           | CADASTRAR NOVO CORRETOR |\n");
    printf("                           |_________________________|\n");
    printf("\n");
    printf("                              NOME COMPLETO: ");
    fflush(stdin);
    gets(corretor.nome);
    printf("\n                                 CRECI: ");
    scanf("%s", &corretor.numeroCreci);
    printf("\n                                 LOGIN: ");
    scanf("%s", &corretor.login);
    printf("\n                                 SENHA: ");
    scanf("%s", &corretor.senha);

    //INSERIDO O QUE FOI DIGITADO PELO USUARIO AO ARQUIVO COM UM PADRÃO
    fprintf(arquivoCorretor,"Login: %s ,", corretor.login);
    fprintf(arquivoCorretor," Senha: %s ,", corretor.senha);
    fprintf(arquivoCorretor," Nome: %s ,", corretor.nome);
    fprintf(arquivoCorretor," CRECI: %s \n", corretor.numeroCreci);

    fclose(arquivoCorretor);

    printf("\nRegistrado com sucesso!\n");
    printf("PRESSIONE QUALQUER TECLA PARA CONTINUAR.");
    getchar();
    limpar();
    menuGerente();
}

//MENU PARA REMOVER CORRETOR - ADMINISTRADOR (SEPARADAS POR CAUSA DA OPÇÃO VOLTAR)
void excluirCorretorAdministrador()
{
    printf("                            _________________________\n");
    printf("                           |                         |\n");
    printf("                           |    EXCLUIR CORRETOR     |\n");
    printf("                           |_________________________|\n");
    printf("\n");
    //ABRINDO ARQUIVO EM MODO DE LEITURA
    arquivoCorretor = fopen("loginCorretor.txt", "r");
    int *codigoCorretor;
    FILE *aux = fopen("transferindoCorretores.txt", "w"); //Arquivo de saída.
    char conteudoCorretor[2501]; //Uma string larga o suficiente para extrair o texto total de cada linha.
    unsigned int linha_atual = 1;
    if (arquivoCorretor == NULL)  // Se houve erro na abertura
    {
         printf("Problemas na abertura do arquivo\n");
         return 0;
    }
    printf("\n");
    printf("                      DIGITE O CODIGO DO CORRETOR A SER EXCLUIDO: ");
    scanf("%d", &codigoCorretor);
    while(fgets(conteudoCorretor, 2501, arquivoCorretor) != NULL){
        if(linha_atual != codigoCorretor){
            fputs(conteudoCorretor, aux);
        }
        linha_atual++;
    }
    fclose(arquivoCorretor);
    fclose(aux);
    remove("loginCorretor.txt");
    rename("transferindoCorretores.txt", "loginCorretor.txt");
    printf("\n                        CORRETOR REMOVIDO COM SUCESSO.");
    printf("\n                PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
    getch();
    limpar();
    menuAdministrador();
}

//MENU PARA CADASTRAR CORRETOR - GERENTE (SEPARADAS POR CAUSA DA OPÇÃO VOLTAR)
void excluirCorretorGerente()
{
    printf("                            _________________________\n");
    printf("                           |                         |\n");
    printf("                           |    EXCLUIR CORRETOR     |\n");
    printf("                           |_________________________|\n");
    printf("\n");
    //ABRINDO ARQUIVO EM MODO DE LEITURA
    arquivoCorretor = fopen("loginCorretor.txt", "r");
    int *codigoCorretor;
    FILE *aux = fopen("transferindoCorretores.txt", "w"); //Arquivo de saída.
    char conteudoCorretor[2501]; //Uma string larga o suficiente para extrair o texto total de cada linha.
    unsigned int linha_atual = 1;
    if (arquivoCorretor == NULL)  // Se houve erro na abertura
    {
         printf("Problemas na abertura do arquivo\n");
         return 0;
    }
    printf("\n");
    printf("                      DIGITE O CODIGO DO CORRETOR A SER EXCLUIDO: ");
    scanf("%d", &codigoCorretor);
    while(fgets(conteudoCorretor, 2501, arquivoCorretor) != NULL){
        if(linha_atual != codigoCorretor){
            fputs(conteudoCorretor, aux);
        }
        linha_atual++;
    }
    fclose(arquivoCorretor);
    fclose(aux);
    remove("loginCorretor.txt");
    rename("transferindoCorretores.txt", "loginCorretor.txt");
    printf("\n                        CORRETOR REMOVIDO COM SUCESSO.");
    printf("\n                PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
    getch();
    limpar();
    menuGerente();
}

//MENU PARA MOSTRAR IMOVEIS - ADMINISTRADOR (SEPARADAS POR CAUSA DA OPÇÃO VOLTAR)
void listarImoveisAdministrador()
{
	printf("                            ____________________________\n");
    printf("                           |                            |\n");
    printf("                           |     IMOVEIS CADASTRADOS    |\n");
    printf("                           |____________________________|\n");
    printf("\n");
    //ABRINDO ARQUIVO EM MODO DE LEITURA
    arquivoImovel = fopen("Imoveis.txt", "r");
    char *result;
    int i;
    char conteudoImovelCadastrado[2501];
    if (arquivoImovel == NULL)  // Se houve erro na abertura
    {
         printf("Problemas na abertura do arquivo\n");
         return 0;
    }
    i = 1;

    while (!feof(arquivoImovel))
    {
        // Lê uma linha (inclusive com o '\n')
        result = fgets(conteudoImovelCadastrado, 2501, arquivoImovel);  // o 'fgets' lê até 2500 caracteres ou até o '\n'

        if (result != NULL)  // Se foi possível ler
        {
            printf("                \n ================================================= \n");
            printf(" Imovel %d: %s",i,conteudoImovelCadastrado);
            printf("                \n ================================================= \n");
            printf("\n");
            i++;
        }
    }

    fclose(arquivoImovel);
    printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
    getch();
    limpar();
    menuAdministrador();
}

//MENU PARA MOSTRAR IMOVEIS - GERENTE (SEPARADAS POR CAUSA DA OPÇÃO VOLTAR)
void listarImoveisGerente()
{
	printf("                            ____________________________\n");
    printf("                           |                            |\n");
    printf("                           |     IMOVEIS CADASTRADOS    |\n");
    printf("                           |____________________________|\n");
    printf("\n");
    //ABRINDO ARQUIVO EM MODO DE LEITURA
    arquivoImovel = fopen("Imoveis.txt", "r");
    char *result;
    int i;
    char conteudoImovelCadastrado[2501];
    if (arquivoImovel == NULL)  // Se houve erro na abertura
    {
         printf("Problemas na abertura do arquivo\n");
         return 0;
    }
    i = 1;

    while (!feof(arquivoImovel))
    {
        // Lê uma linha (inclusive com o '\n')
        result = fgets(conteudoImovelCadastrado, 2501, arquivoImovel);  // o 'fgets' lê até 2500 caracteres ou até o '\n'

        if (result != NULL)  // Se foi possível ler
        {
            printf("                \n ================================================= \n");
            printf(" Imovel %d: %s",i,conteudoImovelCadastrado);
            printf("                \n ================================================= \n");
            printf("\n");
            i++;
        }
    }

    fclose(arquivoImovel);
    printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
    getch();
    limpar();
    menuGerente();
}

//MENU PARA MOSTRAR IMOVEIS - CORRETOR (SEPARADAS POR CAUSA DA OPÇÃO VOLTAR)
void listarImoveisCorretor()
{
	printf("                            ____________________________\n");
    printf("                           |                            |\n");
    printf("                           |     IMOVEIS CADASTRADOS    |\n");
    printf("                           |____________________________|\n");
    printf("\n");
    //ABRINDO ARQUIVO EM MODO DE LEITURA
    arquivoImovel = fopen("Imoveis.txt", "r");
    char *result;
    int i;
    char conteudoImovelCadastrado[2501];
    if (arquivoImovel == NULL)  // Se houve erro na abertura
    {
         printf("Problemas na abertura do arquivo\n");
         return 0;
    }
    i = 1;

    while (!feof(arquivoImovel))
    {
        // Lê uma linha (inclusive com o '\n')
        result = fgets(conteudoImovelCadastrado, 2501, arquivoImovel);  // o 'fgets' lê até 2500 caracteres ou até o '\n'

        if (result != NULL)  // Se foi possível ler
        {
            //EXIBINDO IMOVEIS NA TELA
            printf("                \n ================================================= \n");
            printf(" Imovel %d: %s",i,conteudoImovelCadastrado);
            printf("                \n ================================================= \n");
            printf("\n");
            i++;
        }
    }

    fclose(arquivoImovel);
    printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
    getch();
    limpar();
    menuCorretor();
}

//MENU PARA CADASTRAR IMOVEL - ADMINISTRADOR (SEPARADAS POR CAUSA DA OPÇÃO VOLTAR)
void cadastrarImovelAdministrador()
{
    //ABRINDO ARQUIVO EM MODO DE GRAVAÇÃO E LEITURA
    arquivoImovel = fopen("Imoveis.txt","a");
    if (arquivoImovel == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        sair();
    }

    Imovel imovel;

    printf("                            ________________________\n");
    printf("                           |                        |\n");
    printf("                           |  CADASTRAR NOVO IMOVEL |\n");
    printf("                           |________________________|\n");
    printf("\n");
    printf("                            PROPRIETARIO: ");
    fflush(stdin);
    gets(imovel.proprietario);
    printf("\n                          TELEFONE: ");
    scanf("%s", &imovel.telefone);
    printf("\n                          MODALIDADE: (VENDA | LOCACAO): ");
    scanf("%s", &imovel.modalidade);
    printf("\n                          ENDERECO COMPLETO: ");
    fflush(stdin);
    gets(imovel.endereco);
    printf("\n                          PRECO DO IMOVEL: ");
    scanf("%f", &imovel.preco);
    printf("\n                          DESCRICAO DO IMOVEL (TIPO DE IMOVEL | COMPOSICAO | DETALHES): ");
    fflush(stdin);
    gets(imovel.descricao);

    //INSERIDO O QUE FOI DIGITADO PELO USUARIO AO ARQUIVO COM UM PADRÃO
    fprintf(arquivoImovel,"Proprietario: %s ,", imovel.proprietario);
    fprintf(arquivoImovel," Telefone: %s ,", imovel.telefone);
    fprintf(arquivoImovel," Modalidade: %s ,", imovel.modalidade);
    fprintf(arquivoImovel," Endereco: %s ,", imovel.endereco);
    fprintf(arquivoImovel," Valor: %f", imovel.preco);
    fprintf(arquivoImovel," Descricao do Imovel: %s \n", imovel.descricao);
    fclose(arquivoImovel);

    printf("\n                         REGISTRADO COM SUCESSO!\n");
    printf("                 PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
    getch();
    limpar();
    menuAdministrador();
}

//MENU PARA CADASTRAR IMOVEL - GERENTE (SEPARADAS POR CAUSA DA OPÇÃO VOLTAR)
void cadastrarImovelGerente()
{
    arquivoImovel = fopen("Imoveis.txt","a");
    if (arquivoImovel == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        sair();
    }

    Imovel imovel;

    printf("                            ________________________\n");
    printf("                           |                        |\n");
    printf("                           |  CADASTRAR NOVO IMOVEL |\n");
    printf("                           |________________________|\n");
    printf("\n");
    printf("                            PROPRIETARIO: ");
    fflush(stdin);
    gets(imovel.proprietario);
    printf("\n                          TELEFONE: ");
    scanf("%s", &imovel.telefone);
    printf("\n                          MODALIDADE: (VENDA | LOCACAO): ");
    scanf("%s", &imovel.modalidade);
    printf("\n                          ENDERECO COMPLETO: ");
    fflush(stdin);
    gets(imovel.endereco);
    printf("\n                          PRECO DO IMOVEL: ");
    scanf("%f", &imovel.preco);
    printf("\n                          DESCRICAO DO IMOVEL (TIPO DE IMOVEL | COMPOSICAO | DETALHES): ");
    fflush(stdin);
    gets(imovel.descricao);

    //INSERIDO O QUE FOI DIGITADO PELO USUARIO AO ARQUIVO COM UM PADRÃO
    fprintf(arquivoImovel,"Proprietario: %s ,", imovel.proprietario);
    fprintf(arquivoImovel," Telefone: %s ,", imovel.telefone);
    fprintf(arquivoImovel," Modalidade: %s ,", imovel.modalidade);
    fprintf(arquivoImovel," Endereco: %s ,", imovel.endereco);
    fprintf(arquivoImovel," Valor: %f", imovel.preco);
    fprintf(arquivoImovel," Descricao do Imovel: %s \n", imovel.descricao);
    fclose(arquivoImovel);

    printf("\n                        REGISTRADO COM SUCESSO!\n");
    printf("                 PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
    getch();
    limpar();
    menuGerente();
}

//MENU PARA CADASTRAR IMOVEL - CORRETOR (SEPARADAS POR CAUSA DA OPÇÃO VOLTAR)
void cadastrarImovelCorretor()
{
    arquivoImovel = fopen("Imoveis.txt","a");
    if (arquivoImovel == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        sair();
    }
    Imovel imovel;

    printf("                            ________________________\n");
    printf("                           |                        |\n");
    printf("                           |  CADASTRAR NOVO IMOVEL |\n");
    printf("                           |________________________|\n");
    printf("\n");
    printf("                            PROPRIETARIO: ");
    fflush(stdin);
    gets(imovel.proprietario);
    printf("\n                          TELEFONE: ");
    scanf("%s", &imovel.telefone);
    printf("\n                          MODALIDADE: (VENDA | LOCACAO): ");
    scanf("%s", &imovel.modalidade);
    printf("\n                          ENDERECO COMPLETO: ");
    fflush(stdin);
    gets(imovel.endereco);
    printf("\n                          PRECO DO IMOVEL: ");
    scanf("%f", &imovel.preco);
    printf("\n                          DESCRICAO DO IMOVEL (TIPO DE IMOVEL | COMPOSICAO | DETALHES): ");
    fflush(stdin);
    gets(imovel.descricao);

    //INSERIDO O QUE FOI DIGITADO PELO USUARIO AO ARQUIVO COM UM PADRÃO
    fprintf(arquivoImovel,"Proprietario: %s ,", imovel.proprietario);
    fprintf(arquivoImovel," Telefone: %s ,", imovel.telefone);
    fprintf(arquivoImovel," Modalidade: %s ,", imovel.modalidade);
    fprintf(arquivoImovel," Endereco: %s ,", imovel.endereco);
    fprintf(arquivoImovel," Valor: %f", imovel.preco);
    fprintf(arquivoImovel," Descricao do Imovel: %s \n", imovel.descricao);
    fclose(arquivoImovel);

    printf("\n                         REGISTRADO COM SUCESSO!\n");
    printf("                 PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
    getch();
    limpar();
    menuCorretor();
}

void excluirImovelAdministrador()
{
    printf("                            _________________________\n");
    printf("                           |                         |\n");
    printf("                           |     EXCLUIR IMOVEL      |\n");
    printf("                           |_________________________|\n");
    //ABRINDO ARQUIVO EM MODO DE LEITURA
    arquivoImovel = fopen("Imoveis.txt", "r");
    int *codigo;
    FILE *aux = fopen("transferindoImoveis.txt", "w"); //Arquivo de saída.
    char conteudoImovel[2501]; //Uma string larga o suficiente para extrair o texto total de cada linha.
    unsigned int linha_atual = 1;
    if (arquivoImovel == NULL)  // Se houve erro na abertura
    {
         printf("Problemas na abertura do arquivo\n");
         return 0;
    }
    printf("\n");
    printf("                      DIGITE O NUMERO DO IMOVEL A SER EXCLUIDO: ");
    scanf("%d", &codigo);
    //PEGANDO OS VALORES DO ARQUIVO E ATRIBUINDO NA VARIAVEL CONTEUDOIMOVEL
    while(fgets(conteudoImovel, 2501, arquivoImovel) != NULL){
        //SE FOR DIFERENTE DO CODIGO DIGITADO DO USUARIO A CONDIÇÃO IRÁ ACRESCENTAR O CONTEUDO NO ARQUIVO AUXILIAR
        if(linha_atual != codigo){
            fputs(conteudoImovel, aux);
        }
        //PULA PARA A PROXIMA LINHA
        linha_atual++;
    }
    fclose(arquivoImovel);
    fclose(aux);
    //REMOVE O ARQUIVO ANTIGO
    remove("Imoveis.txt");
    //RENOMEIA O ARQUIVO AUXILIAR COMO ORIGINAL
    rename("transferindoImoveis.txt", "Imoveis.txt");
    printf("\n                        IMOVEL REMOVIDO COM SUCESSO.");
    printf("\n                PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
    getch();
    limpar();
    menuAdministrador();
}

void excluirImovelGerente()
{
    printf("                            _________________________\n");
    printf("                           |                         |\n");
    printf("                           |     EXCLUIR IMOVEL      |\n");
    printf("                           |_________________________|\n");
    //ABRINDO ARQUIVO EM MODO DE LEITURA
    arquivoImovel = fopen("Imoveis.txt", "r");
    int *codigo;
    FILE *aux = fopen("transferindoImoveis.txt", "w"); //Arquivo de saída.
    char conteudoImovel[2501]; //Uma string larga o suficiente para extrair o texto total de cada linha.
    unsigned int linha_atual = 1;
    if (arquivoImovel == NULL)  // Se houve erro na abertura
    {
         printf("Problemas na abertura do arquivo\n");
         return 0;
    }
    printf("\n");
    printf("                      DIGITE O NUMERO DO IMOVEL A SER EXCLUIDO: ");
    scanf("%d", &codigo);
    //PEGANDO OS VALORES DO ARQUIVO E ATRIBUINDO NA VARIAVEL CONTEUDOIMOVEL
    while(fgets(conteudoImovel, 2501, arquivoImovel) != NULL){
        //SE FOR DIFERENTE DO CODIGO DIGITADO DO USUARIO A CONDIÇÃO IRÁ ACRESCENTAR O CONTEUDO NO ARQUIVO AUXILIAR
        if(linha_atual != codigo){
            fputs(conteudoImovel, aux);
        }
        //PULA PARA A PROXIMA LINHA
        linha_atual++;
    }
    fclose(arquivoImovel);
    fclose(aux);
    //REMOVE O ARQUIVO ANTIGO
    remove("Imoveis.txt");
    //RENOMEIA O ARQUIVO AUXILIAR COMO ORIGINAL
    rename("transferindoImoveis.txt", "Imoveis.txt");
    printf("\n                        IMOVEL REMOVIDO COM SUCESSO.");
    printf("\n                PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
    getch();
    limpar();
    menuGerente();
}

//FUNÇÃO SIMPLES DE LIMPAR
void limpar()
{
    system("cls");
}

//FUNÇÃO SIMPLES DE SAIR
void sair()
{
    exit(1);
}


//FUNÇÃO LOGO DO SISTEMA
void logo()
{
    printf("\n");
    printf("  ##  ##     ##  ########  ##     ##  ######  ##      ##    ##  ######## #    \n");
    printf("  ##  ###   ###  ##    ##  ##     ##  ##      ##      ##    ##  ##    ## #    \n");
    printf("  ##  #### ####  ##    ##  ##     ##  ##      ##      ##    ##  ######## #    \n");
    printf("  ##  ## ### ##  ##    ##  ##     ##  ######  ##      ##    ##  ##       #    \n");
    printf("  ##  ##     ##  ##    ##   ##   ##   ##      ##      ##    ##  ##       #    \n");
    printf("  ##  ##     ##  ##    ##    ## ##    ##      ##      ##    ##  ##            \n");
    printf("  ##  ##     ##  ########      #      ######  ######  ########  ##       #    \n");
    printf("\n");
    printf("      > ImovelUp! - Todos os direitos reservados. - 2022 \n\n\n");
	return(0);

}

//FUNÇÃO MANUAL DO USUÁRIO
void manualUsuario()
{
    char opLetraManual;
    printf("                            ________________________\n");
    printf("                           |                        |\n");
    printf("                           |    MANUAL DO USUARIO   |\n");
    printf("                           |________________________|\n");
    printf("\n");
    printf("                          MENU [P]RINCIPAL - INSTRUCOES");
    printf("\n");
    printf("                          [A]DMINISTRADOR - INSTRUCOES");
    printf("\n");
    printf("                            [G]ERENTE - INSTRUCOES");
    printf("\n");
    printf("                            [C]ORRETOR - INSTRUCOES");
    opLetraManual = getch();
    switch(opLetraManual)
    {
        case 'P':
        case 'p':
            //INSTRUÇÕES MENU PRINCIPAL
            printf("\nMENU PRINCIPAL");
            printf("\nDIGITE A PARA ENTRAR COMO ADMINISTRADOR");
            printf("\nDIGITE G PARA ENTRAR COMO GERENTE");
            printf("\nDIGITE C PARA ENTRAR COMO CORRETOR");
            printf("\n");
            printf("PRESSIONE QUALQUER TECLA PARA CONTINUAR. ");
            getch();
            menuPrincipal();
            break;
        case 'A':
        case 'a':
            //INSTRUÇÕES PARA O ADMINISTRADOR
            printf("\nLOGIN ADMINISTRADOR: ");
            printf("\nDIGITE O LOGIN E SENHA - ENTER");
            printf("\nDIGITE V PARA VOLTAR, C PARA CONTINUAR OU S PARA SAIR");
            printf("\n");
            printf("\nMENU ADMINISTRADOR:");
            printf("\nDIGITE G PARA CONFIGURAR GERENTE");
            printf("\nDIGITE C PARA CONFIGURAR CORRETOR");
            printf("\nDIGITE I PARA CONFIGURAR IMOVEL");
            printf("\nDIGITE S PARA SAIR");
            printf("\n");
            printf("\nCONFIGURAR GERENTE:");
            printf("\nDIGITE C PARA CADASTRAR GERENTE");
            printf("\nDIGITE R PARA REMOVER GERENTE");
            printf("\nDIGITE M PARA MOSTRAR GERENTES");
            printf("\nDIGITE V PARA VOLTAR");
            printf("\nDIGITE S PARA SAIR");
            printf("\n");
            printf("\nCADASTRAR GERENTE:");
            printf("\nDIGITE O NOME COMPLETO DO GERENTE - ENTER");
            printf("\nDIGITE O LOGIN DO GERENTE - ENTER");
            printf("\nDIGITE A SENHA DO GERENTE - ENTER ");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU");
            printf("\n");
            printf("\REMOVER GERENTE:");
            printf("\nDIGITE O CODIGO DO GERENTE - ENTER");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU");
            printf("\n");
            printf("\MOSTRAR GERENTES:");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU");
            printf("\n");
            printf("\nCONFIGURAR CORRETOR:");
            printf("\nDIGITE C PARA CADASTRAR CORRETOR");
            printf("\nDIGITE R PARA REMOVER CORRETOR");
            printf("\nDIGITE M PARA MOSTRAR CORRETORES");
            printf("\nDIGITE V PARA VOLTAR");
            printf("\nDIGITE S PARA SAIR");
            printf("\n");
            printf("\nCADASTRAR CORRETOR:");
            printf("\nDIGITE O NOME COMPLETO DO CORRETOR - ENTER ");
            printf("\nDIGITE O CRECI DO CORRETOR - ENTER");
            printf("\nDIGITE O LOGIN DO CORRETOR - ENTER");
            printf("\nDIGITE A SENHA DO CORRETOR - ENTER");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU");
            printf("\n");
            printf("\REMOVER CORRETOR:");
            printf("\nDIGITE O CODIGO DO CORRETOR - ENTER");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU");
            printf("\n");
            printf("\MOSTRAR CORRETORES:");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU");
            printf("\n");
            printf("\nCADASTRAR IMOVEL:");
            printf("\nDIGITE O NOME DO PROPRIETARIO - ENTER ");
            printf("\nDIGITE O TELEFONE DO PROPRIETARIO - ENTER");
            printf("\nDIGITE O TIPO DE IMOVEL - VENDA/LOCACAO - ENTER");
            printf("\nDIGITE O VALOR DO IMOVEL - ENTER");
            printf("\nDIGITE A DESCRICAO DO IMOVEL - ENTER");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU");
            printf("\n");
            printf("\REMOVER IMOVEL:");
            printf("\nDIGITE O CODIGO DO IMOVEL - ENTER");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU");
            printf("\n");
            printf("\MOSTRAR IMOVEIS:");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU");
            printf("\n");
            getch();
            menuPrincipal();
            break;
        case 'G':
        case 'g':
            //INSTRUÇÕES PARA O GERENTE
            printf("\nLOGIN GERENTE: ");
            printf("\nDIGITE O LOGIN E SENHA COM ENTER");
            printf("\nDIGITE V PARA VOLTAR, C PARA CONTINUAR OU S PARA SAIR");
            printf("\n");
            getch();
            printf("\nMENU GERENTE:");
            printf("\nDIGITE C PARA CONFIGURAR CORRETOR");
            printf("\nDIGITE I PARA CONFIGURAR IMOVEL");
            printf("\nDIGITE S PARA SAIR");
            printf("\n");
            printf("\nCONFIGURAR CORRETOR:");
            printf("\nDIGITE C PARA CADASTRAR CORRETOR");
            printf("\nDIGITE R PARA REMOVER CORRETOR");
            printf("\nDIGITE M PARA MOSTRAR CORRETORES");
            printf("\nDIGITE V PARA VOLTAR");
            printf("\nDIGITE S PARA SAIR");
            printf("\n");
            printf("\nCADASTRAR CORRETOR:");
            printf("\nDIGITE O NOME COMPLETO DO CORRETOR - ENTER ");
            printf("\nDIGITE O CRECI DO CORRETOR - ENTER");
            printf("\nDIGITE O LOGIN DO CORRETOR - ENTER");
            printf("\nDIGITE A SENHA DO CORRETOR - ENTER");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU");
            printf("\n");
            printf("\REMOVER CORRETOR:");
            printf("\nDIGITE O CODIGO DO CORRETOR - ENTER");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU");
            printf("\n");
            printf("\MOSTRAR CORRETORES:");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU");
            printf("\n");
            printf("\nCADASTRAR IMOVEL:");
            printf("\nDIGITE O NOME DO PROPRIETARIO - ENTER ");
            printf("\nDIGITE O TELEFONE DO PROPRIETARIO - ENTER");
            printf("\nDIGITE O TIPO DE IMOVEL - VENDA/LOCACAO - ENTER");
            printf("\nDIGITE O VALOR DO IMOVEL - ENTER");
            printf("\nDIGITE A DESCRICAO DO IMOVEL - ENTER");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU");
            printf("\n");
            printf("\REMOVER IMOVEL:");
            printf("\nDIGITE O CODIGO DO IMOVEL - ENTER");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU");
            printf("\n");
            printf("\MOSTRAR IMOVEIS:");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU");
            printf("\n");
            menuPrincipal();
            break;
        case 'C':
        case 'c':
            //INSTRUÇÕES PARA O CORRETOR
            printf("\nLOGIN CORRETOR: ");
            printf("\nDIGITE O LOGIN E SENHA COM ENTER");
            printf("\nDIGITE V PARA VOLTAR, C PARA CONTINUAR OU S PARA SAIR");
            printf("\n");
            printf("\nMENU CORRETOR:");
            printf("\nDIGITE I PARA CONFIGURAR IMOVEL");
            printf("\nDIGITE S PARA SAIR");
            printf("\n");
            printf("\nCADASTRAR IMOVEL:");
            printf("\nDIGITE O NOME DO PROPRIETARIO - ENTER ");
            printf("\nDIGITE O TELEFONE DO PROPRIETARIO - ENTER");
            printf("\nDIGITE O TIPO DE IMOVEL - VENDA/LOCACAO - ENTER");
            printf("\nDIGITE O VALOR DO IMOVEL - ENTER");
            printf("\nDIGITE A DESCRICAO DO IMOVEL - ENTER");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU");
            printf("\n");
            printf("\REMOVER IMOVEL:");
            printf("\nDIGITE O CODIGO DO IMOVEL - ENTER");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU");
            printf("\n");
            printf("\MOSTRAR IMOVEIS:");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU");
            printf("\n");
            getch();
            menuPrincipal();
            break;
        case 'V':
        case 'v':
            limpar();
            menuPrincipal();
            break;
        default:
            printf("OPCAO INVALIDA. TENTE NOVAMENTE. ");
            limpar();
            manualUsuario();
            break;
    }
}

//FUNCAO MASCARAR SENHAS
void campoSenha(char senha[30])
{
    char c; //DECLARAÇÃO DE VARIÁVEIS - O CAMPO SENHA VAI RECEBER O CONTEÚDO
    int a = 0; //VARIÁVEL QUE VAI INDICAR A POSIÇÃO DO VETOR QUE ESTÁ SENDO PREENCHIDA
    do{
      c=getch();
      if(isprint(c)){       //ANALISA SE O CARACTER DIGITADO É IMPRIMÍVEL
        senha[a]=c;         //ARMAZENA O CARACTER NO VETOR
        a++;                //INCREMENTA A POSIÇÃO DO VETOR
        printf("*");        //IMPRIME O *
      }
      else if(c==8&&a){     //8 É O CARACTER ESPAÇO NA TABELA ASCII; VERIFICA SE O CARACTER DIGITADO É ESPAÇO E SE ESTÁ NA PRIMEIRA POSIÇÃO DO VETOR
        senha[a]='\0';
        a--;
        printf("\b \b");       //APAGA O CARACTER DIGITADO
      }
    }while(c!=13);             //13 É O VALOR DE ENTER NA TABELA ASCII

    senha[a]='\0';   //INSERE O /0 NO FINAL DO VETOR

    return senha;
}
