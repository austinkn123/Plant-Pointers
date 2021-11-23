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
    string plantName, flowerName, colorOfFlowers, isAnnualString;
    int plantCost, flowerCost;
    bool isAnnual;

    cout << "Enter \"plant\" or \"flower\" or enter -1 to quit: ";
    cin >> input;

    while (input != "-1") {
        // TODO: Check if input is a plant or flower
        //       Store as a plant object or flower object
        //       Add to the vector myGarden
        if (input == "plant")
        {
            Plant* myPlant = new Plant();
            cout << "Enter plant name: ";
            cin >> plantName;
            cout << "Enter plant cost: ";
            cin >> plantCost;
            cout << endl;

            myPlant->SetPlantName(plantName);
            myPlant->SetPlantCost(plantCost);

            myGarden.push_back(myPlant);
        }
        else if (input == "flower")
        {
            Flower* myFlower = new Flower();

            cout << "Enter flower name: ";
            cin >> flowerName;
            cout << "Enter flower cost: ";
            cin >> flowerCost;

            cout << "Is it annual (true or false): ";
            cin >> isAnnualString;
            if (isAnnualString == "true")
                isAnnual = true;
            else if (isAnnualString == "false")
                isAnnual = false;
            cout << "Enter flower color: ";
            cin >> colorOfFlowers;
            cout << endl;

            myFlower->SetPlantName(flowerName);
            myFlower->SetPlantCost(flowerCost);

            myFlower->SetPlantType(isAnnual);
            myFlower->SetColorOfFlowers(colorOfFlowers);

            myGarden.push_back(myFlower);
        }
        cout << "Enter \"plant\" or \"flower\" or enter -1 to quit: ";
        cin >> input;
        cout << endl;
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
