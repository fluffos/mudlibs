#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

string query_long(string str) {
   object ob;
   if (str) return ::query_long(str);
   if (load_object(ROOMS"l1m5")->query_bell()) { 
    return "The top of the temple's bell tower has a very holy feeling "
     "about it. The ceiling is a yellow and white glowing energy field. "
     "Archangels come here to ascend their bodies into the heavens. A "
     "very large golden and copper bell hangs suspended from the ceiling "
     "by a single thick rope. Day in and day out, the room is magically "
     "lit by the ceiling alone.";
   } else { 
    return "The top of the temple's bell tower has a very holy feeling "
     "about it. The ceiling is a yellow and white glowing energy field. "
     "Archangels come here to ascend their bodies into the heavens. "
     "Day in and day out, the room is magically lit by the ceiling alone. "
     "Stairs lead down the bell tower towards the bottom floor. Strangely, "
     "there is no bell at the top of the bell tower.";
    }
}

void create() {
 ::create();
   set_short("The top of the temple's bell tower");
   set_items(([
     "ceiling" : "In place of a ceiling, there is a yellow force field "
                 "with white lightning shooting across it.",
     "light"   : "Bright yellow and white light.",
     "bell"    : "Those foolish souls in search of a cheap thrill could "
                 "jump onto it."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "indoors" : 1 ]));
   set_exits(([
     "down" : ROOMS"l2m5"
   ]));
}

int ascend() {
   if (this_player()->query_race() != "archangel") return 0;
   write("%^YELLOW%^You ascend into the heavens.");
   say("%^YELLOW%^"+this_player()->query_cap_name()+" ascends "+
     this_player()->query_title_gender()+" body into the heavens.",
     this_player());
   this_player()->move_player("/wizards/inferno/angel/main", "into the "
     "light");
   return 1;
}

int jump_bell(string str) {
   object ob;
   if (!str) return 0;
   if (str != "bell" && str != "onto bell" && str != "onto the bell")
     return 0;
   if (!load_object(ROOMS"l1m5")->query_bell()) { write("There is no bell to jump onto!"); return 1; }
  if (date(time()) != 7) { write("The bell has been raised too high to reach."); return 1; }
   write("You leap like a fool and grab onto the bell.");
   say(this_player()->query_cap_name()+" jumps like a fool and grabs onto "
     "the bell. The bell swings, but "+this_player()->query_cap_name()+
     "manages to stablize it.", this_player());
   this_player()->move_player(ROOMS"l3bell", "bell");
   return 1;
}

void init() {
 ::init();
   add_action("ascend", "ascend");
   add_action("jump_bell", "jump");
}
