#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"dagger", "ivory dagger"}));
set_name("dagger");
set_short("Ivory dagger");
set_long("A dagger of ivory that has been magically strengthened.  The blade is about seven inches in length and the handle is hollowed for lighter weight.");
set_weight(8);
set_value(400);
set_wc(10);
set_ac(0);
set_type("knife");
set_hands(1);
set_wield("%^CYAN%^BOLD%^You feel a slight tingle as you wield the dagger.%^RESET%^");
set_unwield("%^BOLD%^CYAN%^You unwield the ivory dagger.%^RESET%^");
set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 75) {
write("You %^BOLD%^RED%^SLICE%^RESET%^ your foe with a particularly brutal hit.");
say((string)this_player()->query_cap_name()+"'s dagger %^BOLD%^RED%^SLICES%^RESET%^ horribly as it strikes.");
result=(random(20))+((this_player()->query_level()));
return result;
}
}
int query_auto_load() {return 1; }
