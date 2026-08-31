// Coded by Whit
// Letter

#include <std.h>

inherit OBJECT;

void create() {
::create();
set_name("letter");
set_long("This is a small letter.  It is marked from the high priest.  You may be "
"able to read it.");
set_short("a small, tarnished letter");
set_id(({"letter", "tarnished letter"}));

}

void init() {
::init();
add_action("read", "read");
}

int read(string str) {
if(!str) return 0;
if(str != "letter") return 0;
write("");
call_out("burn", 3);
return 1;
}

void burn() {
write("The entire letter seems to set itself on fire.  It burns away to nothing.");
this_object()->remove(this_object());
}
