//----------------------------------------------------------------------------
// Title:						Author:
//	Monk's soul alias handling funs.			Sauron.
//
// File:						Started:
//	/players/sauron/guild/soul/soul_alias.h		041096.
//
// Purpose:
//	This file contains the guild soul's alias handling funs.
//
// History of revisions/fixes:
//
// 041096: Sauron: Started programming.
//
//----------------------------------------------------------------------------

#ifndef __SOUL_ALIAS_H__

#define __SOUL_ALIAS_H__

// Preprocessor directives:

#include "/players/sauron/guild/soul/soul_basic.h"

// End preprocessor directives.


// Prototypes:

void init_soul_aliases();
string *soul_alias(string verb,string str,object tp);

// End prototypes.


// Global variables:

// Non-nosave variables - saved in/restored from the player's guild file.
mapping soul_aliases;
         
// Static variables - not saved in/restored from the player's guild file.

// End global variables. 


void init_soul_aliases() {
  soul_aliases=([
    "exa":({1,"examine",}),
  ]);
}
  
string *soul_alias(string verb,string str,object tp) {
  int sz;
  mixed *tmp;
  
  if(member(soul_aliases,verb)) {       // Simple soul alias system.
    tmp=soul_aliases[verb];
    if((sz=sizeof(tmp))>=2 && query_guild_level(tp)>=tmp[0]) {
      verb=tmp[1];
      if(sizeof(tmp)>2) {  
        if(str)
          str=tmp[1]+" "+str;
        else
          str=tmp[1];
      }
    } 
  }
  return ({verb,str});
}

#endif // __SOUL_ALIAS_H__
