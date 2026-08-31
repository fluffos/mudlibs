#include <std.h>
#include <amun.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("paw warmers");
    set("id", ({ "gloves", "paw warmers", "paw", "warmers" }) );
    set("short",
      "%^RESET%^%^ORANGE%^P%^RESET%^a%^ORANGE%^w "
      "%^RESET%^W%^ORANGE%^a%^RESET%^r%^ORANGE%^m"
      "%^RESET%^e%^ORANGE%^r%^RESET%^s"
    );
    set("long",
      "%^RESET%^%^ORANGE%^These thick coverings can protect a bastet's paws "
      "from damage and keep them warm, too. "
      "This pair is fitted for the front paws.%^RESET%^"
    );
    set_type("gloves");
    set_ac(1);
    set_limbs( ({ "right paw", "left paw" }) );
    set_weight(25);
    set_curr_value("gold", 100); 
}
int query_auto_load() {
    return this_player()->query_level() >= 30;
}
