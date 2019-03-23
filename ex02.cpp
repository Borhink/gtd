#include <string>
#include <limits.h>

#include <iostream>
#include <stdlib.h>
#include <time.h>

//Simulation hasNextCount
bool hasNextCount()
{
    return rand() % 365 == 0;
}

//Simulation getNextCount
bool getNextCount(std::string& date, int& nbVisitor)
{
    if (hasNextCount())
    {
        //Random date
        date = "";
        //Random visitor count
        nbVisitor = rand() % 10000001;
        
        return true;
    }

    return false;
}

//Simulation getWeekDayFromDate
int getWeekDayFromDate(std::string& /*date*/)
{
    return rand() % 7;
}

int getBestDay()
{
    long weekDays[7] = {0, 0, 0, 0, 0, 0, 0};
    int weekDaysSize = sizeof(weekDays) / sizeof(*weekDays);

    while (hasNextCount())
    {
        std::string date;
        int nbVisitor;

        getNextCount(date, nbVisitor);
        int dayID = getWeekDayFromDate(date);
        weekDays[dayID] += nbVisitor;
    }

    long bestDayVisitor = LONG_MAX;
    int bestDayID = 0;
    for (int i = 0; i < weekDaysSize; i++)
    {
        if (weekDays[i] < bestDayVisitor)
        {
            bestDayVisitor = weekDays[i];
            bestDayID = i;
        }
    }

    return bestDayID;
}

int main()
{
    srand(time(NULL));

    //Création d'un journal fictif pour les tests

    //Récupération du meilleur jour selon les résultats générés :
    int best = getBestDay();

    //Affichage de différentes data de repère

    //Affichage du jour calculé
    std::cout << "The best day is " << best << std::endl;
}


/*
** Pour les test, il faut essayer avec un journal :
**  -vide
**  -très chargé
**  -cas de référence si il y a
**  -avec beaucoup de dates/entrées similaire
**  -avec uniquement des dates/entrées similaire
**  -des cas un peu plus aléatoires
*/

/*
** Pour récupérer les meilleurs jours on pourrait:
**  -remplacer le tableau 'weekDays' par un tableau de structure contenant {int dayID, int nbVisitors}
**  -trier le tableau 'weekDays'
**  -renvoyer un tableau des N premiers élément, qui seront les meilleurs
*/