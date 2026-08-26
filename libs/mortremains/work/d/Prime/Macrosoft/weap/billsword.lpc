// The BIG thing wielded by Bill Gates.
// The most complex weapon Cyanide has ever written!

#include <move.h>

inherit WEAPON;

void create() {
    set("short", "The Sword of the Corporations");
    set("long", wrap("This appears to be a large blade of "+
	"exceedingly advanced technical design, covered "+
	"with resistors and capacitors, and seems to be "+
	"designed to store and transfer some kind of "+
	"energy. The words \"Macrosoft WhoopAss99\" are "+
	"etched into the blade.") );
    set("id", ({ "sword", "weapon" }) );
    set_weapon_type("sword/long");
    set("name", "Sword of the Corporations");
    set("damage", ({ 2, 15 }) );
    set_bonus(5);
    set_verbs( ({ "whomp", "slash", "rip" }) );
    set("value", 10000);
}

int hit_func ( object targ, int damage ) {
    object attacker, ob;
    int hp;
    string name = targ->query("name");

    switch(random(100)) {
    case 0..2 :    

	attacker = environment(TO);
	hp = targ->receive_damage(random(25)+5, "necromancy");
	if (hp>0) {
	    attacker->receive_healing(hp);
	    message("combat", wrap("The Sword of the Corporations "+
		"glows green as it strikes "+name+", and "+subjective(
		  targ->query("gender"))+" he stumbles briefly."), 
	      all_inventory(environment(targ)), ({ targ, attacker }) );
	    tell_object(targ, wrap("The Sword of the Corporations "+
		"glows green as it strikes you, and you suddenly "+
		"feel very weak."));
	    tell_object(attacker, wrap("The Sword of the Corporations "+
		"glows green as it strikes "+name+", and you "+
		"suddenly feel invigorated!"));
	}
	break;

    case 3..5 :
	message("combat", wrap("There is a great clap of thunder "+
	    "as The Sword of the Corporations strikes a "+
	    "mighty blow, and "+name+" is stunned!"), 
	  all_inventory(environment(targ)), targ);
	tell_object(targ, wrap("There is a great clap of thunder "+
	    "as The Sword of the Corporations strikes a mighty "+
	    "blow, and "+name+" is stunned!"));
	targ->block_attack(5);
	targ->set("blind", 5);
	break;

    case 6..8 :
	message("combat", wrap("There is a great flash of light "+
	    "from the Sword of the Corporations, and "+name+" is "+
	    "badly burned!"), all_inventory(environment(targ)), targ);
	tell_object(targ, wrap("There is a great flash of light "+
	    "from the Sword of the Corporations, and you are "+
	    "badly burned!"));
	targ->receive_damage(random(20)+2, "electricity");
	break;

    case 9 :
	ob = targ->query("weapon1");
	if (ob && userp(targ) && ob->move(environment(targ))==MOVE_OK) {
	    message("combat", "The Sword of the Corporations disarms "+
	      name+"!\n", all_inventory(environment(targ)), targ);
	    tell_object(targ,"The Sword of the Corporations "+
	      "disarms you!\n");    
	}
	break;
    }

    return damage;
}

/* EOF */
