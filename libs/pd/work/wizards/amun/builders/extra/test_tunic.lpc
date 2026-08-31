#include <std.h>
#include <amun.h>
inherit ARMOUR;   
int stored = 0;
object tp;                                                      
void create() {
    ::create();  
    set_id(({"tunic", "angelskin tunic"}));
    set_name("Angelskin Tunic");
    set_short("%^BOLD%^%^WHITE%^A%^YELLOW%^n%^WHITE%^g%^YELLOW%^e%^WHITE%^l%^YELLOW%^s%^WHITE%^k%^YELLOW%^i%^WHITE%^n %^YELLOW%^T%^WHITE%^u%^YELLOW%^n%^WHITE%^i%^YELLOW%^c%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This %^RESET%^%^ORANGE%^tunic %^BOLD%^%^YELLOW%^was %^WHITE%^made %^RESET%^%^ORANGE%^by %^BOLD%^%^YELLOW%^the %^WHITE%^Father %^RESET%^%^ORANGE%^of %^BOLD%^%^YELLOW%^Heaven%^WHITE%^. It %^RESET%^%^ORANGE%^is %^BOLD%^%^YELLOW%^said %^WHITE%^to %^RESET%^%^ORANGE%^hold %^BOLD%^%^YELLOW%^a %^WHITE%^great %^RESET%^%^ORANGE%^power%^BOLD%^%^YELLOW%^.%^RESET%^");
    set_curr_value("gold", 300);
    set_ac(3);
    set_type("tunic");
    set_limbs( ({ "head", "left arm", "right arm" }) );
    set_weight(5);
    set_wear("%^BOLD%^%^WHITE%^You %^YELLOW%^feel %^WHITE%^a %^YELLOW%^tingling %^WHITE%^sensation %^YELLOW%^throughout %^WHITE%^your %^YELLOW%^body%^WHITE%^.%^RESET%^");
    set_remove("%^BOLD%^%^WHITE%^The %^YELLOW%^tingling %^WHITE%^sensation %^YELLOW%^subsides%^WHITE%^.%^RESET%^");
    set_property("magic item", ({ "shift" }) );
    set_heart_beat(1);
}
int query_auto_load()
{
    if (this_player()->query_level() > 36) return 1;
    return 0;
}

void init()
{
    ::init();
    add_action("shift_func", "shift"); // function, command
}
void heart_beat() {
    if(tp = this_object()->query_worn()) {
	if(tp->query_current_attacker()) {
	    if(random(100) > 85) {
		tp->query_current_attacker()->set_paralyzed(3, "You are unable to move right now!");
		message("info", "%^BOLD%^%^WHITE%^Your %^RESET%^%^ORANGE%^tunic %^BOLD%^%^YELLOW%^glows %^WHITE%^brightly%^RESET%^%^ORANGE%^!%^RESET%^", tp, );
		message("room", "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+"'s %^RESET%^%^ORANGE%^tunic %^BOLD%^%^YELLOW%^glows %^WHITE%^brightly %^RESET%^%^ORANGE%^!%^RESET%^", environment(tp), tp);
		stored = stored + 25 + random(tp->query_level());
	    }
	}
    }
}
int shift_func(string str)
{
    string what;
    int num;
    if(!this_object()->query_worn()) {
	write("You must wear the tunic to use it!");
	return 1;
    }
    if(tp->query_disable()) {
	write("You are to busy to use your tunic.");
	return 1;
    }
    if(!str) {
	write("shift to what?");
	return 1;
    }
    if (sscanf(str,"to %s", what) != 1) {
	write("Shift to what?");
	return 1;
    }

    if(what == "hp") {
	if(stored < 100 + tp->query_level()) {
	    write("The tunic is too dim.");
	    return 1;
	}
	num = 25 + random(tp->query_level()); 
	tp->add_hp(num);
	stored = stored - (num * 2);
    }
    else if(what == "sp") {
	if(stored < 100 + tp->query_level()) {
	    write("The tunic is too dim.");
	    return 1;
	}
	num = 20 + random(tp->query_level());
	tp->add_sp(num);
	stored = stored - (num * 2);
    }
    else if(what == "mp") {
	if(stored < 100 + tp->query_level()) {
	    write("The tunic is too dim.");
	    return 1;
	}
	num = 30 + random(tp->query_level());
	tp->add_sp(num);
	stored = stored - (num * 5 / 3);
    }
    tp->set_disable();
    write("%^BOLD%^%^WHITE%^All %^RESET%^%^ORANGE%^the %^BOLD%^%^YELLOW%^energy %^WHITE%^from %^RESET%^%^ORANGE%^Heaven %^BOLD%^%^YELLOW%^flows %^WHITE%^through %^RESET%^%^ORANGE%^you%^BOLD%^%^YELLOW%^!");
    return 1;
}
