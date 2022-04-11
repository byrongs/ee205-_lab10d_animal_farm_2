///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author @Byron Soriano <@byrongs@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#

#include <cstring>
#include <stdexcept>
#include <cassert>
#include <iostream>


#include "reportCats.h"
#include "catDatabase.h"
#include "catClass.h"
#include "deleteCats.h"

using namespace std ;



bool printAllCats() {
    NumCats numCats = 0 ;

    assert( validateDatabase() ) ;

    for(Cat* findCat = catDataBaseHeadPointer ; findCat != nullptr ; findCat = findCat->next ) {
        findCat->print() ;
        numCats++ ;
    }

#ifdef DEBUG
    cout << "numCats = [" << numCats << "]" << endl;

#endif

    return true;
}


Cat* findCatName( const char* name ) {
    assert( Cat().validateName( name ) ) ;

    for(Cat* findCat = catDataBaseHeadPointer ; findCat != nullptr ; findCat->next ) {
        if( strcmp( name, findCat->getName() == 0 ) {
            return findCat ;
        }
    }
    return nullptr ;
}


const char* genderName( const enum Gender gender ) {
    switch( gender ) {
        case UNKNOWN_GENDER: return "UNKNOWN" ;
        case MALE: return "MALE" ;
        case FEMALE: return "FEMALE";
    }

    throw logic_error(PROGRAM_NAME ": Gender name is not mapped to any string values ") ;
}


const char* breedName( const enum Breed breed ) {
    switch( breed ) {
        case UNKNOWN_BREED: return "UNKNOWN" ;
        case MAINE_COON: return "MAINE COON" ;
        case MANX: return "MANX" ;
        case SHORTHAIR: return "Shorthair" ;
        case PERSIAN: return "PERSIAN" ;
        case SPHYNX: return "SPHYNX" ;
    }
    throw logic_error(PROGRAM_NAME ": Breed name is not mapped to any string values ") ;
}


