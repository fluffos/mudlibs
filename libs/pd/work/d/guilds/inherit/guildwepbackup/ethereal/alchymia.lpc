#include <std.h>
#include <ether.h>
inherit ETHERWEP;



void create() {
 ::create();
   set_name("staff");
   set_short("%^BLUE%^a%^BOLD%^l%^CYAN%^c%^RESET%^%^CYAN%^h%^GREEN%^y%^BOLD%^m%^YELLOW%^i%^RESET%^%^ORANGE%^a%^RESET%^");
   set_long("%^CYAN%^This staff was created for the mages of Ethereal, by an unknown but very powerful Alchemist. It is encrusted with sapphires, emeralds, and various other precious gems. It glows with a bright white aura.%^RESET%^");
   set_weight(10);
   set_id( ({ "staff","alchymia" }) );
set_curr_value("gold",120);
   set_ac(2);
   set_wc(9);
   set_type("blunt");
   set_hands(1);
   set_hit((:this_object(),"weapon_hit":));
}
int weapon_hit()
{
	int result;
	object at;
	at = (object)this_player()->query_current_attacker();
        if(random(100) < 19) {
		write("%^BOLD%^%^WHITE%^You annihilate "+at->query_name()+" with your staff.%^RESET%^");
		say((string)"%^BOLD%^%^WHITE%^"+this_player()->query_cap_name()+"'s staff annihilates "+at->query_name()+".%^RESET%^");
		result=(random(55))+((this_player()->query_level())*3/2);
		this_player()->add_mp(result / 4);
	  	if(random(100) < 15) {
			write("%^BOLD%^%^CYAN%^Your staff temporarily paralyzes "+at->query_name()+".%^RESET%^");
			say("%^BOLD%^%^CYAN%^"+this_player()->query_cap_name()+"'s staff temporarily paralyzes "+at->query_name()+".%^RESET%^");
			at->set_paralyzed(random(3));
		}
        }
	return result;
}
int query_auto_load()
{
	if (this_player()->query_level() > 49) return 1;
	return 0;
}






