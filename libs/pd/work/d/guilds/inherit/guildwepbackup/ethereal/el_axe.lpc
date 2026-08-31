#include <std.h>
#include <ether.h>
inherit ETHERWEP;
int weapon_hit();
create() {
    ::create();
    set_id(({"dragon axe","dragonaxe","axe"}));
    set_name("Dragon Axe");
    set_short("%^BOLD%^%^BLACK%^Dragon %^RESET%^%^RED%^Axe%^RESET%^");
    set_long("%^RED%^This axe was passed down from the DragonLords of Primal Darkness. "
         "The blade is made of a single piece of flawless diamond. "
         "A picture of a dragon has been embedded within the diamond blade. "
         "The handle is made of an unknown material and has been etched with undecipherable symbols. "
         "No one knows where or how the creators of this axe obtained the material to create this axe. "
         "The one thing that you can be sure of, is this axe is truly a weapon of mass destruction.%^RESET%^");
    set("skill level", 240);
    set_weight(30);
    set_curr_value("gold", 800);
    set_wc(13);
    set_ac(1);
    set_type("axe");
    set_hands(1);
    set_wield("%^YELLOW%^You feel the DragonLords are watching over you.%^RESET%^");
    set_unwield("%^ORANGE%^The spirits of the DragonLords are no longer present.%^RESET%^");
    set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) > 84) {
        write("%^BOLD%^%^WHITE%^The dragon in your axe emerges from the blade for a split second, "
              "breathing a huge %^RESET%^%^RED%^f%^BOLD%^i%^YELLOW%^r%^RESET%^%^ORANGE%^e%^RED%^b%^BOLD%^a%^YELLOW%^l%^RESET%^%^ORANGE%^l%^RESET%^%^BOLD%^%^WHITE%^ towards your opponent and stuns them senseless!");
        say("%^BOLD%^%^WHITE%^A dragon emerges from an unknown source and breathes a huge %^RESET%^%^RED%^f%^BOLD%^i%^YELLOW%^r%^RESET%^%^ORANGE%^e%^RED%^b%^BOLD%^a%^YELLOW%^l%^RESET%^%^ORANGE%^l%^RESET%^%^BOLD%^%^WHITE%^!%^RESET%^");
        result=(random(50)+(this_player()->query_skill("axe"))/4);
        atk->set_paralyzed(2);
        return result;
    }
}

int query_auto_load() { 
if (this_player()->query_level()>49) return 1; 
return 0;
}
