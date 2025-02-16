#include <stdio.h>

int main(){
    int age = 94;

    if(age>60){
        printf("You are a citizen and you can Drive");
    }
    else if(age>40){
        printf("You are elder and you can Drive");
    }
    else if(age>18){
        printf("You are young and you can Drive");
    }
    else{
        printf("You can mot Drive");
    }
    return 0;
}