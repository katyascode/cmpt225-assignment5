/*
 * UnableToInsertException.h
 *
 * Class Description: Defines the exception that is thrown when a newElement
 *                    cannot be inserted into the data collection ADT class.
 *
 * Author: Inspired from our textbook's authors Frank M. Carrano and Tim Henry.
 *         Copyright (c) 2013 __Pearson Education__. All rights reserved.
 */

#ifndef UNABLE_TO_INSERT_EXCEPTION_H
#define UNABLE_TO_INSERT_EXCEPTION_H

#include <stdexcept>

using std::string;
using std::logic_error;

class UnableToInsertException : public logic_error {

   public:
      // Constructor
      UnableToInsertException(const string& message = "");
   
}; 
#endif
