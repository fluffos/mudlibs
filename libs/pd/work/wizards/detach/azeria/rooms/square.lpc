#include <std.h>
#include <azeria.h>
inherit ROOM;

void create() {
   object oi;
   ::create();
   set_name("Azeria Square");
   set_items((["sky"   : "The sky glows with a white aura",
               "ground"  : "The ground seems to glow with a yellow aura"]));   

   set_properties((["light":2, "night light":3]));
   set_short("Azeria Square");
   set_long("%^BOLD%^%^BLUE%^Welcome to Azeria Square, Where Healer's come to converse. "
"This town seems to be a very holy place. Every where you look, a strange aura
follows.");
set_exits( (["east" : ROOMS"room2",  "south"  :  ROOMS"room24",  "west" : ROOMS"room28",  "north" : ROOMS"room39"])
);     
   
    oi = new("/std/bboard");
    oi->set_name("azeria board");
    oi->set_id( ({ "board", "azeria board", "healer board" }) );
    oi->set_board_id("azeria_board");
    oi->set_max_posts(100);
    oi->set_location("/wizards/detach/azeria/rooms/square");
    oi->set("short", "Azeria Healer Board");
    oi->set("long", "This board is for the Healers of Azeria");


}
