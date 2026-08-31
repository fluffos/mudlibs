#include <std.h>
#include <guild.h>

inherit ROOM;
void create() {
    ::create();
    set_name("Darksoul Prayer Room");
    set_properties(([
	"light":2, "night light":2, "no attack":1, "no magic":1, 
	"no bump":1, "no steal":1, "indoors":1, "no teleport":1,
      ]));

    set_long("%^BOLD%^%^BLACK%^An altar dedicated to all the souls who have gone before sits "
      "%^BOLD%^%^BLACK%^here. Members come here to honor those of the past and pray "
      "%^BOLD%^%^BLACK%^to their spirits in times of need.");
    set_exits(([
	"west" : ROOMS"darksoul/dungeon",
      ]));
}
