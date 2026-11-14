// SilberLand MUDlib
//
// std/living.c -- living objects base
//
// $Date: 1997/09/17 14:14:13 $                      
/* $Revision: 3.2 $       
 * $Log: living.c,v $
 * Revision 3.2  1997/09/17 14:14:13  Woody
 * void vor init() gestellt
 *
 * Revision 3.1  1997/06/25 11:21:46  Woody
 * init(): description::init() aufrufen
 *
 * Revision 3.0  1997/03/13 03:01:05  Woody
 * prepared for revision control
 *
 * Revision 2.5  1995/04/26  15:44:00  Rochus
 * Skillsystem endgueltig eingebaut
 *
 * Revision 2.4  1995/02/06  19:44:14  Jof
 * RCS-Logs aufgeraeumt (leere Logs raus usw)
 *
 * Revision 2.3  1994/09/08  17:44:00  Rochus
 * Skillsystem testweise eingebaut
 *
 * Revision 2.2  1994/07/10  17:23:38  Jof
 * Revision 2.1  1994/03/21  16:48:13  Jof
 * Revision 2.0  1994/01/13  16:51:41  mud
 */                            

#pragma strong_types

inherit "/std/thing/properties";
inherit "/std/thing/description";
inherit "/std/living/attributes";
inherit "/std/living/life";
inherit "/std/living/moving";
inherit "/std/living/combat";
//inherit "std/thing/util";
inherit "/std/container/restrictions";
inherit "/std/living/skills";

#define NEED_PROTOTYPES

#include <thing/properties.h>
#include <config.h>
#include <properties.h>


void create() {
  properties::create();
  description::create();
  attributes::create();
  life::create();
  AddId("Living");

  SetProp(P_MSGIN,"kommt an");
  SetProp(P_MSGOUT,"geht nach");
  SetProp(P_MMSGIN,"erscheint in einer Rauchwolke");
  SetProp(P_MMSGOUT,"löst sich in einer Rauchwolke auf");
}

void init()
{
  description::init();
}
