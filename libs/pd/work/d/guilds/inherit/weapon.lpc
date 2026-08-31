#include <std.h>
inherit WEAPON;
int weapon_hit(object atk);

object ob = this_player(); // This is so the weapons don't bug up.

string name = "guild weapon";
string short = "A Guild Weapon";
string long = "This is a guild weapon. It sucks. Your leaders are lazy.";
string *id = ({});
string type = "knife";
string wield = "You wield the weapon.";
string unwield = "You unwield the weapon.";
string guild = "council";
string playerm = "Biff!";
string targetm = "Biff!";
string roomm = "Biff!";

void create() {
    ::create();
    //set_weapon
    set_name(name);
    set_short(short);
    set_long(long);
    set_id(id);
    set_mass(5);
    set_curr_value("gold", 500);
    set_type(type);
    set_wc(12);
    set_hands(1);
    set_wield(wield);
    set_unwield(unwield);
    set_hit((:weapon_hit:));
}

int weapon_hit(object atk) {
    int result;
    if(random(100) > 85) {
	result=(random(50));
	message("player message",playerm, this_player());
	message("target message",targetm, atk);
	message("room message",roomm, environment(this_player()), ({this_player(), atk}));
	return result;
    }
}

int wield() {
    if (this_player()->query_guild() == guild) return 1;
}

int query_auto_load() { 
    if(this_player()->query_guild() == guild) return 1;
}
