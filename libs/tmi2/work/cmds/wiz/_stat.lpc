// _stat.c
// Command to show a living object's status.
// Created by Mobydick@TMI-2, 11-11-92
// Replaced an existing _stat command which had no header and which had
// lost all touch with reality.

#include <mudlib.h>
#include <money.h>

inherit DAEMON ;
inherit COINVALUE ;

int help() ;

int cmd_stat (string name) {

	string *coins, *list, *statnames ;
	object ob ;
	string *skillnames ;
	mapping skills ;
	int i, flag ;
	string spouse, tempstr ;
	string subj ;
	mapping stats ;
	mapping wealth ;

	if (!name) {
		return help() ;
	}
	ob = get_object(name);
	if (!ob || !living(ob)) {
		notify_fail("No such living object exists.\n");
		return 0 ;
	}
	subj = capitalize(subjective(ob->query("gender"))) ;
	tempstr = ob->query("race") ;
	if (tempstr) write (subj+" is " + article(tempstr) + " " + tempstr +
		".\n") ;
	spouse = ob->query("spouse") ;
	if (spouse) {
		write (subj+" is married to "+spouse+".\n") ;
	}
	if ((int)ob->query("no_attack")) {
		write (subj+"  is not an attackable object.\n") ;
	}
/*
	If you want drunkeness, put this back in.
	flag = ob->query("drunk") ;
	switch (flag) {
		case 1..5 : {
			write (subj+" are a bit tispy.\n") ;
			break ;
		}
		case 6..10 : {
			write (subj+" are somewhat drunk.\n") ;
			break ;
		}
		case 11..15 : {
			write (subj+" are rather drunk.\n") ;
			break ;
		}
		case 16..20 : {
			write (subj+" are completely smashed.\n") ;
			break ;
		}
		case 21..25 : {
			write (subj+" are maximally drunk.\n") ;
			break ;
		}
	}
*/
	write ("Hit points: "+ob->query("hit_points")+" of "+
		ob->query("max_hp")+"\n") ;
	write ("Spell points: "+ob->query("spell_points")+" of "+
		ob->query("max_sp")+"\n") ;
	write ("\n") ;
	stats = ob->query("stat") ;
	if (stats && sizeof(stats)) {
	statnames = keys(stats) ;
	for (i=0;i<sizeof(stats);i++) {
		write (sprintf("%12-s : %d\n",capitalize(statnames[i]),stats[statnames[i]])) ;
	}
	write ("\n") ;
	}
	wealth = ob->query("wealth") ;
	if (!wealth) {
                write (subj+" doesn't have any coins in "+
               possessive(ob->query("gender"))+" purse.\n");
	} else {
	coins = keys(wealth) ;
	list = sort_array(coins,"sort_coins",this_object()) ;
	flag=0 ;
	for (i=0;i<sizeof(coins);i++) {
		if (wealth[list[i]]>0) {
			write (sprintf("   %15-s %d\n",capitalize(list[i]),wealth[list[i]])) ;
			flag=1 ;
		}
	}
	if (flag==0) {
               write (subj+" doesn't have any coins in "+
             possessive(ob->query("gender"))+" purse.\n");
	}
	}
	skills = ob->query_skills() ;
	if (skills && sizeof(skills)) {
	skillnames = keys(skills) ;
	write ("\n") ;
	write (capitalize(possessive(ob->query("gender"))) +
		 " skills are:\n") ;
	list = sort_array(skillnames, "sort_skills", this_object()) ;
	for (i=0;i<sizeof(skills);i++) {
		write (sprintf("%24-s : %d\n",capitalize(list[i]),skills[list[i]])) ;
	}
	}
	return 1 ;
}

int sort_skills (string s1, string s2) {
        return strcmp( s1, s2 );
}


int sort_coins(string s1, string s2) {
	return (coinvalue(s1)<coinvalue(s2)) ;
}

int help() {
	write ("Usage: stat <living name>\n"+
"The stat command shows the scores of a living object.\n") ;
	return 1 ;
}
