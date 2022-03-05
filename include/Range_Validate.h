/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: This function will validate the range for the values of the command ID passed to it.
 * @file Range_Validate.h
 * @brief Range will be verified only for set command before storage. Range will be verified once the template of set command is verified.
 *
 * This function is called in Validate_IP_Frame.c
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

#ifndef RANGE_VALIDATE_H_
#define RANGE_VALIDATE_H_

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

/** This function will validate the range for the values of the command ID passed to it
 *
 * This function is defined in Range_Validate.c
 *
 * @param[in] BYTE IP_Frame [28], Type
 *
 * @param[out] None.
 *
 * @return BYTE 0,1
 */
BYTE Range_Validate(BYTE IP_Frame[28], BYTE Type);

#endif