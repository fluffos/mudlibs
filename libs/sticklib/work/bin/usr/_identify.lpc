#include <cmd.h>
#include <armour_defs.h>
#include <weapon_defs.h>
#include <conditions.h>
#include <stats.h>
#include <invis_levels.h>

nomask int _identify(object tp, string name);

nomask string
stat_name(int s)
{
    switch (s)
    {
    case ST_STR: case ST_BASE_STR: return "Strength"; break;
    case ST_DEX: case ST_BASE_DEX: return "Dexterity"; break;
    case ST_CON: case ST_BASE_CON: return "Constitution"; break;
    case ST_INT: case ST_BASE_INT: return "Intelligence"; break;
    case ST_FAT: case ST_BASE_FAT: return "Fatigue"; break;
    case ST_SP_HEAL_RATE: return "Spell Point Healing Rate"; break;
    case ST_HP_HEAL_RATE: return "Hit Points Healing Rate"; break;
    case ST_FP_HEAL_RATE: return "Fatigue Healing Rate"; break;
    default: return sprintf("Stat %d", s); break;
    }
}

nomask string
random_stat()
{
    return stat_name(({
	ST_STR, ST_DEX, ST_CON, ST_INT,
	ST_SP_HEAL_RATE,
	ST_HP_HEAL_RATE,
	ST_FP_HEAL_RATE, })[random(7)]);
}

nomask string
cond_name(int c)
{
    switch (c)
    {
    case C_BLIND: return "Blindness"; break;
    case C_DEAF: return "Deafness"; break;
    case C_STUNNED: return "Stun"; break;
    case C_UNCONSCIOUS: return "Unconsciousness"; break;
    case C_CONFUSED: return "Confusion"; break;
    case C_POISONED: return "Poisoning"; break;
    case C_DETECT_INVIS: return "Detect Invisible"; break;
    case C_SLOWED: return "Slow"; break;
    case C_HASTED: return "Haste"; break;
    case C_HALLUCINATING: return "Hallucination"; break;
    case C_DETECT_MAGIC: return "Detect Magic"; break;
    case C_RESIST_POISON: return "Resist Poison"; break;
    case C_RESIST_FIRE: return "Resist Fire"; break;
    case C_RESIST_COLD: return "Resist Cold"; break;
    case C_RESIST_ACID: return "Resist Acid"; break;
    case C_RESIST_ELECTRICITY: return "Resist Electricity"; break;
    case C_CASTING: return "Casting"; break;
    case C_EUNUCH: return "Eunuch"; break;
    case C_SICK: return "Sickness"; break;
    case C_RESIST_DEATH: return "Resist Death"; break;
    default: return sprintf("Condition %d", c); break;
    }
}

nomask string
random_cond()
{
    return cond_name(({
	C_BLIND, C_DEAF, C_STUNNED, C_UNCONSCIOUS, C_CONFUSED,
	C_POISONED, C_DETECT_INVIS, C_SLOWED, C_HASTED, C_HALLUCINATING,
	C_DETECT_MAGIC, C_RESIST_POISON, C_RESIST_FIRE, C_RESIST_COLD, C_RESIST_ACID,
	C_RESIST_ELECTRICITY, C_EUNUCH, C_SICK, C_RESIST_DEATH,})[random(19)]);
}

nomask string
random_resist()
{
    return cond_name(({
	C_BLIND, C_DEAF, C_STUNNED, C_UNCONSCIOUS, C_CONFUSED,
	C_POISONED, C_HALLUCINATING, C_SICK, })[random(8)]);
}

nomask string
desc_b(int a)
{
    if (a < 0) a = -a;
    if (a < 2) return " slightly.";
    else if (a < 3) return " somewhat.";
    else if (a < 4) return " a lot!";
    else return " very much!";
}

nomask string
random_desc_b()
{
    return desc_b(random(5));
}

nomask int
identify_cmd(string name)
{
    return _identify(this_player(), name);
}

nomask int
_identify(object tp, string name)
{
    object ob;
    string *tmp, tmp2;
    int *sp, s, i, sinv, fail;

    if (!CHECK) return 0;

    if (!name) {
	notify_fail("Identify what?\n");
	return 0;
    }

    sinv = (tp->query_condition(C_DETECT_INVIS) ? IL_INVISIBLE : 0);

    ob = present4(lower_case(name), tp, tp, sinv);
    if (!ob) ob = present4(lower_case(name), environment(tp), tp, sinv);
    if (!ob && lower_case(name) == "me")
	ob = tp;

    if (!ob) {
	tp->tell_me("You can't see anything called " + name
	  + " around here.");
	return 1;
    }

    if (!(tmp2 = (string)ob->query_short(sinv, tp))
      && !(tmp2 = (string)ob->query_real_name()))
	tmp2 = "something";

    tmp = ({
      capitalize(tmp2) + ":"
    });

    // Fumbled?
    fail = ((random(101) >= 66)
      || (random(101) >= (int)tp->query_level()));
    if ((int)tp->query_coder_level()
      && fail)
	tp->tell_me("Debug note (given to coders only): Identify was fumbled.");

    if (ob->is_weapon()
      || (!ob->is_armour() && fail && (random(101) > 60)))
    {
	if ((!fail && ob->query(WP_TROLL_WEAPON))
	  || (fail && (random(101) < 50)))
	    tmp += ({ " This weapon can be used by trolls." });

	if ((!fail
	    && (ob->is_poisoned()
	      || call_other("/guilds/thieves/poison_d", "is_poisoned", ob)))
	  || (fail && (random(101) < 30)))
	    tmp += ({ " It is poisoned!" });
    }

    /* Info hasn't been used for strictly player stuff.
     * set_info()s must be checked before this can be given.
    if (stringp(tmp2 = (string)ob->query_info()))
      tmp += ({ tmp2 });
    */

    if (ob->is_armour()
      || (!ob->is_weapon() && fail && (random(101) > 60)))
    {
	// Note: Bless/curse must not be detected by identify.

	if (!fail
	  && pointerp(sp = (int *)ob->query_specialProperties())
	  && ((s = sizeof(sp)) > 1))
	    for (i = 0; i < s; i += 2)
	    {
		if (sp[i] & ARM_SP_BOOST_STAT)
		    tmp += ({
		      " Boosts " +
		      stat_name(sp[i] & ~ARM_SP_BOOST_STAT)
		      + desc_b(sp[i + 1])
		    });
		else if (sp[i] & ARM_SP_DRAIN_STAT)
		    tmp += ({
		      " Drains " +
		      stat_name(sp[i] & ~ARM_SP_DRAIN_STAT)
		      + desc_b(sp[i + 1])
		    });
		else if (sp[i] & ARM_SP_CAUSE_CONDITION)
		    tmp += ({
		      " Causes " +
		      cond_name(sp[i] & ~ARM_SP_CAUSE_CONDITION)
		    });
		else if (sp[i] & ARM_SP_RESIST_CONDITION)
		    tmp += ({
		      " Resists " +
		      cond_name(sp[i] & ~ARM_SP_RESIST_CONDITION)
		    });
	    }
	else if (fail && (random(101) < 60))
	{
	    for (i = 0; i < random(4); i++)
	    {
		if (random(101) < 50)
		    tmp += ({ (random(3) ? " Resists " + random_resist() :
			" Causes " + random_cond()) });
		else
		    tmp += ({ (random(3) ? " Boosts " : " Drains ")
		      + random_stat() + random_desc_b() });
	    }
	}
    }

    if (sizeof(tmp) < 2)
	tmp = ({ "There doesn't seem to be anything special about it." });

    tp->more(tmp);
    return 1;
}
