#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>

void tela_funcionalidade()
{
    char resultado[250];
    char conta[250];
    char agencia[250];
    int acao;
    float saldoTotal = 0;
    float soma = 0;
    float subtracao = 0;
    float saldo = 0;
    float deposito = 0;
    float transferencia = 0;
    float saque = 0;
    float saldototalNovo = 0;

    printf("\t1|\tSaldo\t        |\n");
    printf("\t2|\tSaque\t        |\n");
    printf("\t3|\tTransferência\t|\n");
    printf("\t4|\tDepósito\t|\n");
    printf("\t5|\tSair\t        |\n");
    printf("\tInforme a ação desejada: ");
    scanf("%d", &acao);

    do
    {
        saldoTotal = (saldo + deposito);
        switch (acao)
        {
        case 1:
            saldoTotal = saldototalNovo;
            system("cls || clear");
            printf("Saldo da conta: %.2f", saldoTotal);

            printf("\n\t1|\tSaldo\t        |\n");
            printf("\t2|\tSaque\t        |\n");
            printf("\t3|\tTransferência\t|\n");
            printf("\t4|\tDepósito\t|\n");
            printf("\t5|\tSair\t        |\n");
            printf("\tInforme a ação desejada: ");
            scanf("%d", &acao);
            break;

        case 2:
            saldoTotal = saldototalNovo;
            system("cls || clear");
            printf("Qual o valor deseja sacar? ");
            scanf("%f", &saque);

            if (saldoTotal < saque)
            {
                saque = 0;
                strcpy(resultado, "Não foi possivel realizar o saque\nVerifique seu saldo e tente novamente ");
                printf("%s\n", resultado);
            }

            printf("\n\t1|\tSaldo\t        |\n");
            printf("\t2|\tSaque\t        |\n");
            printf("\t3|\tTransferência\t|\n");
            printf("\t4|\tDepósito\t|\n");
            printf("\t5|\tSair\t        |\n");
            printf("\tInforme a ação desejada: ");
            scanf("%d", &acao);
            saldototalNovo = saldoTotal - saque;
            break;
        case 3:
            saldoTotal = saldototalNovo;
            system("cls || clear");

            printf("Informe a conta que deseja transferir o dinheiro: ");
            scanf("%s", &conta);
            printf("Informe a agência que deseja transferir o dinheiro: ");
            scanf("%s", &agencia);
            printf("Informe o valor que deseja transferir: ");
            scanf("%f", &transferencia);

            if (saldoTotal < transferencia)
            {
                transferencia = 0;
                strcpy(resultado, "Não foi possivel realizar o saque\nVerifique seu saldo e tente novamente ");
                printf("%s\n", resultado);
            }

            printf("\n\t1|\tSaldo\t        |\n");
            printf("\t2|\tSaque\t        |\n");
            printf("\t3|\tTransferência\t|\n");
            printf("\t4|\tDepósito\t|\n");
            printf("\t5|\tSair\t        |\n");
            printf("\tInforme a ação desejada: ");
            scanf("%d", &acao);
            saldototalNovo = saldoTotal - transferencia;

            break;
        case 4:
            system("cls || clear");

            printf("Qual o valor que deseja depositar? ");
            scanf("%f", &deposito);

            printf("\n\t1|\tSaldo\t        |\n");
            printf("\t2|\tSaque\t        |\n");
            printf("\t3|\tTransferência\t|\n");
            printf("\t4|\tDepósito\t|\n");
            printf("\t5|\tSair\t        |\n");
            printf("\tInforme a ação desejada: ");
            scanf("%d", &acao);
            saldototalNovo = saldototalNovo + deposito;
            break;
        case 5:
            system("cls || clear");

            printf("Muito obrigado pela preferência!");

            sleep(5);
            system("cls || clear");
            break;
        default:
            printf("Código incorreto...");
            printf("Tente novamente");

            system("cls || clear");
            sleep(1500);

            printf("\n\t1|\tSaldo\t        |\n");
            printf("\t2|\tSaque\t        |\n");
            printf("\t3|\tTransferência\t|\n");
            printf("\t4|\tDepósito\t|\n");
            printf("\t5|\tSair\t        |\n");
            printf("\tInforme a ação desejada: ");
            scanf("%d", &acao);
            saldoTotal = saldo + deposito - transferencia - saque;
        }
    } while (acao != 0);
}

int main()
{

    setlocale(LC_ALL, "portuguese");

    int codigo;
    char cpf[250];
    char cpfSalvo[250];
    char senha[250];
    char senhaSalva[250];
    int resultadoCPF;
    int resultadoSenha;

    printf("Seja Bem-Vindo!\n");
    printf("1- Criar cadastro\n");
    printf("2- Login\n");
    printf("Informe o código desejado: ");
    scanf("%d", &codigo);

    if (codigo == 2)
    {
        fflush(stdin);

        printf("Digite o seu cpf: ");
        gets(cpf);
        printf("Digite a sua senha: ");
        gets(senha);

        system("cls || clear");
        printf("Informações corretas...\nSeja Bem-vindo!\n");
        Sleep(1500);
        system("cls || clear");

        tela_funcionalidade();
    }
    else
    {
        // cadastro
        fflush(stdin);

        printf("Informe o seu CPF para realizar o cadastro: ");
        gets(cpfSalvo);
        printf("Digite a senha desejada: ");
        gets(senhaSalva);

        system("cls || clear");

        printf("Login e senha cadastrados com sucesso!");
        Sleep(1500);

        system("cls || clear");

        do
        {
            fflush(stdin);

            printf("Digite o seu cpf: ");
            gets(cpf);
            printf("Digite a sua senha: ");
            gets(senha);

            system("cls || clear");

            resultadoCPF = strcmp(cpf, cpfSalvo);
            resultadoSenha = strcmp(senha, senhaSalva);

            if (resultadoCPF == 0 && resultadoSenha == 0)
            {
                printf("Informações corretas...\nSeja Bem-vindo!\n");
                sleep(3);
                system("cls || clear");

                tela_funcionalidade();
            }
            else if (cpfSalvo != 0 || senhaSalva != 0)
            {
                printf("Login ou senha incorreto\n Tente novamente...\n");
                Sleep(1500);
                system("cls || clear");
            }

        } while (resultadoCPF != 0 || resultadoSenha != 0);
    }

    return 0;
}
