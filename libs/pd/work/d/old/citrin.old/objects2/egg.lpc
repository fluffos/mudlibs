// Coded by Whit

#include <std.h>
#include <citrin.h>
inherit OBJECT;

void init() {
::init();
add_action("crack", "crack");
}

int crack(string str) {
if(!str) return 0;
write("The egg cracks open to reviel a baby raknid.");
new(MON2"braknid")->move();
this_object()->remove(this_object());
return 1;
}

void create() {
::create();
set_name("egg");
set_id(({ "egg", "raknid egg", "egg_citrin" }));
set_short("a baby raknid egg");
set_long("This is a baby raknid egg.  There is a faint noise coming from the "
"egg.");
}
