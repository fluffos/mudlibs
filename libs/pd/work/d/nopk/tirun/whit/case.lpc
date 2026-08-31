#include <std.h>
inherit OBJECT;
void create() {
::create();
set_name("Trophy Case");
set_short("a trophy case");
set_long("This is the trophy case.  Many trophies from past Laser Tag games "
"are kept here.");
set_prevent_get("You may not take the trophy case!");
set_id(({"case", "trophy case" }));
}
void init() {
::init();
add_action("list", "list");
add_action("look", "look");
}
int list() {
string *dir;
int i;
message("info", "The following people have claimed a trohpy:",this_player());
dir = get_dir("/d/tirun/whit/trophies/");
for(i=0; i<sizeof(dir); i++) dir[i] = replace_string(dir[i], "_", "");
message("info", replace_string(format_page(dir, 3), "\n", " "),
this_player());
message("info", "You may <look 'trophy'> to see more about that players "
"score", this_player());
return 1;
}
int look() {
return 0;
}
