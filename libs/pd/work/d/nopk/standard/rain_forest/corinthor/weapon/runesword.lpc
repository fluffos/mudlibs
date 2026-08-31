#include <std.h>
inherit WEAPON;

void create() {
   ::create();
     set_name("runesword");
     set_short("A runesword");
     set_id(({"sword", "runesword"}));
     set_long("A forged steel longsword, it has several runes marked along the flat edge of the blade, and the leather handle makes for excellent grip.");
     set_wc(5);
     set_type("blade");
     set_curr_value("gold", 18);
     set_mass(15);
}

int query_auto_load() {
    if(this_player()->query_level() > 6) return 1;
    return 0;
}
