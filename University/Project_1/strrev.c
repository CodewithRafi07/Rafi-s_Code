#include <stdio.h>
#include <string.h>

int main() {
    char str[100] = "Najmul Hossain!";
    
    // Reverse the string using strrev
    strrev(str);
    
    printf("Reversed string: %s\n", str);
    
    return 0;
}
