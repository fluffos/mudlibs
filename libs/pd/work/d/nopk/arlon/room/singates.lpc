#include <std.h>
#include <arlon.h>
inherit ROOM;

void create() {
 ::create();
    set_property("beach",1);
   set_short("The southern gates of Sindarii");
   set_long("The beach ends at the southern gates of Sindarii. "
            "A small, scatered forest starts to the south, then "
            "opens into a large plains. The tall gates cast a "
            "mighty shadow across the room.");
   set_items(([ "gates" : "The tall, golden gates send a shadow upon the room." ]));
   set_exits(([ "north" : "/d/standard/beach7",
                "gates" : ROOMS+"s_gates" ]));
}

void reset() {
 ::reset();
   if (!present("peacekeeper")) {
      new(MOB+"soldierkeeper")->move(this_object());
      new(MOB+"soldierkeeper")->move(this_object());
   }
   if (!present("gates"))
     new(OBJ"dawn")->move(this_object());
}
void init()
{
 ::init();
 add_action("go_gates", "gates");
 add_action("go_gates", "north");
}
int go_gates()
{
 if(!present("peacekeeper")) return 0;
 if (this_player()->query_pk_flag())
   {
    present("peacekeeper")-> force_me("shout "+this_player()->query_cap_name()+" is an outlaw and will die!!!");
    this_player()->move("/d/standard/jail");
    present("peacekeeper")->force_me("say listen up you outlaw. You will stay here and not leave until you serve your time.");
    write("You have been moved to the jail.");
    this_player()->force_me("look");
    new("/d/standard/obj/misc/handcuff")->move(this_player());
    return 1;
   }
  return 0;
}
