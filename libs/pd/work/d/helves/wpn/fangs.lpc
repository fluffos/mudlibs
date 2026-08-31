#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
::create();
set_id(({"fang","fangs","bloodwormfangs","bloodworm fangs"}));
set_name("Bloodworm Fangs");
set_short("Bloodworm Fangs");
set_long("These are the fangs of the mysterious Bloodworm. Many"
	" have ventured out to find and kill these creatures"
	" although few have returned. These fangs show great"
	" skill in battle. And among the high elves, great loyalty.");
set("skill level", 300);
set_weight(6);
    set_curr_value("silver", 5);
set_wc(4);
set_ac(2);
set_type("knife");
set_hands(1);
set_wield("%^MAGENTA%^The Bloodworms squirm as you wield their weapons!");

set_unwield("%^MAGENTA%^You hear the screams of a dying Bloodworm from somewhere");



set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 69) {
write("%^RED%^BOLD%^You circle behind your opponent and rip out their spine!");
say("%^BOLD%^RED%^The fangs glow with power!");
result=(random(100))+((this_player()->query_level()));
return result;


}

}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
