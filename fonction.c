#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "fonction.h"
#define MAX 10




Sclient *firstC, *currentC, *nextC, *lastC, *interC;
Sdocteur *firstD, *currentD, *nextD, *lastD, *interD;



int choix,x;
int a;

Sclient clients[20];
Sanimal animals[20];
Sassistant assistants[20];
Sdocteur docteurs[20];
Srendez_vous rdvs[20];



void MENU_PRINCIPAL()
{
    printf("****************************************************************\n");
    printf("\t ______________________________________________");
    printf("\n\t|                                              |");
    printf("\n\t|                MENU PRINCIPAL                |");
    printf("\n\t|______________________________________________|\n");
    printf("\n****************************************************************\n");
    printf("\t\t1- Je suis un client.\n");
    printf("\t\t2- Je suis un personel.\n");

    //printf("choisir le MENU : ");
    scanf("%d", &choix);
    while(true)

        client_config(choix);

}


void client_config(int a)
{
    if(a == 1)
    {
        system("cls");
        printf("\n\t __________________________________________");
        printf("\n\t|                                          |");
        printf("\n\t|            Je suis un client.            |");
        printf("\n\t|__________________________________________|\n\n");
        printf("1-Afficher liste client.\n");
        printf("2-Ajouter un client.\n");
        printf("3-Prise de rendez-vous.\n");
        printf("4-Annuler un rendez-vous\n");
        printf("5-Rapport\n");
        printf("6-Retourner au MENU PRINCIPAL :\n");
        printf("choisir le menu : ");
        scanf("%d", &a);
        system("cls");
        patient_config(a);

    }
    else if(a==2)
    {
        system("cls");
        printf("1-Docteur\n");
        printf("2-Assistant\n");
        printf("3-Affichage de l'archive\n");
        printf("4-liste rendez vous\n");
        printf("5-retouner au MENU PRINCIPAL\n ");
        printf("choisir le menu : ");
        scanf("%d", &a);
        personel_config(a);
        system("cls");

    }
}


void patient_config(int a)
{
    int b;
    if (a==1)
    {

        afficherListeCli();
        system("pause");
        system("cls");



    }
    else if (a ==2)
    {


        ajouterCli();
        system("pause");
        system("cls");

    }
    else if (a ==3)
    {

        ajouter_rdv();
        system("pause");
        system("cls");
    }

    else if( a==4)
    {
        //annuler_rdv();
    }
    else if(a==5)
    {
        // rapport();

    }
    else if (a==6)
    {
        system("cls");
        MENU_PRINCIPAL();
    }
    else
    {
        printf("mauvais choix");
        return 0;
    }

}
void ajouterCli()
{
    struct Sclient client;
    //int n = 0;

    FILE * file;

    printf("Veuiller introduire vos informations:");

    printf("\nNom : ");
    scanf("%s",&client.nom_cli);


    printf("\nPrenom : ");
    scanf("%s",&client.prenom_cli);


    printf("\nVeuiller introduire un ID  : ");
    scanf("%d",&client.id_cli);

    printf("\nDonner un ID a votre animal : ");
    scanf("%d",&client.animal.id_ani);

    printf("Type de votre animal : ");
    scanf("%s",&client.animal.type);

    printf("\nPseudo de votre animal : ");
    scanf("%s",&client.animal.pseudo);

    printf("\n");


    file = fopen("client.txt", "a");
    fwrite(&client, sizeof(client), 1, file);

    if(fwrite != 0)
        printf("client ajoute avec succes. \n");
    else
        printf("erreur!!");
    fclose(file);
}
void afficherListeCli()
{
    struct Sclient client;

    FILE *file;

    file = fopen("client.txt", "r");
    int nbClients = 0;
    while(fread(&client, sizeof(struct Sclient), 1, file))
    {
        clients[nbClients] = client;
        nbClients++;
    }
    fclose(file);

    system("cls");
    printf("Nombre de patients : %2d\n",nbClients);
    printf("************************\n");
    printf("\nNom  \t\tPrenom     \t\tId_client     \t\t Animal.pseudo   \t Type   \tId_animal ");
    printf("\n----------------------------------------------------------------------------------------------------------------\n");
    for (int n=0 ; n<nbClients ; n++)
    {
        printf("%-9s  \t%-9s  \t\t%d     \t\t%-9s   \t\t%-9s   \t%d\n",clients[n].nom_cli,clients[n].prenom_cli,clients[n].id_cli,clients[n].animal.pseudo,clients[n].animal.type,clients[n].animal.id_ani);

    }

    printf("\n----------------------------------------------------------------------------------------------------------------\n");
}


