// Standard equipped monster.
// Clones equipment, and will also pick any of same eqs that may
// be left from "previous" monster of this type.

// Version 1.01 22-feb-96 by Doomdark

// NEW:
//
// 22.02.96 Doomdark: Now you can use an array of strings and/or closures,
//	or a closure as 1st argument. If it's a closure, it's first applied,
//	and resulting value (string or object) is used. If it's an object,
//	no cloning is done; otherwise normal rules for it are used. If the 1st
//	argument is an array, one of elements is chosen in random, and then
//	used (ie. it can be a string or a closure etc.)

#include <weapon_defs.h>
#include <armour_defs.h>
#include <treasure_defs.h>

#pragma verbose_errors
#include <npc.h>

mixed *pick_items;
status pick_call_on;

/***********************************************************************
//
// Funtion:
//	add_weapon()
//
// Purpose:
//	To add weapons for the monster, and also allow picking of any weapons
//	like this that exist in the room, as they are most probably ones left
//	from "previous instance" of this npc. Those are called
//	"leftover weapons" from now on.
//
// Arguments:
//
//	fname: Either 0 for standard weapon, string not beginning with "/"
//		for name of weapon to be created by weapon server, or
//		filename of the weapon to be cloned.
//	NEW: Can also be an array, in which case one element in random
//		is chosen; or, can be a closure, in which case closure is
//		applied, and resulting string (or object) is used, like it
//		was the original argument (so, appropriate object is cloned
//		and so forth)
//	id_name: Name of the weapon used in checking if leftover weapon(s)
//		exists in the room npc is first put. This will generally
//		be same as name of the weapon; if not, it's one of synonyms
//		of weapon. Note that you can now use 0 here if you are using
//		a weapon provided by weapon server. If so, fname is used as
//		id_name as well.
//	init_data: Array of arrays, used to specify calls to functions to
//		initialize this weapon. Syntax specified later on in the code.
//	pick_delay: Delay in seconds for checking whether there's "leftover
//		weapon" here. Should be somewhere between 2 and 10 usually.
//		If this is 0, no checking is done for this weapon.
//	pick_msg: Either message to be printed if leftover weapon was found,
//		or arary of such strings, in which case one is chosen in
//		random to be printed.
//
***********************************************************************/

status
add_weapon(mixed fname, string id_name, mixed *init_data,
  int pick_delay, mixed pick_msg)
{
    object ob;
    int i, size;
    mixed *x;
    // We can use an array there no prob... If so, one element is chosen
    // randomly
    if (pointerp(fname))
	fname = fname[random(sizeof(fname))];
    if (closurep(fname)) {
	fname = funcall(fname);
	// You can skip equipping by returning 0 from the closure...
	if (!fname) return 0;
    }
    if (objectp(fname)) ;
    else if (!fname) {
	if (!pointerp(init_data)) return 0;
	// Let's be sure we'll init it somehow if using std weapon(s).
	ob = clone_object(WEAPON_FILE);
    } else if (!stringp(fname)) return 0;
    else if (fname[0] != '/')
	ob = (object) WEAPON_SERVER -> make_weapon(fname);
    else ob = clone_object(fname);

    // We can initialize our weapon here. Array used as init_data, is of form:
    // ({ call1, call2, ... }) where each call is an array, with any number of
    // elements depending on amount of args call takes. So, something like:
    // ({ "set_name", "big sword" }) etc. 1st element is the function to call,
    // and rest (if any) are arguments to the function call.

    if (pointerp(init_data)) {
	for (i = 0, size = sizeof(init_data); i < size; i++) {
	    if (!pointerp(x = init_data[i])) continue;
	    if (sizeof(x) < 2) call_other(ob, x[0]);
	    else apply(#'call_other, ob, x[0]
		  , x[1..]);
	}
    }

    move_object(ob, this_object());
    wield(ob, 1);

    // If we use pick_delay (ie. it's a positive number), this npc picks up
    // any identical weapon in the room where it's first moved. Usually this
    // is left from "previous" same kind of npc.

    if (pick_delay) {
	if (!id_name && stringp(fname))
	    id_name = fname;

	if (!pick_items)
	    pick_items = ({ ({ id_name, pick_delay, pick_msg }) });
	else 
	    pick_items += ({ ({ id_name, pick_delay, pick_msg }) });
	if (!pick_call_on) {
	    pick_call_on = 1;
	    call_out("_check_pick", pick_delay, 0);
	}
    }

    return 1;
}

