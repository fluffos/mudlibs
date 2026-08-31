#include <std.h>
inherit BAG;
void create() {
    ::create();
    set_name("chest");
    set_id( ({ "chest", "a chest" }) );
    set_short("%^RESET%^%^ORANGE%^A Large%^RESET%^%^BOLD%^YELLOW%^ Golden%^RESET%^ %^ORANGE%^Chest%^");
    set_long("This giant chest acts as a container for members to drop equipment and other valuables that they no longer desire.\n");
    set_mass(10000000); // No one's picking this thing up.
    set_max_internal_encumbrance(10000);
    set_value(0);
    set_prevent_get("You do not have the strength to move this huge chest!");
}

int is_bag() {return 0;} 
varargs int receive_objects(object ob) { return 1; }
