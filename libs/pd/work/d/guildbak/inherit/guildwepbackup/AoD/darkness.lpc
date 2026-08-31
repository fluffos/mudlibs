#include <std.h>
inherit WEAPON;

string *guilds = ({ "AoD", "darksoul" });
int weapon_hit();

void create() {
    ::create();
    set_name("blade");

    set_short("%^ORANGE%^H%^RESET%^eron %^ORANGE%^M%^RESET%^arked %^ORANGE%^B%^RESET%^lade");
    set_long("The blade, very slightly curved and sharp only on one edge, bore a heron etched into the steel near the hilt. Short quillons, worked to look like braid, flanked the hilt. The balance is perfect the edge sharpened to perfection.");
    set_id( ({"blade" }) );
    set_hands(1);
    set_wc(11);          
    set_ac(2);   
    set_curr_value("gold", 100+random(35));
    set_type("blade");        
    set_hit((:this_object(),"weapon_hit":));
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 19) {
	write("You execute the form %^BOLD%^%^BLUE%^cutting the %^WHITE%^clouds, %^BLACK%^slicing %^RESET%^your opponent's %^RED%^throat!%^RESET%^");
	say((string)""+this_player()->query_cap_name()+" uses the %^BOLD%^%^BLUE%^cutting the %^WHITE%^clouds %^BLACK%^bladeform, slicing %^RESET%^their opponent's %^RED%^throat!%^RESET%^");
	result=(random(55))+((this_player()->query_level())*3/2);
	this_player()->add_sp(result/4);
	if(random(100) < 10) {
	    write("You execute the form, %^BOLD%^%^RED%^the heron s%^RESET%^%^RED%^preads i%^MAGENTA%^ts wings%^RESET%^, striking a %^YELLOW%^paralyzing%^RESET%^ blow!");
	    say(""+this_player()->query_cap_name()+"executes the bladeform, %^BOLD%^%^RED%^the heron s%^RESET%^%^RED%^preads i%^MAGENTA%^ts wings, striking a %^YELLOW%^paralyzing%^RESET%^ blow!");
	    atk->set_paralyzed(random(3));
	    return result;
	}
    }
}
int query_auto_load()
{                                   
    if (this_player()->query_level() > 20) return 1;
}
int slap_on_the_wrist(string str) {
    if (!str || present(str, this_player()) != this_object()) return 0;
    if (member_array(this_player()->query_guild(),guilds) != -1) return 0;
    write("This does not belong to you!");
    say(this_player()->query_cap_name()+" yelps as Angrist burns them!",
      this_player());
    return 1;
}

void init() {
    ::init();
    add_action("slap_on_the_wrist", "wield");
}
