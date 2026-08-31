#include <std.h>
inherit OBJECT;
void create() {
::create();
set_name("paperwork");
set_short("housing paperwork");
set_long("You should 'mark' the location of where you want your house "
"to be.");
set_id(({"paperwork", "housing paperwork"}));
}
void init() {
::init();
add_action("mark", "mark");
}
int mark(string str) {
mixed location;
if(!str || str != "here") return notify_fail("Mark what?\n");
if(environment(this_player())->query_property("build ok")) {
write("You mark this area for constrution.");
location = file_name(environment(this_player()));
write_file("/d/guilds/house", this_player()->query_cap_name()+" marked "+location+" to build on.\n");
this_object()->remove();
return 1;
}
write("You may not build here.\n");
return 1;
}
