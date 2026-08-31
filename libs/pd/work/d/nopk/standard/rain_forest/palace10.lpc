#include <std.h>
#include <rain.h>
inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "light" : 3, "night light" : 2, "indoors" :1 ]) );
    set_short("Council Room");
    set_long("There are very elegant looking chairs around the tables.  On "
      "all the tables, there are nice vases with roses on them.  There is "
      "a large couch in the corner for after meetings.");
    set_items((["chairs" : "These are wooden chairs with super fluffy "
	"pillows on the top.",
	"table" : "This table is oddly circle",
	"vaces" : "These contain roses",
	"roses" : "These are brightly colored roses",
	"couch" : "A very fluffy couch for after meetings"]));
    set_exits((["northeast" : ROOMS"palace9"]));
}

void reset() {
    ::reset();
    if(!present("council member")) {
	new(MOB"member")->move(this_object());
	new(MOB"member")->move(this_object());
	new(MOB"member")->move(this_object());
	new(MOB"member")->move(this_object());
    }
}
