// This monster had 3 variables defined and did nothing with them.
// What a fucking waste of memory.  *applause for the lazy code*

// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "defs.h"

inherit MONSTER ;

void create () {


	::create() ;
	seteuid(getuid()) ;
    set("short", "Ruben the Jester") ;
  set("long", @ENDLONG
Ruben was once the jester for a powerful lord in a faraway plane.
Not being as funny as he thought he was, Ruben was exiled to 
this plane, and now he runs this toy shoppe.
ENDLONG
  ) ;
  set("id", ({ "ruben", "jester" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
  set_name("ruben") ;
	set ("gender", "male") ;
	enable_commands() ;
   	set_living_name("akin") ;
  set("natt", 2) ;
  set("armor_class", 2) ;
  set("base_ac", 2) ;
	set ("thac0", 7);
	set ("damage", ({ 1,6 }) ) ;
  set("weapon_name", "fists") ;
  set("race", "half-elf") ;
  set_verbs( ({ "swing at", "attack", "punche at" }) ) ;
   set_level(20) ;
  set("stat/charisma", 24) ;
   set("stat/dexterity", 19) ;
  wear("/d/Outer/Sigil/items/jester_cap", "cap"); // donated by Chronos.
  arm("/d/Outer/Sigil/items/jester_sceptre", "sceptre") ; // also donated.
       		}

