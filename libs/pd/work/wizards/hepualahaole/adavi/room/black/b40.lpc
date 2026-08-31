#include <std.h>
#include <blackserver.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
   set_properties( ([ "no teleport" : 1]) );
    set_property("mountain",1);
    set_short("Nogard path");
    set_day_long(
      "The path abruptly ends at a wall of trees. The "
      "trees are grown so close together that they form "
      "an unbroken barrier. Twisted branches block your "
      "view of what lays beyond. Gnarled roots dig deeply "
      "into thick black mud. Looking back, the sun dapples "
      "the path going west. "
 
    );
    set_night_long(
      "The path abruptly ends at a wall of trees. The "
      "trees are grown so close together that they form "
      "an unbroken barrier. Twisted branches block your "
      "view of what lays beyond. Gnarled roots dig deeply "
      "into thick black mud. Looking back, the moon shimmers "
      "the path going west. "
      
    );
    set_items(([
        "path" : "Ends abrubtly at a wall of trees.",
        "wall" : "Made of trees that have grown close "
                 "together.",
        "trees" : "The trees were grown close together to "
                  "form a wall.",
         "branches"   : "Thick and gnarly, almost like fingers "
                        "grabbing for you.",
        "roots"   : "Because the trees were grown so close "
                    "together, the roots grew in too thickly "
                    "causing some of them to grow above ground.  "
                    "There seems to be a small opening among them.",
        "mud"  : "Pitch black in color, some tracks seem to go "
                 "right through the wall of trees.",
        "opening"   : "Sure enough, there is a passage way "
                      "through, but it doesn't seem to be "
                      "wide enough.",
        "ground"  : "Very muddy, with gnarled roots growing "
                    "upwards because of lack of space.",
    ]));
    set_smell("default", "The pungent aroma of wet earth fills your nostrils.");
    set_exits( ([
"west" : BLACK "b41",
    ]) );
}
void init() 
{
    ::init();
    add_action("partfunc", "part");
}
int partfunc(str)
{
    if(str == "roots")
    {
        write("You part the roots, and see that the path continues on the other side.");
        message("room message", this_player()->query_cap_name()+" parts the roots.", this_object(), this_player());
      add_exit(BLACK "b30" , "enter");
        return 1;
    }
}
