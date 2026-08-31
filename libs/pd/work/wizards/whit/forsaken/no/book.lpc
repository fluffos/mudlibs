#include <std.h>
inherit WEAPON;

create() {
    ::create();
    set_id( ({ "book", "spellbook"}) );
    set_name("Book of the Arcane");
    set_short("%^ORANGE%^Book%^BOLD%^%^BLACK%^ of the %^RESET%^%^RED%^A"
      "%^BOLD%^r%^BLACK%^c%^RESET%^a%^BOLD%^%^WHITE%^n%^RED%^e%^RESET%^");
    set("long", "This book hold some of the most arcane magiks from "
      "around the realm..");
    set_weight (10);
    set_curr_value ("gold", 85);
    set_wc (10);
    set_ac (1);
    set_hands (2);
    add_poisoning (15);
    set_type ("blunt");
    set_hit((: this_object(), "weapon_hit" :));
    set_wield("As you hold the %^ORANGE%^book%^RESET%^ a strange wind "
      "passes through");
    set_unwield("The arcane magik within your %^BOLD%^%^RED%^blood%^RESET%^ "
      "seems to subside");
}

int weapon_hit() {
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 30) {
        write("You recite some %^RED%^a%^BOLD%^r%^BLACK%^c%^RESET%^a%^BOLD%^"
          "%^WHITE%^n%^RED%^e%^RESET%^ words at your oponent, making them "
          "look %^BOLD%^%^GREEN%^sick%^RESET%^");
        message("attack", ""+(string)this_player()->query_cap_name()+
          " recites some "
          "%^RED%^a%^BOLD%^r%^BLACK%^c%^RESET%^a%^BOLD%^%^WHITE%^n%^RED%^"
          "e%^RESET%^ words at their oponent, making them look %^BOLD%^"
          "%^GREEN%^sick%^RESET%^", environment(this_player()), ({ this_player(), atk }) );
        message("attack", "You start to feel sick after "+
          this_player()->query_cap_name()+" recites some %^RED%^a"
            "%^BOLD%^r%^BLACK%^c%^RESET%^a%^BOLD%^%^WHITE%^n%^RED%^e"
            "%^RESET%^ words.", atk);
        result = (random(75)+25);
        this_player()->add_hp(result);
    }
}
int query_auto_load() {
    if(this_player()->query_guild() == "forsaken") return 1; else return 0;
}
