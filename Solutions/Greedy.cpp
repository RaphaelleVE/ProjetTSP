//
// Created by mpore on 10/05/2023.
//

#include "Greedy.h"
#include <utility>
#include <algorithm>
#include <limits>

/**
 * Constructor
 * @param cities
 */
Greedy::Greedy(std::vector<City> cities) : m_cities(std::move(cities)) {}

/**
 * Give a greedy solution for a specific vector
 * @return
 */
std::vector<City> Greedy::resolve() {
    std::vector<City> solution;
    std::vector<City> copyCities = m_cities;

    const int nbTotCities = copyCities.size();
    solution.push_back(copyCities[0]);
    copyCities.erase(copyCities.begin());

    /* Tq solution.size != nbTotCities, faire
     *      On récupère la dernière valeur de solution
     *      On donne une valeur à keep (qui deviendra dist minimale)
     *
     *      Pour i, 0 -> nbTotCities, faire
     *          Si i n'est pas dans solution (prend aussi en compte si back == i), faire
     *              On calcule la distance entre back et cities(i)
     *              Si la distance est < à keep, faire
     *                  keep prend la valeur et on sauvegarde le numéro de la ville
     *              Fin Si
     *          Fin Si
     *      Fin Pour
     *
     *      On ajoute la ville la + petite à solution
    */
    while (solution.size() != nbTotCities) {
        City startCity = solution.back();
        int minDistance = std::numeric_limits<int>::max();
        City nextCity;

        for (int i = 0; i < copyCities.size(); ++i) {
            int currentDistance = dist2Cities(startCity, copyCities[i]);

            if (currentDistance < minDistance) {
                minDistance = currentDistance;
                nextCity = copyCities[i];
            }
        }

        int indexNextCity = getIndex(copyCities, nextCity);

        solution.push_back(nextCity);
        copyCities.erase(copyCities.begin() + indexNextCity);
    }

    writeAnswerFile(solution);

    return solution;
}
