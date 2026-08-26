/*
** File: /cmds/std/_score.c (Score command)
** Purpose: Gives basic stats and conditions, etc.
** Changes: This command has been completely rewritten from scratch by
**     Cyanide, and has several advantages over the standard _score used
**     on most MUDs. First, wizards may use the command as a "stat" command
**     by adding an argument. Also, wizards get more information (MR, 
**     resistances, etc.). Quite nice.
** Credits: 
**   15 Nov 97  Cyanide rewrote the command. Little remnants remain of the
**      previous version written by Mobydick@TMI-2.
*/

#define STAT_NAMES ({ "strength", "intelligence", "constitution", \
   "wisdom", "dexterity", "charisma" })

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;

int cmd_score(string str) {
    int wiz = 0, x, y;
    mapping lvl_map ;
    string refer, tmpA, tmpB, *str_array;
    object ob;

    if (wizardp(TP)) wiz = 1;

    if (!wizardp(TP) || !str)
	ob = TP;
    else 
	ob = find_player(str);

    if (!ob) ob = present(str, environment(TP));
    if (!ob || !living(ob)) {
	write("There is no player or monster in the room named "+
	  capitalize(str)+".\n");
	return 1;
    }

    if (ob == TP) refer = "You are";
    else refer = ob->query("cap_name")+" is";

    write("[ " + capitalize((string)ob->query("short")) + " ]\n\n");

    tmpA = ob->query("race") ;
    if (!tmpA) tmpA = "generic monster";
    lvl_map = ob->query_levels();

    y = 0;
    if (lvl_map && tmpA) {
	write (refer+" a level "+values(lvl_map)[0]+" "+
	  tmpA+" "+keys(lvl_map)[0]+".\n");
	if (sizeof(keys(lvl_map)) > 1) {
	    if (ob == TP) str = "You previously were";
	    else str = ob->query("cap_name")+" previously was";
	    write(str+" a level "+values(lvl_map)[1]+" "+
	      keys(lvl_map)[1]+".\n"); 
	}
	y++;
    }
    if (ob->query("age")) {
	write(refer + " " + format_time((int)ob->query("age"), 1) +
	  " old.\n");
	y++;
    }

    if (y) write("\n");
    str = "";

    if (!ob->query("stat")) {
	write("** WARNING - NO STATS SET **\n\n");
    } else {
	if (!ob->query("base_stat"))
	    ob->set("base_stat", ob->query("stat") );

	for (x=0; x<sizeof(STAT_NAMES); x+=2) {
	    string very_tmp = "";

	    very_tmp = STAT_NAMES[x];      
	    tmpA = capitalize(very_tmp)+": "+ob->query("base_stat/"+very_tmp);
	    y = (int)ob->query("stat/"+very_tmp) - 
	    (int)ob->query("base_stat/"+very_tmp);
	    if (y<0) tmpA += " (" + y + ")";
	    if (y>0) tmpA += " (+" + y + ")";

	    very_tmp = STAT_NAMES[x+1];
	    tmpB = capitalize(very_tmp)+": "+ob->query("base_stat/"+very_tmp);
	    y = (int)ob->query("stat/"+very_tmp) - 
	    (int)ob->query("base_stat/"+very_tmp);
	    if (y<0) tmpB += " (" + y + ")";
	    if (y>0) tmpB += " (+" + y + ")";

	    str += sprintf("%22-s%s\n", tmpA, tmpB);
	}
    }
    write(str+"\n");
    str = "";
    if (ob->query("max_hp")) {
	x = ob->query("max_hp");
	y = ob->query("hit_points");
	str+=("Hit Points: "+y+" of "+x+" ("+((y*100)/x)+"%)\n");
    }
    if (ob->query("max_sp")) {
	x = ob->query("max_sp");
	y = ob->query("spell_points");
	str+=("Spell Points: "+y+" of "+x+" ("+((y*100)/x)+"%)\n");
    }
    if (ob->query("max_tp")) {
	x = ob->query("max_tp");
	y = ob->query("theurgy_points");
	str+=("Theurgy Points: "+y+" of "+x+" ("+((y*100)/x)+"%)\n");
    }
    if (wiz) {
	if (ob==TP) tmpA = "You have";
	else tmpA = ob->query("cap_name")+" has";

	x = ob->query("armor_class") - PROPERTY_D->query_dex_ac_bonus(ob) -
	ob->query("magical_defense");

	write(tmpA + " an armor class of " + x +".\n");
    }
    write(str+"\n");

    str = "";
    write("Experience: "+ob->query("experience")+"\n");
    tmpA = "Kills: "+ob->query("kills");
    tmpB = "Deaths: "+ob->query("deaths");
    str += sprintf("%22-s%s\n", tmpA, tmpB);
    tmpA = "Player Kills: "+ob->query("pkills");
    tmpB = "Player Deaths: "+ob->query("pdeaths");
    str += sprintf("%22-s%s\n", tmpA, tmpB);
    write(str+"\n");
    y = 0;

    lvl_map = ob->query("best_kill");
    if (lvl_map) {
	if (ob==TP) 
	    str = "Your best kill is: ";
	else
	    str = ob->query("cap_name")+"'s best kill is: ";

	str += keys(lvl_map)[0] + " (" + values(lvl_map)[0] + " xp)\n";
	write(str);
    }

    if (ob==TP) {
	tmpB = "You're";
	str = "You have";
    } else {
	tmpB = ob->query("cap_name")+" is";
	str = ob->query("cap_name")+" has";
    }

    if (ob->query("wealth")) {
	y = (int)ob->query("wealth");
	write(str+" "+y+" credits.\n");      
    } else {
	write(refer + " piss broke.\n");
    }
    write("\n");

    if (ob==TP)
	tmpA = "You feel";
    else
	tmpA = ob->query("cap_name")+" feels";

    if (ob->query("spouse"))
	write(refer+" married to "+ob->query("spouse")+"\n");

    x = this_player()->query("drunk") ;

    switch (x) {
    case -100..-4 : write(tmpA+" like stir-fried shit.\n"); break;
    case -3..-2 : write (tmpB+" pretty hung over.\n") ; break ;
    case -1 : write(str+" a slight headache.\n"); break;
    case 0 : break;
    case 1..5 : write (tmpB+" a bit buzzed.\n") ; break ;
    case 6..10 : write (tmpB+" really buzzed.\n") ; break ;
    case 11..15 : write (tmpB+" pretty drunk.\n") ; break ;
    case 16..20 : write (tmpB+" completely smashed.\n") ; break ;
    default : write (tmpB+" too drunk to see.\n") ; break ;
    }

    if (ob==TP) tmpA = "your";
    else tmpA = ob->query("cap_name")+"'s";

    x = ob->query("woundlevel");
    if (x && wiz) {
	x = ( (int)ob->query("max_hp") * 10 ) / x;
	write(x+"% of "+tmpA+" wounds are unhealable.\n");
    }

    if (ob->query("undead"))
	write(refer + " undead.\n");

    if (ob->query("magic_resist") && (wiz)) 
	write(refer+" "+ob->query("magic_resist")+"% magic resistant.\n");

    if (ob->query("weap_resist") && (wiz))
	write(refer+" immune to weapons of less than +"+
	  ob->query("weap_resist")+" enchantment.\n");

    y=0;
    if (ob->query("resist_type") && wiz) {
	str = "Immunities and Resistances:\n  ";
	lvl_map = ob->query("resist_type");
	for (x=0; x<sizeof(keys(lvl_map)); x++) {
	    if ( (int)(values(lvl_map)[x]) != 100 ) {
		str += capitalize(keys(lvl_map)[x])+" ("+
		values(lvl_map)[x]+"%)";
		y++;
	    }
	}
	if (y) write(str+"\n");
    }

    return 1;
}


string help() {
    string str;
    str = ("Usage: score\n"+
      "The score command will show you your current hit points, spell points,\n"+
      "statistics, and wealth. You can see your skills by typing \"skills\"\n") ;
    return str ;
}


/* EOF */
