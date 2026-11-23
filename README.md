TP 2 — Mise en place de l’environnement C++

Présentation du projet — Partie D : Squelette UIN-Campus

Nom du projet : UIN-Campus

Description : Système de gestion académique de l’UIN, développé en C++.

⸻

Partie A — Installation et vérification de l’environnement

A.ii — Versions des outils installés

Outil	Version
G++	15.2.0
Clang++	21.1.8
CMake	4.2.3
Ninja	1.13.2
GDB	17.1
Git	2.53.0

A.iii — Compilation et exécution du programme de test C++23

Le fichier de test utilisé est test_cpp23.cpp.

Avec GCC :

g++ -std=c++23 test_cpp23.cpp -o test
./test

Avec Clang :

clang++ -std=c++23 test_cpp23.cpp -o test_clang
./test_clang

Résultat obtenu avec les deux compilateurs :

C++23 fonctionne : __cplusplus = 202302

⸻

Partie B — Configuration de l’éditeur

B.i — Installation de VS Code

Visual Studio Code a été installé avec l’extension C/C++ et les outils nécessaires au développement C++.

B.ii — Vérification de clangd

Le fonctionnement de clangd a été vérifié en introduisant volontairement une erreur dans le code. L’erreur a été signalée par un soulignement rouge, puis corrigée.

⸻

Partie C — Débogage et sanitizers

C.i — Débogage avec GDB

Le programme bug.cpp a été compilé en mode débogage et exécuté avec GDB.

Une erreur d’accès hors limites du vecteur a été identifiée.

C.ii — Détection de l’erreur avec ASan et UBSan

AddressSanitizer a signalé une erreur de type heap-buffer-overflow à la ligne 9 de bug.cpp.

C.iii — Correction du bug

La condition de la boucle a été corrigée :

i < notes.size()

Après recompilation et exécution, le programme affiche :

Moyenne : 14

Aucune erreur de sanitizer n’a été signalée.

C.iv — Analyse des fuites mémoire

Le fichier fuite.cpp a été analysé avec LeakSanitizer et Valgrind.

Les deux outils ont détecté une fuite mémoire de 40 octets à la ligne 4.

⸻

Partie D — Squelette UIN-Campus

D.i — Configuration, construction et exécution

Le projet a été configuré avec le preset debug :

cmake --preset debug

Construction du projet :

cmake --build --preset debug

Exécution :

./build/debug/uin_campus

Résultat obtenu :

UIN-Campus - Système de gestion académique
Version 0.1.0

D.ii — Formatage et analyse du code

Formatage avec clang-format :

clang-format -i app/main.cpp src/version.cpp src/regles.cpp src/saisie.cpp include/uincampus/version.hpp include/uincampus/regles.hpp include/uincampus/saisie.hpp

Analyse statique avec clang-tidy :

