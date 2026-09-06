/****************************************************************
*								*
*			Unique daemon				*
*								*
* Made by:	Val alias Tero.Pelander@utu.fi			*
* Version 2.0 by Doomdark 25-mar-95.				*
*								*
* Last change:  19-May-98                                       *
*								*
* NEW:								*
*								*
* - You can now do 'pseudo-unique' items; that is, items that	*
*   can have only fixed amount of copies. See example below.	*
*                                                               *
* - Unique items do not always appear immediately after reboot. *
*   Just after boot there's 30% chance, that the item will be   *
*   unique, and the chance get's better linearily with          *
*   query_uptime(), until the mud has been up for 210 minutes,  *
*   when the chance is 100%                                     *
*   Chopin 19-May-1998                                          *
*								*
****************************************************************/

// Usually we should make some inferior item if we can't make any more
// new items of this 'pseudo-unique' item class.
//
// Example of adding new 'pseudo-unique' item (note that this is not
// complete example; you'd have to add descriptions and so on!):
//
// #include <weapon.h>
//
// void
// create_weapon()
// {
//	UNIQUED -> create_unique(object_name(this_object()), 3);
//	if (UNIQUED -> query_unique(object_name(this_object())) {
//		set_name("supersword");
//		set_wc(20);
//		set_two_handed(1);
//		set_weight(4);
//		UNIQUED -> add_unique(object_name(this_object()), this_object());
//	} else {	// Create inferior weapon!
//		set_name("sword");
//		set_wc(12);
//		swt_weight(3);
//	}
// }

#define ERRLOG "UNIQUE"

mapping uniq_map;
status	uniq_lock;

nomask void
create()
{
    uniq_map = ([ ]);
}

// Let's get rid of possible clone-number.

nomask private string
get_original(string s)
{
    string t;
    int i;
    if (sscanf(s, "%s#%d", t, i) == 2) return t;
    return s;
}

nomask
object get_unique(string name)
{
    return uniq_map[name];
}

nomask object
set_unique(string name, object uniq)
{
    object ob;

    if (stringp(name)) {
	ob = uniq_map[name];
	if (ob || objectp(uniq)) uniq_map[name] = uniq;
	if (ob) log_file(ERRLOG, sprintf("Changed %s\n\t'%s' to %s by %s\n",
		ctime(time()), name, object_name(ob),
		uniq ? object_name(uniq) : "none" ));
	return ob;
    }
}

// With this we can create a new unique item class; that means a group
// of items that can contain only fixed amount of items. Usually, this
// will be used for some special weapons or armours.

nomask status
create_unique(string name, int max_amount)
{
    name = get_original(name);
    if (!max_amount) {
	// We want to remove exit status of the unique item.
	m_delete(uniq_map, name);
	return 1;
    }
    if (uniq_map[name]) return 0;	// Already have this unique item...
    uniq_map[name] = ({ max_amount });
    return 1;
}

// With this we can check how many more unique items of this class we can
// make. Use this in your item's create_xxx function (create_weapon etc.).

nomask int
query_unique(string name)
{
    mixed x;
    int size, size2;
    int probability;

    if(uniq_lock) return 0; // not allowed if locked

    if(query_uptime() < 12600) {
	probability = 30 + query_uptime() / 180;
	// will be 100 after 12600 seconds = 210 minutes

	if(probability < random(101))
	    return 0;
    }

    name = get_original(name);
    if (!(x = uniq_map[name]) || !(size = sizeof(x))) return 0;
    x -= ({ 0 });
    if ((size2 = sizeof(x)) != size)
	uniq_map[name] = x;
    return uniq_map[name][0] - size2 + 1;
}

// With this function we'll add new unique item to some unique item class.
// Be sure to first check that we can add it, with "query_unique".
// Also, item class has to be created before using this function.

nomask status
add_unique(string name, object uniq)
{
    string t;
    int size;
    mixed *x;
    name = get_original(name);
    if (!(x = uniq_map[name])) return 0;
    x += ({ uniq });
    uniq_map[name] = x;
}

string *
query_unique_index()
{
    return m_indices(uniq_map);
}

mixed *
query_unique_values()
{
    return m_values(uniq_map);
}

mapping query_unique_list() { return uniq_map; }

// lock_unique(1) will prevent us from allowing unique items to be
// created. Be sure to release with lock_unique(0) when done.
// This is used by the lockers for example.

status
lock_unique(int arg)
{
    return (uniq_lock = arg);
}
status
query_unique_lock()
{
    return uniq_lock;
}
