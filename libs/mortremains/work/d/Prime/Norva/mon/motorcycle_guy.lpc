#include <mudlib.h>
#include "../defs.h"

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short",  "a motorcyclist");
    set ("long", @ENDLONG
This guy is getting ready to get on his motorcycle and go home.
ENDLONG
  );
    set ("id", ({"motorcyclist", "guy", "cyclist"}) );
    set_name("motorcyclist");
    set ("gender", "male") ;  
    set ("race", "human");
    enable_commands() ;
     set ("damage", ({ 3, 7 }) ) ;
    set ("weapon_name", "fists");
    set_verbs( ({ "punche at", "swing at", "swipe at" }) ) ;
  set("author", "Chronos") ;
    set_size(6);
    set_level(10);
    set ("speed", 10);
    wear(ARM(motorcycle_helmet)) ;
    wear(ARM(leather_gloves)) ;
    wear(ARM(leather_boots)) ;
   set("prevent_summon", 1) ;    
   set("wealth", 200 + random(20) ) ;
}

void init() {
   command("wear all SILENT") ;
}
