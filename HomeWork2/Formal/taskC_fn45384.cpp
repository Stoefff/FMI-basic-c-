// Compiled with g++ 5.4.0 on Ubuntu 16.04 64 bit
// Using "g++ -std=c++11 Bitmap.cpp" so the header could compile
#include "Bitmap.h"
#include <iostream>
#include <cmath>

typedef unsigned int uint;

const size_t MAX_SIZE = 100000;
const char fileName[9] = "test.bmp";

void cutRow(uint (&image)[MAX_SIZE], uint & width, uint & height, int & row);
void cutColumn(uint (&image)[MAX_SIZE], uint & width, uint & height, int & column);
bool areColorsClose(uint & backgroundColor, uint & currentColor);

//White color: 4294967295

int main(){

	uint width, height, image[MAX_SIZE], backgroundColor;
	int rval;

	// LoadBitmap() overwrites image, width, height
	rval = LoadBitmap(fileName, image, MAX_SIZE, width, height);
	if (rval != ALL_OK){
		std::cerr << "Cannot load image data from test.bmp! Error code " << rval << "\n";
		return 1;
	}

	std::cout << "Enter background color";
	std::cin >> backgroundColor; // Could be in dec, hex or both??

	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			if (areColorsClose(backgroundColor, image[(width * i) + j])==0) break;
			//if (image[(width * i) + j] != backgroundColor) break;
			if (j == (width - 1)) cutRow(image, width, height, i);

		}
	}
	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			if (areColorsClose(backgroundColor, image[(width * j) + i])==0) break;
			//if(image[(width * j) + i] != backgroundColor) break;
			if (j == (height - 1)) cutColumn(image, width, height, i);
		}
	}

	rval = SaveBitmap("test_new.bmp", image, width, height);

	if (rval != ALL_OK)
	{
		std::cerr << "Cannot save image data to test_new.bmp! Error code " << rval << "\n";
		return 2;
	}

    return 0;
}

void cutRow(uint (&image)[MAX_SIZE], uint & width, uint & height, int & row){
	for (int i = (row * width); i < ((height * width) - width); i++){
		image[i] = image[i + width];
	}
	height--;
	row--;
}

/* Could be done like this too
void cutRow(uint (&image)[MAX_SIZE], uint & width, uint & height, int & row){
	for(int i = row; i < (height-1); i++){
		for(int j = 0 ; j < width; j++){
			image[(width*i) + j] = image[(width*(i+1)) + j];
		}
	}
	height--;
	row--;
}
*/

void cutColumn(uint (&image)[MAX_SIZE], uint & width, uint & height, int & column){
	for(int i = column; i < ((width * height) - height); i+=(width-1)){
		for (int j = i; j < ((width * height) - 1); j++){
			image[j]=image[j+1];
		}
	}
	width--;
	column--;
}

//Euclidian Alogorithm: if (distance > 43) => close colors
// https://en.wikipedia.org/wiki/Color_difference
bool areColorsClose(uint & backgroundColor, uint & currentColor){
	const uint allowedDistance = 43; // 10% of the max Euclidian sum(443) is 43

	if (backgroundColor == currentColor) return true;

	uint deltaG = (backgroundColor & 0x0000FF00 ) - (currentColor & 0x0000FF00);
	deltaG = pow(deltaG, 2);
	uint deltaR = (backgroundColor & 0x00FF0000 ) - (currentColor & 0x00FF0000);
	deltaR = pow(deltaR, 2);
	uint deltaB = (backgroundColor & 0x000000FF ) - (currentColor & 0x000000FF);
	deltaB = pow(deltaB, 2);
	uint distance = deltaB + deltaR + deltaG;
	distance = sqrt(distance);

	return (distance <= allowedDistance) ? true : false;

}
