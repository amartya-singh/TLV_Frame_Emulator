/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: This header file is common for all the file in this project.
 * @file commons.h
 * @brief This header file is included in all the c files
 *
 * This is project commons header file.
 *
 * Author       - Amartya Singh
 *******************************************************************************
 *
 * History
 *
 * March/2/2021, Amartya Singh, Completed TLV Frame Emulator
 *
 * Feb/2/2021, Amartya Singh, Created (TLV Frame Emulator)
 *
 ******************************************************************************/

#ifndef COMMONS_H_
#define COMMONS_H_

/******************
* Includes
*******************/

#include <stdio.h>
#include <string.h>

/*************************
 * Defines
 *************************/

/* For Set Command Response */

#define SUCCESS 0x00            
#define FAILED 0xFF
#define MAX_VALUE_SIZE 24

/**************************************
 * Structures, Enumerations, Typedefs
 *************************************/

typedef unsigned char BYTE;
typedef unsigned short int BYTE_2;
typedef unsigned int BYTE_4;

/* Command ID indexing */
enum Command_ID
{
    /*Advertising Frequency*/

    SET_ADV_FREQ = 0x10,
    GET_ADV_FREQ = 0x11,

    NORMAL_ADV_FREQ = 0x12,
    CHECKIN_ADV_FREQ = 0x13,
    HIE_ADV_FREQ = 0x14,
    ALERT_ADV_FREQ = 0x15,

    /*Advertising Timeout*/

    SET_ADV_TIMEOUT = 0x20,
    GET_ADV_TIMEOUT = 0x21,

    NORMAL_ADV_TIMEOUT = 0x22,
    CHECKIN_ADV_TIMEOUT = 0x23,
    HIE_ADV_TIMEOUT = 0x24,
    ALERT_ADV_TIMEOUT = 0x25,

    /*Accelerometer Configuration*/

    SET_ACC_CONFIG = 0x30,
    GET_ACC_CONFIG = 0x31,

    ACC_SCALE = 0x32,
    ACC_WAKEUP_THRESHOLD = 0x33,

    /*Impact Configuration*/

    SET_IMPACT_CONFIG = 0x40,
    GET_IMPACT_CONFIG = 0x41,

    EMFIT_SENSING_THRESHOLD = 0x42,
    EMFIT_SAMPLE_RATE = 0x43,
    EMFIT_TOTAL_SAMPLE = 0x44,

    /*General Device Configuration*/

    SET_DEVICE_CONFIG = 0x50,
    GET_DEVICE_CONFIG = 0x51,

    CHECKIN_INTERVAL = 0x52,
    INACTIVE_TIMEOUT = 0x53,

    /*HIE Configuration*/

    SET_HIE_CONFIG = 0x60,
    GET_HIE_CONFIG = 0x61,

    HIE_QUEUE_SIZE = 0x62,
    HIE_THRESHOLD = 0x63,
    HIE_TIMEOUT = 0x64,
};

/* For Range Validation */
enum Range
{
    /*Advertising Frequency*/

    MAX_NORMAL_ADV_FREQ = 0x07D0,
    MIN_NORMAL_ADV_FREQ = 0x0A,

    MAX_CHECKIN_ADV_FREQ = 0x07D0,   
    MIN_CHECKIN_ADV_FREQ = 0x0A,

    MAX_HIE_ADV_FREQ = 0x07D0,
    MIN_HIE_ADV_FREQ = 0x0A,

    MAX_ALERT_ADV_FREQ = 0x07D0,
    MIN_ALERT_ADV_FREQ = 0x0A,

    /*Advertising Timeout*/

    MAX_NORMAL_ADV_TIMEOUT = 0x02BF20,
    MIN_NORMAL_ADV_TIMEOUT = 0x2710,

    MAX_CHECKIN_ADV_TIMEOUT = 0x02BF20,
    MIN_CHECKIN_ADV_TIMEOUT = 0x2710,

    MAX_HIE_ADV_TIMEOUT = 0x02BF20,
    MIN_HIE_ADV_TIMEOUT = 0x2710,

    MAX_ALERT_ADV_TIMEOUT = 0x02BF20,
    MIN_ALERT_ADV_TIMEOUT = 0x2710,

    /*Accelerometer Configuration*/

    ACC_SCALE_2 = 0x02,
    ACC_SCALE_4 = 0x04,
    ACC_SCALE_8 = 0x08,
    ACC_SCALE_16 = 0x10,

    MAX_ACC_WAKEUP_THRESHOLD_2 = 0x07D0,
    MAX_ACC_WAKEUP_THRESHOLD_4 = 0x0FA0,
    MAX_ACC_WAKEUP_THRESHOLD_8 = 0x1F40,
    MAX_ACC_WAKEUP_THRESHOLD_16 = 0x3E80,

    MIN_ACC_WAKEUP_THRESHOLD = 0x00,

    /*Impact Configuration*/

    MAX_EMFIT_SENSING_THRESHOLD = 0x4E20,
    MIN_EMFIT_SENSING_THRESHOLD = 0x00,

    MAX_EMFIT_SAMPLE_RATE = 0x4E20,
    MIN_EMFIT_SAMPLE_RATE = 0x00,

