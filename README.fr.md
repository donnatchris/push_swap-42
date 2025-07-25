##### [🇫🇷 Version française](README.fr.md) / [🇬🇧 English version](README.md)

# PROJET PUSH_SWAP POUR 42
Par chdonnat (Christophe Donnat de 42 Perpignan, France)

## BUT DU PROJET :

Le projet Push swap est un exercice d'algorithmique simple et efficace :
vous devez trier des données.
Vous disposez d'un ensemble d'entiers, de deux piles (stacks),
et d'un ensemble d'instructions pour les manipuler.
Votre objectif ? Écrire un programme en C nommé push_swap qui calcule
et affiche sur la sortie standard le plus petit programme,
composé d'instructions du langage Push swap, qui trie les entiers passés en paramètres.

## QUELQUES COMMANDES UTILES :

compiler le programme push_swap

	make

compiler le programme checker

	make bonus

supprimer tous les fichiers .o générés par la commande make

	make clean

générer une liste de 500 entiers (sans doublons) séparés par des espaces
et assigner la liste à la variable ARG
(vous pouvez choisir un autre nombre comme 100 ou 5 par exemple)
 
	ARG=$(<mettez ici votre liste de nombres à trier>)

compter le nombre d'étapes utilisées par push_swap pour trier les nombres dans ARG

	./push_swap "$ARG" | wc -l
 
pour Mac:
vérifier la sortie de push_swap en utilisant le testeur de 42 :
renvoie OK si la sortie de push_swap trie les nombres dans ARG
ou renvoie KO sinon
renvoie une erreur s'il y a eu une erreur

	./push_swap "$ARG" | ./tests/checker_Mac "$ARG"

identique à ci-dessus mais pour linux

	./push_swap "$ARG" | ./tests/checker_linux "$ARG"

identique à ci-dessus mais en utilisant mon propre testeur (réalisé pour le bonus du projet)

	./push_swap "$ARG" | ./checker "$ARG"

 ---

## À propos de mon algorithme
J'ai utilisé un algorithme de tri assez standard pour un push_swap (comparé à ce que vous trouverez en ligne). Essentiellement, le programme pousse toutes les valeurs à trier sur la pile B, ne laissant que 3 valeurs sur la pile A, qu'il trie directement.
À partir de là, le programme identifie la valeur à ramener à la bonne position dans la pile A (similaire au tri par insertion) en choisissant celle qui nécessite le moins de mouvements. Il déplace ensuite cette valeur à la bonne position dans la pile A et répète le processus jusqu'à ce que la pile B soit vide.
Enfin, il effectue une rotation sur la pile A pour placer la plus petite valeur en haut.

Pour ce projet, j'ai utilisé deux listes doublement chaînées circulaires pour représenter les piles.
Vous trouverez les fonctions pour manipuler ces listes doublement chaînées circulaires dans les fichiers dclst.c.

> Si vous souhaitez voir une approche de tri beaucoup plus originale (qui nécessite moins de calculs, même si elle demande plus de mouvements), j'ai codé un push_swap qui utilise trois fonctions récursives. > Ce fut un véritable casse-tête à mettre en œuvre, mais le résultat est très satisfaisant.
> Malheureusement, je n'ai pas utilisé cette version pour le projet 42 car elle ne permettait pas d'obtenir le meilleur score pour le tri de 100 valeurs.
> Il faut plus de 700 mouvements pour 100 valeurs mais reste en dessous de 5500 mouvements pour 500 valeurs.
> Vous pouvez trouver cet algorithme dans mon autre dépôt :

