#include <std.h>
inherit WEAPON;

create() {
  ::create();
        set_id(({"staff", "quarterstaff"}));
        set_name("quarterstaff");
        set_short("%^RESET%^ORANGE%^Quarterstaff%^RESET%^");
        set_long("The quarterstaff is a useful weapon, capable of simultaneously blocking and attacking. This one, though made of wood, has been magically treated to be hard as steel. A method often used by the Kra'toan race.");
        set_weight(30);
        set_curr_value("gold",140);
        set_wc(12);
        set_ac(3);
        set_type("blunt");
        set_hands(2);
        set_wield("You twirl the staff in your hands.");
        set_decay_rate(1000);
}
int query_auto_load() {
    if(this_player()->query_level() > 44) return 1;
    return 0;
}
