/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: Storing Structures in Files.
 * @file Store_Data.h
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

#ifndef STORE_DATA_H_
#define STORE_DATA_H_

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

/** This will store structures in file
 *
 * This function is defined in Store_Data.c
 *
 * @param[in] BYTE Command_ID (BYTE here is unsigned char)
 *
 * @param[out] None
 *
 * @return None
 */
void Store_Data(BYTE Command_ID);

#endif