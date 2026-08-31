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
      "The trees thin out a bit as a large boulder comes into "
      "view.  The boulder rises out of the earth and comes to a "
      "steep point, making it impossible to climb over it to "           "continue the journey north.  Along the east wall, some vines "
      "cling onto it.  The path to the south leads back "
      "through the swamp."
    );
    set_night_long(
      "The trees thin out a bit as a large boulder comes into "
      "view.  The boulder rises out of the earth and comes to a "
      "steep point, making it impossible to climb over it to "           "continue the journey north.  Along the east wall, some vines "
      "cling onto it.  The path to the south leads back "
      "through the swamp."
    );
    set_items(([
        "trees" : ".",
        "boulder" : ".",
        "earth" : ".",
        "point"  : ".",
        "path"   : ".",
        "wall"   : ".",
        "vines"  : ".",
        "wall"   : ".",
        "swamp" : ".",
    ]));
    set_smell("default", "A fresh earthy smell fills your lungs.");
    set_exits( ([
"south" : BLACK "b22",
    ]) );
}
void init() 
{
    ::init();
    add_action("climbfunc", "climb");
}
int climbfunc(str)
{
    if(str == "vines")
    {
        write("You start your ascent up the vines."); 
        message("room message", this_player()->query_cap_name()+" climbs up the vines.", this_object(), this_player()); 
        call_out("climb2", 3); 
        return 1;
    }
}
int climb2()
{
    write("You scurry up the vines with ease.");
        this_player()->move_player(BLACK "b13", "climbs up the vines."); 
    return 1;
}
