// SilberLand MUDlib
//
// std/npc/comm.c -- Basical communication for NPCs
//
// $Date: 1997/06/25 11:58:29 $
/* $Revision: 1.2 $
 * $Log: comm.c,v $
 * Revision 1.2  1997/06/25 11:58:29  Woody
 * break_string() in sage()
 *
 * Revision 1.1  1997/03/13 01:20:36  Woody
 * prepared for revision control
 *
*/

/*
 *-------------------------------------------------------------------
 * comm.c
 * This file is part of the MorgenGrauen mudlib.
 * Basical communiacation commands for npc.
 * For better support of the sequencer module.
 *
 * written by Rumata 15.08.92
 *-------------------------------------------------------------------
 */

#include <language.h>
#define NEED_PROTOTYPES
#include <thing/description.h>

void create() {
  add_action( "sage", "sag", 1 );
  add_action( "echo", "echo" );
  add_action( "emote", "emote" );
}

int echo(string str ) {
  say( str + "\n" );
  return 1;
}

int sage(string str ) {
  say( break_string(str, 78, Name(WER,2)+" sagt: "));
  return 1;
}

int emote(string str ) {
  say( capitalize(name(WER,2))+" "+str+"\n" );
  return 1;
}
