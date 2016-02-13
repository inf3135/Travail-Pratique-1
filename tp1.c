
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TAILLE_NOM 256
#define LONG_CODE_PAYS 3
#define MAX_PAYS 300
#define MAX_TAILLE_LIGNE 2048
#define MAX_VILLES 25000


struct Pays {
	char nom[MAX_TAILLE_NOM]; // Le nom ASCII
	char code[LONG_CODE_PAYS]; // Le code a 2 lettres
};
const struct Pays PAYS_BIDON = {"??","??"};

struct Ville {
	char nom[MAX_TAILLE_NOM]; // Le nom ASCII
	long population; // La population
	struct Pays pays; // Le Pays de la ville
};
const struct Ville VILLE_BIDON = {"??",-1,{"??","??"}};

//prototypes des fonctions

//fonction pour decouper les string i.e (separe par une virgule pour delimiter)
char *strtok_new(char * string, char const * delimiter);
//fonction de tri rapide arrange le tableau des villes
void quicksort(struct Ville a[MAX_VILLES], int n);
//fonction pour lire l`information des pays du fichier
int readCountryInfo(char *fileName, struct Pays pays[MAX_PAYS]);
//fonction pour lire l`information des villes du fichier
int readCityInfo(char *fileName, struct Ville villes[MAX_PAYS]);
//fonction pour mettre a jour les noms des villes des pays
void updateCities(struct Pays pays[MAX_PAYS], int num_pays, struct Ville villes[MAX_VILLES], int num_villes);
//fonction pour afficher les n premieres villes
void displayTop(struct Ville villes[MAX_VILLES], int n, int size);

int main(int argc, char * argv[])
{
	struct Pays pays[MAX_PAYS];
	static struct Ville villes[MAX_VILLES];
	int num_pays = 0;
	int num_villes = 0;
	int n = 0;

	if (argc != 2)
	{
		printf("Erreur: Entrer un Entier\n");
		printf("Usage: %s <nombre de villes>\n", argv[0]);
		return 1;
	}
    
	
	n = atoi(argv[1]);
	num_pays = readCountryInfo("countryInfo.txt",pays);
	num_villes = readCityInfo("cities15000.txt", villes);
	updateCities(pays,num_pays, villes,num_villes);
	quicksort(villes,num_villes);
	displayTop(villes,n,num_villes);

	return 0;
}

//fonction de tri rapide 
void quicksort(struct Ville a[MAX_VILLES], int n) {
	int i, j;
	struct Ville t, p;

	if (n < 2)
		return;
	p = a[n / 2];
	for (i = 0, j = n - 1;; i++, j--) {
		while (a[i].population > p.population)
			i++;
		while (p.population > a[j].population)
			j--;
		if (i >= j)
			break;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	quicksort(a, i);
	quicksort(a + i, n - i);
}

//fonction pour lire l`information des pays du fichier
int readCountryInfo(char *fileName, struct Pays pays[MAX_PAYS])
{
	FILE *fptr;
	char line[MAX_TAILLE_LIGNE];
	int len = 0;
	char *ch;
	int count = 0;
	int index = 0;

	fptr = fopen(fileName, "r");
	if (fptr == NULL)
	{
		printf("Erreur: impossible de trouver %s\n", fileName);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, MAX_TAILLE_LIGNE, fptr))
	{
		if (strlen(line) > 0 && line[0] != '#')
		{
			count = 0;
			ch = strtok(line, "\t");
			while (ch != NULL) {
				if (count == 0)
					strcpy(pays[index].code, ch);
				if (count == 4)
					strcpy(pays[index].nom, ch);
				ch = strtok(NULL, "\t");
				count++;
			}
			//printf("%s,%s\n", pays[index].code, pays[index].nom);
			index++;
		}
	}

	fclose(fptr);
	return index;
}

//fonction pour decoupage
char *strtok_new(char * string, char const * delimiter){
	static char *source = NULL;
	char *p, *retour = 0;
	if (string != NULL)         source = string;
	if (source == NULL)         return NULL;

	if ((p = strpbrk(source, delimiter)) != NULL) {
		*p = 0;
		retour = source;
		source = ++p;
	}
	return retour;

}

//fonction pour lire l`information des villes du fichier
int readCityInfo(char *fileName, struct Ville villes[MAX_PAYS])
{
	FILE *fptr;
	char line[MAX_TAILLE_LIGNE];
	int len = 0;
	char *ch;
	int count = 0;
	int index = 0;

	fptr = fopen(fileName, "r");
	if (fptr == NULL)
	{
		printf("Erreur: impossible de trouver %s\n", fileName);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, MAX_TAILLE_LIGNE, fptr))
	{
		if (strlen(line) > 0 && line[0] != '#')
		{
			count = 0;
		
			ch = strtok_new(line, "\t");
			while (ch != NULL) {
				if (count == 1)
					strcpy(villes[index].nom, ch);
				if (count == 8)
				{
					strcpy(villes[index].pays.code, ch);
				}
				if (count == 14)
				{
					villes[index].population = atoi(ch);
				}
				ch = strtok_new(NULL, "\t");
				count++;
			}
			//printf("%s,%s,%d\n", villes[index].nom, villes[index].pays.code, villes[index].population);
			index++;
		}
	}

	fclose(fptr);
	return index;
}

//fonction pour mettre a jour les noms des villes des pays
void updateCities(struct Pays pays[MAX_PAYS], int num_pays, struct Ville villes[MAX_VILLES], int num_villes)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < num_villes; i++)
	{
		for (j = 0; j < num_pays; j++)
		{
			if (strcmp(villes[i].pays.code, pays[j].code) == 0)
			{
				strcpy(villes[i].pays.nom, pays[j].nom);
				break;
			}
		}
	}
}

//fonction pour afficher les n premieres villes
void displayTop(struct Ville villes[MAX_VILLES], int n, int taille)
{
	int i = 0;
	int count = 0;
	if ( n<1 || n > 5000 ) 
	{ 
		printf("Erreur ! n doit etre situe entre 1 et 5000\n");
		return 0;
    }
    
	if (taille >= n)
	{
		printf("%4s\t%-18s\t%-18s\t%10s\n", "Rang", "Nom", "Pays", "Population");
		printf("%4s\t%-18s\t%-18s\t%10s\n", "----", "---", "----", "----------");
		while (count < n)
		{
			if (strlen(villes[i].pays.nom) > 0)
			{
				printf("%4d\t%-18.18s\t%-18.18s\t%10ld\n", count + 1, villes[i].nom, villes[i].pays.nom, villes[i].population);
				count++;
			}
			i++;
		}
	}
	printf("\n");
}
