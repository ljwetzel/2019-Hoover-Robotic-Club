#include <kipr/botball.h>

//Motor Ports
#define LEFTMOTOR 3
#define RIGHTMOTOR 0

//Sensor Ports
#define FRONTET 0
#define IRSENSOR 1

void turnleft();
void turnright();
void forward(int time);
void shovel();
void followline();
void drive(int leftspeed, int rightspeed);
void follow_line();
void turn_right();
/*
void reverse(int time);
void reverseRight();

*/void seeYellow();

int main()
{

    camera_open();

    printf("Hello World\n");
    //black 3200-3800
    //grey:400-250
    //white: 200-170
    //turn right

    turnright();
    //forward
    drive(100,100);
    msleep(2800);//2600
    //turn left
    turnleft();
    //move forward
    drive(100,100);
    msleep(1700);
    //forward(2000);
    //turn left
    turnleft();
    follow_line();
    printf("no follow\n");

    seeYellow();
    // msleep(1000);
    printf("end seeing yellow\n");

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

//yellow: 
void seeYellow()
{
    camera_update();
    int x = get_object_center_x(0,1);
    int y = get_object_center_y(0,1);
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    if(get_object_center_x(0,1) < 100 && get_object_center_x(0,1) >= 10 && get_object_center_y(0,1)<80)
    {
        turn_right();
        forward(500);
        turnleft();
        forward(300);
        printf("see yellow\n");
    }

    else
    {      
        drive(100,80);
        msleep(700);
        printf("no objects\n");
    }
    camera_close();
}
/*void reverse(int time){
    motor(0,-100);
    motor(0, -100);
    msleep(time);
}

void reverseRight(){
    motor(0, 0);
    motor(3, -100);
    msleep(1250);
}

*/
void drive (int leftspeed, int rightspeed)
{
    motor(LEFTMOTOR, leftspeed);
    motor(RIGHTMOTOR, rightspeed);
}

void follow_line()
{
    while(analog(FRONTET) < 1300) //ET at the front to see distance (1300)
    {
        if(analog(IRSENSOR) < 1600) // NOT ON BLACK TAPE
        {
            drive(100,0);//Turn right on black tape
            printf("Off black\n");
        }
        else //ON BLACK TAPE
        {
            drive(0,100);//Turn left on black tape
            printf("On Black\n");   
        }

    }
}
void turnleft() 
{
    motor(3, 0);
    motor(0, 100);
    msleep(1100);
    ao();
}
void turnright() {
    motor(3, 100);
    motor(0, 0);
    msleep(1100);
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
    while(counter<=84)
    {
        if(analog(0)>1000 && analog(0)<4000)
        {
            motor(0, 100);
            motor(3, 0);
            printf("see black, move left\n");
        }

        else 
        {
            motor(0,0);
            motor(3,100);
            printf("not black, go right\n");                 
        }  
        msleep(200);
        counter++;


    }
}

void turn_right()
{
    motor(3, 100);
    motor(0, 0);
    msleep(1500);
    ao();  
}