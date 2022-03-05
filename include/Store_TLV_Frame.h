/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: Storing In TLV Structure.
 * @file Store_TLV_Frame.h
 * @brief This program will store Input frame in TLV structure.
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

#ifndef STORE_TLV_FRAME_H_
#define STORE_TLV_FRAME_H_
/******************
* Includes
*******************/

#include "../include/commons.h"

/*************************
 * Defines
 *************************/

/* None */

/**************************************
 * Structures, Enumerations, Typedefs
 *************************************/

/* None */

/************************
 * Function Prototypes
 ************************/

/** This function will store the input frame in TLV Structure
 *
 * This function is defined in Store_TLV_Frame.c
 *
 * @param[in] BYTE IP_Frame [28]
 *
 * @param[out] struct BLE_Data_TLV
 *
 * @return &Set_Response_Frame[0] (Pointer to Base address of Set_Response_Frame)
 */
void Store_TLV_Frame(BYTE IP_Frame[28]);

#endif