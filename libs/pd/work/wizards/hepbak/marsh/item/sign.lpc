#include <std.h>
#include <marsh.h>
inherit OBJECT;
void init() {
    ::init();
    add_action("read_sign", "read");
}
void create() {
 ::create();
   set_id(({ "sign" }));
   set_name("sign");
   set_long("It's a simple sign covered in mud.");
   set_short("A sign covered in mud");
   set_weight(1);
   set("value", 0);
set_prevent_get( "You can't get that, it's stuck in the mud." );
}
int read_sign(string str) {
    if(!str) {
        notify_fail("Read what?\n");
        return 0;
    }
    if(str != "sign" && str != "Sign") {
        notify_fail("That is not here.\n");
        return 0;
    }
    write("Welcome to Mystic Marsh");
     return 1;
}