// Tableau pour stocker les disponibilités de chaque jour
    bool disponibilites[6]= {true, true, true, true, true, true};

     int i, j, choix,choixJour,choixSemain,choixMois,choixPersonnel,choixClient,choixDispo,choixAnimal,choixnomvet;
     char choixpseudo,choixnomcli,choixpseudo,chaoixnomass;
    char semaines[5][5] = {"Sem1","Sem2","Sem3","Sem4"};
    char jours[7][9] = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"};
    char mois[7][10]= {"Mois1","Mois2","Mois3","Mois4","Mois5","Mois6"};
    char heuresHoraire[17][12] =
    {
        "08H00-08H30",
        "08H30-09H00",
        "09H00-09H30",
        "09H30-10H00",
        "10H00-10H30",
        "10H30-11H00",
        "11H00-11H30",
        "11H30-12H00",
        "13H00-13H30",
        "13H30-14H00",
        "14H00-14H30",
        "14H30-15H00",
        "15H00-15H30",
        "15H30-16H00",
        "16H00-16H30",
        "16H30-17H00"
    };



void ajouter_rdv()
{
    struct Sdocteur docteur;
    struct Srendez_vous rdv;
    // Sdocteur *currentD;
    bool flag = false;



    // ajouterCli();
    //cause

    printf("Veuiller choisir un ID pour votre rendez-vous : ");
    scanf("%d",&rdv.id_rdv);
      afficherListeCli();
      fflush(stdin);
    printf("veuiller choisir l'id du client:\n");
    scanf("%d",&choixClient);
  //  fflush(stdin);
    printf("veuiller choisir le nom du client:\n");
    scanf("%s",&choixnomcli);
   // gets(choixnomcli);
   //  fflush(stdin);

    printf("veuiller choisir l'id du l'animal:\n");
    scanf("%d",&choixAnimal);
    printf("veuiller choisir pseudo du l'animal:\n");
    gets(choixpseudo);

    printf("1-soin et consultation : \n");/*lundi jusqu samedi doc*/
    printf("2-toilettage : \n");//merceredi assis
    printf("3-operation : \n");//mardi & jeudi doc
    scanf("%d", &a);
    if(a==1)
    {
        docteursList();
        printf("veuiller choisir l'id du vett:\n");
        scanf("%d",&choixPersonnel);
        //choix de la date
        // Affichage du lundi au samedi

        for ( i = 1; i <= 6; i++)
            printf("%2d - %s\n", i, jours[i - 1]);
        printf(" 0 - Annuler\n  ");
        printf("Choisissez un jour (1 = lundi, 2 = mardi, ..., 6 = samedi) : ");
        scanf("%d",&choixJour);



    }
    else if (a==2)
    {
        assistantList();
        printf("veuiller choisir l'id du l'assistant:\n");
        scanf("%d",&choixPersonnel);
        printf("veuiller choisir le nom du l'assistant:\n");
        gets(chaoixnomass);


        //Affichage du mercredi
        printf("3 - %8s\n",jours[2]);
        printf("Le toilettage est reserve juste pour Mercredi!!\n");
        printf("Choisissez Mercredi (3 = mercredi) : ");
        scanf("%d",&choixJour);



    }
    else if (a==3)
    {


        docteursList();
        printf("veuiller choisir l'id du vett:\n");
        scanf("%d",&choixPersonnel);
        printf("veuiller choisir le nom du vett:\n");
        gets(choixnomvet);
        //Affichage de mardi et jeudi
        printf("2 - %8s\n",jours[1]);
        printf("4 - %8s\n",jours[3]);
        printf("Les operations sont reserves juste pour Mardi et Jeudi!! \n");
        printf("Choisissez Mardi et Jeudi (2 = mardi, 3 = jeudi) : ");
        scanf("%d",&choixJour);

    }
    //fichier pour enregistrer les rendez-vous
FILE * frdv;
 //Affichage des semaines
        for(i = 1; i<= 4;i++)
        printf("%2d - %-8s\n",i,semaines[i -1]);
        printf(" 0 - Annuler\n  ");
        printf("Choisissez une semaine (1 = sem1, 2 = sem2, ..., 4 = sem4) : ");
        scanf("%d",&choixSemain);
        //Affichage des mois
        for(i = 1; i<= 6;i++)
        printf("%2d - %-8s\n",i,mois[i -1]);
        printf(" 0 - Annuler\n  ");
        printf("Choisissez un mois (1 = mois1, 2 = mois2, ..., 6 = mois6) : ");
        scanf("%d",&choixMois);
    if (choixJour !=0)
    {
        while (!flag)
        {

            system("cls");
            printf("\n%s\n********\n", jours[choixJour - 1]);
            printf("\n      Heure         Patient\n\n");
            for (j = 1; j <= 16; j++)
            {
                printf(" %2d - %-11s   \n", j, heuresHoraire[j - 1]);
                //  printf("%-20d  ",disponibilites[j - 1] /*currentD->rdv[choix][j].nom_patient*/);
                //   printf("%-20s  %c\n", rdv[choix][j].id_client);
            }
            printf(" 0 - Annuler\n");
            printf("\n: ");
            scanf("%d",&choixDispo);



            // scanf("%d", &jour);

            // Vérifier si le jour est disponible
            if (disponibilites[choixDispo - 1] || disponibilites[choixJour - 1] || disponibilites[choixMois - 1] || disponibilites[choixSemain - 1])
            {
                printf("Rendez-vous confirme pour la %deme heure de la %deme journee de la %deme semaine du %deme mois.\n", choixDispo,choixJour,choixSemain,choixMois);
                // Marquer le jour comme indisponible
                disponibilites[choixDispo - 1] = false;
                 disponibilites[choixJour - 1] = false;
                  disponibilites[choixMois - 1]= false;
                   disponibilites[choixSemain - 1] = false;
                flag=true;
            }
            else
            {

                printf("Désolé, cette heure est déjà réservée. Veuillez choisir une autre heure :\n");
                system("pause");
                system("cls");
                printf("\n%s\n********\n", jours[choix - 1]);
                printf("\n      Heure         Patient\n\n");
                for (j = 1; j <= 16; j++)
                {
                    printf(" %2d - %-11s   \n", j, heuresHoraire[j - 1]);
                }
                printf(" 0 - Annuler\n");
                printf("\n: ");
                scanf("%d", &choixDispo);
            }

        }

        /* printf(" 0 - Annuler\n");
         printf("\n: ");
         scanf("%d",&choix);
         printf("vous avez choisi %d : %-11s ",choix,heuresHoraire[choix - 1]);*/
    }
    frdv = fopen("rendez-vous.txt", "a");
    fwrite(&choixJour, sizeof(choixJour), 1, frdv);
    fwrite(&choixSemain, sizeof(choixSemain), 1, frdv);
    fwrite(&choixMois, sizeof(choixMois), 1, frdv);
    fwrite(&choixDispo, sizeof(choixDispo), 1, frdv);
    fwrite(&rdv.id_rdv, sizeof(rdv.id_rdv),1, frdv);
   // fwrite(&jours, sizeof(jours), 1, frdv);

    if(fwrite != 0)
        printf("rendez-vous ajoute avec succes. \n");
    else
        printf("erreur!!");
    fclose(frdv);

}
void list_rapport()
{

    system("cls");
    FILE * fp;
    struct Sclient client;
    struct Sanimal animal;
    struct Sassistant ass;
    printf("<== rapport List ==>\n\n");


    printf("%-7s| %-7s| %-7s |%-7s |%-7s|%-7s |%-7s |%-7s |%-7s |%-7s| %-7s \n", "idclient", "Nomclient",  "prenom","idanimal","pseudo","type","idassi","nomassi","date","cause","rapport");
    printf("-------------------------------------------------------------------------------------------------------------------\n");

    fp = fopen("rapport.txt", "rb");
    while(fread(&client, sizeof(client), 1, fp) == 1)

    {
        fflush(stdin);
        printf("%-7d |%-7s |%-7s |%-7d |%-7s|%-7s |%-7d |%-7s |%d/%d/%d |%-7s |%-7s\n", client.id_cli,client.nom_cli, client.prenom_cli,client.animal.id_ani,client.animal.pseudo,client.animal.type,client.ass.id_assi,client.ass.nom_assi,client.jour,client.mois,client.an,client.causes,client.rapports);
        printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    fclose(fp);



}

void list_rdv()
{
    struct Srendez_vous rdv;
    FILE * frdv;
    printf("<== liste rendez-vous ==>\n\n");
      printf("%-7s| %-7s| %-7s |%-7s |%-7s|%-7s |%-7s |%-7s |%-7s |%-7s| %-7s \n", "id_rdv","id_client","idanimal","pseudo","type","idassi","nomassi","date","cause","rapport");
    printf("-------------------------------------------------------------------------------------------------------------------\n");


    for ( i = 1; i <= 6; i++)
    {
        printf("%2d - %s %-7d \n", i, jours[i - 1],choixDispo,rdv.id_rdv);
    }




    frdv = fopen("rendez-vous.txt", "r");
    int nbRendez_vous = 0;
    while(fread(&choixJour, sizeof(choixJour), 1, frdv))
    {
        disponibilites[nbRendez_vous] = choixJour;
        nbRendez_vous++;
    }
    fclose(frdv);



}

void personel_config(int a)
{
    if (a==1)
    {
        system("cls");
        printf("1-Ajouter un docteur\n");
        printf("2-afficher la liste des docteurs\n");
        printf("3-Supprimer un docteur\n");
        printf("4-retourner au menu precedant\n");
        printf("choisir : ");

        scanf("%d", &a);
        docteur_config(a);

    }
   else if(a ==2)
    {
        system("cls");
        printf("1-Ajouter un assistant\n");
        printf("2-afficher la liste des assistants\n");
        printf("3-supprimer un assistant\n");
        printf("4-retourner au menu precedant\n");
        printf("choisir : ");
        scanf("%d", &a);
        assistant_config(a);
    }else if(a==3){
    //archive


    }else if(a==4){
        system("cls");

    list_rdv();
    system("pause");

    }
    else if (a==5){
    MENU_PRINCIPAL();

    }

}
void docteur_config (int a)
{
    if (a==1)
    {
        ajouter_docteur();
        system("pause");
        system("cls");
    }
    else if (a==2)
    {
        docteursList();
        system("pause");
        system("cls");
    }
    else if (a == 3)
    {
        supprimer_docteur();
        system("pause");
        system("cls");
    }

}
void ajouter_docteur()
{

    struct Sdocteur docteur;
    int n = 0;

    FILE * fp;
    system("cls");
    printf("<== Add Doctor ==>\n\n");
    printf("Veuiller introduire vos informations: \n");

    printf("Enter Doctor id: ");
    scanf("%d", &docteur.id_doc);

    printf("Enter Doctor Name: ");
    scanf("%s",&docteur.nom_doc);

    printf("Doctor Specialize in: ");
    scanf("%s",&docteur.specialite);


    fp = fopen("docteur.txt", "a");
    fwrite(&docteur, sizeof(docteur), 1, fp);

    if(fwrite != 0)
        printf("Doctor Added Successfully\n\n");
    else
        printf("erreur!!");

    fclose(fp);

    printf("\n");

}
void docteursList()
{

    FILE * fp;
    struct Sdocteur docteur;
    printf("<== Doctor List ==>\n\n");


    fp = fopen("docteur.txt", "r");
    int nbDocteurs = 0;
    while(fread(&docteur, sizeof(struct Sdocteur), 1, fp))
    {
        docteurs[nbDocteurs] = docteur;
        nbDocteurs++;

    }

    fclose(fp);
    system("cls");
    printf("Nombre de docteurs : %2d\n",nbDocteurs);
    printf("************************\n");
    printf("id \t\tName   \t\t\t\t\t\t\tSpecialize\n");
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    for (int n=0 ; n<nbDocteurs ; n++)
    {
        printf("%-10d \t%-30s   \t\t%s\n", docteurs[n].id_doc,docteurs[n].nom_doc,docteurs[n].specialite);

    }

    printf("\n----------------------------------------------------------------------------------------------------------------\n");

}
void ajouter_assistant()
{
    FILE*fp;

    struct Sassistant assistant;

    system("cls");
    printf("<== Add assistant ==>\n\n");
    fp = fopen("assistant.txt", "a");

    printf("Enter assistant id: ");
    scanf("%d", &assistant.id_assi);

    printf("Enter assistant full Name: ");
    fflush(stdin);
    gets(assistant.nom_assi);


    printf("Doctor Specialize in: ");
    fflush(stdin);
    gets(assistant.specialite);

    printf("assistant Added Successfully\n\n");

    fwrite(&assistant, sizeof(assistant), 1, fp);
    fclose(fp);


}
void supprimer_docteur()
{
    struct Sdocteur docteur;
    int id,f=0;
    system("cls");
    printf("<== supprimer un docteur ==>\n\n");
    printf("Entrer id du docteur a supprimer: ");
    scanf("%d", &id);

    FILE *ft;
    FILE *fp;
    fp = fopen("docteur.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&docteur, sizeof(docteur), 1, fp) == 1)
    {

        if(id == docteur.id_doc)
        {
            f=1;
        }
        else
        {
            fwrite(&docteur, sizeof(docteur), 1, ft);
        }
    }

    if(f==1)
    {
        printf("\n\ndocteur supprimer Successfully.");
    }
    else
    {
        printf("\n\nRecord Not Found !");
    }

    fclose(fp);
    fclose(ft);

    remove("docteur.txt");
    rename("temp.txt", "docteur.txt");

}
void assistantList()
{
    struct Sassistant assistant;
    system("cls");
    FILE * fp;
    struct Sclient client;
    printf("<== assistant List ==>\n\n");

    printf("id Name  Specialize\n");
    printf("-------------------------------------------------------------------------------------------------------------------\n");

    fp = fopen("assistant.txt", "r");
    while(fread(&assistant, sizeof(assistant), 1, fp) == 1)
    {
        printf("%-10d %-30s %s \n", assistant.id_assi,assistant.nom_assi, assistant.specialite);
    }

    fclose(fp);
}
void supprimer_assistant()
{

    struct Sassistant assistant;
    int id,f=0;
    system("cls");
    printf("<== supprimer un assistant ==>\n\n");
    printf("Entrer id de l'assistant a supprimer: ");
    scanf("%d", &id);

    FILE *ft;
    FILE *fp;
    fp = fopen("assistant.txt", "r");
    ft = fopen("temp.txt", "w");

    while(fread(&assistant, sizeof(assistant), 1, fp) == 1)
    {

        if(id == assistant.id_assi)
        {
            f=1;
        }
        else
        {
            fwrite(&assistant, sizeof(assistant), 1, ft);
        }
    }

    if(f==1)
    {
        printf("\n\n assistant supprime Successfully.");
    }
    else
    {
        printf("\n\nRecord Not Found !");
    }

    fclose(fp);
    fclose(ft);

    remove("assistant.txt");
    rename("temp.txt", "assistant.txt");

}
void assistant_config(int a)
{
    if(a==1)
    {
        ajouter_assistant();
        system("pause");
        system("cls");
    }
    else if (a == 2)
    {
        assistantList();
        system("pause");
        system("cls");
    }
    else if (a==3)
    {
        supprimer_assistant();
        system("pause");
        system("cls");
    }
}


/*void sous_menu(int a)
{
    if(a==1)
    {
        printf("1- ajouter\n");
        printf("2- modifier\n");
        printf("3- supprimer\n");
        printf("4- afficher\n");
        printf("5- retour\n");
        printf("choisir le sous-menu :");
        scanf("%d",&x);
        gere_client(x);

    }
    else if (a==2)
    {
         printf("1- ajouter\n");
        printf("2- rechercher\n");
        printf("3- affichier la liste\n");
        printf("4- supprimer\n");
        printf("5- retour\n");
        printf("choisir le sous-menu :");
        scanf("%d",&x);
       // gere_rdv(x);
    }
    else if (a==4)
        return 0;
    else
    {
        printf("movaix choix");
        return 0;
    }

}
void gere_client(int a)
{
    if(a==1)
    {
        struct Sclient client;
        FILE *file;
        printf("id client :");
        scanf("%d",&client.id.id_cli);
        printf("nom :");
        scanf("%s",&client.nom_cli);
        printf("prenom :");
        scanf("%s", &client.prenom_cli);
        file = fopen("client.txt", "a");
        fwrite(&client, sizeof(client), 1, file);

        if (fwrite!=0)
            printf("client ajouter zvec succes");
        else
            printf("erreur");

        fclose(file);
    }
    else if (a==4)
    {
        FILE *file;
        struct Sclient client ;
        file = fopen("client.txt","r");
        int nbClients =0;
        while (fread(&client,sizeof(struct Sclient),1 ,file)){
               clients[nbClients]=client;
               nbClients++;
               }
               fclose(file);
                printf("\n __________________________________________");
                printf("\n|                                          |");
                printf("\n|           TABLEAU DE CLIENTS             |");
                printf("\n|__________________________________________|\n");
               for(int c=0 ; c<nbClients ; c++)
                {
                    printf("\n\tID client : %d",clients[c].id.id_cli);
                    printf("\n\tNOM client : %s",clients[c].nom_cli);
                    printf("\n\tPRENOM client : %s",clients[c].prenom_cli);
                    printf("\n__________________________________________");
                }
    }
}*/
/*void rechercherCli(Sclient *first,Sclient **current)
{
    ID tmpID_cli;
    int n = 0,cp = 0,i;
    //int tmpID_cli;
    printf("Entrez l'ID du client :");
    tmpID_cli.id_cli=lireInt(&tmpID_cli.id_cli, 9);
    printf("\n");
    printf("\nNom                   Prenom                   id_client         animal.pseudo          type        id_animal ");
    printf("\n----------------------------------------------------------------------------------------------------------------\n");

    for (*current = first; *current != NULL; *current = (*current)->next)
    {
        if (n == 0)
            cp++;
        if ((*current)->id.id_cli == tmpID_cli.id_cli )
        {
            n++;
            printf("%-9s      %-9s     %s     %d  %-9s   %-9s   %d",(*current)->nom_cli,(*current)->prenom_cli,(*current)->id.id_cli,(*current)->animal.pseudo,(*current)->animal.type,(*current)->animal.id.id_ani);

        }
    }
    printf("\n----------------------------------------------------------------------------------------------------------------\n");
    if (n != 0)
    {
        *current = first;
        for (i = 1; i < cp; i++)
            *current = (*current)->next;
    }
    else
    {
        printf("Personne non trouvee\n");
        *current == NULL;
    }

}*/
