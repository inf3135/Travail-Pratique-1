# inf3135-hiv2016-tp1
TP1
# Travail pratique 1

## Description

Dans ce projet, le but est de lire les informations sur les pays et villes a partir
des fichiers CityInfo.txt et Cities15000.txt qui donnent des statistiques sur la population dans ces endroits,
et ensuite extraire ces informations et les arranger, afin de pouvoir afficher les n villes les plus peuplees au monde, en ordre decroissant.
n etant un entier entre a la ligne de commande et se situant entre 1 et 5000.

Travail Pratique 1, INF3135 , Groupe 10, HIVER 2016, donne par Mr. Alexandre Blondin Massé.

## Auteur

prenom et nom  : HAYTHEM KHELIFI 
Code Permanent : KHEH28128907

## Fonctionnement

Pour executer ce projet on peut : 
Aller au terminal (ligne de commande) , et choisir la directive dans laquelle se situe le projet, ensuite faire la commande : 
make
qui va creer le fichier executable tp1.exe , ensuite, entrer :

/tp1 <nombre de villes a afficher>
qui va vous afficher les n villes les plus peuplees au monde en ordre decroissant, pourvu que n soit un entier entre 1 et 5000.

Un autre exemple d'utilisation serait par exemple, pour supprimer le fichier executable tp1.exe, il faut donc faire la commande : 
make clean


## Contenu du projet

-makefile        : c'est le fichier essentiel qui permet de faire les differentes commandes 
                   make pour creer l'executable
			       make clean pour le supprimer
			       make database pour telecharger les fichiers d'entree

-CountryInfo.txt : fichier conetnant les informations sur les pays
-Cities15000.txt : fichier contenanet les informations sur les villes avec au moins 15000 habitants.
-tp1.c           : fichier de code source contenant entre autres la fonction main.
-Readme.txt      : Il s'agit de ce fichier qui decrit le projet.
-gitignore       : 
## Références

Algorithme de tri rapide appris en INF2120 (Java), meme principe traduit et implemente en C.
Les fichiers CityInfo.txt et Cities15000.zip contenant les informations se trouvent sur le site GeoNames.com (http://download.geonames.org/export/dump/) 

## Statut

Le projet est Complet. Mais il ya un petit warning pour la fonction d'affichage qui n'a pas d'influence sur le rendement du projet.
