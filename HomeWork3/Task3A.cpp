// Compiled with g++ 5.4.0 on Ubuntu 16.04 64 bit
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int MAX_STRING_SIZE = 1024;

size_t strlen(const char * str){
    size_t length = 0;
    while(*str != '\0'){
        length++;
        str++;
    }
    return length;
}
size_t strlenRec(const char * str){
    if ((*str == '\0')||(*str == ')')) return 0; // ')' needed for counting length in the bracets
    return strlenRec(++str) + 1; // str++ would end up in infinite recursion :)
}

char * strcpy(char * dest, const char * src){
	size_t i = 0;
	while (src[i]) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

int strcmp(const char* text1, const char* text2){
    while (*text1 != '\0' && *text1 == *text2){
        text1++;
        text2++;
    }
    return *text1 - *text2;
}

char * strcat(char * destination, const char * source){
    size_t destinationSize = strlen(destination);
    size_t i = 0;
    while(*source != '\0'){
        destination[destinationSize++] = source[i];
        destinationSize++;
        i++;
    }
    destination[destinationSize] = '\0';
    return destination;
}

char * strdup(char * str, char *& pointer, size_t size){
    char * dest = new (std::nothrow) char[strlen(str) + size + 1];
    if(str){ strcpy(dest, str);
    } else {
        cout << "Memery allocation fail";
    }
    int offset = pointer - str;
    pointer = dest + offset;
    delete [] str; // Not included in the standard definition but could prove usefull
    return dest;
}

// *& in order for the pointer of the decom string to be always at the end even after nesteted recursion
// The implemented recursion is tree-like and recomputing values but im too lazy to it properly :(
void decompress(char * com, char *& decom, char * decomStart){
    if(*com == '\0') *decom = '\0';
    if ((*com != '\0')&&(*com != ')')){
        if(*com >= 'A' && *com <= 'Z'){
            *decom = *com;
            decompress(++com, ++decom, decomStart);
        } else { //Found a number followed by '('
            int dupCount = *com; // Number of times to copied - 1 because we already have it one time
            size_t buffLength = strlenRec(com+2);// Length of the string in the brackets
            if(*com != '0' ){
                decomStart = strdup(decomStart, decom, dupCount * buffLength ); // Allocating more memory
                decompress(com+2, decom, decomStart);
                *com -= 1;
                decompress(com, decom, decomStart);
            } else {
                decompress(com+(buffLength + 3), decom, decomStart);
            }
        }
    }
    cout << decomStart << endl;
    //Mostly test with ABC2(XY) - At some point after the recursion has found '\0'
    // when the decomStart is ok and couts valid values something happens when
    // backtrasing and suddenly everything fucks up.
}

int main(){

    char compressedString[MAX_STRING_SIZE];

    cout << "Enter compressed string: " << endl;
    cin.getline(compressedString, MAX_STRING_SIZE);

    char* decompressedString = new (std::nothrow) char[strlen(compressedString)+1];
    if (!decompressedString) cout << "Allocation fail" << endl;

    char * temp = decompressedString;

    cout << compressedString << "  ->  ";

    decompress(compressedString, temp, decompressedString);

    cout << decompressedString << endl;

    delete [] decompressedString;
    return 0;
}
