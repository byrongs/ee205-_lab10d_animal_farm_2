///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 2.0
///
/// @author @Byron Soriano <@byrongs@hawaii.edu>
/// @date   7_April_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstddef>   // For the size_t datatype

#include "catClass.h"
#include "config.h"


extern Cat* headPointer ; // Headpointer


extern NumCats numCats ;

/// Initializes the database for new data ///
extern void initializeDatabase() ;

/// Scans for if cat is in the database
extern bool isCatInDatabase( const Cat* presentCat ) ;

/// Verifies that the database is valid ///
extern bool validateDatabase() ;