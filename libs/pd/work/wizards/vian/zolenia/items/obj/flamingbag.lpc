#include <std.h>
inherit BAG;
void create() {
    ::create();
    set_id( ({"bag", "flamingbag", "flaming bag"}) );
    set_name("%^RED%^fl%^YELLOW%^a%^RED%^mi%^YELLOW%^ng b%^RED%^ag%^RESET%^");
    set("short", "%^RED%^fl%^YELLOW%^a%^RED%^mi%^YELLOW%^ng b%^RED%^ag");
    set_weight(20);
    set("long", "%^RED%^This %^RED%^fl%^YELLOW%^a%^RED%^mi%^YELLOW%^ng b%^RED%^ag looks as if it burns items down to hold a large quantity of things.");
    set_curr_value("gold", 2500);
    set_max_internal_encumbrance(3500+random(500));
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 4);
}
