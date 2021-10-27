///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///           Projeto Sistema de Agendamento de Consultas para Pets         ///
///                Developed by  @OliveiraAnna99 - Out, 2021                ///
///                Developed by  @EuViniciuslima - Out, 2021                ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

void login_cadastro(void);
void login(void);
void cadastro(void);
void telaMenu(void);
void telaEquipe(void);
void telaSobre(void);
void telaPet(void);
void telaCad_Pet(void);
void telaConsulta(void);


// Fazer login ou se cadastrar.

int main(void)
{
    int log_cadast;
    login_cadastro();
    printf("Digite a opção: \n1. Login\n2. Cadastrar-se\nEscolha: ");
    scanf("%d", &log_cadast);

    if (log_cadast == 1)
    {
        login();

        return 0;
    }
    if (log_cadast == 2)
    {

        cadastro();

        return 0;
    }

    cadastro();
    telaMenu();
    telaEquipe();
    telaSobre();
}

void login_cadastro(void)
{
    printf("                                                                          - □ x\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///        Projeto Sistema de Agendamento de Consultas para Pets            ///\n");
    printf("///                Developed by  @OliveiraAnna99 - Out, 2021                ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///    = = = = = Sistema de Agendamento de Consultas para Pets = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            1.LOGIN                                                      ///\n");
    printf("///            2.CADASTRE-SE                                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void login(void)
{
    printf("                                                                          - □ x\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///        Projeto Sistema de Agendamento de Consultas para Pets            ///\n");
    printf("///                Developed by  @OliveiraAnna99 - Out, 2021                ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///    = = = = = Sistema de Agendamento de Consultas para Pets = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            Email:                                                       ///\n");
    printf("///            Senha:                                                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    printf("Digite o seu email: ");
    char email_log[60];
    scanf("%s", email_log);

    printf("Digite o sua senha: ");
    char senha_log[60];
    scanf("%s", senha_log);

    telaMenu();

    printf("Escolha: ");
    int escolha;
    scanf("%d", &escolha);

    if (escolha == 1)
    {
        telaPet();
    }

    if (escolha ==2)
    {
        telaConsulta();
    }
}

void cadastro(void)
{
    printf("                                                                          - □ x\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///        Projeto Sistema de Agendamento de Consultas para Pets            ///\n");
    printf("///                Developed by  @OliveiraAnna99 - Out, 2021                ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///    = = = = = Sistema de Agendamento de Consultas para Pets = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            1.Email:                                                     ///\n");
    printf("///            2.Senha:                                                     ///\n");
    printf("///            3.Confirme a senha:                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    FILE *pont_cadUsu;
    pont_cadUsu = fopen("cadastro_usuario.txt", "w");
    char email[60];
    printf("Digite o seu email: ");
    scanf("%s", email);

    char senha[60];
    printf("Digite a sua senha: ");
    scanf("%s", senha);

    fprintf(pont_cadUsu, "%s \n", email);
    fprintf(pont_cadUsu, "%s \n", senha);
    fclose(pont_cadUsu);

    printf("1. Login\n2. Sair\nEscolha:  ");
    int escolha;
    scanf("%d", &escolha);

    if (escolha == 1)
    {
        login();
    }
}

void telaMenu(void)
{
    printf("                                                                          - □ x\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///        Projeto Sistema de Agendamento de Consultas para Pets            ///\n");
    printf("///                Developed by  @OliveiraAnna99 - Out, 2021                ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///    = = = = = Sistema de Agendamento de Consultas para Pets = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Módulo Pet                                                ///\n");
    printf("///            2. Módulo Consulta                                           ///\n");
    printf("///            3. Módulo Usuário                                            ///\n");
    printf("///            4. Módulo Avisos                                             ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}
void telaSobre(void)
{

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///          Projeto Sistema de Agendamento de Consultas para Pets          ///\n");
    printf("///                Developed by  @AnnaOliveira99 - Out, 2021                ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///    = = = = = Sistema de Agendamento de Consultas para Pets = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("///  O Programa SIG-Pet é ums sistema de agendamento de consultas para pets ///\n");
    printf("///  desenvolvido para fins acadêmicos, de modo que o usuário seja capaz de ///\n");
    printf("///  agendar uma consulta para seu animal de estimação do conforto da sua   ///\n");
    printf("///  casa, além de acompanhar por meio do quadro de avisos, a data de vaci- ///\n");
    printf("///  nação do seu bichinho, bem como as pendências do animal                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}
void telaEquipe(void)
{

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///          Projeto Sistema de Agendamento de Consultas para Pets          ///\n");
    printf("///                Developed by  @AnnaOliveira99 - Out, 2021                ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///    = = = = = Sistema de Agendamento de Consultas para Pets = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("///    Esse projeto está sendo desenvolvido por:                            ///\n");
    printf("///                                                                         ///\n");
    printf("///    Developed by  @OliveiraAnna99 - Out, 2021                            ///\n");
    printf("///    Developed by  @EuViniciuslima - Out, 2021                            ///\n");
    printf("///    Email: anna.oliveira.700@ufrn.edu.br                                 ///\n");
    printf("///    Email: vinicius.lima.114@ufrn.edu.br                                 ///\n");
    printf("///    GitHub repositorio: https://github.com/EuViniciuslima/sigpet.git     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
}

// Tela de "cadastrar pet" está pronta. (disponível para alterações no código "linha 301")
void telaPet(void)
{
    printf("                                                                          - □ x\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///        Projeto Sistema de Agendamento de Consultas para Pets            ///\n");
    printf("///                Developed by  @OliveiraAnna99 - Out, 2021                ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///    = = = = = Sistema de Agendamento de Consultas para Pets = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar Pet                                             ///\n");
    printf("///            2. Pesquisar Pet                                             ///\n");
    printf("///            3. Editar Pet                                                ///\n");
    printf("///            4. Apagar Pet                                                ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    int Escolha_Pet;
    printf("Escolha: ");
    scanf("%d", &Escolha_Pet);

    if (Escolha_Pet == 1)
    {
        telaCad_Pet();
    }
}

// telaCad_Pet sendo elaborada, mas até o momnento funcionando. Após o cadastro do animal ele irá voltar pra telaPet.

void telaCad_Pet(void)
{

    printf("                                                                          - □ x\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///      Nome:                                                              ///\n");
    printf("///      Idade:                                                             ///\n");
    printf("///      Especie:                                                           ///\n");
    printf("///      Sexo:                                                              ///\n");
    printf("///      Dono:                                                              ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    FILE *cad_pet;

    cad_pet = fopen("cadastro_pet.txt", "w");
    char nome_pet[60];
    printf("Digite o nome do animal:\t");
    scanf("%s", nome_pet);

    int idade_pet;
    printf("Digite a idade do animal:\t");
    scanf("%d", &idade_pet);

    char sexo_pet[60];
    printf("Digite o sexo do animal:\t");
    scanf("%s", sexo_pet);

    char especie_pet[60];
    printf("Digite a especie do animal:\t");
    scanf("%s", especie_pet);

    char dono_pet[60];
    printf("Digite o nome do dono do animal:\t");
    scanf("%s", dono_pet);

    fprintf(cad_pet, " %s\n", nome_pet);
    fprintf(cad_pet, "%d\n", idade_pet);
    fprintf(cad_pet, "%s\n", sexo_pet);
    fprintf(cad_pet, "%s\n", especie_pet);
    fprintf(cad_pet, "%s\n", dono_pet);
    fclose(cad_pet);

    int cad_perg;
    printf("Deseja fazer um novo cadastro?\n1. Novo Cadastro\n2. Concluir Cadastro\nSua Escolha: ");
    scanf("%d", &cad_perg);

    if (cad_perg == 1)
    {
        telaCad_Pet();
    }
    if (cad_perg == 2)
    {
        telaPet();
    }
}

void telaConsulta(void)
{
    printf("                                                                          - □ x\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///        Projeto Sistema de Agendamento de Consultas para Pets            ///\n");
    printf("///                Developed by  @OliveiraAnna99 - Out, 2021                ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///    = = = = = Sistema de Agendamento de Consultas para Pets = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar Consulta                                        ///\n");
    printf("///            2. Pesquisar Consulta                                        ///\n");
    printf("///            3. Editar Consulta                                           ///\n");
    printf("///            4. Apagar Consulta                                           ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}