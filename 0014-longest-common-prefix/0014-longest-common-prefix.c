char * longestCommonPrefix(char ** strs, int strsSize){
  int min_len= strlen(strs[0]);
    int index =0;
    int i,j;
    for(i=0; i<strsSize; i++){
        int len = strlen(strs[i]);
        if(len < min_len){
            min_len = len;
        }
    }
    /*Allocate memory for the common prefix result*/
    char *result = (char*)malloc((min_len+1)*sizeof(char));
    for(i=0;i<min_len;i++){
        char c = strs[0][i];
        for(j=0;j<strsSize;j++){
            if(strs[j][i] != c){
                result[index] = '\0';
                return result;
            }
        }
        result[index] = c;
        index++;
    }

    result[index] = '\0';
    return result;
}