#include <std.h>
inherit WEAPON;
int weapon_hit();

create() {
::create();
set_id(({"scepter","blunt","large scepter","large"}));
set_name("Large Scepter");
set_short("Large golden scepter");
set_long("This is a beautiful golden scepter"
        " with jewels in it. It has a large diamond"
        " mounted on the top.");
set_weight(50);
    set_curr_value("gold", 100);
set_wc(20);
set_ac(2);
set_type("blunt");
set_hands(1);
set_wield("You hold the scepter in your hand, wonder if you can pawn it?");

set_unwield("You decide that it is worth more sold!");



set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 69) {
write("The diamond%^RED%^ bleeds%^RESET%^ your opponent!");
say("%^YELLOW%^The diamond smashes some heads!");
result=(random(300))+((this_player()->query_level()));
return result;

}

}