clang-tidy -p . app/main.cpp src/*.cpp include/uincampus/*.hpp

D.iii — Dépôt Git et publication sur GitHub

Le projet a été enregistré dans un dépôt Git, puis publié sur GitHub.

Lien du dépôt : https://github.com/kadidjatou123/uin-campus

⸻

Conclusion

L’environnement de développement C++ a été installé et vérifié. Les exercices de débogage et d’analyse mémoire ont été réalisés. Le projet UIN-Campus a été configuré, construit, analysé et publié sur GitHub.



⸻

TP 3 — Calcul des moyennes et statistiques d’une UE

Partie A — Fil rouge UIN-Campus

A.i — Gestion des règles de notation

Création des fichiers :

* include/uincampus/regles.hpp
* src/regles.cpp

Ces fichiers permettent de définir les règles de notation et les mentions :

* Ajourné
* Passable
* Assez bien
* Bien
* Très bien

Une note est valide si elle est comprise entre 0 et 20. Le seuil de validation est fixé à 10.

A.ii — Gestion des saisies

Création des fichiers :

* include/uincampus/saisie.hpp
* src/saisie.cpp

Les fonctions permettent de saisir un texte, un nombre entier et une note.

Les saisies incorrectes sont refusées. Les notes décimales peuvent être saisies avec une virgule ou un point.

A.iii — Calcul de la moyenne d’un étudiant

Le fichier app/main.cpp a été modifié pour permettre de :

* Saisir le nom d’un étudiant.
* Saisir le nombre de notes.
* Saisir les différentes notes.
* Calculer la moyenne.
* Déterminer la mention.
* Afficher la décision de validation.

A.iv — Compilation et tests

Configuration :

cmake --preset debug

Compilation :

cmake --build --preset debug

Exécution :

./build/debug/uin_campus

Les tests ont permis de vérifier le calcul de la moyenne, l’attribution des mentions et le refus des notes incorrectes.

Partie B — Exercice de statistiques d’une UE

B.i — Création du programme

Création du fichier :

app/statistiques.cpp

Ajout de la cible statistiques_ue dans CMakeLists.txt.

B.ii — Calcul des statistiques

Le programme permet de :

* Saisir le nom d’une UE.
* Saisir le nombre d’étudiants (de 1 à 200).
* Saisir les notes des étudiants (de 0 à 20).
* Calculer la note minimale et la note maximale.
* Calculer la moyenne générale.
* Calculer l’écart-type.
* Déterminer le nombre et le pourcentage d’admis.
* Afficher un histogramme horizontal des mentions.

B.iii — Tests et vérifications

Les tests ont permis de vérifier :

* Le refus d’un nombre d’étudiants égal à 0.
* Le refus d’une note supérieure à 20.
* L’acceptation des notes décimales avec une virgule.
* Le calcul correct des statistiques.
* L’affichage correct de l’histogramme des mentions.

Exemple de résultat obtenu avec cinq étudiants :

Indicateur	Résultat
Note minimale	8,00
Note maximale	18,00
Moyenne	12,70
Écart-type	3,54
Nombre d’admis	4
Pourcentage d’admis	80 %

B.iv — Formatage, compilation et exécution

Formatage du fichier :

clang-format -i app/statistiques.cpp

Compilation :

cmake --build --preset debug

Exécution :

./build/debug/statistiques_ue

Les deux programmes, uin_campus et statistiques_ue, ont été compilés avec succès.

Conclusion du TP3

Les règles de notation, les fonctions de saisie et le calcul de la moyenne d’un étudiant ont été intégrés au projet UIN-Campus.

Un programme indépendant de statistiques d’une UE a également été développé et testé. Les deux programmes ont été compilés avec CMake, et les modifications ont été enregistrées dans Git puis publiées sur GitHub.

## TP4 — Carnet de notes et module de calculs

### 1. Carnet de notes en mode menu

Un programme de gestion de notes a été développé dans le fichier `app/carnet_notes.cpp`.

Il permet de :
- Ajouter une note.
- Afficher les notes.
- Modifier une note.
- Supprimer une note.
- Trier les notes par ordre croissant ou décroissant.
- Afficher les statistiques.
- Appliquer un bonus aux notes.

Les fonctionnalités ont été organisées dans l'espace de noms `carnet`.

### 2. Module de calculs de UIN-Campus

Les fichiers suivants ont été ajoutés :

- `include/uincampus/calculs.hpp`
- `src/calculs.cpp`

Ce module permet de calculer :
- La somme des notes.
- La moyenne simple.
- La moyenne pondérée par les coefficients.
- Le minimum et le maximum.
- L'écart-type.
- Le nombre de notes validées.
- L'arrondi des résultats.

### 3. Amélioration de la saisie

Le fichier `src/saisie.cpp` a été amélioré avec des structures de retour et des liaisons structurées.

### 4. Programme principal

Le fichier `app/main.cpp` a été modifié pour :
- Lire les arguments de la ligne de commande.
- Afficher la version avec l'argument `--version`.
- Calculer la moyenne pondérée d'un étudiant.
- Afficher les statistiques et la mention.

### 5. Compilation et exécution

Formatage du code :

```bash
clang-format -i include/uincampus/*.hpp src/*.cpp app/*.cpp
```

Compilation :

```bash
cmake --build --preset debug
```

Exécution du carnet de notes :

```bash
./build/debug/carnet_notes
```

Exécution de UIN-Campus :

```bash
./build/debug/uin-campus
```

Affichage de la version :

```bash
./build/debug/uin-campus --version
```

### Conclusion du TP4

Le carnet de notes et le module de calculs académiques ont été intégrés au projet UIN-Campus. Les programmes ont été compilés avec CMake et le calcul de la moyenne pondérée a été testé avec succès.
```

TP5 — Gestion de la mémoire et utilisation de std::vector

1. Présentation du TP

Objectif : comprendre la gestion dynamique de la mémoire en C++, découvrir les risques liés aux pointeurs et apprendre à utiliser le conteneur std::vector.

Le TP est organisé en trois parties :

* Partie A : création d’un tableau dynamique avec new[] et delete[].
* Partie B : étude des problèmes liés à la copie superficielle.
* Partie C : utilisation de std::vector.

2. Partie A — Création d’un tableau dynamique

2.1. Création du programme

Le fichier tp5_memoire.cpp contient une structure appelée TableauDynamique.

Cette structure possède trois éléments :

* donnees : pointeur vers les données stockées en mémoire.
* taille : nombre d’éléments présents dans le tableau.
* capacite : nombre d’éléments que le tableau peut contenir.

2.2. Gestion de la mémoire

Trois fonctions ont été développées :

* ajouter() : ajoute une valeur et augmente la capacité lorsque le tableau est plein.
* liberer() : libère la mémoire avec delete[] et réinitialise les informations du tableau.
* element() : permet d’accéder à un élément après vérification de l’indice avec assert.

La capacité du tableau double lorsqu’il n’y a plus de place.

2.3. Résultat obtenu

Lors de l’ajout de dix valeurs, la capacité évolue de la manière suivante :

Taille	Capacité
1	4
2	4
3	4
4	4
5	8
6	8
7	8
8	8
9	16
10	16

3. Partie B — Étude de la copie superficielle

Une expérience a été réalisée en copiant une structure contenant un pointeur.

La copie superficielle recopie la valeur du pointeur, mais ne crée pas une nouvelle zone mémoire.

Les deux structures pointent donc vers la même zone mémoire.

Lorsque les deux structures tentent de libérer cette même zone, AddressSanitizer détecte une erreur de double libération (double-free).

Une autre expérience a permis de constater qu’une mémoire qui n’est pas libérée provoque une fuite mémoire (memory leak).

Enfin, l’utilisation de delete à la place de delete[] provoque une erreur, car la mémoire avait été réservée avec new[].

Conclusion de la partie B : il faut respecter les règles d’allocation et de libération de la mémoire. Une copie superficielle d’une structure contenant un pointeur peut entraîner des erreurs de gestion mémoire.

4. Partie C — Utilisation de std::vector

4.1. Création du programme

Le fichier tp5.cpp utilise le conteneur std::vector<double>.

std::vector permet de gérer automatiquement un tableau dynamique sans avoir à utiliser directement new[] et delete[].

La fonction push_back() permet d’ajouter des valeurs à la fin du vecteur.

Les fonctions size() et capacity() permettent respectivement de connaître le nombre d’éléments et la capacité du vecteur.

Une copie du vecteur a également été réalisée pour observer le comportement de la copie avec std::vector.

4.2. Résultat obtenu

Lors de l’ajout de dix valeurs, le programme a affiché :

taille  1, capacité  1
taille  2, capacité  2
taille  3, capacité  4
taille  4, capacité  4
taille  5, capacité  8
taille  6, capacité  8
taille  7, capacité  8
taille  8, capacité  8
taille  9, capacité 16
taille 10, capacité 16

La stratégie d’augmentation de la capacité de std::vector dépend de l’implémentation de la bibliothèque standard.

5. Compilation et exécution

5.1. Compilation du programme de la partie A

g++ -std=c++23 -Wall -Wextra -g -fsanitize=address,undefined -fno-omit-frame-pointer tp5_memoire.cpp -o tp5_memoire

Exécution :

./tp5_memoire

5.2. Compilation du programme de la partie C

g++ -std=c++23 -Wall -Wextra -g -fsanitize=address,undefined -fno-omit-frame-pointer tp5.cpp -o tp5

Exécution :

./tp5

6. Conclusion générale du TP5

Ce TP a permis de comprendre le fonctionnement de la mémoire dynamique en C++.

La première partie a permis de créer et de gérer manuellement un tableau dynamique avec new[] et delete[].

La deuxième partie a montré les risques liés à la copie superficielle, aux doubles libérations et aux fuites mémoire.

La troisième partie a permis de découvrir std::vector, qui facilite la gestion des tableaux dynamiques et réduit les risques d’erreurs liés à la gestion manuelle de la mémoire.

Bilan : l’utilisation de std::vector est généralement préférable à la gestion manuelle de la mémoire lorsque ce conteneur répond au besoin du programme.