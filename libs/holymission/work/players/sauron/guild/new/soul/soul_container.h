//----------------------------------------------------------------------------
// Title:						Author:
//	Monk's soul container system.					Sauron.
//
// File:						Started:
//	/players/sauron/guild/soul/soul_container.h			141096.
//
// Purpose:
//	This file contains the guild soul's container handling funs.
//
// History of revisions/fixes:
//
// 141096: Sauron: Started programming.
//
//----------------------------------------------------------------------------

#ifndef __SOUL_CONTAINER_H__

#define __SOUL_CONTAINER_H__

// Preprocessor directives:

#include "/players/sauron/guild/soul/soul_basic.h"

// End preprocessor directives.


// Global variables:

// Non-nosave variables - saved in/restored from the player's guild file.
         
// Static variables - not saved in/restored from the player's guild file.
nosave int weight_held,soul_weight;

// End global variables. 

// Prototypes:

int query_container();
int can_put_and_get();
int query_max_weight();
int add_weight(int i);

// End prototypes.

int query_container() { 
  return 1; 
}

int can_put_and_get() {
  return 1;
}

int query_max_weight() {
  return LEVEL(query_tmp("owner"))/2;
}

int add_weight(int i) {
  if(weight_held+i>query_max_weight())
    return 0;
  weight_held+=i;
  soul_weight=1+(2*weight_held/query_max_weight());
  return 1;
}

#endif // __SOUL_CONTAINER_H__