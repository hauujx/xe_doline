#include <AFMotor.h>
 /* su dung thu vien AFMotor dieu khien dong co L293D 
 http://k2.arduino.vn/img/2015/05/27/0/1406_882450-1432722684-0-af-motor.zip */
///
AF_DCMotor mt_headL (1,MOTOR12_64KHZ); // khoi tao dong co 1
AF_DCMotor mt_headR (2,MOTOR12_64KHZ); // ...               2
AF_DCMotor mt_tailL (3,MOTOR12_64KHZ); // ...               3
AF_DCMotor mt_tailR (4,MOTOR12_64KHZ); // ...               4
#define IRleft 13 
#define IRright 12
int Left= 0 ; 
int Right = 0; 
/// function 
void read_IR (void); // doc tin hieu hong ngoai 
void turn_Left(void) ; // quay trai 
void turn_Right(void) ; // quay phai 
void forward (void);    // di thang
void backward(void);    // lui


void read_IR ()
    {
       Left = digitalRead(IRleft);
       Right = digitalRead(IRright);
       Serial.println("IR trai : %d , IR phai : %d ",Left,Right);
       if ( Left == 0 && Right == 1)
            {
                turn_Left();
            }
        else if (Left == 1 && Right == 0)
           {
               turn_Right();
           }
        else if (Left == 1 && Right == 1)
           {
               forward();
           }
        else if (Left == 0 && Right == 0)
        {
            turn_Left ();
            
        }
        
        


}
void forward(){
        mt_headL.SetSpeed(120);
        mt_TailL.SetSpeed(120);
        mt_headL.run(FORWARD);
        mt_tailL.run(FORWARD);      // di thang
        mt_headR.run(FORWARD);
        mt_tailR.run(FORWARD); 
}
void turn_Right(){
        mt_headR.SetSpeed(50);
        mt_TailR.SetSpeed(50);
        mt_headL.run(FORWARD);
        mt_tailL.run(FORWARD);      // quay qua phai
        mt_headR.run(FORWARD);
        mt_tailR.run(FORWARD);
}

void turn_Left()
    {   
        mt_headL.SetSpeed(50);
        mt_TailL.SetSpeed(50);
        mt_headL.run(FORWARD);
        mt_tailL.run(FORWARD);      // quay qua trai
        mt_headR.run(FORWARD);
        mt_tailR.run(FORWARD);
    
}
void backward(){
        mt_headL.SetSpeed(120);
        mt_TailL.SetSpeed(120);
        mt_headL.run(BACKWARD);
        mt_tailL.run(BACKWARD);      // quay qua trai
        mt_headR.run(BACKWARD);
        mt_tailR.run(BACKWARD);

}
void setup() {
  
  Serial.begin(9600); // khai bao toc do Serial 
  Serial.println("program is running");
        mt_headL.SetSpeed(120);  // dat toc do dong co     
        mt_headR.SetSpeed(120);
        mt_tailL.SetSpeed(120);
        mt_tailR.SetSpeed(120);  
  
}
/*** main loop ***/
void loop() {

    read_IR();
}