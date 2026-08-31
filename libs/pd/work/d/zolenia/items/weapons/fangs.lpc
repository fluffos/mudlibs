#include <std.h>
#include <zolenia.h>
inherit WEAPON;

void create() {
::create();
    set_name("fangs");
    set_short("%^RESET%^%^BOLD%^crystalline%^RESET%^ fangs");
    set_long("These are the strangest spider's fangs that you would never find above land..  they are made purely of crystal, and very sharp.");
    set_id(({"fangs", "crystalline fangs"}));
    set_weight(2);
    set_type("knife");
    set_wc(10);
    set_ac(1);
    set_curr_value("gold", 80);
}
int query_auto_load()
{
if (this_player()->query_level() > 33) return 1;
}
