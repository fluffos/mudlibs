#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
    set_name("Illuminati Shop");
    set_properties((["light":3, "indoors":1, "no attack":1]));
    set_short("Illuminati Shop");
    set_long("The equipment store for the Illuminati, it is here where members may purchase "
      "special guild items such as weapons, armour, shields and other things that can "
      "be worn and wielded. All sorts of display items are hung all around the walls. "
      "The hall is out to the northwest.");
    set_smell("default", "The smell of iron and weapon oil wafts in the air.");
    set_listen("default", "Heavy panting can be heard nearby.");
    set_exits(([
	"northwest" : ROOMS"illuminati/hall",
      ]));
}
void reset() {
    ::reset();
    if(!present("perrin"))
	new(ROOMS"illuminati/mobs/eqsmith")->move(this_object());
}
