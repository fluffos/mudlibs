/* 'Devour'-command; moved from /basic/player/race_cmds.c here
 * 30-sep-94.
 */

#include <conditions.h>
#include <stats.h>
#include <cmd.h>
#include <daemons.h>
#include <disease.h>

/* We have to artifically check if we can eat, before letting player object
   check that, because otherwise we could get the "Too stuffed" msg twice.
   //Frobozz */
int
can_eat(int strength,int called, object me)
{
    if (!called || (int)me->query_stuffed() + strength <=
      (int) me->query_stat(ST_CON) * 8)
	return (int)me->eat_food(strength);
}

void
check_decay(int d, object me)
{
    string tmp;
    int foo;
    object ob;

    tmp = ({ "meat", "meal", "food" })[random(3)];

    if (d > 3) foo = 0;
    else if (d == 3) foo = 1 + random(5);
    else if (d == 2) foo = 3 + random(4);

    switch(foo) {
    case 0: break; /* nami nami */
    case 1: me -> tell_me("Yuk! This " + tmp + " is no good!"); break;
    case 2: me -> tell_me("YUK! Bad " + tmp + "!"); break;
    case 3: me -> tell_me("Yoorgh! You spit out worms and mucus!"); break;
    case 4: me -> tell_me("Rotten " + tmp + "! You feel dizzy."); break;
    case 5: me -> tell_me("This " + tmp + " is spoiled!"+
	  "You feel rather light headed."); break;
    case 6: me -> tell_me("Yulgh! This " + tmp + " is tainted!"+
	  "You get very sick."); break;
    default:
	me -> tell_me("This " + tmp + " tastes very strange!");
	break;
    }

    if (foo > 5) {
	/* Infect eater with food poisoning or perhaps cholera or dysentery */
	if (!present("disease", me)) {
	    ob = clone_object(DISEASE_FILE);
	    switch(random(4)) {
	    case 0: ob->set_disease("cholera"); break;
	    case 1: ob->set_disease("dysentery"); break;
		/* Fever */
	    default: ob->set_disease("default"); break;
	    }
	    move_object(ob, me);
	}
    } else if (foo > 3) {
	me -> add_condition(C_HALLUCINATING, random(200) + 50);
    }
}

/* 'devour corpse' for half-orcs */
varargs nomask status
devour_cmd(string what, object me)
{
    int dummy,decay, heal_amount, corpse_level, half_corpse;
    string pronoun, corpse_name, race;
    object corpse, ob;
    int i;
    object *inv;

    if (!me && !(me = this_player())) return 0;

    if (!what) return notify_fail("Devour what?\n"), 0;

    /* Monsters and NPCs can all devour. //Graah */
    if (!me->query_can_move()) return 0;

    if (interactive(me))
    {
	race = (string)me->query_race();

	if (race !="half-orc" && race !="orc" && race !="troll")
	{
	    me -> tell_me(
	      "YUCK! How can you even THINK of doing what those savage goblinoids do?!?");
	    return 1;
	}
    }

    if (!me -> query_can_move() || me -> test_dark()) return 0;

    /* New check to annoy players :-) //Graah */
    /* Trolls are an exception. Perhaps we will have troll PCs some day... */
    if (!me->query_npc() && race != "troll" && me-> is_fighting()) {
	me -> tell_me(
	  "You are too busy now! Perhaps you should finish this fight first.");
	return 1;
    }

    if (sscanf(what, "the %s", pronoun)) what = pronoun;

    if (!(corpse = present(what,me)) &&
      !(corpse = present((what = lower_case(what)), environment(me))))
    {
	me -> tell_me("You can't see any \""+what+"\" here.");
	return 1;
    }

    if (!corpse -> query_real_corpse())
    {
	me -> tell_me("Try eating it.");
	return 1;
    }
    decay = (int)corpse->query_decay();

    if (decay < 2)
    {
	me -> tell_me("There's only some bones left.");
	return 1;
    }

    heal_amount=(corpse_level=(int)corpse->query_orig_level())+random(3)-1;
    if (decay == 5) heal_amount *= 3;
    else if (decay == 4) heal_amount *= 2;
    else heal_amount = 0;

    pronoun = (string)me->query_pronoun();
    half_corpse = sscanf((string)corpse->short(),"Half-eaten corpse of %s",corpse_name);

    if (can_eat(corpse_level,0,me))
    {
        object corpse_env;
        corpse_env = environment(corpse);

        me->tell_me("You eat the warm corpse with good appetite. YUMMY!");

        /* Had foreach for all_inventory(), but we've had issues with too much
         * stuff laying around, so lets optimize a little
         */
        if (corpse_env) {
            while (ob = first_inventory(corpse))
                move_object (ob, corpse_env);

            if (corpse_env == me) {
                // Subtract weight before desting -- Germ
                me->add_weight(-(int)corpse->query_weight());

                destruct(corpse);

                // And update our gmcp.Char.Items inventory, if interested -- Tamarindo
                TELOPT_D->tell_me_items_list_inv(me);
            } else {
                destruct(corpse);

                // Otherwise the past contents of this corpse, if any, are now strewn across the ground
                // so let's update everyones gmcp.Char.Items room, if interested
                TELOPT_D->tell_here_items_list(corpse_env);
            }
        }
    } else if (!half_corpse && can_eat(corpse_level/2,1,me)) {
        object corpse_env;
        corpse_env = environment(corpse);

        me -> tell_me("You start eating the corpse with good appetite, but you "
                      "get stuffed when you have eaten half of it.");
        heal_amount /= 2;
        corpse->set_orig_level(corpse_level/2);
        corpse->set_short_desc("Half-eaten corpse of ");
        corpse->set_weight( ((int)corpse->query_weight())/2 );

        // Since our short desc suddenly changed...
        // Let's update everyones gmcp.Char.Items room, if interested
        if (corpse_env == me) {
            TELOPT_D->tell_me_items_list_inv(me);
        } else {
            TELOPT_D->tell_here_items_list(corpse_env);
        }
    }

    environment(me) -> tell_here((string)me->query_name(0, me)
      +" jumps on the corpse and starts tearing it apart.\nAfter "
      +pronoun+" has torn it to pieces, "+pronoun+" gorges "
      +(string)me->query_objective()+"self with it.",({ me }));
    me -> add_hp(heal_amount);
    me -> add_sp(heal_amount * 3 / 4);
    me->add_fp(heal_amount);

    /* Check food poisoning */
    check_decay(decay, me);

    return 1;
}
