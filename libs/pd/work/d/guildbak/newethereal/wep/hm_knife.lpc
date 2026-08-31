#include <std.h>
#include <ether.h>
inherit ETHERWEP;

create() {
    ::create();
    set_id(({"claw", "gix"}));
    set_name("Claw of Gix");
    set_short("%^RESET%^%^GREEN%^C%^BOLD%^l%^YELLOW%^a%^WHITE%^w%^RESET%^%^GREEN%^ o%^BOLD%^f %^YELLOW%^G%^WHITE%^i%^RESET%^%^GREEN%^x%^RESET%^");
    set_long("%^GREEN%^This weapon is not crafted by man. It is the severed claw of a beast. "
         "From the size of the thing, one surely wouldn't want to be in the same "
         "room as the creature of whom this claw came from.%^RESET%^");
set_curr_value("gold",100);
    set_weight(20);
    set_value(20);
    set_wc(13);
    set_ac(2);
    set_type("knife");
    set_hands(1);
    set_wield("%^GREEN%^You feel like ripping things apart.%^RESET%^");
    set("skill level", 50);
    set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
    int result;
    object atk, tp;
    tp = this_player();
    atk = (object)this_player()->query_current_attacker();
    if(random(100) > 90) {
        write("Your claw rips a huge part of your opponent's skin off!");
        say(" "+tp()->query_cap_name()+"'s claw rips "+atk->query_cap_name()+"'s skin off!"); 
result = result = (((tp->query_skill("knife")) * tp->query_stats("dexterity"))/35);
return result;
}

return 0;
}

