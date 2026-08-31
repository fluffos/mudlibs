#include <std.h>
#include <guild.h>


inherit ROOM;

void create() {
    ::create();
    set_name("scorpions lair");
    set_short("A scorpions lair.");
    set_long("This is a storage area for some of the rarest "
      "healing substances. Not many are privileged enough to enter this area. The "
      "walls are covered in Shining rare crystals. On the floor you notice many tiny "
      "scorpions crawling all over. ");
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
		    "no teleport" : 1,
		    "no scry" : 1,
		    "indoors" : 1,
                    "no steal"    : 1 ]) );


    set_exits( (["up" : ROOMS"scorpio/hall", ]) );


}

void reset() {
    ::reset();
    if (!present("scorpion", this_object()))
	new(ROOMS"scorpio/scorpion" )->move(this_object());
}
