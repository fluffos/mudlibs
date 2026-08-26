// credits.c
// The basic money object.
// Sets the property "money". You can identify credits by checking that property.
// Created by Mobydick@TMI-2, 8-24-92
// Cyanide hacked to remove variable credit types - went to gold standard.
// Also 10 credits now weigh 1 pound - Cyanide@Nightfall's Keep 5-27-97
//
// 22 May 1999  Now, we just use 'credits', which weigh nothing.

#include <move.h>
#include <mudlib.h>

inherit OBJECT ;

int number ;

/* Set_descs() is called whenever the number of credits is changed. */

void set_descs() {
    set ("mass", 0) ;  //Ilz sept 16 97
    set ("id", ({ "credit", "credits" }) ) ;
    if (number==1) set ("short", "a credit") ;
    else set ("short", number+" credits") ;
    //set ("mass", number) ;
    switch (number) {
    case 1 : {
	    set ("long", "A single credit.\n") ;
	    break ;
	}
    case 2..5 : {
	    set ("long", "A few credits.\n") ;
	    break ;
	}
    case 6..15 : {
	    set ("long", "A handful of credits.\n") ;
	    break ;
	}
    case 16..25 : {
	    set ("long", "About twenty credits.\n") ;
	    break ;
	}
    case 26..35 : {
	    set ("long", "About thirty credits.\n") ;
	    break ;
	}
    case 36..65 : {
	    set ("long", "About fifty credits.\n") ;
	    break ;
	}
    case 66..85 : {
	    set ("long", "About seventy-five credits.\n") ;
	    break ;
	}
    case 86..150: {
	    set ("long", "About one hundred credits.\n") ;
	    break ;
	}
    case 151..350 : {
	    set ("long", "About 250 credits.\n") ;
	    break ;
	}
    case 351..750 : {
	    set ("long", "About 500 credits.\n") ;
	    break ;
	}
    case 751..10000 : {
	    set ("long", "A very large stack of credits.\n") ;
	}
    default :
	set ("long", "More credits than the mind can "+
	  "comfortably comprehend.\n") ;

    }
    return ;
}

void create() {
    number = 1 ;
    set_descs() ;
    set ("money",1) ;
}


void set_number (int num) {
    if (num<1) remove() ;
    number = num ;
    set ("mass", 0) ;   //Ilz
    set_descs() ;
}

// This is just here for debug purposes.  Cyanide 2 May 99
string query_type() { return "TYPE ERROR"; }

int query_number() { return number ; }

// When credits move we need to do two checks. First, if we just moved into a
// player, put money into his wealth variable and remove this object. Second,
// if our destination has a pile of the same type of credits, increase the
// number of that pile, and remove this object. If neither of these is true,
// then move the object itself.
// 22 May 99 Much simpler sfter cyanide removed 'types'. Now just 'credits'.

int move(mixed dest) {
    string tmp ;
    int i ;
    object ob ;

    if (living(dest)) {
	i = dest->query("wealth") ;
	dest->credit(number);
	remove() ;
	return MOVE_OK ;
    }
    ob = present("credits", dest) ;
    if (!ob) {
	i = ::move(dest) ;
	return i ;
    }

    i = ob->query_number() ;
    ob->set_number(i+number) ;
    remove() ;
    return MOVE_OK ;
}
