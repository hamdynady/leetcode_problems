char * intToRoman(int num){
    /*declares an array called symbols that stores pointers to constant characters.*/
    const char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    const int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    
    char *result = (char*)malloc(20 * sizeof(char));
    /*strcat works by finding the null-terminating character ('\0') in the destination.*/
    result[0] = '\0';
    
    for(int i=0;i < 13; i++){
       while(num >= value[i]){
    
/*- char* strcat(char* destination, const char* source);
- destination is a pointer to the string where the resulting concatenated string will be stired. It must be large enough to accommodate the concatenated string.
- source is a pointer to the string that will be appended to the destination string.
*/
          strcat(result,symbols[i]);
          num -= value[i];
       } 
    }
    return result;
}