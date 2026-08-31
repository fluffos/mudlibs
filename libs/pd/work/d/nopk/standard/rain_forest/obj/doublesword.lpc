#include <std.h>
inherit WEAPON;

create() {
    ::create();
    set_name("sword");
    set_short("A vicious two-handed sword");
    set_long("This sword is razor-sharp.  The blade is about 4 feet "
      "long, and 1 foot wide.");
    set_type("blade");
    set_hands(2);
    set_weight(20);
    set_wc(8);
    set_curr_value("gold", 150);
    set_id(({"sword", "two-handed sword", "two handed sword", "vicious sword"}));
}
int query_auto_load() { if(this_player()->query_level() >=10) return 1; }
