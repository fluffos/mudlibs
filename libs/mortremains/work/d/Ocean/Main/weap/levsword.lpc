/*
** File: sword.c
** Purpose: a weapon
** Credits: Created by Herself on July 25, 2000
*/


#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author" , "herself");
    set_weapon_type("sword/long");
    set("id" , ({"sword" ,"sword of water" }) );
    set("short" , "sword of water");
    set("long" , wrap(
	"The magical sword of Leviathan. It's sharp blade "+
	"is formed out of water, held in place by a "+
	"magical force. "
      ));
    set("name" , "sword of water");
    set("nosecond", 0);
    set("value" , 2500);
    set("damage_type" , "slashing");
    set_bonus(3);
    set("mass" , 15);
    set_verbs( ({"slash at" , "swipe at" , "stab at"}) );
    set_verbs2( ({"slashes at" , "swipes at" , "stabs at"}) );
}     

int hit_func(object targ, int damage){
    targ=this_object()->query_current_attacker();
    if (!targ) return damage ;
    if(!random(25)) {
	say("The sword starts to vibrate, and a flood "+
	  "of water smashes down on "+
	  targ->query("cap_name")+"!\n", targ);
	tell_object(targ, "The sword starts to vibrate and "+
	  "a flood of water smashes down on you!\n");
	targ->block_attack(random(2)+1);
	targ->receive_damage((random(20)+10), "suffocation");
    }
    return damage;
}
/* End of File */
