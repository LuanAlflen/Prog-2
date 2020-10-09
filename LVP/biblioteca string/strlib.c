#include "strlib.h"
#include <stdio.h>

int     str_length (const char *str){
    int i=0, lenght=0;
    if(str){
        while (str[i] != '\0'){
            lenght++;
            i++;
        }
    }else{
        return -1;
    }

    return lenght;
}

char*	str_duplicate	(const char *str){
    char *str2;
    int tam;
    if(str){
        tam = str_length(str);
        str2 = (char*) malloc(sizeof(char)*(tam+1));
        for (int i = 0; i < tam; ++i) {
            str2[i] = str[i];
        }
        str2[tam] = '\0';
        return str2;
    }
    str2 = NULL;

    return str2;
}

int		str_compare		(const char *stra, const char *strb){

    int i = 0;
    while (stra[i] != '\0' || strb[i] != '\0'){
        if(stra[i] > strb[i]){
            return 1;
        }
        if(stra[i] < strb[i]){
            return -1;
        }
        i++;
    }
    return 0;
}

int 	str_reverse 	(char *str){
    if(str == NULL){
        return 0;
    }else{
        char *stra = (char*) malloc(sizeof(char)* (str_length(str)+1));
        for(int i=0; i<str_length(str); i++){
            stra[i] = str[str_length(str) - i -1];
        }
        stra[str_length(str)] = '\0';
        for (int i = 0; i < str_length(str); ++i) {
            str[i] = stra[i];
        }
        //printf("%s, alooo\n", str);
        free(stra);
        return 1;
    }
}

int		str_upper 		(char *str){
    if(str){
        char alfabetomin[] =  "abcdefghijklmnopqrstuvwxyz", alfabetomai[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int count=0;

        for (int i = 0; i < str_length(str); ++i) {
            for (int j = 0; j < 26; ++j) {
                if(str[i] == alfabetomin[j]){
                    count++;
                    str[i] = alfabetomai[j];
                }
            }
        }
        return count;
    }else{
        return -1;
    }
}

int		str_lower 		(char *str){
    if(str){
        char alfabetomin[] =  "abcdefghijklmnopqrstuvwxyz", alfabetomai[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int tam_str = str_length(str), count=0;

        for (int i = 0; i < tam_str; ++i) {
            for (int j = 0; j < 26; ++j) {
                if(str[i] == alfabetomai[j]){
                    count++;
                    str[i] = alfabetomin[j];
                }
            }
        }
        return count;
    }else{
        return -1;
    }
}

int 	str_copy		(char *dst, const char *src){
    if(dst == NULL || src == NULL){
        return -1;
    }else{
        if(str_length(dst) >= str_length(src)){
            for (int i = 0; i < str_length(src); ++i) {
                dst[i] = src[i];
            }
            dst[str_length(src)] = '\0';
            return 1;
        }else{
            return 0;
        }
    }
}

char* 	str_concatenate (const char *stra, const char *strb) {
    char *strc;
    if (stra == NULL && strb == NULL) {
        strc = NULL;
        return strc;
    }else{
        if(stra == NULL){
            strc = str_duplicate(strb);
            return strc;
        }
        if(strb == NULL){
            strc = str_duplicate(stra);
            return strc;
        }else{
            //nenhum é nulo
            strc = (char*) malloc(sizeof(char) * (str_length(strb) + str_length(stra) + 1)); //+1 por causa '\0' adicionado
            for (int i = 0; i < (str_length(strb) + str_length(stra)); ++i) {
                if(i<str_length(stra)){
                    strc[i] = stra[i];
                }else{
                    strc[i] = strb[i-(str_length(stra))];
                }
            }
            strc[str_length(strb) + str_length(stra)] = '\0';
            return strc;
        }
    }
}

int 	str_find_first	(const char *str, const char c){
    if(str != NULL){
        for (int i = 0; i < str_length(str); ++i) {
            if(str[i] == c){
                return i;
            }
        }
        return -1;
    }else{
        return -1;
    }
}

int 	str_find_last 	(const char *str, const char c){
    if(str != NULL){
        for (int i = str_length(str); i >=0 ; --i) {
            if(str[i] == c){
                return i;
            }
        }
        return -1;
    }else{
        return -1;
    }
}

int 	str_count_words (const char *str){
    if(str){
        int count=0, tem_espaco;
        tem_espaco = str_find_first(str, ' ');
        if(tem_espaco == -1){
            if(str_length(str) == 0){
                return 0;
            }else{
                count++;
            }
        }else{
            for (int i = 0; i < str_length(str); ++i) {
                while (str[i] != ' ' && i <= str_length(str)){
                    if(i==str_length(str)){
                        if(str[i] != ' '){
                            count++;
                        }
                        i++;
                    }else{
                        if(str[i+1] == ' '){
                            count++;
                            i++;
                        }else{
                            i++;
                        }
                    }
                }
            }
        }

        return count;
    }
    return -1;
}