[recursive_push_swap.
](https://github.com/donnatchris/recursive_push_swap)

---

## DOCUMENTATION

### Complexité

Le concept de complexité temporelle fait référence au temps qu'un algorithme met pour s'exécuter en fonction de la taille de l'entrée.
Elle est généralement exprimée en utilisant la notation Big O, qui fournit une borne supérieure sur le nombre d'opérations que l'algorithme effectuera par rapport à la taille de l'entrée.
Cela nous permet d'estimer comment l'algorithme se comportera à mesure que la taille de l'entrée augmente.

Par exemple, un algorithme avec une complexité temporelle de O(n) signifie que le nombre d'opérations augmentera de manière linéaire avec la taille de l'entrée.
Un algorithme avec une complexité temporelle de O(n^2), comme le tri à bulles, verra son temps d'exécution augmenter de manière quadratique à mesure que la taille de l'entrée augmente.
L'objectif de la compréhension de la complexité temporelle est d'évaluer l'efficacité d'un algorithme à mesure que la taille de l'entrée augmente, en particulier lorsqu'il s'agit de grands ensembles de données.

De même, la complexité spatiale fait référence à la quantité de mémoire qu'un algorithme nécessite par rapport à la taille de l'entrée. La complexité temporelle et spatiale nous aident à comprendre l'efficacité des algorithmes en termes de calcul et d'utilisation de la mémoire.

### Algorithmes de tri courants :

#### Tri à bulles (Bubble Sort):
Le tri à bulles est un algorithme de tri simple basé sur la comparaison.
Il parcourt la liste à plusieurs reprises, compare les éléments adjacents et les échange s'ils sont dans le mauvais ordre.
Ce processus se poursuit jusqu'à ce qu'aucun échange ne soit nécessaire, ce qui signifie que la liste est triée.
Malgré sa simplicité, le tri à bulles est inefficace pour les grands ensembles de données en raison de sa complexité temporelle de O(n^2).

#### Tri par sélection (Selection Sort):
Le tri par sélection divise la liste en une partie triée et une partie non triée.
Il sélectionne à plusieurs reprises le plus petit (ou le plus grand) élément de la partie non triée et l'échange avec le premier élément de la partie non triée,
déplaçant la frontière entre les deux parties jusqu'à ce que toute la liste soit triée.
Sa complexité temporelle est de O(n^2).

#### Tri par insertion (Insertion Sort):
Le tri par insertion construit la liste triée un élément à la fois.
Il prend chaque élément de la partie non triée et l'insère à la bonne position dans la partie triée en décalant les éléments si nécessaire.
Il fonctionne efficacement pour les ensembles de données petits ou presque triés avec une complexité temporelle de O(n^2).

#### Tri fusion (Merge Sort):
Le tri fusion est un algorithme de type "diviser pour régner" qui divise la liste en sous-listes plus petites jusqu'à ce que chaque sous-liste ne contienne qu'un seul élément.
Ensuite, il fusionne ces sous-listes dans l'ordre trié pour former la liste triée finale.
Sa complexité temporelle est de O(n log n), ce qui le rend efficace pour les grands ensembles de données.

#### Tri rapide (Quick Sort):
Le tri rapide est également un algorithme de type "diviser pour régner".
Il sélectionne un élément pivot, partitionne la liste en deux parties (éléments plus petits que le pivot et éléments plus grands que le pivot), et trie récursivement les sous-listes.
Sa complexité temporelle moyenne est de O(n log n), mais elle peut se dégrader à O(n^2) dans le pire des cas.

#### Tri par tas (Heap Sort):
Le tri par tas utilise une structure de données de tas binaire pour trier la liste.
Il construit un tas max à partir de l'entrée et extrait à plusieurs reprises le plus grand élément, le plaçant à la fin de la liste, puis reconstruit le tas.
Il a une complexité temporelle de O(n log n) et est efficace pour les grands ensembles de données.

#### Tri par comptage (Counting Sort):
Le tri par comptage est un algorithme de tri non basé sur la comparaison qui fonctionne bien pour les ensembles de données d'entiers dans une plage limitée.
Il compte les occurrences de chaque élément, puis calcule leurs positions dans la liste triée.
Sa complexité temporelle est de O(n + k), où k est la plage des valeurs d'entrée.

#### Tri par base (Radix Sort):
Le tri par base trie les entiers en traitant les chiffres individuels du moins significatif au plus significatif.
Il utilise un algorithme de tri stable comme le tri par comptage pour chaque position de chiffre.
Sa complexité temporelle est de O(nk), où k est le nombre de chiffres dans le plus grand nombre.