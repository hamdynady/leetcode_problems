char* below_20[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                "Seventeen", "Eighteen", "Nineteen"};
char* tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char* thausand[] = {"", "Thousand", "Million", "Billion"};

void helper(int num, char* result){
    if(num == 0){
        return;
    }
    if(num < 20){
        strcat(result,below_20[num]);
        strcat(result," ");
    }else if(num >= 20 && num <100){
        strcat(result, tens[num/10]);
        strcat(result," ");
        helper(num%10,result);
    }else{
        strcat(result, below_20[num/100]);
        strcat(result," Hundred ");
        helper(num%100,result);
    }
}

void removeEndSpaces(char* str) {
    int length = strlen(str);
    int end = length - 1;

    // Find the last non-space character from the end
    while (end >= 0 && isspace(str[end])) {
        end--;
    }

    // Add null-terminating character to remove trailing spaces
    str[end + 1] = '\0';
}

char * numberToWords(int num){
    if (num == 0) {
        return "Zero";  // Special case: zero
    }
    char *result = (int*)(malloc(100 *  sizeof(int))); // Allocate memory for the result
    result[0] = '\0';// Initialize result as an empty string
    
    int i =0; // Index for thousands array
    
    while(num>0){
        if(num % 1000 != 0){
            char temp[100] = "";// Temporary string for each three-digit segment
            helper(num%1000,temp);
            strcat(temp,thausand[i]);
            strcat(temp, " ");
            strcat(temp, result);
            strcpy(result, temp); // Update the result
        }
        num /= 1000;  // Move to the next three-digit segment
        i++;// Increment the thousands array index
    }
    removeEndSpaces(result);
    return result;
} 