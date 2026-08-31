#include <std.h>
#include <citrin.h>

inherit VIRTUALSERVER;
void create() {
    ::create();
    set_how_long(1);
    set_day_sentances( ({
	"The sun light sparkles through the crystal clear water.  "
	"Schools of fish are here swimming around in circles.  A "
	"truly rare occurence.\n%^BOLD%^%^GREEN%^Green%^RESET%^"
	"%^GREEN%^ seaweed is here flowing in the current.%^RESET%^",

	"The sun light sparkles through the crystal clear water.  "
	"Strangely,  not many fish seem to inhabit this part of "
	"the lake.\n%^BOLD%^%^BLACK%^Shadows seem to move about "
	"the lake floor.%^RESET%^",
      }) );
    set_night_sentances( ({
	"All seems quiet in the waters.  It is almost too dark to "
	"see.  Several rocks seem to shine from the lake floor."
      }) ); 
    set_reset_list(({}));
    set_reset_list(({
        MON"lake/eel",
	MON"lake/salmon",MON"lake/swordfish",MON"lake/shark",
	MON"lake/mermaid", MON"lake/merman", MON"lake/tuna",
      }));
    set_item_list(([]));
    set_properties( ([ "light" : 2, "night light" : 0, "lake" : 1,
	"no teleport":1, "no gate":1, "no scry":1 ]) );
    set_short("swimming in a lake");
}


