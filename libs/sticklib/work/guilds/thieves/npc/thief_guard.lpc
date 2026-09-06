#include <sys/configuration.h>
#include <group_npc.h>
#include <attack.h>
#include <weapon_defs.h>
#include <armour_defs.h>
#include <guild.h>
#include <areas.h>
#include <daemons.h>

#include "dirs.h"

/* Time server */
#define	MASTER_OB	"/secure/master"

#define TO this_object()

status called_help;
object hlp;
object sword, armour, key;

/* Fake "controlled" monster - makes player kills PKs */
status query_ctrl() { return 1; }

void
reset_monster()
{
    called_help = 0;
}

void
create_monster()
{
    int i;

    called_help = 0;

    set_name("guard");
    set_id(({ "guild_guard", "guild guard", "thief_guard" }));
    set_short("The Guild Guard");
    set_long(
      "A VERY tough-looking master fighter, who has been hired to guard the Guild \
of Thieves. Type \"join\" if you wish to join the guild.");
    set_level(25);
    set_ep(250000);
    set_hp(4000);
    set_dead_ob(this_object());
    set_money(random(500) + 150);
    set_alignment(AL_NASTY);
    set(NPC_YES_CONDITION);
    set_gender(G_MALE);
    set_guild("thief");
    set_group("thief_guard");
    configure_object(this_object(), OC_HEART_BEAT, 1);

    armour = clone_object(ARMOUR_FILE);
    armour->set_name("chain mail");
    armour->set_short("A chain mail");
    armour->set_long("A fine chain mail armour (though quite heavy).");
    armour->set_value(800);
    armour->set_ac(3);
    armour->set_weight(7);
    armour->set_id("chain");
    move_object(armour, this_object());
    wear(armour);

    /* Key to guild door */
    key = clone_object(GDIR + "obj/temple_key");
    move_object(key, this_object());

    for(i = 0; i < 2; i++)
	move_object(clone_object(GDIR + "obj/heal_potion"),
	  this_object());

    call_out("check_beat",5);
    set_wc(100, 1);
    set_ac(80);
}

check_beat()
{
    object g;

    if (!environment()) return;

    if (!is_fighting()) {
	g = present("guild_guard",environment(this_object()));
	if (g) {
	    if (g && g->query_attack()) {
		attack_object(g->query_attack());
	    }
	} else {
	    if (object_name(environment()) != GDIR2 + "rooms/entry") {
		move_player("to his guardpost#" + GDIR2 + "rooms/entry");
	    }
	}
    }
    call_out("check_beat",5);
}

#define ATT attacker_ob

heart_beat()
{
    object *inv, ob;
    int i;
    string tmp, tmp2;

    if (!environment()) return;

    ATT = query_attack();

    // Pets dare to attack us? Ha!
    if (ATT && ATT->query_npc())
    {
	environment()->tell_here(":%<me.capname>% \
stomps %<him.capname>% into a wet spot on the floor.",
	  0, 0, this_object(),
	  this_object(), ATT, 0);
	ATT->hit_player(100000, DT_IMPACT);
	return;
    }

    if (ATT && present(ATT,environment(TO)) && (random(100) < 60))
    {
	if (random(100) > 75)
	{
	    ATT->tell_me("The guard kicks you skillfully in the groin.");
	    environment()->tell_here(
	      "The guard kicks " + ATT->query_name() +
	      " in the groin.\n", ({ ATT }));
	    /* If we are male, then it HURTS! */
	    if (ATT->query_gender() == 1) {
		ATT->tell_me("AARGHHHH!!!");
		ATT->hit_player(random(60));
	    } else {
		ATT->hit_player(random(40));
	    }
	}
	if (!called_help)
	{
	    called_help = 1;

	    if (random(100) < 43)

		ATT = TO->query_attack();
	    tmp = ATT->query_real_name();
	    if (!tmp) tmp = ATT->query_name();
	    if (!tmp) tmp = ATT->short();
	    if (!tmp) tmp = "Someone";

	    tmp = capitalize(tmp);

	    tmp2 = "Hey fellows! " + tmp + " just attacked me!";

	    CHANNEL_D->send_channel_message(TO, "thief", tmp2);
	    //display_mesg("Guild Guard",0,tmp2);

	}

    } /* end if (attacker_ob is around) */

    if (hit_point< 200 && present("potion",TO))
	call_out("init_command",1,"drink potion");

    ::heart_beat();
}

/* What? Someone is fighting us? Yell help! */
yell_help()
{
    string *dd, tmp;
    object *exs, ob;
    int i, j;

    if (!environment() || dead) return;

    dd = environment()->query_dest_dir();
    if (!dd || sizeof(dd) < 1) return;

    exs = ({});

    for (i = j = 0; i < sizeof(dd); i += 2)
	if (dd[i] && (ob = find_object(dd[i]))) {
	    exs += ({ ob });
	    j++;
	}

    if (j < 1) return;

    tmp = ({ "Brothers! There's a fight going on in here!",
      "Alarm! Reinforcements needed here!",
      "Hey fellows! Come to help me with this intruder!",
      "Alert! An assault going on in here!" })[random(4)];

    environment()->tell_here("Guard yells: " + tmp);

    for (i = 0; i < j; i++) {
	exs[i]->tell_here("You hear a shout: " + tmp);
	if ((ob = present("thief_guard", exs[i])) &&
	  !ob->query_attack() && !ob->query_alt_attack())
	{
	    environment()->tell_here("You hear a shout: Coming!");
	    exs[i]->tell_here(ob->query_name() + " shouts: Coming!");
	    ob->move_player("running towards the battle", environment());
	    if (attacker_ob) ob->attack_object(attacker_ob);
	    else if (alt_attacker_ob) ob->attack_object(alt_attacker_ob);
	}
    }
}

monster_died(object this_npc, object killer)
{
    object tg;
    string tmp;


    if (!killer) killer = this_player();

    tmp = killer->query_real_name();
    if (!tmp) tmp = "Something weird";
    else tmp = capitalize(tmp);

    write_file(GDIR+"ATTACKLOG", tmp+ " killed our guard at " +
      NATURE_D->query_about_time() + ", " + NATURE_D->query_date_s() +
      "\n");

    if (key &&
      (tg = present("lesser_thief_guard", environment())))
    {
	environment()->tell_here(query_name() +
	  " throws a key to " + tg->query_name() +
	  " who skillfully catches it.");
    }

    /* The key must disappear after a while. Call a kludge in lobby. */
    if (key) call_other(GDIR + "rooms/entry", "key_kludge", key);

    return 0;
}
