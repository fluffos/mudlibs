#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
::create();
set_id(({"Beseech", "sword"}));
set_name("sword, Beseech");
set_short("%^YELLOW%^Be%^WHITE%^s%^YELLOW%^e%^WHITE%^ec%^YELLOW%^h%^RESET%^");
set_long(    "Syntax: <beseech [living]>\n" 
    "A holy spell of the White Dragon. The Dragon prays to Valor, the Dragon "
	"Lord, for a holy blast from the heavens to strike down his enemies.");
set_weight(10);
set_curr_value("platinum",420);
//set("skill level", 5);
set_wc(16);
set_ac(1);
set_type("blade");
set_wield("%^BOLD%^%^GREEN%^I pity da foo'!%^RESET%^");
set_unwield("You decide to stop beseeching things for a while....");
set_hit((:this_object(),"weapon_hit":));
}
int weapon_hit() {
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 90) {
write("%^YELLOW%^You beseech Valor, praying for a holy blast upon "
	"your opponent.");
say((string)""+this_player()->query_cap_name()+"'s prayers are
answered and a blast from the heavans strikes your opponent.");
result=(random(50))+((this_player()->query_level())*2/3);
if(random(100) > 74) {
write("The strength of the blast stuns your opponent!");
say("The strength of the blast causes a stunning blow!");
atk->set_paralyzed(random(2));
return result;
}
}
}
int query_auto_load() {
if(this_player()->query_class() != "dragon") return 0;
if(this_player()->query_subclass() != "white") return 0;
if(this_player()->query_level() < 40) return 0;
 return 1; 
}
