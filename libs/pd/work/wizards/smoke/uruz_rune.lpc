#include <std.h>
#include <cp.h>

inherit RUNESTONE;

void create() {
        set_name("runestone");
        set_id( ({"runestone", "stone", "rune", "uruz rune"}) );
        set_short("%^BOLD%^%^BLACK%^small runestone");
     set_long(" \n%^BOLD%^%^BLACK%^"
	     "    __\n        "
	     "  _/  \_\n	    "
             " /  %^GREEN%^|\%^BLACK%^  \\n       "
	     "|   %^GREEN%^| \%^BLACK%^  |\n	    "
	     "|   %^GREEN%^|  \%^BLACK%^ |\n	    "
	     " \_    _/\n	    "
	     "   \__/\n 	   %^RESET%^ ");
        set_weight(2);
        set_value(0);
}
int query_auto_load() {
      object tp=this_player();
      int tp_lvl=(this_player()->query_level());
      if(tp_lvl >=1) {return 1;}
      else {return 0;}
}
