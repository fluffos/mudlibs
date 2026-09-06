/*
**
** lich.c
**
** (C) Tron
**
*/


#include <npc.h>
#include <areas.h>

status moved;

void
create_monster()
{
    set_name("lich");
    set_race("lich");
    set_short("A lich");
    set_long("This, otherwise ordinary, human skeleton has "+
      "a hollow look in his eyes and a faint blue aura. "+
      "He is wearing a long black robe with golden edges.");
    set_level(25);
    set_hp(550);
    set_ep(1500000);
    set_wc(35);
    set_ac(25);
    set(NPC_AGGRESSIVE);
    set(LIV_UNDEAD);
    set_spell_chance(10);
    set_spell_dam(60);
    set_spell_mess1("The lich shoots a lightning bolt.\n");
    set_spell_mess2("You are hit by a lightning bolt.\n");

    load_a_chat(5, ({
	"Lich laughs in a hollow voice: You'll die!!!\n",
	"Lich's bony mouth turns into a wild disgusting smile.\n",
	"Your hair raises up from electrical shower created by Lich.\n",
	"Lich's red eyes glow as he swings at you.\n",
	"Lich mumbles something in a strange language.\n",
	"Lich says: Ahh, you look chubby enough for my liking.\n"
      }));

}

status
fnd_armour(object ob) {

    return (status) ob -> is_armour() && !ob -> drop(1);
    // 2nd check added by Doomdark 26-may-95 to prevent mages' hat from
    // getting dested.
}

void
heart_beat() {

    mixed *armours;
    object ob;
    object attacker_ob;

    ::heart_beat();

    if ((attacker_ob = query_attack()) && present(attacker_ob, environment())) {

	if(!random(5)) {
	    tell_room(environment(), 
	      "The Lich mumbles: Armoricum destructicum.\n");
	    armours = filter(all_inventory(attacker_ob),
	      "fnd_armour", this_object());
	    if(armours && sizeof(armours)) {
		ob = armours[random(sizeof(armours))];
		command("drop "+(string)ob->query_name(), attacker_ob);
		tell_object(attacker_ob, "You drop "+ ob->short() +
		  " and it breaks in to million pieces.\n");
		tell_room(environment(), attacker_ob->query_name()+" drops "+
		  ob->short() + " and it breaks like glass.\n",
		  ({attacker_ob}));
		destruct(ob);
	    }
	}
    }

    if(( query_hp() < 70) && !moved) {
	tell_room(environment(), "The Lich vanishes. "+
	  "You only hear a hollow laughter.\n");
	move_object(this_object(), AREA_TRISTEZA "duel/virtual/world/rooms/17_13");
	moved = 1;
    }
}

void
init_monster()
{
    add_action("west", "west");

    if(moved) add_action("south", "south");
}

status
west() {

    if(moved) return 0;

    this_player()->tell_me("The Lich stops you and you struggle in pain as the"+
      " dead cold touch drains your life force.\n");

    say(this_player()->query_name()+ " steps back in pain.\n");

    this_player()->hit_player(random(50));
    if (this_player())
	this_player()->add_sp(-random(50));
    return 1;
}

status
south() {

    if(!moved) return 0;

    moved = !moved;
    west();
    moved = !moved;

    return 1;
}
