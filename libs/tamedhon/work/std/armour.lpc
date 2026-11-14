// SilberLand Mudlib
//
// ARMOUR.C -- armour standard object
//
// $Date: 1997/09/25 18:49:10 $
/* $Revision: 2.3 $
 * $Log: armour.c,v $
 * Revision 2.3  1997/09/25 18:49:10  Woody
 * short() hier raus, ist doch schon in description.c drin :)
 *
 * Revision 2.2  1997/09/25 15:06:03  Woody
 * inherited material nicht mehr (-> std/thing/description)
 *
 * Revision 2.1  1997/06/25 11:11:55  Woody
 * inherit std/armour/description
 *
 * Revision 2.0  1997/03/13 02:48:50  Woody
 * prepared for revision control
 *
 * Revision 1.3  96/09/21  12:00:00  Woody
 * description::init() statt add_action("lies"), P_WORN_TEXT
 *
 * Revision 1.2  96/05/25  18:00:00  Woody
 * short() Aenderungen wieder retour
 *
 * Revision 1.1  29/02/96  23:00:00  Mupfel
 * inherit "/std/thing/material"; - argl
 *
 * Revision 1.0  22/02/96  23:00:00  Hadra
 * short() geaendert
 */

#pragma strong_types

inherit "/std/thing/properties";
inherit "/std/thing/commands";
inherit "/std/thing/restrictions";
inherit "/std/armour/description";
inherit "/std/armour/moving";
inherit "/std/armour/combat";
inherit "/std/thing/language";

#define NEED_PROTOTYPES

#include <config.h>
#include <properties.h>
#include <language.h>
#include <combat.h>
#include <wizlevels.h>
#include <defines.h>

ENVCHECKPROC

void create()
{
  properties::create();
  commands::create();
  description::create();
  combat::create();
  AddId("Ruestung");
  AddId("Rüstung");
  ENVCHECK
}

void init()
{
  commands::init();
  combat::init();
  description::init();
}

void reset() {}

