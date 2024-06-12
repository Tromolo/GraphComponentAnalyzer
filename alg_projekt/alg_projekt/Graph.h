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
    * Preh�ad�vanie grafu do h�bky (DFS) z dan�ho vrcholu a vr�ti ve�kos� komponenty, do ktorej dan� vrchol patri.
    *
    * @param v Vrchol, z ktor�ho sa m� za�a� preh�ad�va�
    *
    * @param visited Vektor, ktor� uchov�va inform�ciu o tom, �i bol dan� vrchol u� nav�t�ven�
    *
    * @param component Vektor, do ktor�ho sa ukladaj� vrcholy n�jden� v r�mci preh�ad�vania
    *
    * @return Ve�kos� komponenty, do ktorej dan� vrchol patr�
    */
    int DFS(int v, vector<bool>& visited, vector<int>& component);
    /**
    * Preh�ad�vanie grafu do ��rky (BFS) z dan�ho �tartovacieho vrcholu a vr�ti eccentricitu najvacsej komponente
    *
    * @param start Vrchol, z ktor�ho sa m� za�a� preh�ad�va�
    *
    * @return eccentricita
    */
    int findEccentricities(int start, vector<bool>& visited);
    /**
    * N�jdenie excentric�t (vzdialenost� od ka�d�ho vrcholu k najvzdialenej�iemu vrcholu) pre ka�d� vrchol v najv��ej komponente.
    *
    * @param radius Parameter pre ulo�enie najmen�ej excentricity
    *
    * @param diameter Parameter pre ulo�enie najv��ej excentricity
    */
    void radiusdiameter(int& radius, int& diameter);
public:
    /**
     * Inicializovanie max_vertex_index neorientovan�ho grafu zo �pecifik�cie v textovom s�bore
     *
     * Vytvorenie zoznamu susednosti do vektoru pomocou max_vertex_index
     *
     * Vytvor� graf zo �peficik�cie v textovom subore
     *
     * @param path Cesta k s�boru
     */
    Graph(string path);
    /**
    * Nevy�aduje sa �iadne uvo��ovanie pam�te
    *
    * Pou��vame vektor ktor� spravuje svoju vlastn� pam�(nie je potrebn� uvo��ova� pam� v de�truktore
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
    * Najde najv��iu komponentu v grafe a n�jde jej polomer a priemer.
    *
    * Vyp�e v�sledky na �tandardn� v�stup.
    */
    void PrintProperties();
};