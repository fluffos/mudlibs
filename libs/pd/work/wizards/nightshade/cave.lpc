#include <locations.h>
#include <std.h>
// If you modify the following line, I will NOT be happy.
#define ALLOWED ({"greysha", "nightshade", "stormbringer", "azire"})
inherit ROOM;

void create() {
   ::create();
   set_properties( ([ "light" : 2, "indoors" : 1, "no gate" : 1, "no teleport" : 1, "no scry" : 1]) );
    set_short("Crystal Cave");
    set_long(
      "%^RESET%^%^BOLD%^The large crystal cave sparkles with a glow "
      "all of it's own.  The walls are smooth with wide %^RESET%^r%^BOLD%^i%^RESET%^p%^BOLD%^p%^RESET%^l%^BOLD%^e%^RESET%^s%^BOLD%^, casting "
      "beautiful patterns of light across the cave.  The floor is covered "
      "in thornless %^RED%^roses%^RESET%^%^BOLD%^ that soften every step.  A large pile in the "
      "center of the cave looks like a wonderful place to lounge.  There "
      "is a small %^MAGENTA%^portal%^WHITE%^ at the far wall.");
    set_items(([
        ({"cave", "crystal", "wall", "walls"}) : "The crystal is clear and flawless, but as far into it as you can peer, you see only more crystal.",
        ({"patterns", "ripples"}) : "The patterns of light form broad curves and swirls, broken only occasionally by your shadow.",
        "floor" : "The entire floor is covered in roses, making it very soft and cushy.",
        "roses" : "All these roses were given to Nightshade by his beautiful wife Azire.  He has put them to good use in this special "
                  "place that only they are able to enter.",
        ({"pile", "center"}) : "The deep pile of roses is large enough for two people to easily sit or lay down on.  You reach out and "
                               "press on the pile, finding it quite soft and comfortable for laying down upon.",
        "portal" : "As you look at the portal you can see the activity of the Tirun Square, yet they do not seem to notice the portal "
                   "is there."
    ]));
    set_smell("default", "The air is fresh and clean, with a slight hint of rose fragrance.");
    set_listen("default", "The sound of each footstep or movement is dampened by the soft roses scattered across the cave.");
    set_exits( ([ 
        "portal" :  SQUARE_LOC
    ]) );
}

void init() {
  ::init();
  if(member_array(this_player()->query_name(), ALLOWED) == -1) {
    this_player()->move(SQUARE_LOC);
    message("info", capitalize(this_player()->query_name())+" tries to enter the cave, but is thwarted by the magical field.", this_object());
    message("info", "You were not invited and have been moved elsewhere.", this_player());
  }
}
