#include <std.h>
inherit OBJECT;
void init() {
    ::init();
    add_action("get_firework", "take");
}
void create() {
 ::create();
   set_id(({ "station" }));
   set_name("firework station");
 set_long("Free fireworks! All you have to do is <take firework> and <throw firework at [person]>. Enjoy!");
   set_short("A small fireworks station.");
   set_weight(1);
   set("value", 0);
set_prevent_get( "You can't get that, it's for everyone!" );
}
int get_firework(string str) {
    if(!str) {
        notify_fail("Take what?\n");
        return 0;
    }
    if(str != "firework" && str != "fireworks") {
        notify_fail("Take what?\n");
        return 0;
    }
    new("/wizards/wraith/firework")->move(this_player());
    write("Have fun!");
     return 1;
}