    MAX_EMFIT_TOTAL_SAMPLE = 0x4E20,
    MIN_EMFIT_TOTAL_SAMPLE = 0x00,

    /*General Device Configuration*/

    MAX_CHECKIN_INTERVAL = 0x07D0,
    MIN_CHECKIN_INTERVAL = 0x10,

    MAX_INACTIVE_TIMEOUT = 0x02BF20,
    MIN_INACTIVE_TIMEOUT = 0x2710,

    /*HIE Configuration*/

    MAX_HIE_QUEUE_SIZE = 0xFF,
    MIN_HIE_QUEUE_SIZE = 0x00,

    MAX_HIE_THRESHOLD = 0xFF,
    MIN_HIE_THRESHOLD = 0x00,

    MAX_HIE_TIMEOUT = 0x02BF20,
    MIN_HIE_TIMEOUT = 0x2710,
};

/* For Length Validation of Input Frame*/
enum Command_Length
{
    /*Length of Get Command*/
    LENGTH_GET_CMD = 0x00,

    /*Length of Set Command*/

    /*Advertising Frequency*/
    LENGTH_ADV_FREQ = 0x18,
    LENGTH_NORMAL_ADV_FREQ = 0x04,
    LENGTH_CHECKIN_ADV_FREQ = 0x04,
    LENGTH_HIE_ADV_FREQ = 0x04,
    LENGTH_ALERT_ADV_FREQ = 0x04,

    /*Advertising Timeout*/
    LENGTH_ADV_TIMEOUT = 0x18,
    LENGTH_NORMAL_ADV_TIMEOUT = 0x04,
    LENGTH_CHECKIN_ADV_TIMEOUT = 0x04,
    LENGTH_HIE_ADV_TIMEOUT = 0x04,
    LENGTH_ALERT_ADV_TIMEOUT = 0x04,

    /*Accelerometer Configuration*/
    LENGTH_ACC_CONFIG = 0x07,
    LENGTH_ACC_SCALE = 0x01,
    LENGTH_ACC_WAKEUP_THRESHOLD = 0x02,

    /*Impact Configuration*/
    LENGTH_IMPACT_CONFIG = 0x0C,
    LENGTH_EMFIT_SENSING_THRESHOLD = 0x02,
    LENGTH_EMFIT_SAMPLE_RATE = 0x02,
    LENGTH_EMFIT_TOTAL_SAMPLE = 0x02,

    /*General Device Configuration*/
    LENGTH_DEVICE_CONFIG = 0x0C,
    LENGTH_CHECKIN_INTERVAL = 0x04,
    LENGTH_INACTIVE_TIMEOUT = 0x04,

    /*HIE Configuration*/
    LENGTH_HIE_CONFIG = 0x0C,
    LENGTH_HIE_QUEUE_SIZE = 0x01,
    LENGTH_HIE_THRESHOLD = 0x01,
    LENGTH_HIE_TIMEOUT = 0x04,
};

/* BLE TLV Structure */
typedef struct
{
    BYTE Type;
    BYTE Length;
    BYTE Value[MAX_VALUE_SIZE];
} BLE_Data_TLV;
BLE_Data_TLV TLV_Frame;

/* Structures For Storing Value */

/* Advertising Frequency Configuration */
typedef struct
{
    BYTE_4 Normal_Adv_Freq;
    BYTE_4 Checkin_Adv_Freq;
    BYTE_4 HIE_Adv_Freq;
    BYTE_4 Alert_Adv_Freq;
} Adv_Freq_Config;
Adv_Freq_Config Adv_Freq;

/* Advertising Timeout Configuration */
typedef struct
{
    BYTE_4 Normal_Adv_Timeout;
    BYTE_4 Checkin_Adv_Timeout;
    BYTE_4 HIE_Adv_Timeout;
    BYTE_4 Alert_Adv_Timeout;
} Adv_Timeout_Config;
Adv_Timeout_Config Adv_Timeout;

/* Accelerometer Configuration */
typedef struct
{
    BYTE Acc_Scale;
    BYTE_2 Acc_Wakeup_Threshold;
} Acc_Config;
Acc_Config Acc;

/* Impact Configuration */
typedef struct
{
    BYTE_2 Emfit_Sensing_Threshold;
    BYTE_2 Emfit_Sample_Rate;
    BYTE_2 Emfit_Total_Sample;
} Impact_Config;
Impact_Config Impact;

/* Device Configuration */
typedef struct
{
    BYTE_4 Checkin_Interval;
    BYTE_4 Inactive_Timeout;
} Device_Config;
Device_Config Device;

/* HIE Configuration */
typedef struct
{
    BYTE HIE_Queue_Size;
    BYTE HIE_Threshold;
    BYTE_4 HIE_Timeout;
} HIE_Config;
HIE_Config HIE;

/***********************
 * Global Variables
 ***********************/
// All global variables shown here are declared in main.c

extern BYTE Response_Frame[28];
extern BYTE Get_Response_Frame[28]; 
extern BYTE Set_Response_Frame[6]; 
extern BYTE IP_Frame [28];

/************************
 * Function Prototypes
 ************************/
/*None*/

#endif