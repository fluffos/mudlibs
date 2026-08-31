#include <std.h>
inherit WEAPON;

string *guilds = ({ "ethereal", "unholy" });
int weapon_hit();

void create() {
    ::create();
    set_name("Eidolon Blade");
    set_short("%^BOLD%^%^BLACK%^E%^RESET%^i%^RED%^d%^BOLD%^%^RED%^o%^RESET%^%^RED%^l%^RESET%^o%^BOLD%^%^BLACK%^n %^RESET%^B%^RED%^l%^BOLD%^%^RED%^a%^RESET%^%^RED%^d%^RESET%^e%^RESET%^");
    set_long("%^BOLD%^%^RED%^As you glance over the sword, an eerie feeling creeps over your body causing you to draw it close. The %^YELLOW%^l%^WHITE%^i%^YELLOW%^g%^WHITE%^h%^YELLOW%^t%^RESET%^%^BOLD%^%^RED%^ dances over the blade in a faint %^RESET%^%^GREEN%^m%^BOLD%^i%^RESET%^%^GREEN%^s%^BOLD%^t%^RESET%^%^BOLD%^%^RED%^, surrounding itself in strange shapes. These shapes mean something...if only you knew what...%^RESET%^");
    set_id( ({"blade", "sword", "eidolon blade"}) );
    set_hands(1);
    set_weight(20);
    set_wc(13);
    set_ac(1);
    set_curr_value("gold", 100+random(35));
    set_type("blade");
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 19) {
	write("%^RESET%^You plunge the %^BOLD%^%^BLACK%^E%^RESET%^i%^RED%^d%^BOLD%^%^RED%^o%^RESET%^%^RED%^l%^RESET%^o%^BOLD%^%^BLACK%^n %^RESET%^B%^RED%^l%^BOLD%^%^RED%^a%^RESET%^%^RED%^d%^RESET%^e%^RESET%^ stealthily into your enemy's chest bringing them %^BOLD%^%^RED%^EXTREME%^RESET%^ pain.");
	say((string)"%^RED%^"+this_player()->query_cap_name()+"'s %^BOLD%^%^BLACK%^E%^RESET%^i%^RED%^d%^BOLD%^%^RED%^o%^RESET%^%^RED%^l%^RESET%^o%^BOLD%^%^BLACK%^n %^RESET%^B%^RED%^l%^BOLD%^%^RED%^a%^RESET%^%^RED%^d%^RESET%^e%^RESET%^ plunges deep into their attacker's chest bringing them %^BOLD%^%^BLACK%^UTTER%^RESET%^%^RED%^ pain.%^RESET%^");
	result=(random(55))+((this_player()->query_level())*3/2);
	this_player()->add_sp(result)/4;
	if(random(100) < 10) {
	    write("%^RESET%^%^RED%^The %^BOLD%^%^BLACK%^E%^RESET%^i%^RED%^d%^BOLD%^%^RED%^o%^RESET%^%^RED%^l%^RESET%^o%^BOLD%^%^BLACK%^n %^RESET%^B%^RED%^l%^BOLD%^%^RED%^a%^RESET%^%^RED%^d%^RESET%^e%^RESET%^%^RED%^ twists so deep into your enemy that they become temporarily paralyzed!%^RESET%^");
	    say("%^RED%^The %^BOLD%^%^BLACK%^E%^RESET%^i%^RED%^d%^BOLD%^%^RED%^o%^RESET%^%^RED%^l%^RESET%^o%^BOLD%^%^BLACK%^n %^RESET%^B%^RED%^l%^BOLD%^%^RED%^a%^RESET%^%^RED%^d%^RESET%^e%^RESET%^ %^RED%^twists deep into their attacker's body causing them to become temporarily paralyzed.%^RESET%^");
	    atk->set_paralyzed(random(3));
	    return result;
	}
    }
}
int query_auto_load()
{
    if (this_player()->query_level() > 50) return 1;
}
int slap_on_the_wrist(string str) {
    if (!str || present(str, this_player()) != this_object()) return 0;
    if (member_array(this_player()->query_guild(),guilds) != -1) return 0;
    write("This does not belong to you!");
    say(this_player()->query_cap_name()+" lets out a piercing scream as the weapon burns them.",
      this_player());
    return 1;
}

void init() {
    ::init();
    add_action("slap_on_the_wrist", "wield");
}

