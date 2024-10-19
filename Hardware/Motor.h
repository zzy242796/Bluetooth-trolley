#ifndef __MOTOR_H
#define __MOTOR_H

void Motor_Init(void);
void Motor1_SetSpeed(int8_t Speed);
void Motor2_SetSpeed(int8_t Speed);

void turn_right(int8_t Speed1,int8_t Speed2);
void forward(int8_t Speed1,int8_t Speed2);
void turn_lift(int8_t Speed1,int8_t Speed2);
void back(int8_t Speed1,int8_t Speed2);

#endif
