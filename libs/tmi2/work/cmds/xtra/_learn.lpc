// _learn.c
// A quick hack to let people learns spells.
// Until I get something better written.
 
// Mobydick, TMI-2, 2-8-93
// With a very small hack by Gurtheru
 
#include <magic.h>
 
int cmd_learn (string str) {
 
	int i ;
	mixed *known ;
 
	known = (string *)this_player()->query("spells") ;
	if (!str) {
		if (!known) {
			write ("You don't know any spells.\n") ;
			return 1 ;
		}
		write ("You know the following spells:\n" +
			dump_variable(known)+"\n") ;
		return 1 ;
	}
	if (!known) known = ({ }) ;
	if (member_array(str,SPELLS)==-1) {
		write ("There is no such spell!\n") ;
		return 1 ;
	}
	if (member_array(str,known)!=-1) {
		write ("You already know that spell.\n") ;
		return 1 ;
	}
	known += ({ str }) ;
	this_player()->set("spells", known) ;
	write ("You now know the "+str+" spell.\n") ;
	return 1 ;
}
 
int help() {
	write ("Usage: learn <spell>\n\n"+
"The learn command lets you learn the spell you name. Don't let players\n"+
"have this. Only wizards.\n") ;
	return 1;
}
