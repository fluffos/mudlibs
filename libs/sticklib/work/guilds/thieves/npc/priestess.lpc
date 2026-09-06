#include <npc.h>
#include <weapon_defs.h>
#include <armour_defs.h>

#include "dirs.h"

int summoned;

void
create_monster()
{
    object ob;

    set_name("priestess");
    set_race("human");
    set_id(({ "woman", "high priestess", "high", "priestess of skert"}));
    set_gender(2);
    set_short("Priestess of Skert");
    set_long("She is a High Priestess of Skert.");
    set_level(29);
    //	set(NPC_NOT_AGGRESSIVE);
    set_money(random(200) + 100);
    set_alignment(AL_NICE);
    set_ep(200000);
    set_chance(30);
    set_spell_mess1("The priestess casts a flame strike spell!");
    set_spell_mess2("You are hit by a flame strike spell!");
    set_spell_dam(30);
    load_chat(2,({"Priestess kneels down to pray.\n",
	"Priestess says: Don't touch the altar!\n",
	"Priestess chants: O Skert, thou great god of love!\n",
	"Priestess says: Skert is the mightiest god of this world.\n",
	"Priestess says: You should join the Guild of Thieves.\n",
	"Priestess says: Perhaps you should 'pray' to visit the Guild.\n",
	"Priestess says: Thieves' rule the City. Now they also rule the Wilds.\n",
	"Priestess chants: O Skert, thou God of Thieves!\n",
	"Priestess says: Sacrifice lots of things to allmighty Skert!\n",
	"Priestess says: Cremate corpses here to lay them to rest.\n",
	"Priestess says: Beware of the cowardly ninjas of Tristeza!\n",
	"Priestess sacrifies a valuable thing.\n"}));
    set(NPC_YES_CONDITION);

    ob = clone_object(WEAPON_FILE);
    ob->set_name("spiked mace");
    ob->set_id("mace");
    ob->set_short("spiked mace");
    ob -> set(WP_BLUNT);
    ob->set_wc(13);
    ob->set_weight(3);
    ob->set_value(500);
    move_object(ob,this_object());
    wield(ob, 1);

    ob = clone_object(ARMOUR_FILE);
    ob->set_id("black robes");
    ob->set_id("robes");
    ob->set_short("black robes");
    ob->set_ac(0);
    ob->set_weight(1);
    ob->set_value(random(120) + 20);
    move_object(ob,this_object());
    wear(ob, 1);

    summoned = 0;
}

heart_beat() {
    int i;
    object ob;

    if (query_attack() && environment() &&
      present(query_attack(), environment())) {
	if (!summoned && random(100) < 25) {
	    tell_room(environment(), "Priestess cries: Destroy " +
	      query_attack()->query_objective() +
	      ", my demons!\n", ({ this_object() }));
	    for (i = 0; i < 1 + random(2); i++) {
		ob = clone_object(GDIR + "npc/demon");
		ob->move_player("X#" + object_name(environment()));
		summoned++;
		ob->attack_object(query_attack());
	    }
	}
    } else if (environment()) {
	while ((ob = present("skert_demon", environment()))) {
	    destruct(ob);
	    tell_room(environment(),
	      "A nasty-looking demon disappears!\n", ({ this_object(),ob }));
	}
    }

    ::heart_beat();
}

catch_tell(str) {
    object from;
    string *msg,t;
    string dummy;
    int i;

    from = this_player();
    if(!from) return;

    if(!sscanf(str,"%s\n",t)) return;
    t = lower_case(t) + " ";
    msg = explode(t," ");

    if (!msg) return;

    for(i=0;i<sizeof(msg);i++) {
	if(msg[i] == "death") {
	    say("Priestess says: Skert doesn't like if someone throws cow shit on\n"+
	      "                his face. A nice way to visit Death, that one.\n");
	    break;
	}
	if(msg[i] == "shit") {
	    say("Priestess says: Yes, you heard it correctly. Cow shit.\n");
	    break;
	}
    }

    return;
}

give_object_by(who, what)
{
    if (what->id("corpse"))
	who->tell_me(
	  "Priestess tells you: You should cremate this corpse yourself.\n");
    else
	who->tell_me(
	  "Priestess tells you: You should sacrifice this thing to Skert yourself.\n");

    add_weight(-(what->query_weight()));
    move_object(what, environment());
    if (what->short())
	say("Priestess drops " + what->short() + ".\n");

}
