#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);
create() {
    ::create();
    set_id(({"scourge","bane of the righteous","bola"}));
    set_name("bola");
    set_short("Bola - Bane of the Righteous");
    set_long("Four wooden balls, wrapped tightly in black leather and attached to a wooden shaft by lengths of leather chord, this Bola's origins are unknown. Very little is truely known about it except that it was once the property of a powerful Demon known as Amon'Sol, which was sent by the Demon Lord Asmodeus to protect some of his agents on the moral realm. When a mightly Paladin, the name of whom is lost to history, slew the Demon and his charges the weapon was thought destroyed. However, it would seem that the arm of Asmodeus does not easily release it's most prized possessions...");
    set_value(140);
    set_weight(15);
    set_wc(10);
    set_type("flail");
    set_hit( (: weapon_hit :) );
    set_hands(1);
    set_wield("%^BOLD%^%^BLACK%^Your vision clouds over with visions of death and dispair.%^RESET%^");
    set_unwield("%^BOLD%^%^BLACK%^Your vision returns to normal.%^RESET%^");
}

int weapon_hit(object atk) {
    int result;

    if(random(100) > 90) {
	write("You snap your wrist forward, lashing your opponant!");
	say((string)this_player()->query_cap_name()+"'s bola whips forward and emits a powerful crack as it connects.");
	result = this_player()->query_alignment()/50;
	result = (random(random(result)))*((this_player()->query_level()/18)+2);
	result=random(result)+1;
	atk->set_paralyzed(random(3)+1);
	return result;
    }
    return 0;
}
int query_auto_load() { if (this_player()->query_level() >= 45) return 1; }
