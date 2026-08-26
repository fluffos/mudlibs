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
**   30 Apr 00  Chronos reinvents the wheel and spruces up the score
**      command.
**    5 May 00  Cyanide makes wizard/admin status independant of
**              level so Tiamat doesn't detect as admin anymore.
**              He also centered the name in the top field.
*/

#define LINE "_______________________________________________________________________________"
#define STAT_NAMES ({ "strength", "intelligence", "constitution", \
   "wisdom", "dexterity", "charisma" })

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;

int cmd_score(string str) {
    int wiz = 0, x, y;
    mapping lvl_map ;
    string refer, tmpA, tmpB, ClassStr ;
    string *str_array ;
    object ob, link;

    if (wizardp(TP)) wiz = 1;

    // These 2 lines allow us to use the score command on other people.
    if (!wizardp(TP) || !str) ob = TP;
    else ob = find_player(str);

    if (!ob) ob = present(str, environment(TP));
    if (!ob || !living(ob)) {
	write("There is no player or monster in the room named "+
	  capitalize(str)+".\n");
	return 1;
    }

    // Write the name and title here.
    tmpA = "[ "+capitalize((string)ob->query("short")) +" ]" ;

    // Cyanide did the sweet sprintf().  Love him. Now.
    write( sprintf( "%|79\'_\'s\n", tmpA ) ); 

    /*
	y = 79 - strlen(tmpA) ;
	for(x=0;x<y;x++) tmpA += "_" ;
	write(tmpA+"\n") ;
    */

    // This is the section that don't work for shit.
    ClassStr ="";
    tmpA = capitalize(ob->query("gender")) + " " + capitalize(ob->query("race")) ;
    if (!tmpA) tmpA = "Generic Monster" ;
    lvl_map = ob->query_levels();
    y = 0;
    if (lvl_map) {
   ClassStr = "Level "+values(lvl_map)[0]+" "+capitalize(keys(lvl_map)[0]);
	if (sizeof(keys(lvl_map)) > 1) 
  ClassStr+="/ Level "+values(lvl_map)[1]+" "+
     capitalize(keys(lvl_map)[1]) ;
	y++;
    } 
    y = ob->query_level()  ;
    if (!y) y=1;
    if (wizardp(ob)) ClassStr = sprintf("Wizard of the %s Domain" ,
	  DOMAIN_D->query_domain(ob->query_link())) ;
    if (adminp(ob)) ClassStr = "Administrator of Mortal Remains" ;
    if (!lvl_map) ClassStr = "Level "+y+" Peasant" ;  
    ClassStr += "." ;
    y = 79 - (strlen(ClassStr)+strlen(tmpA))  ;
    write(tmpA); 
    for(x=0;x<y;x++) write(" ") ;
    write(ClassStr+"\n") ;

    str = "";
    write(LINE+"\n") ;

    if (!ob->query("stat")) write("** INTERNAL ERROR - NO STATS SET **\n\n");
    else {
	if (!ob->query("base_stat"))
	    ob->set("base_stat", ob->query("stat") );

	for (x=0; x<sizeof(STAT_NAMES); x+=2) {
	    string very_tmp = "";

	    very_tmp = STAT_NAMES[x];      
	    tmpA = capitalize(very_tmp) ;
	    if (very_tmp=="strength") tmpA+="        : ";
	    if (very_tmp=="constitution") tmpA+="    : ";
	    if (very_tmp=="dexterity") tmpA+="       : ";
	    tmpA += ob->query("base_stat/"+very_tmp);
	    y = (int)ob->query("stat/"+very_tmp) - 
	    (int)ob->query("base_stat/"+very_tmp);
	    if (y<0) tmpA += " (" + y + ")";
	    if (y>0) tmpA += " (+" + y + ")";

	    very_tmp = STAT_NAMES[x+1];
	    tmpB = capitalize(very_tmp) ; 
	    if (very_tmp=="intelligence") tmpB+="    : ";
	    if (very_tmp=="wisdom") tmpB+="          : ";
	    if (very_tmp=="charisma") tmpB+="        : " ;
	    tmpB += ob->query("base_stat/"+very_tmp);
	    y = (int)ob->query("stat/"+very_tmp) - 
	    (int)ob->query("base_stat/"+very_tmp);
	    if (y<0) tmpB += " (" + y + ")";
	    if (y>0) tmpB += " (+" + y + ")";

	    str += sprintf("           %28-s%s\n", tmpA, tmpB);
	}
    }
    write(str);
    write(LINE+"\n") ;
    str = "           eXperience: ";
    x=ob->query("hit_points") ;
    y=ob->query("max_hp") ;
    str += sprintf("%-15d Hit Points    : %i of %i (%i%%)\n",
      (int)ob->query("experience"),x,y,(x*100)/y) ;
    write(str) ;
    str = "           Credits   : ";
    str += sprintf("%-15d ", (int)ob->query("wealth") ) ;
    if (ob->query("max_sp")) {
	x = ob->query("max_sp");
	y = ob->query("spell_points");
	str += ("Spell Points  : "+y+" of "+x+" ("+((y*100)/x)+"%)") ;
    }
    write(str+"\n") ;
    str = "           Kills     : ";
    str += sprintf("%-15d ",(int)ob->query("kills") ) ;
    if (ob->query("max_tp")) {
	x = ob->query("max_tp");
	y = ob->query("theurgy_points");
	str+=("Theurgy Points: "+y+" of "+x+" ("+((y*100)/x)+"%)");
    }
    write(str+"\n") ;
    str = "           Deaths    : ";
    str += sprintf("%-15d ", (int)ob->query("deaths") ) ;
    if (wiz) {
	x = ob->query("armor_class") -
	PROPERTY_D->query_dex_ac_bonus(ob) -
	ob->query("magical_defense");
	str += "Armor Class   : " + x;
    }
    write(str+"\n");
    write(LINE+"\n") ;
    y = 0;
    if (ob == TP) refer = "You are";
    else refer = ob->query("cap_name")+" is";
    if (ob->query("age")) 
	write(refer + " " + format_time((int)ob->query("age"), 1) +
	  " old.\n");
    if (ob->query("spouse"))
	write(refer+" married to "+ob->query("spouse")+".") ;
    if (ob->query("spouse")=="Chronos" || 
      ob->query("spouse")=="Cyanide" ) 
	write(". You lucky girl, you.  :)\n") ;
    else write("\n") ;
    lvl_map = ob->query("best_kill");
    if (lvl_map) {
	if (ob==TP) 
	    str = "Your best kill is: ";
	else
	    str = ob->query("cap_name")+"'s best kill is: ";

	str += keys(lvl_map)[0] + " (" + values(lvl_map)[0] + " xp)\n";
	write(str);
    }
    if (ob==TP) tmpA = "You feel";
    else tmpA = ob->query("cap_name")+" feels";
    x = this_player()->query("drunk") ;
    switch (x) {
    case -100..-4 : write(tmpA+" like stir-fried shit.\n"); break;
    case -3..-2 : write (tmpA+" pretty hung over.\n") ; break ;
    case -1 : write(tmpA+" a slight headache.\n"); break;
    case 0 : break;
    case 1..5 : write (tmpA+" a bit buzzed.\n") ; break ;
    case 6..10 : write (tmpA+" really buzzed.\n") ; break ;
    case 11..15 : write (tmpA+" pretty drunk.\n") ; break ;
    case 16..20 : write (tmpA+" completely smashed.\n") ; break ;
    case 21..22 : write (tmpA+" seeing double.\n") ;
    default : write (tmpA+" too drunk to see.\n") ; break ;
    }

    if (ob==TP) tmpA = "your";
    else tmpA = ob->query("cap_name")+"'s";
    x = ob->query("woundlevel");
    if (x && wiz) {
	x = ( (int)ob->query("max_hp") * 10 ) / x;
	write(x+"% of "+tmpA+" wounds are unhealable.\n");
    }

    tmpA = ob->query("gang") ;
    if (tmpA) 
	write(refer+" a member of the "+capitalize(tmpA)+" gang.\n") ;
    if (ob->query("immortal"))
	write(refer + " immortal.\n");
    if (ob->query("blind"))
	write(refer + " blind.\n");
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
    str += "  ";
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
    return @ENDHELP
Usage: score

The score command will show you your current hit points, spell points,
statistics, and wealth. 

See also:
  For information on your skills: skills
  For combat statistics and info: combat
  For your kill statistics      : kills
ENDHELP
    ;   
}   

/* EOF */

