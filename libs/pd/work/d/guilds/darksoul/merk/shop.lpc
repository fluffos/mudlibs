#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
    ::create();
    set_name("Dark Souls selling");
    set_items((["corpses"   : "%^ORANGE%^A pile of roting corpses",
	"blood"  : "%^RED%^Pools of blood all over"]));
    set_properties(([ "light":1, "night light":1, "no steal":1,
	"no bump":1, "no scry":1, "no gate":1, "no castle":1, "no attack":1,
	"no teleport":1 ]));
    set_short("Dark Souls Shop");
    set_long("%^BOLD%^BLACK%^Swords, daggers, and other weapons of mass destruction "
      "hang %^BOLD%^BLACK%^from the walls alongside the skulls of slain enemies. "
      "A %^BOLD%^BLACK%^shapely leg can be seen through the screen in the back as the "
      "%^BOLD%^BLACK%^storekeeper comes up to the counter with a curse at the %^BOLD%^BLACK%^interruption. "
      "Anubis fidgets behind the counter waiting to %^BOLD%^BLACK%^buy or sell you anything "
      "you need...but make your exchange quick. %^BOLD%^%^WHITE%^Death fills "
      "the room.%^RESET%^");
    set_smell("default", "The smell of iron and weapon oil wafts in the air.");
    set_listen("default", "Heavy panting can be heard nearby.");
    set_exits(([
	"south" : ROOMS"darksoul/merk/hall",
      ]));
}
void reset() {
    ::reset();
    if(!present("anubis"))
        new(DARKSOUL"mon/annubis")->move(this_object());
}
