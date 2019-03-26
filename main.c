#include <kipr/botball.h>

int main()
{
    printf("Hello World\n");
    while(1){
        motor(0, 50);
        motor(3, 50);
        if (analog(0)>2000){
            motor(0, 0);
            motor(3, 50);
        } 
    }
    return 0;
}
