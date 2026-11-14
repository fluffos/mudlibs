// SilberLand Mudlib
//
// std/weapon.c -- weapon standard object
//
// $Date: 1997/09/25 15:14:21 $
/* $Revision: 2.2 $
 * $Log: weapon.c,v $
 * Revision 2.2  1997/09/25 15:14:21  Woody
 * inherited material nicht mehr (-> std/thing/description)
 *
 * Revision 2.1  1997/06/25 11:43:45  Woody
 * inherit std/weapon/description
 *
 * Revision 2.0  1997/03/13 03:22:22  Woody
 * prepared for revision control
 *
 * Revision 1.2  96/09/21  12:30:00  Woody
 * P_WIELDED_TEXT
 *
 * Revision 1.1  96/05/25  18:00:00  Woody
 * short() Aenderungen wieder retour
 *
 * Revision 1.0  22/02/96  23:00:00  Hadra
 * short() geaendert
 */                            

#pragma strong_types

inherit "std/thing/properties";
//inherit "std/thing/util";
inherit "std/thing/language";
inherit "std/thing/commands";
inherit "std/thing/restrictions";
inherit "/std/weapon/description";
inherit "/std/weapon/moving";
inherit "/std/weapon/combat";

#define NEED_PROTOTYPES

#define <thing/properties.h>

#include <properties.h>
#include <moving.h>
#include <defines.h>

void create()
{
  properties::create();
  commands::create();
  restrictions::create();
  combat::create();
  description::create();
  AddId("Waffe");
}

void init()
{
  commands::init();
  description::init();
  combat::init();
}

void reset()  // Man kann in ALLEN Standardobjekten ::reset aufrufen!
{ }

// Prevents tampering with the master object
int query_prevent_shadow() { return 1; }
