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

void telaMenuPrincipal(void);
void telaEquipe(void);
void telaSobre(void);

void telaMenuPet(void);
void telaCadastrarPet(void);
void telaPesquisarPet(void);
void telaExcluirPet(void);
void telaEditarPet(void);

void telaMenuConsulta(void);
void telaMenuUsuario(void);
void cadastroNovoUsuario(void);
void editarUsuario(void);
void pesquisarUsuario(void);
void pesq_usuario_exclui(void);
void telaCadastrarConsulta(void);
void telaPesquisarConsulta(void);
void telaExcluirConsulta(void);
void telaEditarConsulta(void);

void func_cad_pet(void);
void func_cad_usu(void);
void func_escolha(void);

int Escolha_Pet;
int Escolha_Consulta;

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

    if (log_cadast != 1 && log_cadast != 2)
    {
        return 1;
    }

    cadastro();
    telaMenuPrincipal();
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

    telaMenuPrincipal();

    printf("Escolha: ");
    int escolha;
    scanf("%d", &escolha);

    if (escolha == 1)
    {
        telaMenuPet();
    }

    if (escolha == 2)
    {
        telaMenuConsulta();
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

    func_cad_usu();
}

void telaMenuPrincipal(void)
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
void telaMenuPet(void)
{
    printf("                                                                          - □ x\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                                                                         ///\n");
    printf("///          ===================================================            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          =  Sistema de Agendamento de Consulta para Pets   =            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          ===================================================            ///\n");
    printf("///                Developed by @OliveiraAnna99 - Out, 2021                 ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///           = = = = = = = = =  Menu Pet   = = = = = = = = =               ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar Pet                                             ///\n");
    printf("///            2. Pesquisar Pet                                             ///\n");
    printf("///            3. Editar Pet                                                ///\n");
    printf("///            4. Apagar Pet                                                ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    printf("Escolha: ");
    scanf("%d", &Escolha_Pet);
    func_escolha();
}

// telaCad_Pet sendo elaborada, mas até o momnento funcionando. Após o cadastro do animal ele irá voltar pra telaPet.

void telaCadastrarPet(void)
{

    printf("                                                                          - □ x\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                                                                         ///\n");
    printf("///          ===================================================            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          =  Sistema de Agendamento de Consulta para Pets   =            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          ===================================================            ///\n");
    printf("///                Developed by @OliveiraAnna99 - Out, 2021                 ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///           = = = = = = = = =  Cadastro Pet = = = = = = = =               ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///            Nome do Pet:                                                 ///\n");
    printf("///            Idade do Pet:                                                ///\n");
    printf("///            Sexo do Pet:                                                 ///\n");
    printf("///            Especie do Pet:                                              ///\n");
    printf("///            Dono:                                                        ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    func_cad_pet();
}

void telaPesquisarPet(void)
{

    printf("                                                                          - □ x\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                                                                         ///\n");
    printf("///          ===================================================            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          =  Sistema de Agendamento de Consulta para Pets   =            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          ===================================================            ///\n");
    printf("///                Developed by @OliveiraAnna99 - Out, 2021                 ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///           = = = = = = = = =  Pesquisar Pet  = = = = = = =               ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Pesquisar por nome:                                       ///\n");
    printf("///            2. Pesquisar por idade:                                      ///\n");
    printf("///            3. Pesquisar por sexo:                                       ///\n");
    printf("///            4. Pesquisar por especie:                                    ///\n");
    printf("///            5. Pesquisar por dono:                                       ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void telaEditarPet(void)
{

    printf("                                                                          - □ x\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                                                                         ///\n");
    printf("///          ===================================================            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          =  Sistema de Agendamento de Consulta para Pets   =            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          ===================================================            ///\n");
    printf("///                Developed by @OliveiraAnna99 - Out, 2021                 ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///           = = = = = = = = =   Editar Pet  = = = = = = = =               ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///            Nome do Pet:                                                 ///\n");
    printf("///            Idade do Pet:                                                ///\n");
    printf("///            Sexo do Pet:                                                 ///\n");
    printf("///            Especie do Pet:                                              ///\n");
    printf("///            Dono:                                                        ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void telaExcluirPet(void)
{

    printf("                                                                          - □ x\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                                                                         ///\n");
    printf("///          ===================================================            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          =  Sistema de Agendamento de Consulta para Pets   =            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          ===================================================            ///\n");
    printf("///                Developed by @OliveiraAnna99 - Out, 2021                 ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///           = = = = = = = = =  Exluir Pet   = = = = = = = =               ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///            Nome do Pet:                                                 ///\n");
    printf("///            Idade do Pet:                                                ///\n");
    printf("///            Sexo do Pet:                                                 ///\n");
    printf("///            Especie do Pet:                                              ///\n");
    printf("///            Dono:                                                        ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    printf("Deseja Excluir este Registro?");
}

void telaMenuConsulta(void)
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

    printf("Escolha: ");
    scanf("%d", &Escolha_Consulta);
    func_escolha();
}

void func_cad_pet(void)
{

    FILE *cad_pet;

    cad_pet = fopen("cadastro_pet.txt", "w");
    char nome_pet[60];
    printf("Digite o nome do animal:\t");
    scanf("%s", nome_pet);
    fprintf(cad_pet, "%s\n", nome_pet);

    int idade_pet;
    printf("Digite a idade do animal:\t");
    scanf("%d", &idade_pet);
    fprintf(cad_pet, "%d\n", idade_pet);

    char sexo_pet[60];
    printf("Digite o sexo do animal:\t");
    scanf("%s", sexo_pet);
    fprintf(cad_pet, "%s\n", sexo_pet);

    char especie_pet[60];
    printf("Digite a especie do animal:\t");
    scanf("%s", especie_pet);
    fprintf(cad_pet, "%s\n", especie_pet);

    char dono_pet;
    printf("Digite o primeiro nome do dono do animal:\t");
    scanf("%s", &dono_pet);
    fprintf(cad_pet, "%s\n", &dono_pet);

    fclose(cad_pet);

    int cad_perg;
    printf("Deseja fazer um novo cadastro?\n1. Novo Cadastro\n2. Concluir Cadastro\nSua Escolha: ");
    scanf("%d", &cad_perg);

    if (cad_perg == 1)
    {
        telaCadastrarPet();
    }
    if (cad_perg == 2)
    {
        telaMenuPet();
    }
}

void func_cad_usu(void)
{
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

void telaMenuUsuario(void) // Atualizando agora no domingo.
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
    printf("///            1. Cadastrar Novo Usuário                                    ///\n");
    printf("///            2. Editar Usuário                                            ///\n");
    printf("///            3. Pequisar Usuário                                          ///\n");
    printf("///            4. Apagar Usuário                                            ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void cadastrarNovoUsuario(void) // Referente a telaMenuUsuario L 553
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
    printf("///            1. Email                                                     ///\n");
    printf("///            2. Senha                                                     ///\n");
    printf("///            3. Confirmação de senha                                      ///\n");
    printf("///            4. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void editarUsuario(void) // Referente a telaMenuUsuario L 553
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
    printf("///            1. Alterar email                                             ///\n");
    printf("///            2. Alterar senha                                             ///\n");
    printf("///            3. Alterar número de telefone                                ///\n");
    printf("///            4. Alterar nome                                              ///\n");
    printf("///            5. Endereço                                                  ///\n");
    printf("///            6. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void pesq_usuario_exclui(void) // Referente a telaMenuUsuario L 553
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
    printf("///        1.Nome  2.Email  3.Telefone  4.Bairro  5.Cidade / Filtrar        ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///        6. Sair                                        7. excluir        ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void telaCadastrarConsulta(void)
{

    printf("                                                                          - □ x\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                                                                         ///\n");
    printf("///          ===================================================            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          =  Sistema de Agendamento de Consulta para Pets   =            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          ===================================================            ///\n");
    printf("///                Developed by @OliveiraAnna99 - Out, 2021                 ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///           = = = = = = = = =  Cadastro Consulta  = = = = =               ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///            Data da Consulta:                                            ///\n");
    printf("///            Nome do Paciente(Pet):                                       ///\n");
    printf("///            Dono/Responsavel:                                            ///\n");
    printf("///            Descricao:                                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void telaPesquisarConsulta(void)
{

    printf("                                                                          - □ x\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                                                                         ///\n");
    printf("///          ===================================================            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          =  Sistema de Agendamento de Consulta para Pets   =            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          ===================================================            ///\n");
    printf("///                Developed by @OliveiraAnna99 - Out, 2021                 ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///           = = = = = = = = =  Pesquisar Consulta  = = = = =              ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Pesquisa por Data da Consulta:                            ///\n");
    printf("///            2. Pesquisa pelo Nome do Paciente(Pet):                      ///\n");
    printf("///            3. Pesquisa pelo Dono/Responsavel:                           ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void telaEditarConsulta(void)
{

    printf("                                                                          - □ x\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                                                                         ///\n");
    printf("///          ===================================================            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          =  Sistema de Agendamento de Consulta para Pets   =            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          ===================================================            ///\n");
    printf("///                Developed by @OliveiraAnna99 - Out, 2021                 ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///           = = = = = = = = =   Editar Consulta   = = = = =               ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///            Data da Consulta:                                            ///\n");
    printf("///            Nome do Paciente(Pet):                                       ///\n");
    printf("///            Dono/Responsavel:                                            ///\n");
    printf("///            Descricao:                                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void telaExcluirConsulta(void)
{

    printf("                                                                          - □ x\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                                                                         ///\n");
    printf("///          ===================================================            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          =  Sistema de Agendamento de Consulta para Pets   =            ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///          ===================================================            ///\n");
    printf("///                Developed by @OliveiraAnna99 - Out, 2021                 ///\n");
    printf("///                Developed by  @EuViniciuslima - Out, 2021                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///           = = = = = = = = =  Excluir Consulta   = = = = =               ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///            Data da Consulta:                                            ///\n");
    printf("///            Nome do Paciente(Pet):                                       ///\n");
    printf("///            Dono/Responsavel:                                            ///\n");
    printf("///            Descricao:                                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void func_escolha(void)
{

    if (Escolha_Pet == 1)
    {
        telaCadastrarPet();
    }

    if (Escolha_Pet == 2)
    {
        telaPesquisarPet();
    }

    if (Escolha_Pet == 3)
    {
        telaEditarPet();
    }

    if (Escolha_Pet == 4)
    {
        telaExcluirPet();
    }

    if (Escolha_Pet == 0)
    {
        telaMenuPrincipal();
    }

    if (Escolha_Pet != 1 && Escolha_Pet != 2 && Escolha_Pet != 3 && Escolha_Pet != 4 && Escolha_Pet != 0)
    {

        printf("Essa ação não é permitida, selecione uma das possiveis ações acima");
    }

    if (Escolha_Consulta == 1)
    {
        telaCadastrarConsulta();
    }
    if (Escolha_Consulta == 2)
    {
        telaPesquisarConsulta();
    }
    if (Escolha_Consulta == 3)
    {
        telaEditarConsulta();
    }
    if (Escolha_Consulta == 4)
    {
        telaExcluirConsulta();
    }

    if (Escolha_Consulta == 0)
    {
        telaMenuPrincipal();
    }

    if (Escolha_Consulta != 1 && Escolha_Consulta != 2 && Escolha_Consulta != 3 && Escolha_Consulta != 4 && Escolha_Consulta != 0)
    {

        printf("Essa ação não é permitida, selecione uma das possiveis ações acima");
    }
}