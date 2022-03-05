/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: Storing Structures in Files.
 * @file Store_Data.c
 * @brief This program will store values from structures in file.
 *
 * This function is called in main.c
 *
 * Author       - Amartya Singh
 *******************************************************************************
 *
 * History
 *
 * March/2/2021, Amartya Singh, Completed TLV Frame Emulator
 *
 * Feb/16/2021, Amartya Singh, Created (TLV Frame Emulator)
 *
 ******************************************************************************/

#include "../include/Store_Data.h"
#include "../include/commons.h"

void Store_Data(BYTE Command_ID)
{
    FILE *store;

    if ((Command_ID == SET_ADV_FREQ) || (Command_ID == NORMAL_ADV_FREQ) || (Command_ID == CHECKIN_ADV_FREQ) || (Command_ID == HIE_ADV_FREQ) || (Command_ID == ALERT_ADV_FREQ))
    {
        store = fopen ("ADV_Freq.dat", "w"); 
        fwrite(&Adv_Freq, sizeof(Adv_Freq_Config), 1, store);
        fclose(store);
    }
    else if ((Command_ID == SET_ADV_TIMEOUT) || (Command_ID == NORMAL_ADV_TIMEOUT) || (Command_ID == MAX_CHECKIN_ADV_TIMEOUT) || (Command_ID == HIE_ADV_TIMEOUT) || (Command_ID == ALERT_ADV_TIMEOUT))
    {
        store = fopen ("ADV_Timeout.dat", "w"); 
        fwrite(&Adv_Timeout, sizeof(Adv_Timeout_Config), 1, store);
        fclose(store);        
    }
    else if ((Command_ID == SET_ACC_CONFIG) || (Command_ID == ACC_SCALE) || (Command_ID == ACC_WAKEUP_THRESHOLD))
    {
        store = fopen ("ACC_Config.dat", "w"); 
        fwrite(&Acc, sizeof(Acc_Config), 1, store);
        fclose(store);
    }
    else if ((Command_ID == SET_IMPACT_CONFIG) || (Command_ID == EMFIT_SENSING_THRESHOLD) || (Command_ID == EMFIT_SAMPLE_RATE) || (Command_ID == EMFIT_TOTAL_SAMPLE))
    {
        store = fopen ("Impact_Config.dat", "w"); 
        fwrite(&Impact, sizeof(Impact_Config), 1, store);
        fclose(store);        
    }
    else if ((Command_ID == SET_DEVICE_CONFIG) || (Command_ID == CHECKIN_INTERVAL) || (Command_ID == INACTIVE_TIMEOUT))
    {
        store = fopen ("Device_Config.dat", "w"); 
        fwrite(&Device, sizeof(Device_Config), 1, store);
        fclose(store);        
    }
    else if ((Command_ID == SET_HIE_CONFIG) || (Command_ID == HIE_QUEUE_SIZE) || (Command_ID == HIE_THRESHOLD) || (Command_ID == HIE_TIMEOUT))
    {
        store = fopen ("HIE_Config.dat", "w"); 
        fwrite(&HIE, sizeof(HIE_Config), 1, store);
        fclose(store);        
    }

}