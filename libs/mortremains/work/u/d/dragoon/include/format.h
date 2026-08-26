//  File:  format.h
//  Creator:  Dragoon (with help from Devil@fire.eitc.edu)
//  Date:  May 1997
//
//  This will format any text so that each line will be outputed
//  as the max LENGTH reguardless of the string length.
//
#define LENGTH 65

string format( string arg ) {
   return sprintf("%-=*s\n",LENGTH,arg);
}
