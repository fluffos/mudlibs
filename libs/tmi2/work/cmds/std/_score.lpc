 
//	File	:  /cmds/std/_score.c
//	Creator	:  Mobydick@TMI  (8-24-92)
//	Updated	:  Watcher@TMI   (4-10-93)
//
//	This command shows a user's status.

#include <mudlib.h>

inherit DAEMON ;
inherit COINVALUE ;

int cmd_score() {

	string *coins, *list, *statnames ;
	string race, spouse ;
	mapping stats ;
	mapping wealth ;
	int i, flag ;

	this_player()->block_attack(4) ;
 
	write("[ " + bold((string)this_player()->query("short")) +
	      " ]\n\n");

	race = this_player()->query("race") ;
	if (race) {
		write("You are " + article(race) + " " + race + ".\n");
	}
	spouse = this_player()->query("spouse") ;
	if (spouse) {
		write ("You are married to "+spouse+".\n") ;
	}
 
	write("You are " + format_time((int)this_player()->query("age"), 1) +
	      " old.\n");
 
/*
     This section of the code reports drunkenness.
     It's all commented out.
     If you put drunkenness in, put this code back in also.

	flag = this_player()->query("drunk") ;
	switch (flag) {
		case -5..-1 : {
			write ("You have a bad headache.\n") ;
			break ;
		}
		case 1..5 : {
			write ("You are a bit tispy.\n") ;
			break ;
		}
		case 6..10 : {
			write ("You are somewhat drunk.\n") ;
			break ;
		}
		case 11..15 : {
			write ("You are rather drunk.\n") ;
			break ;
		}
		case 16..20 : {
			write ("You are completely smashed.\n") ;
			break ;
		}
		case 21..25 : {
			write ("You are maximally drunk.\n") ;
			break ;
		}
	}
*/
	write ("\n");
	write ("Hit points\t: "+this_player()->query("hit_points")+" of "+
		this_player()->query("max_hp")+"\n") ;
	write ("Spell points\t: "+this_player()->query("spell_points")+" of "+
		this_player()->query("max_sp")+"\n") ;
	write ("\n") ;
	stats = this_player()->query("stat") ;
        statnames = stats && mapp(stats) ? keys(stats) : ({ });
	for (i=0;i<sizeof(stats);i++) {
		write (sprintf("%12-s : %d\n",capitalize(statnames[i]),stats[statnames[i]])) ;
	}
	write ("\n") ;
	wealth = this_player()->query("wealth") ;
	if (!wealth) {
		write ("You don't have any coins in your purse.\n") ;
		return 1 ;
	}
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
		write ("You have no coins at all in your purse.\n") ;
	}
	return 1 ;
}

int sort_coins(string s1, string s2) {
	int i,j;
	i=coinvalue(s1);
	j=coinvalue(s2);
	return (i<j) ? 1 : (i>j) ? -1 : 0;
}

int help() {
	write ("Usage: score\n"+
"The score command will show you your current hit points, spell points,\n"+
"statistics, and wealth. You can see your skills by typing \"skills\"\n") ;
	return 1 ;
}
