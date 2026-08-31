/// This is the Eihwaz Runestone--Add's +5 dex to weapon then 1 each level after that
#include <std.h>
#include <cp.h>

inherit RUNESTONE;

void create() {
        set_name("runestone");
        set_id( ({"runestone", "stone", "rune", "eihwaz rune"}) );
        set_short("small runestone");
     set_long("     %^BOLD%^%^BLACK%^__\n"
"   _/  \\_\n"
"  /      \\\n"
" |  %^GREEN%^|\\/|%^BLACK%^  |\n"
" |  %^GREEN%^|  |%^BLACK%^  |\n"
" |  %^GREEN%^|  |%^BLACK%^  |\n"
"  \\_    _/\n"
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
