#include <stdio.h>

int main(){
    float radius , Area, volume , height;

    printf("Enter Radius: ");
    scanf("%f" , &radius);

    printf("Enter Height: ");
    scanf("%f" , &height);
    

    Area =  (3.14*radius*radius);
    printf("The area of circle with radius %.2f is %.2f\n", radius, Area);

    volume = (3.14*radius*radius*height);
    printf("The volume of the cylinder with radius %.2f and height %.2f is %.2f\n", radius, height, volume);
    return 0;
}