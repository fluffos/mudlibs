#include <std.h>
inherit WEAPON;

int weapon_hit(object ob);

void create() {
    ::create();
    set_id(({ "morning star", "star", "morning" }) );
    set_name("morning star");
    set_short("%^BOLD%^%^WHITE%^a %^RESET%^double-headed %^BOLD%^%^WHITE%^morning star%^RESET%^");
    set_long("At the end of a short wooden handle, two large black "
      "spiked spheres are attached by thick chain links. It looks quite "
      "dangerous in the right hands.");
    set_weight(12);
    set_curr_value("platinum", 5);
    set_hands(2);
    set_wc(7);
    set_type("flail");
    set_hit((:this_object(), "weapon_hit":));
}

int weapon_hit(object ob) {
    if (this_player()->query_skill("flail") < 30) return 0;
    if (random(2500) > 140) return 0;
    if (!ob) return 0;
    write("%^BOLD%^%^WHITE%^You smash your opponent between the two heads of your morning star!%^RESET%^");
    tell_room(environment(this_player()), "%^BOLD%^%^WHITE%^"+this_player()->query_cap_name()+
      " smashes "+possessive(this_player())+" opponent with the "
      "morning star!%^RESET%^", ({ ob, this_player() }));
    tell_object(ob, "%^BOLD%^%^WHITE%^"+this_player()->query_cap_name()+" smashes you between "
      "the two heads of "+this_player()->query_title_gender()+" morning star!%^RESET%^");
    return this_player()->query_skill("flail")/3 + random(20);
}

int query_auto_load() { if (this_player()->query_skill("flail") >= 20) return 1; }
