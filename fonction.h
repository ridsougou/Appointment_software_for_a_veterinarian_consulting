#ifndef FOCTION_H_INCLUDED
#define FOCTION_H_INCLUDED
#define MAX 10











typedef struct Srendez_vous
{
    int id_rdv;
   // char nom_patient[MAX];
    /*char semaines[5][5];
    char jours [7][9];
    char heuresHoraire[17][12];
    char mois[7][10];*/
//    struct DATE d_rdv;
} Srendez_vous;





typedef struct Sanimal
{
    int id_ani;
    char type[MAX];
    char pseudo[MAX];
} Sanimal;



typedef struct Sassistant
{
    int id_assi;
    char nom_assi[MAX];
    char prenom_assi[MAX];
     char specialite[MAX];
} Sassistant;


typedef struct Sdocteur Sdocteur;
 struct Sdocteur
{
    int id_doc;
    char nom_doc[MAX];
    char prenom_doc[MAX];
    char specialite[MAX];
   // Srendez_vous rdv[7][17];
  //  Sdocteur *next;
};

/*typedef struct SEMAINE
//configurer les heurs
{

    char lundi;
    char mardi;
    char mercredi;
    char jeudi;
    char vendredi;
    char samedi;



} SEMAINE;*/


typedef struct Scause
{
    char soin_consultation[20];
    char toilletage[20];
    char operation[20];
//    struct DATE d_cause;
} Scause ;



typedef struct Sclient Sclient;
struct Sclient
{
   int id_cli;
   char id_test[MAX];
    char nom_cli[MAX];
    char prenom_cli[MAX];
    int jour,mois,an;
    char causes[MAX];
    char rapports[MAX];
    struct Sanimal animal;
    struct Sassistant ass;
    Sclient *next;
};

/*Sclient clients[20];
Sanimal animals[20];
Sassistant assistants[20];
Sdocteur docteurs[20];
Srendez_vous rdvs[20];*/



void MENU_PRINCIPAL();
void client_config(int);
void patient_config(int );
void afficherListeCli();
void ajouterCli();

void personel_config();
void docteur_config();
void assistant_config();
void ajouter_docteur();
void ajouter_assistant();
void docteursList();
void assistantList();
void supprimer_docteur();
void supprimer_assistant();


void ajouter_rdv();
void list_rdv();
void cause_config (int );





void majuscule(char *);
void clearBuffer();
int lire(char *, int);
void lireChar(char*);
int lireInt(char *, int);
#endif // FOCTION_H_INCLUDED
