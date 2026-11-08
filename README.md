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
