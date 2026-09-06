
#include "../thief.h"
status make_poison(object who)
{
    string *ingred;
    status failed;
    int i, corpse_lev;
    object ob;

    if (!who) return 0;

    if (who->is_fighting())
    {
	who->tell_me("You can't make poison while fighting!\n");
	return 0;
    }
    if (!(ob = present("t_vial",who)))
    {
	who->tell_me("You need a poison vial!");
	return 0;
    }
    if (ob->query_filled()) {
	who->tell_me("Problem. Your vial is full");
	return 0;
    }
    ingred = (({
	"jojojopo",
	"corpse",
	"mushroom",
      }));
    for (i=0;i<sizeof(ingred);i++)
    {
	if (!present(ingred[i],who))
	{
	    who->tell_me("You don't have the " + ingred[i] + ".");
	    failed = 1;
	}
    }
    if (failed) return 0;
    for (i=0;i<sizeof(ingred);i++)
    {
	if (ob = present(ingred[i],who))
	{
	    if (ob->id("corpse"))
		corpse_lev = (int) ob->query_orig_level();
	    who->add_weight(-((int)ob->query_weight()));
	    destruct(ob);
	}
    }
    who->tell_me("You mix the ingredients together...");
    environment(who)->tell_here(who->query_name() + " busily mixes \
something...",who);
    call_out("check_poison",1,who,corpse_lev);
    return 1;
}
status check_poison(object who, int corpse_lev)
{
    object tm,p_vial;
    int t_int,poison_skill,adv;
    int failed, p_strength;
    if (!who) return 0;
    if (who->is_fighting())
    {
	who->tell_me("The fighting interupts your mixing.");
	return 0;
    }
    if (!p_vial = present("t_vial",who))
    {
	who->tell_me("You seem to have lost your vial.");
	return 0;
    }
    if (p_vial->query_filled())
    {
	who->tell_me("Your poison vial is already \
full!");
	return 0;
    }

    tm = (object) who->query_guild_object();
    poison_skill = (int)tm->query_skills(SK_POISON);
    t_int = who->query_stat(ST_INT);
    adv = tm->query_adv();
    if (random(101) < 6 ||
      ((poison_skill/100) + (t_int/2) + adv + 1 + random(35)) >
      50 + random(20) + random(65))
    {
	who->tell_me("You succeed in concocting some sort of \
mixture.  You carefully contain it in a vial for later \
use.");
	environment(who)->tell_here(who->query_name() + " seems pleased \
and pours a strange mixture into a vial.",who);
	// Slightly decreased: dividers 150 and 300  ->  300 and 600
	// Graah 20-Apr-98
	p_strength = (poison_skill/300) + random(poison_skill/600) +
	(corpse_lev/2) + (adv*2);
	// 20-Apr-98 / Graah: Megatitan gave level 160+ poison.
	// It is a BIT too much. Now there's a max level of 100.
	if (p_strength > 100) p_strength = 100;
	failed = 0;
    }
    else
    {
	who->tell_me("Ack, you spill everything everywhere.  \
Better try again!");
	environment(who)->tell_here(who->query_name() + " looks \
embarrassed as " + who->query_pronoun() + " slops something all \
over the place.",who);

	if(t_int < 10)
	    if(random(10-t_int))
		return 0;

	tm->set_skill(SK_POISON,(int)tm->advance_skill(poison_skill, (DIFF_POISON/(1+random(2)))));
	failed = 1;
    }
    if (failed) return 0;
    p_vial->set_filled();
    p_vial->set_strength(p_strength);

}

