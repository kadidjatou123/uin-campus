

#include "uincampus/saisie.hpp"
#include "uincampus/regles.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

namespace uin {

namespace {

// Résultats des conversions internes.
struct EntierLu {
  bool valide;
  int valeur;
};

struct ReelLu {
  bool valide;
  double valeur;
};

// Fonctions internes à ce fichier.
std::string lireLigne(std::string_view invite) {
  std::cout << invite;

  std::string ligne;
  std::getline(std::cin, ligne);

  return ligne;
}

[[nodiscard]] EntierLu estEntierStrict(const std::string &texte) {
  std::istringstream flux{texte};
  int valeur{};
  char reste{};

  const bool valide = static_cast<bool>(flux >> valeur) && !(flux >> reste);

  return {valide, valeur};
}

[[nodiscard]] ReelLu estReelStrict(std::string texte) {
  for (char &c : texte) {
    if (c == ',') {
      c = '.';
    }
  }

  std::istringstream flux{texte};
  double valeur{};
  char reste{};

  const bool valide = static_cast<bool>(flux >> valeur) && !(flux >> reste);

  return {valide, valeur};
}

} // namespace

std::string lireTexte(std::string_view invite) { return lireLigne(invite); }

int lireEntier(std::string_view invite, int min, int max) {
  while (std::cin) {
    const std::string ligne = lireLigne(invite);
    const auto [valide, valeur] = estEntierStrict(ligne);

    if (!valide) {
      std::cout << "Saisie invalide : entrez un nombre entier.\n";
    } else if (valeur < min || valeur > max) {
      std::cout << "La valeur doit être comprise entre " << min << " et " << max
                << ".\n";
    } else {
      return valeur;
    }
  }

  return min;
}

double lireNote(std::string_view invite) {
  while (std::cin) {
    const std::string ligne = lireLigne(invite);
    const auto [valide, note] = estReelStrict(ligne);

    if (!valide) {
      std::cout << "Saisie invalide : entrez un nombre "
                   "(ex. 12.5 ou 12,5).\n";
    } else if (!estNoteValide(note)) {
      std::cout << "La note doit être comprise entre " << noteMin << " et "
                << noteMax << ".\n";
    } else {
      return note;
    }
  }

  return noteMin;
}

} // namespace uin