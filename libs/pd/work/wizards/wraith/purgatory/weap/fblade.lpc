#include <std.h>
inherit WEAPON;
create() {
    ::create();
    set_id(({"blade", "sword"}));
    set_name("%^BOLD%^%^BLACK%^Fo%^BOLD%^%^WHITE%^rb%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^dd%^BOLD%^%^BLACK%^en %^BOLD%^%^BLACK%^B%^BOLD%^%^WHITE%^l%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^d%^BOLD%^%^BLACK%^e");
    set_short("%^BOLD%^%^BLACK%^Fo%^BOLD%^%^WHITE%^rb%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^dd%^BOLD%^%^BLACK%^en %^BOLD%^%^BLACK%^B%^BOLD%^%^WHITE%^l%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^d%^BOLD%^%^BLACK%^e");
    set_long( "%^BOLD%^%^BLACK%^This %^BOLD%^%^BLACK%^B%^BOLD%^%^WHITE%^l%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^d%^BOLD%^%^BLACK%^e was forged by an insane smith using metals tainted by evil.");
    set_mass(60+random(10));
    set_curr_value("gold",75+random(10));
    set_wc(12);
    set_ac(2);
    set("skill level", 300);
    set_type("blade");
    set_wield("%^BOLD%^%^BLACK%^The sword quivers with evil and a cold chill creeps up your arm.");
    set_unwield("%^BOLD%^%^WHITE%^The chill receeds from your body as the sword releases you.");
    set_hit((:this_object(), "weapon_hit":));
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("%^BOLD%^%^BLACK%^Your %^BOLD%^%^BLACK%^Fo%^BOLD%^%^WHITE%^rb%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^dd%^BOLD%^%^BLACK%^en %^BOLD%^%^BLACK%^B%^BOLD%^%^WHITE%^l%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^d%^BOLD%^%^BLACK%^e rips the flesh of "+atk->query_cap_name()+".");
        say(""+(string)this_player()->query_cap_name()+"'s %^BOLD%^%^BLACK%^Fo%^BOLD%^%^WHITE%^rb%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^dd%^BOLD%^%^BLACK%^en %^BOLD%^%^BLACK%^B%^BOLD%^%^WHITE%^l%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^d%^BOLD%^%^BLACK%^e chops deeply into "+atk->query_cap_name()+".");
       
result= (random(120)+10);

    }
}
 int query_auto_load() { if (this_player()->query_level() > 44) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_name() == "Purgatory townsman") return 0;
   write("Wielding this sword would not be a good idea.");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}
