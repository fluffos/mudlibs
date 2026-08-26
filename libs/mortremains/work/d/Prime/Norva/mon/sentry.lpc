#include <mudlib.h>
#include "../defs.h"

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short",  "a sentry");
    set ("long", @ENDLONG
This sentry is protecting the gate.
ENDLONG
  );
    set ("id", ({"sentry" }) );
    set_name("sentry");
    set ("gender", "male") ;
    set ("race", "human");
    enable_commands() ;
    set ("damage", ({ 4, 8 }) ) ;
    set ("weapon_name", "fists");
    set_verbs( ({ "punche at", "swing at", "swipe at" }) ) ;
    set_size(6);
  set("author", "Chronos") ;
    set_level(16);
   set("prevent_summon", 1) ;
   set("wealth", 20 + random(240) ) ;
   arm(WEP(beretta)) ;
   wear(ARM(whitehat)) ;
}

void init() {
   command("wear all SILENT") ;
}
