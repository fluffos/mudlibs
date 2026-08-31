#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
   set_property("mountain",1);
    set_property("no castle", 1);
    set("short", "Eastern end of the Daroq Mountains Pass");
    set("long",
	"To the east, past the pass through the Daroq Mountains, "
        "lies Tirun and the Great Western Highway. Much larger "
        "mountains tower high above the pass. Lining the pass "
        "are openings to several small caves. Two small paths "
        "lead northwest and southwest above the pass.");
    set_items(
	(["pass" : "A gloomy pass through the Daroq Mountains.",
	  "highway" : "The Great Western highway.  It leads into Tirun.",
	  "caves" : "Several cave openings dot the sides of the pass.",
          "openings" : "They are the openings to caves.",
	  "pass" : "From here, the pass heads down westward into "
	    "a mountain range and the Qajip Desert."]));
    set_exits(([ "down" : ROOMS"pass1",
                 "southwest" : ROOMS"spass1",
                 "northwest" : ROOMS"npass1",
                 "west" : ROOMS"pass5" ]));
}

void reset() {
 ::reset();
   if (!present("balrog"))
      new(MOB"balrog2")->move(this_object());
}
