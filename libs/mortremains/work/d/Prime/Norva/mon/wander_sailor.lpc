#include <mudlib.h>
#include "../defs.h"

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short",  "a sailor");
    set ("long", @ENDLONG
It's just another sailor going about his daily business.
ENDLONG
  );
    set ("id", ({"sailor" }) );
    set_name("sailor");
    set ("gender", "male") ;
    set ("race", "human");
    enable_commands() ;
    set ("damage", ({ 4, 8 }) ) ;
    set ("weapon_name", "fists");
    set_verbs( ({ "punche at", "swing at", "swipe at" }) ) ;
    set_size(6);
    set_level(10);
   set("moving", 1) ;
set("author", "Chronos") ;
  set("speed", 20) ;
   set("prevent_summon", 1) ;
   set("wealth", 20 + random(240) ) ;
  wear(ARM(whitehat)) ;
}

void init() {
command("wear all SILENT") ;
}
