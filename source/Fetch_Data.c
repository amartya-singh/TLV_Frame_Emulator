/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: Fetching Structures Data From Files.
 * @file Fetch_Data.c
 * @brief This program will fetch stored values from file in structures.
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

#include "../include/Fetch_Data.h"
#include "../include/commons.h"

void Fetch_Data()
{
    FILE *fetch;

    fetch = fopen ("ADV_Freq.dat", "r"); 
    fread(&Adv_Freq, sizeof(Adv_Freq_Config), 1, fetch);
    fclose(fetch);

    fetch = fopen ("ADV_Timeout.dat", "r"); 
    fread(&Adv_Timeout, sizeof(Adv_Timeout_Config), 1, fetch);
    fclose(fetch);

    fetch = fopen ("ACC_Config.dat", "r"); 
    fread(&Acc, sizeof(Acc_Config), 1, fetch);
    fclose(fetch);

    fetch = fopen ("Impact_Config.dat", "r"); 
    fread(&Impact, sizeof(Impact_Config), 1, fetch);
    fclose(fetch);

    fetch = fopen ("Device_Config.dat", "r"); 
    fread(&Device, sizeof(Device_Config), 1, fetch);
    fclose(fetch);

    fetch = fopen ("HIE_Config.dat", "r"); 
    fread(&HIE, sizeof(HIE_Config), 1, fetch);
    fclose(fetch);
    
}