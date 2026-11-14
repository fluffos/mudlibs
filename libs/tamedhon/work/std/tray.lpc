// SilberLand MUDlib               
//
// std/tray.c -- tray standard object
//
// $Date: 1997/03/13 03:19:23 $
/* $Revision: 3.0 $
 * $Log: tray.c,v $
 * Revision 3.0  1997/03/13 03:19:23  Woody
 * prepared for revision control
 *
 * Revision 2.7  1997/02/10  Woody
 * description::init() statt add_action
 *
 * Revision 2.6  1995/05/09  08:45:55  Jof
 * copied from container
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

inherit "std/thing/properties";
inherit "std/thing/moving";
inherit "std/thing/commands";
inherit "std/tray/description";
inherit "std/thing/language";
inherit "std/container/restrictions";

#include <properties.h>
#include <wizlevels.h>
#include <defines.h>

ENVCHECKPROC

void create()
{
  properties::create();
  commands::create();
  description::create();
  restrictions::create();
  AddId("Tray");
  SetProp(P_TRAY,1);
  ENVCHECK
}

void init() 
{
  commands::init();
  description::init();
}

void reset()
{}

