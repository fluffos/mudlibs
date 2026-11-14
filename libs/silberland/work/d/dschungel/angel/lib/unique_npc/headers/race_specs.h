/*******************************************************************************
 * Race Specs header Datei
 * Datei: race_specs.h
 * Autor: Angel (avs@sbox.tu-graz.ac.at)
 */

#include "./def.h"

#ifndef __RACE_SPECS_H__
#define __RACE_SPECS_H__

// Properties
#define P_UNIQUE_SURNAME_POLICY       "unique_surname_policy"

#endif // __RACE_SPECS_H__

#ifdef NEED_PROTOTYPES_RACE_SPECS
#ifndef __RACE_SPECS_H_PROTOTYPES__
#define __RACE_SPECS_H_PROTOTYPES__

  // Prototypes for the race specifications:
  void set_race_specs(string race);            // Installs the specifications. (NEEDS an inherited race_specs file!) 
  int get_variation (int number, int percent); // Returns a random variation in percent of the number.
  
#endif
#endif

