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