#include <std.h> 
#include <amun.h>
inherit BAG;
void create() {
    ::create();
    set_name("Black Casket");
    set("id", ({"casket", "large casket"}) );
    set_short("%^BOLD%^%^BLACK%^A L%^WHITE%^a%^BLACK%^rge C%^WHITE%^a%^BLACK%^sket%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Normally this casket would hold a dead body, but the leaders of the Last Saints recycled it and now use it for members to store things they no longer need or want.%^RESET%^");
    set_mass(1);
    set_max_internal_encumbrance(10000);
    set_value(0);
    set_prevent_get("It is too heavy!");
}

int is_bag() { 
    return 0;
}
