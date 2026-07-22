// An emote testing object.

#include <mudlib.h>
#include <daemons.h>

string *list ;
int which, target ;

inherit MONSTER ;

void create() {
	::create() ;
	enable_commands() ;
	set_living_name("barney") ;
	set("gender", "male") ;
	set("id", ({ "barney", "dick" }) ) ;
	set ("short", "Barney the dinosaur") ;
	set ("long", "Barney is looking very emotional.\n") ;
	set_name("barney") ;
tell_object(find_player("mobydick"),"frog") ;
	list = sort_array((string *)EMOTE_D->query_keys(),"compare",this_object());
	which = 0 ;
}

void init() {
	add_action ("poke", "poke") ;
}

int poke( string str) {
	write ("You poke Barney in the tummy.\n") ;
	if (str)  which = member_array(str,list) ;
	if (which==-1) which = 0 ;
	call_out ("do_emote", 4) ;
	return 1 ;
}


int compare(string one, string two) {
        return strcmp(one, two);
}

int do_emote() {

	string str ;
tell_object(find_player("mobydick"),which+"\n") ;

	switch (target) {
	    case 0 : { str = list[which] ; break ; }
	    case 1 : { str = list[which] + " annoyingly" ; break ; }
	    case 2 : { str = list[which] + " mobydick" ; break ; }
	}
	command (str) ;
	say ("Barney says: That was the "+str+" emote. Thank you.\n") ;
	switch (target) {
	    case 2 : {
	    	which += 1;
	    	if (which==sizeof(list)) which=0 ;
	    	target = 0 ;
		break ;
	    }
	    case 1: {
	    	target = 2 ;
		break ;
	    }
	    case 0: {
// this is kinda pointless as is but we have it for future if we need it.
		target = 1 ;
	    }
	}
	call_out ("do_emote", 4) ;
}
