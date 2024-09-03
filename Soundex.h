#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>
char Is_L(char c){
    if(c == 'L')
        return '4';
    else return '0';
}
char Is_R(char c){
    if(c == 'R')
        return '6';
    else return '0';
}
char Is_MN(char c){
    if(c == 'M' || c == 'N')
        return '5';
    else return '0';
}
char Is_Vowel(char c){
    if(c == 'A' || c == 'E' || c =='I' || c == 'O' || c == 'U')
        return '0';
    
}
char Is_BFPV(char c){
    if(c == 'B' || c == 'F' || c =='P' || c == 'V')
        return '1';
    else return '0';
}
char Is_CGJKQSXZ(char c){
    if(c == 'C' || c == 'G' || c =='J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z')
        return '2';
    else return '0';
}
char Is_DT(char c){
    if(c == 'D' || c == 'T')
        return '3';
    else return '0';
}
char getSoundexCode(char c) {
    //c = toupper(c);
    c = Is_BFPV(toupper(c));
    c = Is_CGJKQSXZ(toupper(c));
    c = Is_DT(toupper(c));
    c = Is_L(toupper(c));
    c = Is_MN(toupper(c));
    c = Is_R(toupper(c));
    c = Is_Vowel(toupper(c));
    
    // switch (c) {
    //     case 'B': case 'F': case 'P': case 'V': return '1';
    //     case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
    //     case 'D': case 'T': return '3';
    //     case 'L': return '4';
    //     case 'M': case 'N': return '5';
    //     case 'R': return '6';
    //     default: return '0'; // For A, E, I, O, U, H, W, Y
    // }
    
    return c;
}


void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
