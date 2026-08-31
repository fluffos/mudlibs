#include <std.h>
inherit "/std/bag_logic";



void create() {
    ::create();
    set_id( ({"websack", "sack"}) );
    set_name("websack");
    set("short", "%^RESET%^%^RED%^S%^BOLD%^%^RED%^p%^BLACK%^i%^RESET%^d%^BOLD%^%^BLACK%^e%^RED%^r%^RESET%^%^RED%^s W%^BOLD%^%^RED%^e%^BLACK%^b%^RESET%^s%^BOLD%^%^BLACK%^a%^RED%^c%^RESET%^%^RED%^k%^RESET%^");
    set_weight(41);
    set("long", "A sack formed from the strongest webbing of a %^BOLD%^%^BLACK%^Dire Spider.%^RESET%^");
    set_curr_value("gold", 90);
    set_max_internal_encumbrance(999);
}
int query_auto_load() {
if(this_player()->query_guild() == "acheron") return 1;
return 0;
}
