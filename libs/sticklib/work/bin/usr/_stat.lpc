#include <cmd.h>
#include <armour_defs.h>
#include <weapon_defs.h>
#include <conditions.h>
#include <stats.h>

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
    case ST_SP_HEAL_RATE: return "SPHealRate"; break;
    case ST_HP_HEAL_RATE: return "HPHealRate"; break;
    case ST_FP_HEAL_RATE: return "FPHealRate"; break;
    default: return sprintf("Stat %d", s); break;
    }
}

nomask string
cond_name(int c)
{
    switch (c)
    {
    case C_BLIND: return "Blind"; break;
    case C_DEAF: return "Deaf"; break;
    case C_STUNNED: return "Stunned"; break;
    case C_UNCONSCIOUS: return "Unconscious"; break;
    case C_CONFUSED: return "Confused"; break;
    case C_POISONED: return "Poisoned"; break;
    case C_DETECT_INVIS: return "Detect_Invis"; break;
    case C_SLOWED: return "Slowed"; break;
    case C_HASTED: return "Hasted"; break;
    case C_HALLUCINATING: return "Hallucinating"; break;
    case C_DETECT_MAGIC: return "Detect_Magic"; break;
    case C_RESIST_POISON: return "Resist_Poison"; break;
    case C_RESIST_FIRE: return "Resist_Fire"; break;
    case C_RESIST_COLD: return "Resist_Cold"; break;
    case C_RESIST_ACID: return "Resist_Acid"; break;
    case C_RESIST_ELECTRICITY: return "Resist_Electricity"; break;
    case C_CASTING: return "Casting"; break;
    case C_EUNUCH: return "Eunuch"; break;
    case C_SICK: return "Sick"; break;
    case C_RESIST_DEATH: return "Resist_Death"; break;
    default: return sprintf("Condition %d", c); break;
    }
}

nomask int
stat_cmd(string name)
{
    object ob;
    string *tmp, tmp2;
    int *sp, i, s;

    if (!CHECK) return 0;

    if (!name) {
	notify_fail("Stat whom (or what)?\n");
	return 0;
    }

    ob = present(lower_case(name), environment(TP));
    if (!ob) ob = find_living(lower_case(name));
    if (!ob) ob = present(lower_case(name), TP);
    if (!ob) ob = find_object(name);
    if (!ob) ob = find_object((string)TP->absolute_path(name));
    if (!ob && lower_case(name) == "here")
	ob = environment(TP);
    if (!ob && lower_case(name) == "me")
	ob = TP;

    if (!ob) {
	notify_fail("No such thing found (better stat coming soon).\n");
	return 0;
    }

    if (living(ob))
    {
	if(environment(ob)) TP->tell_me("In Room: "+object_name(environment(ob)) + "\n");
	ob->show_stats();
	return 1;
    }

    tmp = ({});

    tmp += ({ "File name   : " + object_name(ob)
      + ", creator: " + creator(ob) });
    tmp += ({ "Object name : " + (string)ob->query_name(999999),
      "Object short: " + (string)ob->query_short(999999),
      "Object ids  : " + (string)ob->query_id_str(),
      "Obj. weight : " + (int)ob->query_weight(),
      "Obj. value  : " + (int)ob->query_value(),
      "set_light(0): " + (int)call_other(ob, "query_light"),
    });

    if (ob->is_weapon())
    {
	tmp += ({
	  "Weapon type : " + (string)ob->query(WP_TYPE),
	  "Weapon class: " + (int)ob->query_wc(),
	});
	if (ob->query(WP_TROLL_WEAPON))
	    tmp += ({ "Weapon can be used by trolls." });
    }

    if (stringp(tmp2 = (string)ob->query_info()))
	tmp += ({
	  "query_info  : " + tmp2
	});

    if (ob->is_armour())
    {
	tmp += ({
	  "Armour type : " + (string)ob->query_type(),
	  "Armour class: " + (int)ob->query_ac()
	});

	if (stringp(tmp2 = (string)ob->query_race()))
	    tmp += ({ "Armour race : " + tmp2 });

	if (pointerp(sp = (int *)ob->query_specialProperties())
	  && ((s = sizeof(sp)) > 1))
	    for (i = 0; i < s; i += 2)
	    {
		if (sp[i] & ARM_SP_BOOST_STAT)
		    tmp += ({
		      " Boosts " +
		      stat_name(sp[i] & ~ARM_SP_BOOST_STAT) + " by " + sp[i + 1]
		    });
		else if (sp[i] & ARM_SP_DRAIN_STAT)
		    tmp += ({
		      " Drains " +
		      stat_name(sp[i] & ~ARM_SP_DRAIN_STAT) + " by " + sp[i + 1]
		    });
		else if (sp[i] & ARM_SP_CAUSE_CONDITION)
		    tmp += ({
		      " Causes condition " +
		      cond_name(sp[i] & ~ARM_SP_CAUSE_CONDITION)
		      + " to " + sp[i + 1]
		    });
		else if (sp[i] & ARM_SP_RESIST_CONDITION)
		    tmp += ({
		      " Resist condition " +
		      cond_name(sp[i] & ~ARM_SP_RESIST_CONDITION)
		      + " to " + sp[i + 1]
		    });
		else
		    tmp += ({
		      " specialProperty: " + sp[i] + " -> " + sp[i + 1]
		    });
	    }
    }

    TP->more(tmp);
    return 1;
}
