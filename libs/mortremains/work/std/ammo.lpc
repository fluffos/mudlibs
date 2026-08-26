// FILE:    ammo.c
// PURPOSE: The basic ammunition object.
//      Sets the property "ammunition". You can identify coins by 
//      checking that property.
// CREDITS:
//      24 Aug 92  Created by Mobydick@TMI-2
//      07 Jun 99  Cyanide turned coins.c into ammo.c. He accepts
//                 almost NO credit for this.

#include <move.h>
#include <mudlib.h>

inherit OBJECT ;

string type ;
int number ;

/* Set_descs() is called whenever the number or type of rounds is changed. */

void set_descs() {
    set ("id", ({ "ammo", "rounds", type+" ammo", type+" rounds", type }) ) ;
    if (number!=1) 
	set ("short", "a pile of "+type+" rounds") ;
    else 
	set ("short", "a "+type+" round") ;
    //set ("mass", number) ;
    switch (number) {
    case 1 : {
	    set ("long", "A single "+type+" round.\n") ;
	    break ;
	}
    case 2..5 : {
	    set ("long", "A few "+type+" rounds.\n") ;
	    break ;
	}
    case 6..15 : {
	    set ("long", "A handful of "+type+" rounds.\n") ;
	    break ;
	}
    case 16..25 : {
	    set ("long", "About twenty "+type+" rounds.\n") ;
	    break ;
	}
    case 26..35 : {
	    set ("long", "About thirty "+type+" rounds.\n") ;
	    break ;
	}
    case 36..65 : {
	    set ("long", "About fifty "+type+" rounds.\n") ;
	    break ;
	}
    case 66..85 : {
	    set ("long", "About seventy-five "+type+" rounds.\n") ;
	    break ;
	}
    case 86..150: {
	    set ("long", "About one hundred "+type+" rounds.\n") ;
	    break ;
	}
    case 151..350 : {
	    set ("long", "About 250 "+type+" rounds.\n") ;
	    break ;
	}
    case 351..750 : {
	    set ("long", "About 500 "+type+" rounds.\n") ;
	    break ;
	}
    default : {
	    set ("long", "A very large pile of "+type+" rounds.\n") ;
	}
    }
    return ;
}

void create() {
    type = "9mm" ;
    number = 1 ;
    set_descs() ;
    set ("ammunition",1) ;
}

void set_type (string str) {
    type = str ;
    set_descs() ;
}

void set_number (int num) {
    if (num<1) remove() ;
    number = num ;
    //set ("mass", num) ;
    set_descs() ;
}

string query_type() { return type ; }

int query_number() { return number ; }

// When rounds move we need to do two checks. First, if we just moved into a
// player, put rounds into his ammo variable and remove this object. Second,
// if our destination has a pile of the same type of rounds, increase the
// number of that pile, and remove this object. If neither of these is true,
// then move the object itself.

int move(mixed dest) {

    string tmp ;
    int i ;
    object ob ;

    /*   Cyanide took this out for now.
    if (dest->query("capacity")<number) {
	    return MOVE_TOO_HEAVY ;
    }
    */


    if (living(dest)) {
	i = dest->query("ammo/"+type) ;
	dest->set("ammo/"+type,i+number) ;
	//dest->set("capacity",(int)dest->query("capacity")-number) ;
	remove() ;
	return MOVE_OK ;
    }

    tmp = type + " rounds" ;
    ob = present(tmp,dest) ;
    if (!ob) {
	i = ::move(dest) ;
	return i ;
    }
    i = ob->query_number() ;
    ob->set_number(i+number) ;

    //dest->set("capacity",(int)dest->query("capacity")-number) ;

    remove() ;
    return MOVE_OK ;
}
