// exchange.c
// A facility for changing money from one kind of coin to another.
// Written by Mobydick@TMI-2, 8-25-92
// For now the service is free, later we should probably attach a fee to it.

#include <money.h>
#include <move.h>
#include <mudlib.h>

#define SIGN "/obj/coinval_sign"

inherit ROOM ;
inherit COINVALUE ;

void create() {

	object sign ;

	seteuid(getuid()) ;
	::create() ;
	sign = clone_object(SIGN) ;
        sign->set_location(file_name(this_object())) ;
}

void init() {
	add_action ("change", "convert") ;
	add_action ("change", "change") ;
}

int help() ;

int change (string str) {

	int number, i, j, k ;
	string oldtype, newtype ;
	int oldval, newval ;
	object ob ;

	if (!str) return help() ;
	if (sscanf(str,"%d %s to %s",number,oldtype,newtype)!=3)
		if (sscanf(str,"%s to %s",oldtype,newtype)!=2) {
			return help() ;
		}
	oldval = coinvalue(oldtype) ;
	if (!oldval) {
		notify_fail (capitalize(oldtype)+" coins are not legal tender in this realm.\n") ;
		return 0 ;
	}
	if (number < 0) {
		notify_fail ("You can only change positive numbers of coins.\n") ;
		return 0 ;
	} else if (number == 0)
		number=(int)this_player()->query("wealth/"+oldtype) ;
	newval = coinvalue(newtype) ;
	if (!newval) {
		notify_fail (capitalize(newtype)+" coins are not legal tender in this realm.\n") ;
		return 0 ;
	}
	if (this_player()->query("wealth/"+oldtype)<number) {
		notify_fail ("You haven't got that many "+oldtype+" coins!\n");
		return 0 ;
	}
	i = number*oldval ;	/* Value of old coins, in cheapest coin */
	j = i/newval ;		/* Value of old coins, in new coins */
	k = (i-j*newval)/oldval ;   /* Change to be returned.  */
// If we have 0 new coins, then he is just getting back what he started with.
	if (j==0) {
		write (number+" "+oldtype+" coins are not worth one "+newtype+" coin.\n") ;
		return 1 ;
	}
// We need to check to see if he can carry the new number of coins.
	if ((int)this_player()->query("capacity")>j+k-number) {
		this_player()->set("capacity",(int)this_player()->query("capacity")-j-k+number) ;
		i = this_player()->query("wealth/"+oldtype) + k - number ;
		this_player()->set("wealth/"+oldtype,i) ;
		i = this_player()->query("wealth/"+newtype) + j ;
		this_player()->set("wealth/"+newtype,i) ;
		write ("Done.\n") ;
		say (this_player()->query("cap_name")+" changes some "+oldtype+" coins into "+newtype+".\n") ;
		return 1 ;
	}
	notify_fail ("You can't carry that many coins!\n") ;
	return 0 ;
}

int help() {
   write("Usage: " + query_verb() + " [num] [oldtype] to " +
	 "[newtype]\n       " + query_verb() + " [oldtype] " +
	 "to [newtype]\n");
	return 1 ;
}
