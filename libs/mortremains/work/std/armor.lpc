// Inheritable armor object. For now.
// Mobydick@TMI-2, 9-11-92
//
//  2 Nov 97  Cyanide added the set_bonus function.
// 07 Jun 99  Cyanide daemonized weapon and armor.
// 12 Mar 00  Cyanide added support for stat_mod in unequip.

#include <move.h>
#include <mudlib.h>
#include <daemons.h>

inherit OBJECT ;

void unequip(int silent);

#define set_value(x) set("value", x) 

// Armor has its own move function which forces the player to unequip the
// armor if he drops it, gives it away, or otherwise moves it.

int move (mixed dest) {

    object fellow ;

    fellow = environment(this_object()) ;
    if (fellow) {
	if (query("equipped")) {
	    unequip(0);
	}
    }
    return ::move(dest) ;
}

// Similarly, armor has its own remove function, to force the player to
// unequip the armor if it is dested or in some other way destructed.

int remove() {

    object fellow ;

    fellow = environment(this_object()) ;
    if (fellow) {
	if (query("equipped")) {
	    unequip(0);
	}
    }
    return ::remove() ;
}

// The basic unequip procedure. Several commands can call this, which is why
// it is in the armor instead of in a command daemon. Unequip the object and
// alter the player's armor class.

void unequip(int silent) {
    object fellow, obj ;
    string type, tmp ;
    mapping armor, magic_armor ;
    int Class ;

    fellow = environment(this_object()) ;

    if (fellow) {
	obj = this_object() ;
	type = obj->query("type");
	obj->set("equipped",0) ;
	tmp = query("unequip_func");
	if(tmp)  call_other(this_object(), tmp);
	if(!silent)
	    tell_object(fellow,"You remove "+obj->query("short")+".\n") ;

	if(fellow && environment(fellow) && !silent)
	    tell_room (environment(fellow),fellow->query("cap_name")+
	      " removes "+obj->query("short")+".\n",fellow) ;

	armor = fellow->query("armor") ;
	magic_armor = fellow->query("magic_armor");
	map_delete(armor,type) ;
	map_delete(magic_armor, type);	

    if (obj->query("stat_mod") && mapp(obj->query("stat_mod"))) {
		int count, *vals;
		string *akeys;

		akeys = keys( obj->query("stat_mod") );
		vals = values( obj->query("stat_mod") );

		for (count = 0; count < sizeof(vals); count++)
			TP->add("stat/"+akeys[count], -1 * vals[count]);
    }

	fellow->set("armor",armor) ;
	fellow->set("magic_armor",magic_armor) ;
	fellow->calc_armor_class() ;

	if (obj->query("type_std")) {
	    type = obj->query("type_std");
	    obj->set("type", type);
	    obj->delete("type_std");
	} else { 
	    type = obj->query("type") ;
	}
	return ;
    }

}

// This func was written by Cyanide@Nightfall's Keep
// on 11 June 1997 with Nightmask@Nightfall's Keep.  ;)

void set_armor_type (string type) {
    seteuid(getuid());
    WEAPARM_D-> set_armor_type(TO, type );
} //end set_armor_type()


// Cyanide@Nightfall's Keep wrote this, 2 Nov 97

varargs int set_bonus(int bonus, int magic) {
    return WEAPARM_D->arm_set_bonus(TO, bonus, magic);
}

/* EOF */
