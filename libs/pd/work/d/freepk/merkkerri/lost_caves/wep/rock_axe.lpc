
#include <std.h>
inherit WEAPON;

void create() {
  ::create();

    set_name("rock axe");
    set_id( ({ "rock axe", "axe" }) );
    set_short("Rock axe");
    set_long("An axe carved from stone, with a bone handle.");
    set_type("axe");
    set_wc(10);
    set_weight(52);
    set_curr_value("gold", 6);
}





int query_auto_load()
{
    if (this_player()->query_level() > 30) return 1;
    return 0;
}
