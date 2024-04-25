#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
#include <unordered_set>

using namespace std;

// Дефинира се структура която представя държава
struct Country {
    string name;
    vector<Country*> neighbors;

    Country(string countryName) : name(countryName) {}
};

// Функцията Depth-First Search да намери път между две държави
bool dfs(Country* start, Country* destination, unordered_set<Country*>& visited) {
    // Ако текущата държава е дестинацията, пътят е намерен
    if (start == destination) {
        cout << start->name << " ";
        return true;
    }

    // Текущата държава се отбелязва като посетена
    visited.insert(start);

    // Преминава се през съседите на текущата държава
    for (Country* neighbor : start->neighbors) {
        // Ако съседът не е посетен,рекурсивно се извиква функцията dfs 
        if (visited.find(neighbor) == visited.end()) {
            if (dfs(neighbor, destination, visited)) {
                cout << start->name << " ";
                return true;
            }
        }
    }
    return false;
}

int main() {
    // Създаване на държавите
    Country* countryA = new Country("Germany");
    Country* countryB = new Country("Poland");
    Country* countryC = new Country("Ukraine");
    Country* countryD = new Country("Romania");
    Country* countryE = new Country("Bulgaria");

    // Връзки между държавите
    countryA->neighbors = {countryB, countryC};
    countryB->neighbors = {countryC};
    countryC->neighbors = {countryD};
    countryD->neighbors = {countryE};

    // Инициализация на началната държава и на държавата дестинация
    Country* startCountry = countryA;
    Country* destinationCountry = countryE;

    // Задава се да следи посетените държави по време на dfs
    unordered_set<Country*> visited;

    // DFS се изпълнява за да намери път между началната и целевата държава
    cout << "Path from " << startCountry->name << " to " << destinationCountry->name << ": ";
    if (dfs(startCountry, destinationCountry, visited)) {
        cout << endl;
    } else {
        cout << "No path found." << endl;
    }

    // Паметта се освобождава
    delete countryA;
    delete countryB;
    delete countryC;
    delete countryD;
    delete countryE;

    return 0;
}

