#include <mudlib.h>
#include "../defs.h"

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short",  "a young sailor");
    set ("long", @ENDLONG
This young sailor has nothing better to do but sit in the Rec Cen all day.
ENDLONG
  );
    set ("id", ({"sailor", "young sailor"}) );
    set_name("young sailor");
    set ("gender", "male") ;  
    set ("race", "human");
    enable_commands() ;
     set ("damage", ({ 3, 7 }) ) ;
    set ("weapon_name", "fists");
    set_verbs( ({ "punche at", "swing at", "swipe at" }) ) ;
set("author", "Chronos") ;
    set_size(6);
    set_level(3);
   set("prevent_summon", 1) ;    
   set("wealth", 20 + random(20) ) ;
}

