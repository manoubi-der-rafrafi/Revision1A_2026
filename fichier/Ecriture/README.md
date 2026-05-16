# Projet Ecriture

## Role

Ce programme montre comment ecrire les informations d'un etudiant dans :

- un fichier texte `etudiant.txt` ;
- un fichier binaire `etudiant.bin`.

## Fichiers du dossier

- `main.c` : code source principal.
- `etudiant.txt` : fichier texte genere ou complete par le programme.
- `etudiant.bin` : fichier binaire genere par le programme.
- `Ecriture.cbp` : projet Code::Blocks.

## Donnees manipulees

Le programme utilise la structure suivante :

- `id`
- `nom`
- `age`

Dans le code actuel, l'etudiant initialise est :

- `id = 10`
- `nom = "manoubi"`
- `age = 20`

## Fonctionnement

1. Le programme cree une variable `Etudiant`.
2. Il ouvre `etudiant.txt` en mode ajout avec `fopen(..., "a")`.
3. Il ecrit les donnees en texte avec `fprintf`.
4. Il ouvre `etudiant.bin` en mode binaire ecriture avec `fopen(..., "wb")`.
5. Il ecrit la structure complete avec `fwrite`.

## Execution

Avec Code::Blocks :

- ouvrir `Ecriture.cbp` ;
- compiler puis executer la cible `Debug` ou `Release`.

Avec GCC :

```powershell
gcc .\main.c -o .\Ecriture.exe
.\Ecriture.exe
```

## Resultat attendu

Apres execution :

- `etudiant.txt` contient une representation texte des donnees ;
- `etudiant.bin` contient la structure en format binaire.

## Remarques

- Le mode `"a"` ajoute a la fin du fichier texte existant. Si vous lancez plusieurs fois le programme, le contenu de `etudiant.txt` peut s'accumuler.
- Le fichier binaire, lui, est ouvert en `"wb"` : son ancien contenu est ecrase a chaque execution.
- Le code utilise `strcpy`, ce qui suppose la presence de l'en-tete `<string.h>` dans une version C stricte. Cette documentation decrit le comportement actuel sans modifier le source.
