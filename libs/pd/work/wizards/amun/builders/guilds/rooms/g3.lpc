#include <std.h>
#include <daemons.h>
#include <guild.h>
#include <boat.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no steal"    : 1 ]) );
    set_property("town",1);
    set("short", "Guild Town");
    set("long","description");
    set_items(([ "path" : "The path begins to darken as if all life is threatening to become extinct.", "gravel" : "The gravel has barely any color left in it, just blackness.", "vegetation" : "The vegetation is very little and dying quickly.", "plants" : "Some plants are attempting to clutch onto life.", "clouds" : "Black clouds form in the sky blocking the light." ]));
    set_exits( ([ "east" : GROOM "g4", "northeast" : GROOM "g07", "west" : GROOM "g2" ]) );
}
