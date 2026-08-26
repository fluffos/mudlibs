// Inheritable armor object. For now.
// Mobydick@TMI-2, 9-11-92
// Chronos changed it all to "worn" instead of "equipped".  :D

#include <move.h>
#include <mudlib.h>

inherit OBJECT ;

#include <value.h>

void unequip(int silent);

// Armor has its own move function which forces the player to unequip the
// armor if he drops it, gives it away, or otherwise moves it.

int move (mixed dest) {

	object fellow ;

	fellow = environment(this_object()) ;
	if (fellow) {
                if (query("worn")) {
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
  if (query("worn")) {
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
	mapping armor ;
	int class ;

	fellow = environment(this_object()) ;
	if (fellow) {
		obj = this_object() ;
		type = obj->query("type") ;
 obj->set("worn", 0);
    tmp = query("remove_func");
		if(tmp)  call_other(this_object(), tmp);
		if(!silent)
		tell_object(fellow,"You remove "+obj->query("short")+".\n") ;
 
		if(fellow && environment(fellow) && !silent)
		tell_room (environment(fellow),fellow->query("cap_name")+" removes "+obj->query("short")+".\n",fellow) ;
		armor = fellow->query("armor") ;
		map_delete(armor,type) ;
		fellow->set("armor",armor) ;
		fellow->calc_armor_class() ;
		return ;
	}
}

int set_ac(int x) {
  set("armor", x);
  return 1;
}
