#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * Implementacia neorientovaneho grafu pomocou zoznamu susednosti
 */
class Graph {
private:
    vector<vector<int>> adjList;///< Zoznam susednosti
    /**
    * Preh¾adávanie grafu do håbky (DFS) z daného vrcholu a vráti ve¾kos komponenty, do ktorej danı vrchol patri.
    *
    * @param v Vrchol, z ktorého sa má zaèa preh¾adáva
    *
    * @param visited Vektor, ktorı uchováva informáciu o tom, èi bol danı vrchol u navštívenı
    *
    * @param component Vektor, do ktorého sa ukladajú vrcholy nájdené v rámci preh¾adávania
    *
    * @return Ve¾kos komponenty, do ktorej danı vrchol patrí
    */
    int DFS(int v, vector<bool>& visited, vector<int>& component);
    /**
    * Preh¾adávanie grafu do šírky (BFS) z daného štartovacieho vrcholu a vráti eccentricitu najvacsej komponente
    *
    * @param start Vrchol, z ktorého sa má zaèa preh¾adáva
    *
    * @return eccentricita
    */
    int findEccentricities(int start, vector<bool>& visited);
    /**
    * Nájdenie excentricít (vzdialeností od kadého vrcholu k najvzdialenejšiemu vrcholu) pre kadı vrchol v najväèšej komponente.
    *
    * @param radius Parameter pre uloenie najmenšej excentricity
    *
    * @param diameter Parameter pre uloenie najväèšej excentricity
    */
    void radiusdiameter(int& radius, int& diameter);
public:
    /**
     * Inicializovanie max_vertex_index neorientovaného grafu zo špecifikácie v textovom súbore
     *
     * Vytvorenie zoznamu susednosti do vektoru pomocou max_vertex_index
     *
     * Vytvorí graf zo špeficikácie v textovom subore
     *
     * @param path Cesta k súboru
     */
    Graph(string path);
    /**
    * Nevyaduje sa iadne uvo¾òovanie pamäte
    *
    * Pouívame vektor ktorı spravuje svoju vlastnú pamä(nie je potrebné uvo¾òova pamä v deštruktore
    */
    ~Graph();
    /**
     * Prida neorientovanou hranu do grafu.
     *
     * @param from Prvy vrchol
     * @param to Druhy vrchol
     */
    void AddEdge(int from, int to);
    /**
    * Najde najväèšiu komponentu v grafe a nájde jej polomer a priemer.
    *
    * Vypíše vısledky na štandardnı vıstup.
    */
    void PrintProperties();
};