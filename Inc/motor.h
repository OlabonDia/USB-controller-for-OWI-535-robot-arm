#include "stm32f1xx_hal.h"
#include <string.h>
#include "main.h"
#include "math.h"
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern int USART_RX_STA;
extern uint8_t USART1_RX_BUF[];
extern uint8_t aRxBuffer1[1];
extern double pow(double,double);
int command2num(char* temp_command,const char* start_char,const char* end_char);
void Motor_Exec(void);
int ff_flag=1;
int M1_t,M2_t,M3_t,M4_t,M5_t,M6_t;//�ض�����趨��תʱ��
int M1_n,M2_n,M3_n,M4_n,M5_n,M6_n;//��ǰ�ض�����Ѿ���תʱ��
int M_v[6];//����ٶ�
int stop_flag=0xff;//��ֹ�˶���־λ
void set_speed(int set_flag,int speed);
void motor_tick_update(void);

