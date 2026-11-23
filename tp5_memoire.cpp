#include <cassert>
#include <cstddef>
#include <print>

struct TableauDynamique {
    double* donnees{nullptr};
    std::size_t taille{0};
    std::size_t capacite{0};
};

// Fonction pour ajouter une valeur
void ajouter(TableauDynamique& t, double valeur)
{
    if (t.taille == t.capacite) {
        const std::size_t nouvelleCapacite =
            (t.capacite == 0) ? 4 : t.capacite * 2;

        double* nouveau = new double[nouvelleCapacite];

        for (std::size_t i{0}; i < t.taille; ++i) {
            nouveau[i] = t.donnees[i];
        }

        delete[] t.donnees;

        t.donnees = nouveau;
        t.capacite = nouvelleCapacite;
    }

    t.donnees[t.taille] = valeur;
    ++t.taille;
}

// Fonction pour libérer la mémoire
void liberer(TableauDynamique& t)
{
    delete[] t.donnees;
    t.donnees = nullptr;
    t.taille = 0;
    t.capacite = 0;
}

// Fonction pour accéder à un élément
double& element(TableauDynamique& t, std::size_t i)
{
    assert(i < t.taille && "element() : indice hors limites");
    return t.donnees[i];
}

int main()
{
    TableauDynamique notes;

    for (int i{0}; i < 10; ++i) {
        ajouter(notes, 10.0 + i);

        std::println("taille {:>2}, capacité {:>2}",
                     notes.taille, notes.capacite);
    }

    liberer(notes);
}