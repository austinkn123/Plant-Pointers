#include "Plant.h"
#include "Flower.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// TODO: Define a PrintVector function that prints an vector of plant (or flower) object pointers

void PrintVector(vector<Plant*> myGarden);

int main(int argc, char* argv[]) {
    // TODO: Declare a vector called myGarden that can hold object of type plant pointer
    vector <Plant*> myGarden;
    string input;

    // TODO: Declare variables - plantName, plantCost, flowerName, flowerCost,
    //       colorOfFlowers, isAnnual
    string plantName, flowerName, colorOfFlowers;
    int plantCost, flowerCost;
    bool isAnnual;


    cin >> input;

    while (input != "-1") {
        // TODO: Check if input is a plant or flower
        //       Store as a plant object or flower object
        //       Add to the vector myGarden
        if (input == "plant")
        {
            Plant* myPlant = new Plant();

            cin >> plantName;
            cin >> plantCost;

            myPlant->SetPlantName(plantName);
            myPlant->SetPlantCost(plantCost);

            myGarden.push_back(myPlant);
        }
        else if (input == "flower")
        {
            Flower* myFlower = new Flower();

            cin >> flowerName;
            cin >> flowerCost;

            cin >> isAnnual;
            cin >> colorOfFlowers;

            myFlower->SetPlantName(flowerName);
            myFlower->SetPlantCost(flowerCost);

            myFlower->SetPlantType(isAnnual);
            myFlower->SetColorOfFlowers(colorOfFlowers);

            myGarden.push_back(myFlower);
        }
        cin >> input;
    }

    // TODO: Call the method PrintVector to print myGarden
    PrintVector(myGarden);


    for (size_t i = 0; i < myGarden.size(); ++i) {
        delete myGarden.at(i);
    }

    return 0;
}

void PrintVector(vector<Plant*> myGarden)
{
    for (int i = 0; i < myGarden.size(); i++)
    {
        myGarden.at(i)->PrintInfo();
        cout << endl;
    }
}