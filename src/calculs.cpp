#include "uincampus/calculs.hpp"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <numeric>

namespace uin {

[[nodiscard]] double somme(const std::vector<double> &valeurs) {
  return std::accumulate(valeurs.begin(), valeurs.end(), 0.0);
}

[[nodiscard]] double moyenne(const std::vector<double> &notes) {
  assert(!notes.empty());

  return somme(notes) / static_cast<double>(notes.size());
}

[[nodiscard]] double moyenne(const std::vector<double> &notes,
                             const std::vector<double> &coefficients) {
  assert(!notes.empty());
  assert(notes.size() == coefficients.size());

  const double totalCoefficients = somme(coefficients);
  assert(totalCoefficients > 0.0);

  return std::inner_product(notes.begin(), notes.end(), coefficients.begin(),
                            0.0) /
         totalCoefficients;
}

[[nodiscard]] Statistiques
calculerStatistiques(const std::vector<double> &notes) {
  assert(!notes.empty());

  const auto [mini, maxi] = std::ranges::minmax(notes);
  const double moy = moyenne(notes);

  const double sommeCarres = std::accumulate(notes.begin(), notes.end(), 0.0,
                                             [moy](double total, double note) {
                                               const double ecart = note - moy;
                                               return total + ecart * ecart;
                                             });

  const double ecartType =
      std::sqrt(sommeCarres / static_cast<double>(notes.size()));

  return {mini, maxi, moy, ecartType};
}

[[nodiscard]] int compterValidees(const std::vector<double> &notes,
                                  double seuil) {
  return static_cast<int>(std::ranges::count_if(
      notes, [seuil](double note) { return note >= seuil; }));
}

[[nodiscard]] double arrondir(double valeur, int decimales) {
  const double facteur = std::pow(10.0, decimales);
  return std::round(valeur * facteur) / facteur;
}

} // namespace uin