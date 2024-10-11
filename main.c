#include<stdio.h>
#include<stdint.h>

int32_t is_ascii(char str[]){ 
    for(int i=0;str[i]!='\0';i+=1){       //i=0,i!=0,i+=1
        if(str[i]>128||str[i]<0){         //is_not_ascci when certain str[i]<127||certain str[i]<0
        return 0;                         //if yes_it_is_not_ascci return 0;
        }
    }
    return 1;
}

int32_t capitalize_ascii(char str[]){
    int32_t ret=0; 
    for(int i=0; str[i] !='\0';i+=1){  //determain if str[i] is in range, a=97 z=122
        if(96<str[i]<123){
            str[i]=str[i]-32;          //if in the range, then each # -32
            ret+=1;
        } 
    }
    return ret;                                    
}

//Returns 1 for ASCII characters
//and -1 if byte is not a valid start byte.
int32_t width_from_start_byte(char start_byte){
    int i=0;
         //read through all characters
        if((start_byte & 0b10000000)== 0){        
            return 1;
        }
        else if ((start_byte & 0b11100000) == 0b11000000){
            return 2;
        } 
        else if((start_byte & 0b11110000) == 0b11100000){
            return 3;
        }
        else if((start_byte & 0b11111000) == 0b11110000){
            return 4;
        }    
    return -1;
}

//Takes a UTF-8 encoded string and returns the number of UTF-8 codepoints it represents.
//Returns -1 if there are any errors encountered in processing the UTF-8 string.
int32_t utf8_strlen(char str[]){
        int i=0;
        int len = 0;
        while(str[i]!='\0'){
            int width = width_from_start_byte(str[i]);
            if(width != -1){
                len+=1;
            }
            i+=1;
    } 
    return len;
}



int32_t codepoint_index_to_byte_index(char str[], int32_t cpi){
    int i=0; //Byte index
    int cur = 0;  //Current Index
    while(str[i]!=0){
        if(is_ascii(str[i])==1){  //if is ascii
            cur +=1;
        }
        else if(width_from_start_byte(str[i])==-1 &&width_from_start_byte(str[i+1])!=-1){                //if 
            cur+=1;
        }
        else if (width_from_start_byte(str[i])==-1 && width_from_start_byte(str[i+1])==0){
            cur += 1;
        }
        if(cur == cpi){
            return i;
        }
        i+=1;
    } 
    return -1;

}

//return(c1 & 0b00011111)*262144+(c2 & 0b00111111)*4096+(c3 & 0b00111111)*64+(c4 & 0b00111111);

int main(){
    // is_ascii
    printf("Is 🔥 ASCII? %d\n", is_ascii("🔥"));
    printf("Is abcd ASCII? %d\n", is_ascii("abcd"));

    // capitalized and count ret#
    char str[] = "abcd";
    int32_t ret = capitalize_ascii(str);
    printf("Capitalized String: %s\nCharacters updated: %d\n", str, ret);

    // width from the start byte
    char s[] = "Héy"; // same as { 'H', 0xC3, 0xA9, 'y', 0 },   é is start byte + 1 cont. byte
    printf("Width: %d bytes\n", width_from_start_byte(s[1])); // start byte 0xC3 indicates 2-byte sequence
    printf("Width: %d bytes\n", width_from_start_byte(s[2])); // start byte 0xA9 is a continuation byte, not a start byte
    
    //length of the codepoints
    char str1[] = "Joséph";
    printf("Length of string %s is %d\n", str1, utf8_strlen(str1));  // 6 codepoints, (even though 7 bytes)
    int idx = 4;
    //
    printf("Codepoint index %d is byte index %d\n", idx, codepoint_index_to_byte_index("Joséph", idx));

}