///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author @Byron Soriano <@byrongs@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////


#include <cstdlib>  // For EXIT_SUCCESS / EXIT_FAILURE
#include <cassert>  // For assert()
#include <cstring>  // For strcmp()
#include <exception>  // For try/catch blocks
#include <iostream>

#include "config.h"
#include "catClass.h"
#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "deleteCats.h"

using namespace std ;

/// Tests the largest possible name
#define MAX_NAME   "1234567890123456789012345678901234567890123456789"

/// Tests invalid name
#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"

/// Tests invalid weight
#define ILLEGAL_WEIGHT "-120"

//////////////////////////// Animal Farm 2 /////////////////////////////////////////////////////////
int main() {
    cout << "Starting " << PROGRAM_TITLE << endl ;

    initializeDatabase() ;

#ifdef DEBUG
    {
      // Verify that a cat's default values are set
      Cat testCat = Cat();
      assert(testCat.getName() != nullptr );
      assert(strcmp(testCat.getName(), "") == 0);
      assert(testCat.getGender() == UNKNOWN_GENDER);
      assert(testCat.getBreed() == UNKNOWN_BREED);
      assert(testCat.isFixed() == false);
      assert(testCat.getWeight() == UNKNOWN_WEIGHT);
      assert(testCat.getColor() == UNKNOWN_COLOR);
      assert(!testCat.isFixed());
      assert(!testCat.validation());  // The default cat is invalid

      // Test for NULL name
      try {
         testCat.setName(nullptr);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      // Test for empty name
      try {
         testCat.setName("");
         assert(false); // We should never get here
      } catch (exception const &e) {}

      // Test valid names
      testCat.setName("A");       // A 1 character name is valid
      testCat.setName(MAX_NAME1); // A MAX_NAME1 name is valid
      }
      // Test for name too large
      try {
         testCat.setName(ILLEGAL_NAME);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setGender(FEMALE);

      try {
         testCat.setGender(MALE);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setBreed(MAINE_COON);

      try {
         testCat.setBreed(MANX);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.fixCat();
      assert(testCat.isFixed());

      // Test for Illegal cat weight //
      try {
         testCat.setWeight(ILLEGAL_WEIGHT);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setWeight(1.0 / 1024);
      assert(testCat.getWeight() == 1.0 / 1024);

      assert(testCat.validate());  // The cat should now be valid
      testCat.print() ;

      assert(!isCatInDatabase(&testCat)) ;
   }
#endif

    bool result ;
    result = addCat( new Cat( "Loki", MALE, PERSIAN, 1.0, BLACK)) ;
    assert( result ) ;
    if( !result ) throw logic_error (PROGRAM_NAME ": addCat() failed" ) ;
    result = addCat( new Cat( "Milo", MALE, MANX , 1.1, PINK )) ;
    assert( result ) ;
    result = addCat( new Cat( "Bella", FEMALE, MAINE_COON, 1.2, RED )) ;
    assert( result ) ;
    result = addCat( new Cat( "Kali", FEMALE, SHORTHAIR, 1.3, BLUE )) ;
    assert( result ) ;
    result = addCat( new Cat( "Trin", FEMALE, MANX, 1.4,GREEN )) ;
    assert( result ) ;
    result = addCat( new Cat( "Chili", MALE, SHORTHAIR, 1.5, WHITE )) ;
    assert( result ) ;

#ifdef DEBUG
    {
      // Test finding a cat...
      Cat *bella = findCatByName("Bella");
      assert(bella != nullptr);
      // Test not finding a cat
      assert(findCatByName("Bella's not here") == nullptr);

      // Test deleting a cat...
      assert(deleteCat(bella) == true);
      try {
         deleteCat(bella); // To verify that Bella's not there
      } catch (exception const &e) {}

      bella = nullptr;
   }
#endif

    printAllCats() ;

    deleteAllCats() ;

    printAllCats() ;

    cout << "Done with " << PROGRAM_TITLE ;

    return( EXIT_SUCCESS ) ;
}