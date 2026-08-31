#include <std.h>
inherit PACK;

string *guilds = ({ "AoD", "darksoul" });
void create() {
    ::create();
    set_id( ({"sack", "child sack"}) );
    set_name("%^BOLD%^%^BLACK%^Dark %^RESET%^%^ORANGE%^le%^BOLD%^%^BLACK%^at%^RESET%^%^ORANGE%^her %^BOLD%^%^BLACK%^sack%^RESET%^");
    set("short", "%^BOLD%^%^BLACK%^Dark %^RESET%^%^ORANGE%^le%^BOLD%^%^BLACK%^at%^RESET%^%^ORANGE%^her %^BOLD%^%^BLACK%^sack%^RESET%^");
    set_weight(38);
    set("long", "%^BOLD%^%^BLACK%^The dark leather of this sack looks "
      "like it was tandned by a demented soul.  All around the sack, "
      "bits and pieces of a child can be seen, a finger here, an ear "
      "there.  Although grisly, it looks like it could hold quite a bit.%^RESET%^");
    set_curr_value("gold", 90+random(50));
    set_max_internal_encumbrance(1050);
    set_possible_to_close(1);
}
int query_auto_load() {
    if(member_array(this_player()->query_guild(),guilds)) return 1;
    return 0;
}
