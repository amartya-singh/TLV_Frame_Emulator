/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: This function prints the output.
 * @file Response_Output.h
 * @brief This program is equipped with clearing input buffer feature so next data is not corrupted.
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

#ifndef RESPONSE_OUTPUT_H_
#define RESPONSE_OUTPUT_H_

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

/** This function prints the output
 *
 * This function is defined in Response_Output.c
 *
 * @param[in] BYTE IP_Frame [28]
 *
 * @param[out] None
 *
 * @return None
 */
void Response_Output(BYTE Response_Frame[28]);

#endif