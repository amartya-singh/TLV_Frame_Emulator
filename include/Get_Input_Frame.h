/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: This function takes input from user in form of char array then convert it to hex array.
 * @file Get_Input_Frame.h
 * @brief This is capable to handle invalid input.
 *
 * This function is called in TLV_Frame_Emulator.c.
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

#ifndef GET_INPUT_FRAME_H_
#define GET_INPUT_FRAME_H_

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

/** This function takes input from user in form of char array then convert it to hex array
 *
 * This function is defined in Get_Input_Frame.c
 *
 * @param[in] None
 *
 * @param[out] BYTE Set_Response_Frame[6]
 *
 * @return BYTE 0, 1
 */
BYTE Get_Input_Frame();

#endif