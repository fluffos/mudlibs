#include <std.h>
#include <citrin.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("mermaid");
    set_short("a beautiful mermaid");
    set_long("The mermaid has much beauty.  Her hair flows with "
      "the current.");
    if(random(2)) set_level(40); else
	set_level(50);
    set_gender("female");
    set_race("merfolk");
    set("aggressive",30);
    set_body_type("fish");
    set_id(({ "beautiful mermaid", "mermaid" }));
}


