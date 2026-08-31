// syphon

#include <std.h>
#include <rain.h>
inherit ROOM;

void init() {
::init();
//   add_action("climb_up", "climb");
}

void create()
{
 ::create();
set_short("lost in the rain forest");
set_long("The carpet of moss is barely visible from here, "
        "because of the deep puddle of mud. The thin drizzle of rain still patters against the "
     "canopy of leaves.\n%^GREEN%^%^BOLD%^Two long vines are here.");
    set_property("forest", 1);
  set_property("light", 3);
set_property("night light", 1);

   set_items((["vines" : "Several long vines hang here. Mabye you could climb them?"]));
set_smell("default", "The humid air stifils your senses.");
set_listen("default", "You hear animals squeaking.");

   set_exits( (["north" : ROOMS"dirt2", 
                "south" : ROOMS"dirt3"]) );
}

int climb_up(string str)
{
 if (!str || str=="")
   {
    message("info", "Climb what?", this_player());
    return 1;
   }
 if (str!="vines") return notify_fail("You cannot climb that!\n");

 if(this_player()->query_stats("strength") < 20 + random(20)) {
    message("info", "You try to climb the vines, but are not strong enough to pull yourself up.", this_player());
    say(this_player()->query_cap_name()+" tries to climb up, but is too weak to pull themselves up.");
    return 1;
 }
 message("info", "You make a jump for a vine and grab it.", this_player());
 this_player()->move_player(ROOMS"canopy1", "into the trees.");
 return 1;
}

void reset(){
   ::reset();
   if(!present("gremlin"))
   new(MOB"gremlin")->move(this_object());
 }
