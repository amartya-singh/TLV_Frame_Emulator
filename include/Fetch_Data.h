/*******************************************************************************
 * Copyright(c) 2021, Volansys Technologies
 *
 * Description: Fetching Structures Data From Files.
 * @file Fetch_Data.h
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

#ifndef FETCH_DATA_H_
#define FETCH_DATA_H_

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
 * @param[in] None.
 *
 * @param[out] struct 
 *
 * @return None
 */
void Fetch_Data();

#endif