// This works like previous function, except that it makes armours.
// All comments apply here, when each word "weapon" is replaced
// with "armour".

status
add_armour(mixed fname, string id_name, mixed *init_data,
  int pick_delay, mixed pick_msg)
{
    object ob;
    int i, size;
    mixed *x;
    if (!intp(pick_delay))
	raise_error(sprintf("Error in %s: non-integer argument for\
 pick delay in add_armour() on /lib/equipped_npc.c.\n",
	    object_name(this_object())));
    if (pointerp(fname))
	fname = fname[random(sizeof(fname))];
    if (closurep(fname)) {
	fname = funcall(fname);
	// You can skip equipping by returning 0 from the closure...
	if (!fname) return 0;
    }
    if (objectp(fname)) ;
    else if (!fname) {
	if (!pointerp(init_data)) return 0;
	ob = clone_object(ARMOUR_FILE);
    } else if (!stringp(fname)) return 0;
    else if (fname[0] != '/')
	ob = (object) ARMOUR_SERVER -> make_armour(fname);
    else ob = clone_object(fname);

    if (pointerp(init_data)) {
	for (i = 0, size = sizeof(init_data); i < size; i++) {
	    if (!pointerp(x = init_data[i])) continue;
	    if (sizeof(x) < 2) call_other(ob, x[0]);
	    else apply(#'call_other, ob, x[0], x[1..]);
	}
    }

    move_object(ob, this_object());
    wear(ob, 1);

    if (pick_delay) {
	if (!id_name && stringp(fname))
	    id_name = fname;
	if (!pick_items)
	    pick_items = ({ ({ id_name, pick_delay, pick_msg }) });
	else 
	    pick_items += ({ ({ id_name, pick_delay, pick_msg }) });
	if (!pick_call_on) {
	    pick_call_on = 1;
	    call_out("_check_pick", pick_delay, 0);
	}
    }

    return 1;
}

// This works like previous functions, except that it makes general objects.
// These won't be "used" like weapons or armours, simply copied to npc.
// All comments apply here, when each word "weapon"/"armour" is replaced
// with "object".

status
add_object(mixed fname, string id_name, mixed *init_data,
  int pick_delay, mixed pick_msg)
{
    object ob;
    int i, size;
    mixed *x;
    if (pointerp(fname))
	fname = fname[random(sizeof(fname))];
    if (closurep(fname)) {
	fname = funcall(fname);
	// You can skip equipping by returning 0 from the closure...
	if (!fname) return 0;
    }
    if (objectp(fname)) ;
    if (!fname) {
	if (!pointerp(init_data)) return 0;
	ob = clone_object(TREASURE_FILE);
    } else if (!stringp(fname)) return 0;
    else ob = clone_object(fname);

    if (init_data && pointerp(init_data)) {
	for (i = 0, size = sizeof(init_data); i < size; i++) {
	    if (!pointerp(x = init_data[i])) continue;
	    if (sizeof(x) < 2) call_other(ob, x[0]);
	    else apply(#'call_other, ob, x[0], x[1..]);
	}
    }

    move_object(ob, this_object());

    if (pick_delay) {
	if (!id_name && stringp(fname))
	    id_name = fname;
	if (!pick_items)
	    pick_items = ({ ({ id_name, pick_delay, pick_msg }) });
	else 
	    pick_items += ({ ({ id_name, pick_delay, pick_msg }) });
	if (!pick_call_on) {
	    pick_call_on = 1;
	    call_out("_check_pick", pick_delay, 0);
	}
    }

    return 1;
}

void
_check_pick(int eq_nr)
{
    object ob;
    mixed *x;
    int i, size;
    if (!environment()) return;
    if (!pointerp(x = pick_items[eq_nr])) return;
    if (!x[0]) return;
    if (ob = present(x[0], environment())) {
	// Let's then print msg if one is specified...
	if (environment())
	    if (stringp(x[2]))
		environment()->tell_here(x[2], this_object());
	    else if (pointerp(x[2]))
		environment()->tell_here(x[2][random(sizeof(x[2]))],
		  this_object());
	destruct(ob);
	// So, let's check if there's more of this eq...
	call_out("_check_pick", x[1], i);
    } else {
	size = sizeof(pick_items);
	while (++eq_nr < size) {
	    if ((i = pick_items[i][1]) > 0) {
		call_out("_check_pick", i, eq_nr);
		break;
	    }
	}
    }
}
