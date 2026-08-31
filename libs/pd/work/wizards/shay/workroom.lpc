#include <locations.h>
#include <locations.h>
//      from the Nightmare mudlib
//      an example workroom for new immortals

#include <std.h>

inherit ROOM;

string get_desc()
{
 if (this_player()->query_name()!="admin")
   {
    return "How in the hell did you get here?! shoo before you feel my "
           "wrath you innocent mortal, or immortal.";
   }
    return "You have entered the workroom for seeker, the main admin on "
           "Carnage, the place is covered in plans, papers, old "
           "code. This place is hella messy";
   
}
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The workroom of a new immortal");
/* 
   set("night long", "It is night outside.\nA new immortal works here.\n");
    set("day long", "It is day outside.\nA new immortal works here.\n");
*/
   set_long( (: get_desc :) );
     set_exits( ({ SQUARE_LOC, "/d/tirun/adv_main" }),
      ({ "square", "hall" })
    );

    set_smell("default", "It smells like a new immortal in here.");
    set_listen("default", "You hear the sounds of code creation.");
}
