#include <std.h>
inherit WEAPON;

void create() {
  ::create();

    set_name("rusty dagger");
    set_id( ({ "dagger", "rusty dagger" }) );
    set_short("Rusty dagger");
    set_long("A short dagger that has been rusted badly, it looks almost useless now.");
    set_type("knife");
    set_wc(3);
    set_weight(10 + random(5));
    set_curr_value("copper", 25 + random(20));

}
int query_auto_load() { return 1; }
