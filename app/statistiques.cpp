#include "uincampus/regles.hpp"
#include "uincampus/saisie.hpp"

#include <algorithm>
#include <array>
#include <cmath>
#include <format>
#include <print>
#include <string>
#include <string_view>
#include <vector>

int main() {
  std::println("=== Statistiques d'une UE ===\n");

  const std::string nomUE = uin::lireTexte("Nom de l'UE : ");
  const int nombreEtudiants =
      uin::lireEntier("Nombre d'etudiants (1 a 200) : ", 1, 200);

  std::vector<double> notes;

  for (int i = 1; i <= nombreEtudiants; ++i) {
    notes.push_back(uin::lireNote(std::format("Note de l'etudiant {} : ", i)));
  }

  const double somme = [&notes]() {
    double total{0.0};

    for (double note : notes) {
      total += note;
    }

    return total;
  }();

  const double moyenne = somme / static_cast<double>(nombreEtudiants);

  const auto [minimum, maximum] =
      std::minmax_element(notes.begin(), notes.end());

  double sommeCarres{0.0};

  for (double note : notes) {
    const double ecart = note - moyenne;
    sommeCarres += ecart * ecart;
  }

  const double ecartType =
      std::sqrt(sommeCarres / static_cast<double>(nombreEtudiants));

  int admis{0};
  std::array<int, 5> effectifs{};

  for (double note : notes) {
    if (note >= uin::seuilValidation) {
      ++admis;
    }

    const auto mention = uin::mentionPour(note);
    ++effectifs[static_cast<std::size_t>(mention)];
  }

  const double pourcentage =
      100.0 * static_cast<double>(admis) / static_cast<double>(nombreEtudiants);

  constexpr std::array<std::string_view, 5> mentions{
      "Ajourné", "Passable", "Assez bien", "Bien", "Très bien"};

  std::println("\n========== RESULTATS ==========");
  std::println("UE : {}", nomUE);
  std::println("Nombre d'etudiants : {}", nombreEtudiants);
  std::println("Note minimale : {:.2f}", *minimum);
  std::println("Note maximale : {:.2f}", *maximum);
  std::println("Moyenne : {:.2f}", moyenne);
  std::println("Ecart-type : {:.2f}", ecartType);
  std::println("Nombre d'admis : {}", admis);
  std::println("Pourcentage d'admis : {:.2f} %", pourcentage);

  std::println("\n===== HISTOGRAMME DES MENTIONS =====");

  for (std::size_t i = 0; i < mentions.size(); ++i) {
    const std::string barre(static_cast<std::size_t>(effectifs[i]), '#');

    std::println("{:<15} | {} ({})", mentions[i], barre, effectifs[i]);
  }

  return 0;
}