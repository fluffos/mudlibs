// SilberLand MUDlib
//
// std/gilden_room.c -- Standard-Gildenraum
//
// $Date: 1997/03/13 02:56:49 $
/* $Revision: 2.0 $
 * $Log: gilden_room.c,v $
 * Revision 2.0  1997/03/13 02:56:49  Woody
 * prepared for revision control
 *
 * Revision 1.2  1995/02/06  19:41:17  Jof
 * Inserted RCS-Header
 */


// #define NEED_PROTOTYPES
inherit "/std/gilde";
inherit "/std/gilden_ob";
#include <properties.h>
#include <attributes.h>
#include <new_skills.h>
//#pragma strong_types;

void create() {
  ::create();
  AddCmd(({"tritt","trete"}),"bei_oder_aus_treten");
  AddCmd(({"lern","lerne"}),"LearnSpell");
}

int advance(string str) {
  int r1,r2;

  r1=gilde::advance(str);
  r2=gilden_ob::try_advance();
  
  "/room/debug"->debug_message(this_object(),
    sprintf("r1=%i, r2=%i", r1, r2));
  
  return (r1||r2);
}

int is_guild()
{
  return 1;
}