#ifndef SOUNDEX_H
#define SOUNDEX_H
#define LOGIC (i < len) && (sIndex < 4)
#define NULLCHECK code != '0' && code != soundex[sIndex - 1]

#include "Soundex.h"
#include <ctype.h>
#include <string.h>
char Is_L(char c){
    if(c == 'L')
        return '4';
}
char Is_R(char c){
    if(c == 'R')
        return '6';   
}
char Is_MN(char c){
    if(c == 'M' || c == 'N')
        return '5';   
}
char is_BFPV(char c)
{
	char bfpv[4]={'b','f','p','v'};
	int i;
	for(i=0;i<3;i++)
	{
		if(c == bfpv[i])
		return '1';
	}
	
}
char Is_CGJKQSXZ(char c)
{
	char cgjkqsxz[8]={'c','g','j','k','q','s','x','z'};
	int i;
	for(i=0;i<7;i++)
	{
		if(c == cgjkqsxz[i])
		return '2';
	}
}

char Is_DT(char c){
    if(c == 'D' || c == 'T')
        return '3';
    else return '0';
}
// char getSoundexCode(char c) {
//     c = toupper(c);
//     c = is_BFPV(toupper(c));
//     c = Is_CGJKQSXZ(toupper(c));
//     c = Is_DT(toupper(c));
//     c = Is_L(toupper(c));
//     c = Is_MN(toupper(c));
//     c = Is_R(toupper(c));
//     //c = Is_Vowel(toupper(c));
    
//     // switch (c) {
//     //     case 'B': case 'F': case 'P': case 'V': return '1';
//     //     case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
//     //     case 'D': case 'T': return '3';
//     //     case 'L': return '4';
//     //     case 'M': case 'N': return '5';
//     //     case 'R': return '6';
//     //     default: return '0'; // For A, E, I, O, U, H, W, Y
//     // }
    
//     return c;
// }
char getSoundexCode(char c) {
    c = toupper(c);
    char v = '0';
    
    
    // *(ptrArr+1) = is_BFPV(toupper(c));
    
    // *(ptrArr+2) = Is_CGJKQSXZ(toupper(c));
    // *(ptrArr+3) = Is_DT(toupper(c));
    // *(ptrArr+4) = Is_L(toupper(c));
    // *(ptrArr+5) = Is_MN(toupper(c));
    // *(ptrArr+6) = Is_R(toupper(c));
    static const char lookupTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', // A, B, C, D, E, F, G, H
        '0', '2', '2', '4', '5', '5', '0', '1', // I, J, K, L, M, N, O, P
        '2', '6', '2', '3', '0', '1', '0', '2', // Q, R, S, T, U, V, W, X
        '0', '2'                                // Y, Z
    };
    
    return lookupTable[c-65];
    
    //c = Is_Vowel(toupper(c));
    
    // switch (c) {
    //     case 'B': case 'F': case 'P': case 'V': return '1';
    //     case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
    //     case 'D': case 'T': return '3';
    //     case 'L': return '4';
    //     case 'M': case 'N': return '5';
    //     case 'R': return '6';
    //     default: return '0'; // For A, E, I, O, U, H, W, Y
    // }
    
    //return v;
}
void Check_Val(char *soundex, int sIndex, char code){
	
	if (NULLCHECK) {
            soundex[sIndex++] = code;
        }
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; LOGIC; i++) {
        char code = getSoundexCode(name[i]);
        Check_Val(soundex, sIndex, code);
	sIndex++;
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
