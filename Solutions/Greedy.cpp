//
// Created by mpore on 10/05/2023.
//

#include "Greedy.h"

#include <utility>
#include <algorithm>

/**
 * Constructor
 * @param cities
 */
Greedy::Greedy(std::vector<City> cities) : m_cities(std::move(cities)) {}

//TODO : à tester
/**
 * Give a greedy solution for a specific vector
 * @return
 */
std::vector<int> Greedy::resolve() {
    std::vector<int> solution;
    float keep;
    float tempo;
    int back;
    int next;

    const int nbTotCities = m_cities.size();
    solution.push_back(0);

    /* Tq solution.size != nbTotCities, faire
     *      On récupère la dernière valeur de solution
     *      On donne une valeur à keep (qui deviendra dist minimale)
     *
     *      Pour i, 0 -> nbTotCities, faire
     *          Si i n'est pas dans solution (prend aussi en compte si back == i=), faire
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
        back = solution.back();
        keep = 1000000;

        for (int i = 1; i < nbTotCities; ++i) {
            if (!std::count(solution.begin(), solution.end(), i)) {
                tempo = dist2Cities(m_cities[back], m_cities[i]);

                if (tempo < keep) {
                    keep = tempo;
                    next = i;
                }
            }
        }

        solution.push_back(next);
    }

    writeAnswerFile(solution);

    return solution;
}
