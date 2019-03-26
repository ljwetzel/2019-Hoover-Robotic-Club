#include <kipr/botball.h>
void turnleft();
void turnright();
void forward(int time);
void shovel();
void followline();
void reverse(int time);
void reverseRight();
void seeYellow();
int main()
{
    
    printf("Hello World\n");
    //black 3200-3800
    //grey:400-250
    //white: 200-170
    //turn right
    turnright();
    //forward
    forward(3000);
    //turn left
    turnleft();
    //move forward
    forward(2300);
    //turn left
    turnleft();
    followline();
    /*
    //open camera
    camera_open();
    camera_update();
    if (see yellow){
    	seeYellow();
    }
    
    //see yellow, move forward, left,forward, right, forward
    //if not, turn right n forward, reverse, reverse right, forward 
    //close camera
    //hit the yellow ball using the servos
    */
    return 0;
}
void seeYellow(){
    forward();
    turnleft();
    forward();
    turnright();
    forward();
}
void reverse(int time){
    motor(0,-100);
    motor(0, -100);
    msleep(time);
}

void reverseRight(){
    motor(0, 0);
    motor(3, -100);
    msleep(1250);
}

void turnleft() 
{
    motor(3, 0);
    motor(0, 100);
    msleep(1250);
    ao();
}
void turnright() {
    motor(3, 100);
    motor(0, 0);
    msleep(1250);
    ao();
    
}
void forward (int time) {
    motor(3, 100);
    motor(0, 100);
    msleep(time);
    ao();
}

void followline(){
    int counter = 0;
    while(counter<=350)
   {
    if(analog(0)>1000 && analog(0)<4000)
    {
    	motor(0, 50);
    	motor(3, 0);
        printf("see black, move left\n");
    }
       
     else 
     {
         motor(0,0);
         motor(3,50);
         printf("not black, go right\n");                 
     }  
     msleep(200);
   	 counter++;
     
     
    }
}