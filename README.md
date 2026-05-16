# Revision 2026 - Manipulation de fichiers en C

Ce dossier regroupe de petits projets C autour de la lecture et de l'ecriture de fichiers texte et binaires.
Les projets ont ete crees avec Code::Blocks et peuvent aussi etre compiles avec `gcc`.

## Structure du depot

- `Ecriture/` : exemple d'ecriture dans un fichier texte et un fichier binaire.
- `Lecture/` : exemple de lecture de donnees depuis un fichier puis operations simples sur les fichiers.
- `exercice/` : squelette d'exercice a completer.
- `Ecriture.zip` : archive du projet `Ecriture`.

## Objectif pedagogique

Ces projets servent a reviser les notions suivantes :

- declaration d'une structure en C ;
- ouverture d'un fichier avec `fopen` ;
- ecriture de texte avec `fprintf` ;
- ecriture binaire avec `fwrite` ;
- lecture de texte avec `fscanf` ;
- lecture binaire avec `fread` ;
- fermeture, suppression et renommage de fichiers.

## Prerequis

- Code::Blocks avec GCC, ou
- un compilateur C comme `gcc`.

## Compilation rapide avec GCC

Depuis la racine du depot :

```powershell
gcc .\Ecriture\main.c -o .\Ecriture\Ecriture.exe
gcc .\Lecture\main.c -o .\Lecture\Lecture.exe
gcc .\exercice\main.c -o .\exercice\exercice.exe
```

## Execution

Il est preferable d'executer chaque programme depuis son propre dossier, car les fichiers `etudiant.txt`, `etudiant.bin` et `employe.txt` sont utilises avec des chemins relatifs.

Exemple :

```powershell
Set-Location .\Ecriture
.\Ecriture.exe
```

```powershell
Set-Location ..\Lecture
.\Lecture.exe
```

## Notes importantes

- Le projet `Ecriture` cree ou complete `etudiant.txt` et ecrit aussi un fichier binaire `etudiant.bin`.
- Le projet `Lecture` lit un fichier texte, tente ensuite une lecture binaire, supprime `etudiant.bin`, puis renomme `etudiant.txt` en `employe.txt`.
- Le projet `exercice` contient seulement un programme minimal `Hello world!` et peut servir de base pour vos propres exercices.

## Documentation detaillee

Chaque sous-dossier contient un `README.md` avec :

- le role du projet ;
- les fichiers importants ;
- le comportement attendu ;
- les remarques utiles pour les tests.
