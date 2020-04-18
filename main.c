#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classe.h"
#define TAILLE_MAX 1000

int main()
{pNoeud l;
 int n,i,compt=0;
 while(n!=0){

        printf("********************************************************************************\n");
        printf("Menu principale:\n\n1.Creer une nouvelle classe.\n2.Classe existante.\n3.Supprimer une classe existante.\n4.Renommer une classe.\n5.Afficher toutes les classes existantes.\n6.Quitter\n--------------------------------------------------\n");
        printf("Veuillez choisir le numero de l'operation:\n");
        while(scanf("%d",&n)!=1){printf("erreur!!\nRessayer:");int c;while((c=getchar())!='\n');};
        if(n<1 || n>6)printf("cette possibilite n'existe pas\n");
        switch(n)
        {  case 1:{
            pNoeud l=creerclasse();
            char C[20];
            printf("Vous avez choisi de creer une nouvelle classe.\n--------------------------------------------------\n");

            printf("Donner un nom a cette classe:\n");
            scanf("%s",C);
            while (classe_est_existante(C)==1){
                    printf("Erreur!!Une classe existante porte deja ce nom\nVeuillez entrer un nouveau nom:");
                    scanf("%s",C);
                            }

            compt=0,i=1;
            while(i!=0&&compt==0){
                    printf("\t \t**********\n");
                    printf("Menu: \n\t1.Ajouter un etudiant\n\t2.Afficher la liste des etudiants (Numero, nom et prenom).\n\t3.Afficher un etudiant. (par num).\n\t4.Modifier les donnees d un etudiant.\n\t5.Afficher les notes des etudiants.\n\t6.Afficher la moyenne de classe.\n\t7.Supprimer un etudiant.\n\t8.Enregistrer la clasee.\n\t9.Retour au menu principale\n--------------------------------------------------\n");
                    printf("Veuillez choisir un numero:\n");
                    while(scanf("%d",&i)!=1){printf("erreur!!\nRessayer:");int c;while((c=getchar())!='\n');};
                    if(i<0 || i>9)printf("cette possibilite n'existe pas\n");
                    switch(i)
                    {   case 1:{
                                   etud e;
                                   printf("----------------------------------------------------\n");
                                   e=lire(l);
                                   l=ajoutEtudiantFin(l,e);
                                   printf("----------------------------------------------------\n");
                                   break;}
                        case 2:{
                                   printf("----------------------------------------------------\n");
                                   afficherEtuds(l);
                                   printf("----------------------------------------------------\n");
                                   break;}
                        case 3:{
                                   printf("----------------------------------------------------\n");
                                   afficherEtudiant(l);
                                   printf("----------------------------------------------------\n");
                                   break;}
                        case 4:{
                                   printf("----------------------------------------------------\n");
                                    modifierEtudiant(l);
                                   printf("----------------------------------------------------\n");
                                    break;}
                        case 5:{
                                   printf("----------------------------------------------------\n");
                                   affichernote(l);
                                   printf("----------------------------------------------------\n");
                                   break;}
                        case 6:{
                                   printf("----------------------------------------------------\n");
                                   affichermoyen(l);
                                   printf("-----------------------------------------------------\n");
                                   break;}
                        case 7:{
                                   printf("----------------------------------------------------\n");
                                   l=supprimerEtudiant(l);
                                   printf("----------------------------------------------------\n");
                                   break;}
                        case 8:{
                                   printf("----------------------------------------------------\n");
                                    FILE* fichier;
                                    ajouter_classe_dans_ecole(C);
                                    strcat(C,".txt");
                                    fichier=fopen(C,"w+");
                                    enregistrer(l,fichier);
                                    fclose(fichier);
                                   printf("----------------------------------------------------\n");
                                    break;}
                        case 9:{compt=1;
                                   printf("----------------------------------------------------\n");}}};break;}
            case 2:{
                pNoeud l=creerclasse();
                char C[20];
                printf("Vous avez choisi d'ouvrir une classe existante.\n--------------------------------------------------\n");
                afficher_classes();
                printf("Donner le nom de la classe a ouvrir:\n");
                scanf("%s",C);
                while (classe_est_existante(C)==0){
                    printf("Erreur!!Aucune classe ne porte ce nom\nVeuillez ressayer:");
                    scanf("%s",C);
                            }
                printf("La classe '%s' est bien ouverte \n",C);
                strcat(C,".txt");
                FILE* fichier;
                fichier=fopen(C,"r");
                int numbers=countl(fichier);
                fclose(fichier);

                FILE* f;
                f=fopen(C,"r");
                l=importer(f,numbers);
                fclose(f);

                compt=0,i=1;
                while(i!=0&&compt==0){
                            printf("\t \t**********\n");
                            printf("Menu: \n\t1.Ajouter un etudiant\n\t2.Afficher la liste des etudiants (Numero, nom et prenom).\n\t3.Afficher un etudiant. (par num).\n\t4.Modifier les donnees d un etudiant.\n\t5.Afficher les notes des etudiants.\n\t6.Afficher la moyenne de classe.\n\t7.Supprimer un etudiant.\n\t8.Enregistrer les modifications.\n\t9.Retour au menu principale\n--------------------------------------------------\n");
                            printf("Veuillez choisir un numero:\n");
                            while(scanf("%d",&i)!=1){printf("erreur!!\nRessayer:");int c;while((c=getchar())!='\n');};
                            if(i<0 || i>9)printf("cette possibilite n'existe pas\n");
                            switch(i)
                            {   case 1:{
                                           etud e;
                                           printf("----------------------------------------------------\n");
                                           e=lire(l);
                                           l=ajoutEtudiantFin(l,e);
                                           printf("----------------------------------------------------\n");
                                           break;}
                                case 2:{
                                           printf("----------------------------------------------------\n");
                                           afficherEtuds(l);
                                           printf("----------------------------------------------------\n");
                                           break;}
                                case 3:{
                                           printf("----------------------------------------------------\n");
                                           afficherEtudiant(l);
                                           printf("----------------------------------------------------\n");
                                           break;}
                                case 4:{
                                   printf("----------------------------------------------------\n");
                                            modifierEtudiant(l);
                                   printf("----------------------------------------------------\n");
                                            break;}
                                case 5:{
                                           printf("----------------------------------------------------\n");
                                           affichernote(l);
                                           printf("----------------------------------------------------\n");
                                           break;}
                                case 6:{
                                           printf("----------------------------------------------------\n");
                                           affichermoyen(l);
                                           printf("-----------------------------------------------------\n");
                                           break;}
                                case 7:{
                                           printf("----------------------------------------------------\n");
                                           l=supprimerEtudiant(l);
                                           printf("----------------------------------------------------\n");
                                           break;}
                                case 8:{

                                            printf("----------------------------------------------------\n");
                                            FILE* fichier;
                                            fichier=fopen(C,"w+");
                                            enregistrer(l,fichier);
                                            fclose(fichier);
                                            printf("----------------------------------------------------\n");
                                            break;}
                                case 9:{compt=1;
                                            printf("----------------------------------------------------\n");}}};break;}
            case 3:{
                                   printf("----------------------------------------------------\n");
                                   suprimer();
                                   printf("----------------------------------------------------\n");break;}
            case 4:{
                                   printf("----------------------------------------------------\n");
                                   renommer_classe();
                                   printf("----------------------------------------------------\n");break;}
            case 5:{
                                   printf("----------------------------------------------------\n");
                                   afficher_classes();
                                   printf("----------------------------------------------------\n");
                                   break;}
            case 6:{
                        printf("\n*********************************Au revoir**************************************\n");

                exit(0);};
        }
 }
}
