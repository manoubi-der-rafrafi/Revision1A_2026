# Projet Lecture

## Role

Ce programme illustre la lecture de donnees depuis un fichier, puis quelques operations de gestion de fichiers :

- lecture texte ;
- tentative de lecture binaire ;
- suppression ;
- renommage.

## Fichiers du dossier

- `main.c` : code source principal.
- `etudiant.txt` : fichier d'entree attendu pour la lecture texte.
- `employe.txt` : fichier cree apres renommage.
- `Lecture.cbp` : projet Code::Blocks.

## Fonctionnement actuel

1. Le programme ouvre `etudiant.txt` en mode lecture texte `"r"`.
2. Il lit trois champs avec `fscanf`.
3. Il affiche les donnees lues.
4. Il rouvre ensuite un fichier en mode binaire `"rb"`.
5. Il effectue `fread` sur une structure `Etudiant`.
6. Il supprime `etudiant.bin`.
7. Il renomme `etudiant.txt` en `employe.txt`.

## Execution

Avec GCC :

```powershell
gcc .\main.c -o .\Lecture.exe
.\Lecture.exe
```

## Prerequis pour tester

Pour observer un comportement coherent, il faut preparer les fichiers d'entree avant l'execution :

- `etudiant.txt` doit exister si vous voulez tester la lecture texte ;
- `etudiant.bin` doit exister si vous voulez tester la suppression du fichier binaire.

Le plus simple est d'executer d'abord le projet `Ecriture`, puis de copier les fichiers utiles dans ce dossier si necessaire.

## Points d'attention

- Le code ouvre `etudiant.txt` en mode `"rb"` pour la partie binaire, alors que l'operation suivante lit une structure avec `fread`. En pratique, cette partie semble avoir ete ecrite pour un fichier binaire, mais le nom du fichier utilise dans le source est `etudiant.txt`.
- La derniere partie modifie les fichiers du dossier :
  - `etudiant.bin` est supprime ;
  - `etudiant.txt` est renomme en `employe.txt`.

## Usage pedagogique

Ce projet est utile pour comprendre la difference entre :

- lecture formatee d'un fichier texte ;
- lecture brute d'une structure en binaire ;
- manipulation du systeme de fichiers avec `remove` et `rename`.
