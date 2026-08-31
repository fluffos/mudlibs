#include <std.h>
#include <blackserver.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
   set_properties( ([ "no teleport" : 1]) );
    set_property("mountain",1);
   set_short("Adavi Swamp");
    set_day_long(
      "The path leads to a dead end. Nestled at the "
      "base of this large mountain is a large muddy "
      "wallow. Small white flowers ring the mud hole, "
      "contrasting the deep green grass, sharply against "
      "the ruddy earth below. A few patches of green grass "
      "and flowers climb the base of the mountain."
    );
    set_night_long(
      "The path leads to a dead end. Nestled at the "
      "base of this large mountain is a large muddy "
      "wallow. Small white flowers ring the mud hole, "
      "contrasting the deep green grass, sharply against "
      "the ruddy earth below. A few patches of green grass "
      "and flowers climb the base of the mountain."
    );
    set_items(([
        "path" : "The path leads to a large mud ho
e, "
                 "the only way out of here is back the "
                 "way you came.",
        "base" : "Along the west wall, a huge boulder leans "
                 "against it.  A small pond of mud gurgles "
                 "before you while white flowers dances in the "
                 "breeze around it.",
        "wallow" : "It looks looks warm and inviting.",
        "mud"  : "Deep black in color and small bubbles rise "
                 "to the top and bursts.",
        "flowers"   : "They are scattered all along the "
                      "outskirts of the pond.",
        "grass"   : "Grows in small tufts along the outer "
                    "rim of the wallow.",
        "earth"  : "It's very dark in color, almost black.",
        "wall"   : "The wall of this mountain is very smooth. "
                   "Small patches of grass and flowers climbs "
                   "about knee high in length the abrubtly stops.",
        "mountain" : "Shiney black pebbles gleams and twinkles "
          
          "under the nature's light.",
        "boulder" : "It is round, and seems to be covering up "
                    "a hole.",
    ]));
    set_smell("default",
"A mixture of earth and water scents the air.");
    set_exits( ([
"northeast" : BLACK "b24",
    ]) );
}
void init() 
{
    ::init();
    add_action("rollfunc", "roll");
}
int rollfunc(str)
{
    if(str == "boulder")
    {
        write("You push the boulder with all your might."); 
        message("room message", this_player()->query_cap_name()+" rolls the boulder", this_object(), this_player()); 
this_player()->set_paralyzed(16);
        call_out("roll2", 5); 
        return 1;
    }
}
int roll2()
{
    write("The boulder resists a little bit and then nudges.");
        call_out("roll3", 5); 
    return 1;
}
int roll3()
{
    write("Muscles start to ache, but the opening is growing wider.");
        call_out("roll4", 5); 
    return 1;
}
int roll4()
{
    write("Finally the opening is wide enough and you squeeze through before the boulder rolls back.");
       this_player()->move_player(BLACK "b36", "dissappears into the rock."); 
    return 1;
}
