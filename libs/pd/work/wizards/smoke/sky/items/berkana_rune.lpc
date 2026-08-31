/// This is the Berkana Rune--Gives +5 int and +1 for each lvl after max +20 int
#include <std.h>
#include <cp.h>

inherit RUNESTONE;

void create() {
        set_name("runestone");
        set_id( ({"runestone", "stone", "rune", "berkana rune"}) );
        set_short("small runestone");
     set_long("%^BOLD%^%^BLACK%^     __\n"
"   _/  \\_\n"
"  /  %^GREEN%^|\\%^BLACK%^  \\\n"
" |   %^GREEN%^|/%^BLACK%^   |\n"
" |   %^GREEN%^|\\%^BLACK%^   |\n"
"  \\_ %^GREEN%^|/%^BLACK%^ _/\n"
"    \\__/\n");
        set_weight(2);
        set_value(0);
}
int query_auto_load() {
      object tp=this_player();
      int tp_lvl=(this_player()->query_level());
      if(tp_lvl >=1) {return 1;}
      else {return 0;}
}
