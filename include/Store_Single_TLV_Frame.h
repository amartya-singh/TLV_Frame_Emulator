/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: Storing values for single command.
 * @file Store_Single_TLV_Frame.h
 * @brief This program will store single set command values in structures.
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

#ifndef STORE_SINGLE_TLV_FRAME_H_
#define STORE_SINGLE_TLV_FRAME_H_

/******************
* Includes
*******************/

#include "../include/commons.h"
#include "../include/Genrate_Single_Get_Response.h"
#include "../include/Genrate_Set_Success_Response.h"

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

/** This function will store the values from single set TLV command
 *
 * This function is defined in Store_Single_TLV_Frame.c
 *
 * @param[in] BYTE IP_Frame [28]
 *
 * @param[out] struct Single_TLV_struct (stores value in this structure's object)
 *
 * @return &Set_Response_Frame[0] (Pointer to Base address of Set_Response_Frame)
 */
BYTE* Store_Single_TLV_Frame(BYTE IP_Frame[28]);

#endif