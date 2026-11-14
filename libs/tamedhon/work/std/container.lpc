// Tamedhon MUDlib               
//
// std/container.c -- container standard object
//
// $Date: 1997/03/13 02:49:33 $
/* $Revision: 3.0 $
 * $Log: container.c,v $
 * Revision 3.0  1997/03/13 02:49:33  Woody
 * prepared for revision control
 *
 * Revision 2.9  1997/02/10  Woody
 * description::init() statt add_action
 *
 * Revision 2.8  1995/06/14  09:05:18  Wargon
 * read() nach thing/description verlegt.
 *
 * Revision 2.7  1995/02/06  19:44:14  Jof
 * RCS-Logs aufgeraeumt (leere Logs raus usw)
 *
 * Revision 2.6  1994/07/10  17:36:33  Jof
 * Weg mit "show"
 *
 * Revision 2.5  1994/06/16  21:23:07  Kirk
 * removed SetWeight
 *
 * Revision 2.2  1994/03/07  17:32:32  Jof
 * Removed ExistsProp()
 *
 * Revision 2.1  1994/01/14  09:57:57  mud
 * reset eingebaut, lfuns sollten vorhanden sein !
 *
 */

// The most general object class. It defines the really basic functions.
//
// This object should understand the properties short, long, info, read_msg,
// value, weight.
//
// weight is given in grams, 1 kilogram (kg) = 1000 grams (g) = 1 old weight
// unit

#pragma strict_types
// #pragma save_types
#pragma no_clone
#pragma range_check

inherit "/std/thing/properties";
inherit "/std/thing/moving";
inherit "/std/thing/commands";
inherit "/std/container/description";
inherit "/std/thing/language";
inherit "/std/container/restrictions";
inherit "/std/container/inventory";

#include <properties.h>
#include <wizlevels.h>
#include <defines.h>

ENVCHECKPROC

protected void create()
{
  properties::create();
  commands::create();
  description::create();
  restrictions::create();
  SetProp(P_CONTAINER,1);
  ENVCHECK
}

void init() 
{
  commands::init();
  description::init();
}

void reset()
{

}
