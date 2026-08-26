
// This file is part of the TMI mudlib distribution.
// Please include this header if you use this code.
// Written by Buddha@TMI, modularized and revised (5/1/92)
// This is a common module to the different standard objects available.
// Also thanks to Mobydick for his work here.

// #define DEBUG

#include <mudlib.h>
#include <uid.h>
#include <move.h>


// prototypes
mixed query(string what);
varargs void set(string what, mixed value, int access_level);
int remove();
int move(mixed dest);
void add(string what, mixed arg);
varargs void delete(string what, mixed arg);

// The id parsing stuff.

int id(string str) {
        int i;
        string *parts, *ids;
        ids = query("id");
        if (!pointerp(ids) || !ids) return 0;
        if(!stringp(str)) return 0; // bad input
        if(member_array(str, ids) != -1) return 1; // match!
}


// The argument 'dest' is either a string or an object.
// The return values are given in move.h

// updated to use standard properties 8/14/92 buddha@tmi
// also thanks to truilkan for his "last_location" idea, which I converted.

// some stuff commented out by buddha 9/7/92 for speed

int move(mixed dest) {
	object ob;
	string err;
	int bulk, mass;

	bulk = query("bulk");
	mass = query("mass") ;
	// this 'attached' check added by Truilkan 92/06/02
//	if (environment(this_object()) && this_object()->query("attached"))
//		return MOVE_NOT_ALLOWED;
	if (stringp(dest)) {
		ob = find_object(dest);
		if (!ob) { 
                        dest = resolv_path("cwd", dest);
			err = catch(call_other(dest, "???"));
			if (err) { 
				write(err + "\n"); 
				return MOVE_NO_DEST;
			}
			ob = find_object(dest);
		}
	}   
	else ob = dest;
 
	if(environment() && !environment()->release_object(this_object()))
	    return MOVE_NOT_ALLOWED;
 
	if (!ob || !ob->receive_object(this_object()))
	   return MOVE_NOT_ALLOWED;
   
	if (living(this_object()) && living(ob) && !((int)ob->move_ok()))
	   return MOVE_NOT_ALLOWED;
   
        if (environment(this_object()) == ob)
           return MOVE_NOT_ALLOWED;

	if (ob->query("volume") < (int)query("bulk"))
	   return MOVE_NO_ROOM;
   
	if (ob->query("capacity") < (int)query("mass"))
	   return MOVE_TOO_HEAVY ;

	if (environment()) {
	   environment()->add("volume", bulk);
	   environment()->add("capacity", mass) ;
	}
	set("last_location", environment());
	move_object(ob);
	ob->add("volume", -bulk);
	ob->add("capacity", -mass) ;
	return MOVE_OK;
}

/*
* To destruct objects, call 'remove()' in the object. The default here
* is to allow destruction and update encumbrance.
* All objects inside this object is also moved to the "outside" (if any).
*/
int remove() {

   object super;
   int i, res ;
   object *ob_list;
   
   super = environment(this_object());
   if (super) {
      super->add("volume", query("bulk"));
      super->add("capacity", query("mass")) ;
      ob_list = all_inventory(this_object());
      for (i=0; i < sizeof(ob_list); i++) {
         res = ob_list[i]->move(super);
	   if (res!=MOVE_OK) {
		write ("An object vanishes. Tell a wiz!\n") ;
	   }
	}
   }
   destruct(this_object());
   return 1;
}

// clean_up() is called on all objects by the driver in an attempt to do some
// garbage collection.  If it returns 0, then it will never be called again,
// otherwise it will be called after an interval set in the runtime config 
// file.


int clean_up(int inherited) {
	object env, *contents;
	int i;

	if (inherited)  return 0;
	if (userp(this_object())) return 0; /* don't clean_up players */ 
	env = environment();
	if (env && userp(env)) return 1; /* carried ob */
	if (env && environment(env)) 
		return (int)environment(env)->clean_up(); /* recurse */
	contents = deep_inventory(this_object());
	if (contents) {
		for (i=0;i<sizeof(contents);i++)
			if (userp(contents[i])) return 1; /* holding a user */
	}
	if (!env) {
		/* Don't clean up base objects from /std/ */
		if (!inherits(ROOM, this_object()) && !clonep(this_object()) 
		      && (file_name(this_object())[0..4] == "/std/"))
		    return 0;

		/* we're a room with no users inside or a lost object */
		remove();
		return 1;
	}
	return 1; /* try again later... */
}


// anything can get anything right now.

int receive_object(object foo) {
	return 1;
}

// anything can be moved from it right now.

int release_object(object foo) {
	return 1;
}
 
// The recursive light checking function.
// Blame Mobydick, it's his fault.

int check_light() {

	int i ;
	object *obs ;

// First, if this object is emitting light, we have a light source.

	if (query("light")) return 1 ;

// Second, if this object has no inventory, we do not have a light source.

	obs = all_inventory(this_object()) ;
	if (!obs) return 0 ;

// Third, if this object is opaque, we do not have a light source.

	if (query("opaque")) return 0 ;

// If this is a transparent container that is not itself emitting light, then
// we recursively check light on its contents until we find one of them that
// is emitting light or we run out, in which case we do not have a source.

	for (i=0;i<sizeof(obs);i++) {
		if (obs[i]->check_light()) return 1 ;
	}
	return 0 ;
}
