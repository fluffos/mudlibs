#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 2, "night light" : 2, "indoors" : 1]) );
    set_short("Palace Gates");
    set_smell("default", "The smell of armour and sweat is strong here.");
    set_listen("default", "The shuffle of armour when a guard moves can be barely heard.");
    set_long("The entrance to the Palace of the King is a large archway carved out of sandstone, placed here as a welcoming to all the citizens of NuShae. Two guards stand watch here for those whom they deem would cause trouble in the Palace, yet all are still allowed inside. Everyone may enter the Palace, or head back west towards the bright lights of the public square.");
    set_night_long("In the dark, a large archway can be seen here, carved beautifully out of sandstone, it marks the entrance to the Palace, and is a welcome note for all. Two guards stand watch here, looking comfortable in the dark of night instead of nervous. Anyone can enter the Palace, even at night, or head back west to the brightly lit public square.");
    set_items((["palace" : "The Palace stands tall, with four visible towers rising towards the surface of the ocean. The doors leading inside are open and inviting.", "lights" : "The bright lights mark the presence of the NuShae Public Square.", "archway" : "A soft yellow color, looking over two centuries old, the archway is a signal of peace and understanding."]));
    set_exits( (["west" : ROOMS"t3", "enter" : ROOMS"p1", "up" : ROOMS"guard1"]) );
}

void reset() {
  ::reset();
  if(!present("guard")) {
    new(MOB"guard")->move(this_object());
    new(MOB"guard")->move(this_object());
  }
}
