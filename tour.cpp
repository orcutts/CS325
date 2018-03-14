/*
* File:   tour.cpp
* Author: orcutts
*/

#include <iostream>
#include <algorithm>
#include <random>
#include <array>
#include <chrono>
#include "tour.hpp"
#include "tspCity.hpp"
#include "tspFileHandler.hpp"

// Creates a random individual													
void Tour::generateIndividual() {
	// Loop through all our destination cities and add them to our tour
	for (int i = 0; i < tourSize(); i++) {		
		setCity(i, getCity(i));
	}

	// Randomly reorder the tour
	//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();			//Next two lines were the code we looked at Sunday evening - in hangout chat
	//std::shuffle(*thisTour.begin()), thisTour.end(), std::default_random_engine(seed));
	//std::random_shuffle(&thisTour[0], &thisTour[cityIndex]);
	std::random_shuffle(&thisTour[0], &thisTour[tourSize()]);  //**FIXME**
}

// Sets a city in a certain position within a tour	--DONE
void Tour::setCity(int tourPosition, tspCity thisCity) {
	**FIXME** = thisCity;
	fitness = 0;
	distance = 0;
}

// Gets the total distance of the tour
int Tour::getDistance() {
	if (distance == 0) {
		int tourDistance = 0;
		// Loop through our tour's cities
		for (int i = 0; i < tourSize(); i++) {
			// Get city we're travelling from
			tspCity fromCity = getCity(i);						
			// City we're travelling to
			tspCity destinationCity;										
			// Check we're not on our tour's last city, if we are set our 
			// tour's final destination city to our starting city
			if (i + 1 < tourSize()) {
				destinationCity = getCity(i + 1);
			}
			else {
				destinationCity = getCity(0);
			}
			// Get the distance between the two cities
			tourDistance += fromCity.distanceTo(destinationCity);		//missing pointer  
		}
		distance = tourDistance;
	}
	return distance;
}

// Gets a city from the tour
tspCity Tour::getCity(int tourPosition) {
	return Tour[tourPosition];
}

// Gets the tours fitness
double Tour::getFitness() {
	if (fitness == 0) {
		fitness = 1 / (double)getDistance();
	}
	return fitness;
}

//Get number of cities on our tour
int Tour::tourSize() {
	return cityIndex;
}

// Check if the tour contains a city
bool Tour::containsCity(tspCity thisCity) {
	for (int i = 0; i < tourSize(); i++) {
		if (/**FIXME**/ == thisCity.getId())	//hmmmm
			return true;
	}
	return 0;
}
