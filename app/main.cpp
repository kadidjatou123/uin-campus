#include "uincampus/calculs.hpp"
#include "uincampus/regles.hpp"
#include "uincampus/saisie.hpp"
#include "uincampus/version.hpp"

#include <cstdlib>
#include <format>
#include <print>
#include <string>
#include <string_view>
#include <vector>

namespace {

void afficherLigne(std::string_view libelle, std::string_view valeur) {
  std::println("{:<20}{:>20}", libelle, valeur);
}

} // namespace

int main(int argc, char *argv[]) {
  if (argc > 1 && std::string_view{argv[1]} == "--version") {
    std::println("uin-campus {}", uin::version());
    return EXIT_SUCCESS;
  }

  std::println("UIN-Campus - Calcul des résultats d'un étudiant\n");

  const std::string nom = uin::lireTexte("Nom de l'étudiant : ");
  const int nbUE = uin::lireEntier("Nombre d'UE (1 à 30) : ", 1, 30);

  std::vector<double> notes;
  std::vector<double> coefficients;

  for (int i = 1; i <= nbUE; ++i) {
    std::println("\nUE {}", i);

    notes.push_back(uin::lireNote(std::format("Note de l'UE {} : ", i)));

    coefficients.push_back(
        static_cast<double>(uin::lireEntier("Coefficient (1 à 10) : ", 1, 10)));
  }

  const double moyenneGenerale =
      uin::arrondir(uin::moyenne(notes, coefficients));

  const auto [mini, maxi, moyenneSimple, ecartType] =
      uin::calculerStatistiques(notes);

  const int validees = uin::compterValidees(notes);
  const uin::Mention mention = uin::mentionPour(moyenneGenerale);

  std::println("\n{:-<45}", "");
  std::println("BULLETIN DE NOTES");
  afficherLigne("Étudiant", nom);
  std::println("{:<20}{:>20}", "Nombre d'UE", nbUE);
  std::println("{:<20}{:>20.2f}", "Moyenne générale", moyenneGenerale);
  std::println("{:<20}{:>20.2f}", "Moyenne simple", moyenneSimple);
  std::println("{:<20}{:>20.2f}", "Note minimale", mini);
  std::println("{:<20}{:>20.2f}", "Note maximale", maxi);
  std::println("{:<20}{:>20.2f}", "Écart-type", ecartType);
  std::println("{:<20}{:>20}", "UE validées", validees);
  afficherLigne("Mention", uin::libelle(mention));
  afficherLigne("Décision", moyenneGenerale >= uin::seuilValidation
                                ? "Validé"
                                : "Non valide");
  std::println("{:-<45}", "");

  return EXIT_SUCCESS;
}