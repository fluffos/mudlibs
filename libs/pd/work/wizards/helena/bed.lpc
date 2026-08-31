#include <std.h>

inherit OBJECT;

void create() {
::create();
set_name("floating bed");
set_id( ({ "bed", "floating bed"}) );
set_short("A Large Floating Bed");
set_long("The bed is floating in mid air. There are rugs under it that spread to about 3 feet outside the edge of the bed. The bed, you decide, is really comfortable.");
set_weight (100000);
set_prevent_get("This Bed is too awkward and heavy to carry.");;
}

void init() {
::init();
add_action("lie", "lie");
}
int lie(string str) {if(!str)if(str != "bed") return 0;write("You lie down on the bed. It feels so comfy...you may just...fall asleep...");return 1;this_player()->query_rest_type();set_rest_type("4");}
