/// This is the Kenaz Rune--Gives +5 WISDOM and +1 for each lvl after max +20 WIS
#include <std.h>
#include <cp.h>

inherit RUNESTONE;

void create() {
        set_name("runestone");
        set_id( ({"runestone", "stone", "rune", "kenaz rune"}) );
        set_short("small runestone");
     set_long("%^BOLD%^%^BLACK%^     ___\n"
"   _/   \\_\n"
"  /   %^GREEN%^/%^BLACK%^   \\\n"
" |   %^GREEN%^/%^BLACK%^     |\n"
" |   %^GREEN%^\\%^BLACK%^     |\n"
"  \\_  %^GREEN%^\\%^BLACK%^  _/\n"
"    \\___/\n");
        set_weight(2);
        set_value(0);
}
int query_auto_load() {
      object tp=this_player();
      int tp_lvl=(this_player()->query_level());
      if(tp_lvl >=1) {return 1;}
      else {return 0;}
}
