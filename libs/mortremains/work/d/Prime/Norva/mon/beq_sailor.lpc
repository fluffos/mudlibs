#include <mudlib.h>
#include "../defs.h"

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
switch(random(10)+1) {
    case 1..3 :
      set ("short",  "a young sailor");
      set ("long", @ENDLONG
This young sailor has nothing better to do but sit in his room all day and play video games.
ENDLONG
  );
    set ("id", ({"sailor", "young sailor"}) );
    set_name("young sailor");
   break ;
  case 4..6:
    set ("short",  "a sailor");
      set ("long", @ENDLONG
This sailor is studying for his next test in school.
ENDLONG
  );
    set ("id", ({"sailor"}) );
    set_name("sailor");   break ;
  default:
    set ("short",  "a strong sailor");
      set ("long", @ENDLONG
This guy is sitting in his room doing some PT.
ENDLONG
  );
    set ("id", ({"sailor", "strong sailor"}) );
    set_name("strong sailor");   break ;
}
    set ("gender", "male") ;  
    set ("race", "human");
    enable_commands() ;
     set ("damage", ({ 3, 7 }) ) ;
    set ("weapon_name", "fists");
    set_verbs( ({ "punche at", "swing at", "swipe at" }) ) ;
set("author", "Chronos") ;
    set_size(6);
    set_level(3+random(7));
   set("prevent_summon", 1) ;    
   set("wealth", 20 + random(30) ) ;
}
