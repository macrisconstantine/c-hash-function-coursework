#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

/*function used to count the frequency of each letter in the sentence input by user*/
void countLetterFrequency(char *s){
    
    /*declaration of counter variable, current character variable, counted character array*/
    char current;
    float countedCharacters[26] = {0};
    int i, j;
    float total = 0;
    
    /*for loop that loops through the sentence*/
    for (i = 0; s[i] != '\0'; i++)
    {
        /*makes all characters lowercase and checks that they are a letter, then adds them into the characters array*/
        current = tolower(s[i]);
        if(current >= 'a' && current <= 'z'){
            countedCharacters[current - 'a']++;
            total++;
            }
    
    }
    printf("\n__________________________________________________\n");
    /*for loop that cycles through copied array and if statement checks if the value is zero*/
    for (i=0; i < 26; i++){
        if(countedCharacters[i] > 0){
            printf("%c (%.2f) |", tolower(i+'a'), (roundf((countedCharacters[i]/total) * 100)/100));
            /*for loop that cycles through copied array and prints out the character '-' for every 0.01 of its frequency*/
            for (j = (roundf((countedCharacters[i]/total) * 100)); j > 0; j--){
                printf("-");
            }
            printf("\n");
        }
    }
    printf("\n----------------------------BAR PLOT----------------------------");
    printf("\n       (Each '-' represents 1 letter instance out of 100) \n");
} 