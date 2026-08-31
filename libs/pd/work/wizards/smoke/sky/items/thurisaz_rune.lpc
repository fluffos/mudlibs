/// This is the Thurisaz Runestone--Add's +25 to the skill of whatever type of weapon it is
#include <std.h>
#include <cp.h>

inherit RUNESTONE;

void create() {
        set_name("runestone");
        set_id( ({"runestone", "stone", "rune", "thurisaz rune"}) );
        set_short("small runestone");
     set_long("     %^BOLD%^%^BLACK%^___\n"
"   _/   \\_\n"
"  /   %^CYAN%^|%^BLACK%^   \\\n"
" |    %^CYAN%^|\\%^BLACK%^   |\n"
" |    %^CYAN%^|/%^BLACK%^   |\n"
"  \\_  %^CYAN%^|%^BLACK%^  _/\n"
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
