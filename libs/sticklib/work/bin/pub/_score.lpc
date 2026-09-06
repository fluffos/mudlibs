#include <cmd.h>
#include <areas.h>
#include <conditions.h>
#include <coder_levels.h>
#include <daemons.h>
#include <city_name.h>
#include <player_defs.h>

nomask string
query_feets_inches(int x)
{
    int i, f;

    if (!x) return "0'";

    i = ((100 * x) / 245);
    f = (i / 12);
    i = i - (f * 12);

    return sprintf("%d'%d\"", f, i);
}

nomask int
score_cmd(string arg, object me)
{
    string tmp, *gabba, txt;
    int x, ep, expt, epn, lvl, need_expt;
    object ob;

    //  if (!CHECK) return 0;

    ob = me;

    /* Coders can "score xxxx", where xxxx may be any living */
    if ((int)ob->query_coder_level() && arg)
    {
	ob = present(arg, environment(TP));
	if (!ob) ob = find_living(arg);
	if (!ob) {
	    TP -> tell_me("Can't find any living named '"+arg+"'.");
	    return 1;
	}
    }

    if (ob->query_ghost()) {
	TP -> tell_me("You are in an immaterial state with no scores.");
	return 1;
    }

    if (query_verb() == "sc")
    {
	x = (int)ob->query_wimpy();
	ob->tell_me(sprintf(
	    "< HP %3d/%3d | SP %3d/%3d | FP %3d/%3d | %s >",
	    (int) ob->query_hp(), (int) ob->query_max_hp(),
	    (int)ob->query_sp(), (int)ob->query_max_sp(),
	    (int)ob->query_fp(), (int)ob->query_max_fp(),
	    (x > 0 ? sprintf("Wimpy %d%%", x) : "Brave Mode")));
	return 1;
    }

    txt = sprintf(
      "You have %3d/%3d hit, %3d/%3d spell and %3d/%3d fatigue points.",
      (int)ob->query_hp(), (int)ob->query_max_hp(),
      (int)ob->query_sp(), (int)ob->query_max_sp(),
      (int)ob->query_fp(), (int)ob->query_max_fp());

    /* Show qp only if we have them. Some have quests but not yet qp's... */

    lvl = (int)ob->query_level();
    ep = (int)ob->query_ep();
    expt = (int)ob->query_exp_times();
    need_expt = (int)LEVELS_D->query_exp_times_for_level(lvl + 1) - expt;
    x = (int) ob->query_qp();

    if (expt < 1)
	txt = sprintf("%s\nYou have %d experience and %d quest points",
	  txt, ep, x);
    else
	txt = sprintf("%s\nYou have %d (%d) experience and %d quest points",
	  txt, ep, (int)ob->query_exp_times(), x);

    /* New: Show how much one exp & qp needs to next level. //Graah */
    epn = (int)LEVELS_D->query_exp_for_level(lvl);

    x = ((int)QUEST_D->qp_for_level((int)ob->query_level()) - x);
    if (x <=0 ) x = 0;

    if ((epn > ep) || (need_expt > 0) || x)
    {
	txt += "\nYou need ";
	if ((need_expt == 0 && epn > ep) ||
	  (need_expt > 0))
	{
	    if (need_expt == 0 || (epn > ep))
		txt += (epn - ep) + " experience";
	    else
		txt += (epn - ep + 2100000000) + " experience";

	    if (x) txt += " and ";
	}
	if (x) txt += x + " quest points";
	txt += " for the next level.";
    }

    txt += "\nYou have " +(int)ob->query_money() + " gold coins in your purse.";
    TP -> tell_me(txt);

    ob->show_age();	/* ARGGGGGGGGHHH! Shitty way of doing this!!!! */

    if ((x = (int)ob->query_height()))
    {
	TP->tell_me("You are " + query_feets_inches(x) +
	  " (" + x + " cm) tall.");
    }

    if ((x = (int)ob->query_weight_kg()))
    {
	TP->tell_me("You weigh " + (x * 2) + " pounds (" + x + " kg).");
    }

    txt = "";

    if ((tmp = (string)ob->query_al_title()))
	txt += "\nYour alignment is " + capitalize(tmp) + ".\n";

    tmp = (string)ob->query_title();
    if (!tmp) tmp = ""; else tmp = " " + tmp;
    txt += "This ranks you as " + capitalize((string)ob->query_real_name())
    + tmp + ", level "
    + (int)ob->query_level() + " " + (string)ob->query_gender_string();

    if ((tmp = (string)ob->query_race())) txt += " " + tmp;

    TP -> tell_me(txt + ".");

    /* Verbal ability descriptions //Graah */
    "/bin/daemons/descs"->desc_me(ob);

    /* Aaaaaarggghhh!!! No, No, NO, NOOOO direct writes!!!! Always return
     * strings!!!!!
     */

    /* Use stat command to see the real numbers...
       if ((int)TP->query_coder_level())
	  TP->tell_me(sprintf(
  "(Str %d Dex %d Int %d Con %d Fatigue %d)",
  (int) ob->query_stat(ST_STR), (int) ob->query_Stat(ST_DEX),
  (int) ob->query_stat(ST_INT), (int) ob->query_stat(ST_CON),
  (int) ob->query_stat(ST_FAT)));
       */

    txt = "";

    gabba = ({});

    if (ob->query_intoxication()) gabba += ({ "intoxicated" });
    if (ob->query_stuffed()) gabba += ({ "satiated" });
    if (ob->query_soaked()) gabba += ({ "not thirsty" });
    if (ob->query_disguised()) gabba += ({ "disguised" });

    if (x = (int) ob->query_wimpy())
	gabba += ({ "wimpy at " + x + "%" });
    else gabba += ({ "in brave mode" });

    if (ob->query_sit()) gabba += ({ "sitting" });
    if (ob->query_rest()) gabba += ({ "resting" });
    if (ob->query_frog()) gabba += ({ "cursed to be a frog" });
    if (ob->query_invis()) gabba += ({ "invisible"});

    if (sizeof(gabba))
	txt += ("\nYou are "+implode(gabba, ", ", " and ") + ".");

    gabba = ({});

    /* Drained abilities? */
    if ((int)ob->query_stat(ST_STR) < (int)ob->query_stat(ST_BASE_STR))
	gabba += ({ "strength" });
    if ((int)ob->query_stat(ST_DEX) < (int)ob->query_stat(ST_BASE_DEX))
	gabba += ({ "dexterity" });
    if ((int)ob->query_stat(ST_CON) < (int) ob->query_stat(ST_BASE_CON))
	gabba += ({ "constitution" });
    if ((int) ob->query_stat(ST_INT) < (int) ob->query_stat(ST_BASE_INT))
	gabba += ({ "intelligence" });
    /* if ((int)ob->query_experience() < (int)ob->query_max_experience())
       gabba += ({ "experience" }); */

    if ((x = sizeof(gabba)) > 0)
    {
	tmp = "\nYour ";
	if (x == 1) tmp += gabba[0] + " has";
	else tmp += implode(gabba, ", ", " and ") + " have";
	tmp += " been drained!";

	txt += tmp;
    }

    /* Criminal? */
    if (ob->query_crime_level())
	txt += ("\nYou are a criminal in " CITY_NAME ", hunted for "+
	  (string)ob->query_crime_status() + "!");

    if (ob->query_condition(C_BLIND)) txt += "\nYou cannot see anything!";
    if (ob->query_condition(C_DEAF)) txt+="\nYou are unable to hear anything!";
    if (ob->query_condition(C_STUNNED)) txt += "\nYou are stunned!";
    if (ob->query_condition(C_UNCONSCIOUS)) txt += "\nYou are unconscious.";
    if (ob->query_condition(C_CONFUSED)) txt += "\nYou feel very confused.";
    if (ob->query_condition(C_SLOWED)) txt += "\nYou feel very slow.";
    if (ob->query_condition(C_HASTED)) txt += "\nEveryone else seems to move very slowly.";
    if (ob->query_condition(C_POISONED)) txt += "\nYou feel dizzy and weak from poison.";
    if (ob->query_condition(C_HALLUCINATING)) txt += "\nWow, man! Everything looks so cosmic!";

    if (ob->query(PLR_HPSP_REPORT_ON))
	txt += "\nYou are using Report.";
    if (ob->query(PLR_INFO_ON))
	txt += "\nYou are using Info.";
    if (ob->query(PLR_ALLOW_SUMMON)) txt += "\nYou can be easily summoned.";

    if (ob->query(LIV_OK_TO_PK))
	txt = sprintf("%s\nYou can be PKed everywhere now!", txt);
    TP -> tell_me(txt);

    return 1;
}
