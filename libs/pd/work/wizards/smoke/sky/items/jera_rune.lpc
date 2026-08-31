/// This is the Jera Rune--Regens SP slowly for base, more quickly as weapon lvls
#include <std.h>
#include <cp.h>

inherit RUNESTONE;

void create() {
        set_name("runestone");
        set_id( ({"runestone", "stone", "rune", "jera rune"}) );
        set_short("small runestone");
     set_long("%^BOLD%^%^BLACK%^     ___\n"
"   _/   \\_\n"
"  /  %^YELLOW%^/%^BLACK%^    \\\n"
" |  %^YELLOW%^/  \\%^BLACK%^   |\n"
" |  %^YELLOW%^\\   \\%^BLACK%^  |\n"
" |   %^YELLOW%^\\  /%^BLACK%^  |\n"
"  \\_   %^YELLOW%^/%^BLACK%^ _/\n"
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

