// SilberLand MUDlib
//
// std/room/commands.c -- room commands handling
//
// $Date: 1997/03/13 01:58:10 $                      
/* $Revision: 3.0 $       
 * $Log: commands.c,v $
 * Revision 3.0  1997/03/13 01:58:10  Woody
 * prepared for revision control
 *
 * Revision 2.4  1995/06/06  08:45:50  Jof
 * _notify_fail
 *
 * Revision 2.4  1995/06/05  15:01:10  Jof
 * _notify_fail
 *
 * Revision 2.3  1994/07/19  16:14:08  Kirk
 * *** empty log message ***
 *
 * Revision 2.2  1994/07/12  00:09:10  Kirk
 * clean up
 *
 * Revision 2.1  1994/03/21  16:48:13  Jof
 * Reindented files using emacs - once again
 *
 * Revision 2.0  1994/01/13  16:52:18  mud
 * *** empty log message ***
 *             
 */                            

#pragma strong_types

inherit "std/thing/commands";

#define NEED_PROTOTYPES

#include <thing/properties.h>
#include <config.h>
#include <properties.h>
#include <std_headers.h>
#include <defines.h>

void init() 
{
  ::init();

  add_action("imposs", "lies");
  add_action("imposs", "such");
  add_action("imposs", "suche");
}

/* Fuer etwas bessere Fehlermeldungen als 'Wie bitte?' bei einigen */
/* allgemeinen Kommandos.					   */
int imposs()
{
  switch (query_verb())
  {
    case "lies":
    _notify_fail("Was möchtest Du lesen?\n"); break;	
    case "such": case "suche":
    _notify_fail("Du suchst, findest aber nichts.\n"); break;
  }
  return 0;
}
