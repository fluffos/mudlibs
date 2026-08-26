// coins.c
// The basic money object.
// Sets the property "money". You can identify coins by checking that property.
// Created by Mobydick@TMI-2, 8-24-92

#include <move.h>
#include <mudlib.h>

inherit OBJECT ;

string type ;
int number ;

/* Set_descs() is called whenever the number or type of coins is changed. */

void set_descs() {
	set ("id", ({ "coin", "coins", type+" coin", type+" coins", type }) ) ;
	if (number==1) set ("short", "a "+type+" coin") ;
	else set ("short", type+" coins") ;
	set ("mass", number) ;
	switch (number) {
		case 1 : {
			set ("long", "A single "+type+" coin.\n") ;
			break ;
		}
		case 2..5 : {
			set ("long", "A few "+type+" coins.\n") ;
			break ;
		}
		case 6..15 : {
			set ("long", "A handful of "+type+" coins.\n") ;
			break ;
		}
		case 16..25 : {
			set ("long", "About twenty "+type+" coins.\n") ;
			break ;
		}
		case 26..35 : {
			set ("long", "About thirty "+type+" coins.\n") ;
			break ;
		}
		case 36..65 : {
			set ("long", "About fifty "+type+" coins.\n") ;
			break ;
		}
		case 66..85 : {
			set ("long", "About seventy-five "+type+" coins.\n") ;
			break ;
		}
		case 86..150: {
			set ("long", "About one hundred "+type+" coins.\n") ;
			break ;
		}
		case 151..350 : {
			set ("long", "About 250 "+type+" coins.\n") ;
			break ;
		}
		case 351..750 : {
			set ("long", "About 500 "+type+" coins.\n") ;
			break ;
		}
		default : {
			set ("long", "A very large pile of "+type+" coins.\n") ;
		}
	}
	return ;
}

void create() {
	type = "gold" ;
	number = 1 ;
	set_descs() ;
	set ("money",1) ;
}

void set_type (string str) {
	type = str ;
	set_descs() ;
}

void set_number (int num) {
	if (num<1) remove() ;
	number = num ;
	set ("mass", num) ;
	set_descs() ;
}

string query_type() { return type ; }

int query_number() { return number ; }

// When coins move we need to do two checks. First, if we just moved into a
// player, put money into his wealth variable and remove this object. Second,
// if our destination has a pile of the same type of coins, increase the
// number of that pile, and remove this object. If neither of these is true,
// then move the object itself.

int move(mixed dest) {

	string tmp ;
	int i ;
	object ob ;

	if (dest->query("capacity")<number) {
		return MOVE_TOO_HEAVY ;
	}
	if (living(dest)) {
		i = dest->query("wealth/"+type) ;
		dest->set("wealth/"+type,i+number) ;
		dest->set("capacity",(int)dest->query("capacity")-number) ;
		remove() ;
		return MOVE_OK ;
	}
	tmp = type + " coins" ;
	ob = present(tmp,dest) ;
	if (!ob) {
		i = ::move(dest) ;
		return i ;
	}
	i = ob->query_number() ;
	ob->set_number(i+number) ;
	dest->set("capacity",(int)dest->query("capacity")-number) ;
	remove() ;
	return MOVE_OK ;
}
