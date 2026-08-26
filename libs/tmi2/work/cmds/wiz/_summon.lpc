// summon.
// This command lets a wizard move a player to him.
// It should be used ONLY to rescue trapped players. Other use constitutes
// cheating and may be a banishment offense.
// It does not work on fellow wizards.
// Written by Mobydick, 11-19-92
// him->objective() fix supplied by Geolin@Pyrosphere
// and included by Pallando 93-06-06

#include <mudlib.h>
#include <move.h>

inherit DAEMON ;

int help() ;

int cmd_summon (string name) {

	object player ;
	int res ;

	if (!name) {
		return help() ;
	}
	player = find_player(name) ;
	if (!player) {
		notify_fail ("There is no one logged on by that name.\n") ;
		return 0 ;
	}
	if (wizardp(player)) {
		notify_fail("You cannot summon other wizards.\n") ;
		return 0 ;
	}
	res = player->move(environment(this_player())) ;
	if (res==MOVE_OK) {
		write ("You have summoned "+capitalize(name)+".\n") ;
		tell_object(player,(string)this_player()->query("cap_name")+
			" has summoned you to "+objective((string)this_player()->query("gender"))+"!\n");
		return 1 ;
	}
	write ("Summons failed!\n") ;
	return 1 ;
}

int help() {
	write ("Usage: summon <player>\n\n"+
"This command will allow you to bring a player to your environment. It\n"+
"should be used ONLY to rescue players trapped by errors in the\n"+
"MUD. Other uses are illegal and may be a reason for banishment. Summoning\n"+
"has no effect on wizards. They should \"goto\" you instead.\n") ;
	return 1 ;
}
