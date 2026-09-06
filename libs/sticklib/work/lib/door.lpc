/****************************************************************
*                                                              *
*              A new door.c for StickMud.                      *
*                                                              *
*              Coded by Doomdark.                              *
*              V2.0a / 15-may-95                               *
*                                                              *
* v1.3 - added features:                                       *
* ======================                                       *
*                                                              *
* - It's now possible to add adjective(s) to the short_desc etc.*
*   like "big wooden door to the east" etc. They are also used        *
*   in id so that you can use them in commands.                        *
* - The 'type' may be something else than "door", for example  *
*   "gate". If it's changed, you have to use it instead of     *
*   "door" everywhere; "open gate", "knock at the gate" etc.   *
* - If player has only one key, then he/she may use short      *
*   versions of the lock/unlock (ie. "lock door", "unlock big  *
*    wooden gate" etc.).                                       *
*                                                              *
* v2.0                                                         *
* ====                                                         *
*                                                              *
* - Re-coded to be compatible with rest of mudlib. /Doomdark   *
* - Added query_partner_door()  /Germ                          *
****************************************************************/

#include <door_defs.h>
#include <daemons.h>
#include <room_defs.h>

inherit "/basic/id";

#define     COMPAT_DOOR

#define      F_RESET_USED    1
#define        F_INIT_USED     2
#define        F_IS_CLOSED     4
#define        F_IS_LOCKED     8
#define        F_CAN_BE_LOCKED 16
#define       F_CREATING      32

#define		TRANS_FLAGS	12
string direction;     // ie. if "east door" direction = "east"
string door_adj;        // ie. if "wooden door", door_adj = "wooden"
// Note also that this may contain more than 1 word
// like "big shining metal" etc.
string door_type;       // Usually "door", but may be changed ("gate" etc.)
string *lock_ids;    // Synonyms for lock on the door (if there is one).
string *door_ids;	// Synonyms for this door (only door ids).
object partner_door; // 'other side' of this door.
mixed lock_code;   // Special code for the key that fits in this lock.
// (invisible to player) NOTE: May also be an array of strings.
string lock_type;        // Type of the lock ("golden", "iron" etc.)
string lock_long;    // - "" - of the lock.
int pick_level;           // How hard is this door to be picked (percentage)
mixed *door_hooks;    // 'Hooks' that can be set up and used when player
// does something to the door.

int Flags;		// Various flags associated with this door.

// Prototypes

status tell_this_door(string s);
status check_door(string id, string cmd);
status lock_id(string s);
string remove_nr(string s);


/****************************************************************
*                                                               *
*                      Query-functions.                        *
*                                                              *
****************************************************************/

// NEW!

int
query(int x)
{
    switch (x) {
    case DOOR_IS_CLOSED:
	return Flags & F_IS_CLOSED;
    case DOOR_IS_OPEN:
	return !(Flags & F_IS_CLOSED);
    case DOOR_IS_LOCKED:
	return Flags & F_IS_LOCKED;
    case DOOR_IS_UNLOCKED:
	return !(Flags & F_IS_LOCKED);
    case DOOR_CAN_BE_LOCKED:
	return Flags & F_CAN_BE_LOCKED;
    case DOOR_CANT_BE_LOCKED:
	return !(Flags & F_CAN_BE_LOCKED);
    }
}

string query_dir() { return direction; }
string query_type() { return lock_type; }

string query_code() { return lock_code; }
int query_pick_level() { return pick_level; }
/* -1 -> can't be picked. Otherwise percentage between 0 and 100. */
string query_door_type() { return door_type; }
status query_is_locked() { return Flags & F_IS_LOCKED; }
status query_is_closed() { return Flags & F_IS_CLOSED; }
status query_can_lock() { return Flags & F_CAN_BE_LOCKED; }

// Its handy to query where the door leads... - Germ
object query_partner_door() { return partner_door; }


varargs string
query_short(int mode, object who)
{
    if (mode < invis_level)
	return 0;
    return "A " + (stringp(door_adj) ? door_adj + " " : "") + door_type +
    " to the " + direction
    + (query(DOOR_IS_CLOSED) ? " (closed)":" (open)");
}

varargs string
query_long(string str, object who)
{
    mixed a;
    int b;
    if (a = remove_nr(str))
	str = a;

    if (!str || (door_ids && member(door_ids, str) >= 0)) {
	a = ::query_long(str, who);
	if (query(DOOR_CAN_BE_LOCKED)) a +=
	    "\nOn the " + door_type + " there is a " + lock_type + " lock.";
	a +=
	"\nThe "+door_type+" is " + (query(DOOR_IS_CLOSED) ? "closed" : "open") + ".";
	return a;
    }
    if (lock_long)
	return lock_long;
    else return
	"You can see nothing special in it; it's just an ordinary lock that\
 is used to lock doors with.";
}

/****************************************************************
*                                                                *
*                      Set-functions.                          *
*                                                              *
****************************************************************/

// NEW!

void
set(int x)
{
    switch (x) {
    case DOOR_IS_CLOSED:
	Flags |= F_IS_CLOSED; break;
    case DOOR_IS_OPEN:
	Flags &= (~F_IS_CLOSED); break;
    case DOOR_IS_LOCKED:
	Flags |= F_IS_LOCKED; break;
    case DOOR_IS_UNLOCKED:
	Flags &= (~F_IS_LOCKED); break;
    case DOOR_CAN_BE_LOCKED:
	Flags |= F_CAN_BE_LOCKED; break;
    case DOOR_CANT_BE_LOCKED:
	Flags &= (~F_CAN_BE_LOCKED); break;
    }
}

void set_code(string str) { lock_code = str; }
void set_door(object obj) { partner_door = obj; }
void set_can_lock(status val) { Flags |= F_CAN_BE_LOCKED; }

// Old. Use simple "set_long" rather...

void
set_door_long(string str)
{
    if (stringp(str) && str[sizeof(str) - 1] == '\n')
	set_long(str[0..<2]);
    else
	set_long(str);
}

void
set_lock_long(string str)
{
    if (stringp(str) && str[<1..<1] == "\n")
	lock_long = str[0..<2];
    else
	lock_long = str;
}

void
set_pick_level(int level, int x)
{
    pick_level = level;
    if (!x && partner_door)
	partner_door -> set_pick_level(level, 1);
}

// Name is now bit misleading... But we'll use it still for compatibility
void
set_id_string()
{
    string s, *list, *parts;
    int i;
    set_name((door_adj ? door_adj : direction) + " " + door_type);

    list = ({ door_type });
    if (direction) list += ({ direction + " " + door_type });

    if (door_adj) {
	i = sizeof(parts = explode(door_adj, " ")) - 1;

	for (s = door_type; i >= 0; i--) {
	    s = parts[i] + " " + s;
	    list += ({ parts[i] + " " + door_type, s });
	}
    }

    door_ids = list;

    s = (stringp(door_adj) ? door_adj + " " : "") + door_type +
    " to the " + direction;

    if (member(({ 'a', 'e', 'i', 'o' }), s[0]) >= 0)
	set_short("An "+s);
    else
	set_short("A "+s);

}

void
set_door_type(string str, int x)
{
    if (!stringp(str))
	door_type = "door";
    else
	door_type = str;

    if (!(Flags & F_CREATING))
	set_id_string();

    if (partner_door && !x)
	partner_door -> set_door_type(str, 1);
}

void
set_dir(string str)
{
    if (!stringp(str) || str == "")
	direction = "unknown";
    else
	direction = str;

    if (!(Flags & F_CREATING))
	set_id_string();
}

void
set_type(string str)       // Let's also allow flexible ids for locks.
{
    string *parts, s;
    int i, j;

    if (!stringp(str) || str == "") {
	lock_type = "common";
	lock_ids = ({ "lock", "common lock" });
    } else {
	lock_ids = ({ "lock" });
	lock_type = str;
	i = j = sizeof(parts = explode(str, " ")) - 1;
	for (s = "lock"; i >= 0; i--) {
	    s = parts[i] + " " + s;
	    if (i == j) lock_ids += ({ s });
	    else lock_ids += ({ parts[i] + " lock", s });
	}
    }
}

void
set_door_adj(string str, status x)
{
    door_adj = str;

    if (!(Flags & F_CREATING))
	set_id_string();

    if (!x && partner_door)
	partner_door -> set_door_adj(str, 1);
}


varargs void
set_closed(status val, status quiet, status both)
{
    if (query(DOOR_IS_CLOSED)) {
	if (val) return;
    } else if (!val)
	return;

    set(val ? DOOR_IS_CLOSED : DOOR_IS_OPEN);

    if (both && partner_door)
	partner_door -> set_closed(val, quiet, 0);

    if (!quiet)
	tell_this_door(sprintf("The %s %ss.",
	    query_name(), (val ? "close":"open")));
}

varargs void
set_locked(status val, status quiet, status both)
{ 
    if (query(DOOR_IS_LOCKED)) {
	if (val) return;
    } else if (!val)
	return;

    set(val ? DOOR_IS_LOCKED : DOOR_IS_UNLOCKED);

    if (both && partner_door)
	partner_door -> set_locked(val, quiet, 0);

    if (!quiet)
	tell_this_door("You hear a click from the " + query_name() + ".");
}

// Should only set state; ie. locked/unlocked, open/closed type of
// things; others shouldn't be changed! -+ Doomdark +-
varargs void
set_both_status(int newFlags)
{
    if (newFlags) {
	Flags &= (~TRANS_FLAGS);
	Flags |= (newFlags & (~F_CREATING));
	return;
    } else {
	partner_door -> set_both_status((Flags & TRANS_FLAGS) |
	  F_CREATING);
    }
    /*
	    partner_door -> set(query(DOOR_IS_CLOSED) ? DOOR_IS_CLOSED :
		    DOOR_IS_OPEN);
	    partner_door -> set(query(DOOR_IS_LOCKED) ? DOOR_IS_LOCKED : DOOR_IS_UNLOCKED);
    */
    partner_door -> set(query(DOOR_CAN_BE_LOCKED) ? DOOR_CAN_BE_LOCKED :
      DOOR_CANT_BE_LOCKED);
    partner_door -> set_type(lock_type);
    partner_door -> set_code(lock_code);
    partner_door -> set_pick_level(pick_level);
    partner_door -> set_door_type(door_type);
    partner_door -> set_door_adj(door_adj);
    if (query(DOOR_CAN_BE_LOCKED) && lock_long)
	partner_door -> set_lock_long(lock_long);
}

/****************************************************************
*                                                            *
*                      Lfuns.                                  *
*                                                              *
****************************************************************/

void
create()
{
    door_type = "door";
    set_name("door");
    if (function_exists("reset_door"))
	Flags |= F_RESET_USED;

    if (function_exists("init_door"))
	Flags |= F_INIT_USED;

    this_object()->create_door();
}

void
reset()
{
    if (Flags & F_RESET_USED)
	this_object()->reset_door();
}

void
init()
{
    if (!this_player()) return;
    if (direction)
	add_action("go_cmd", direction);
    //	add_action("go_cmd", "go");
    //	add_action("cmd_knock", "knock");
    // add_action("close_or_open","close");
    // add_action("close_or_open","open");
    // add_action( "lock_or_unlock", "unlock");
    // add_action( "lock_or_unlock", "lock");
    if (Flags & F_INIT_USED)
	this_object() -> init_door();
}

status
id(string str)
{
    return (door_ids && member(door_ids, str) >= 0)
    || lock_id(str);
}

/****************************************************************
*                                                            *
*              And then rest of functions...                   *
*                                                              *
****************************************************************/

status
tell_this_door(string str)
{
    if (!environment()) return 0;
    environment() -> tell_here(str);
    return 1;
}

string
remove_nr(string str)
{
    int x, y;
    if (!(x = sizeof(str))) return 0;
    for (y = x = x - 1; x; x--) {
	if (str[x] < '0' || str[x] > '9') break;
    }
    if (y == x) return 0;
    return str[0..x-1];
}

status
is_the_code_ok(string code)
{
    // Used to check if the key fits in the lock.
    if (code == MASTER_KEY) return 1;
    if (pointerp(lock_code))
	return (member(lock_code, code) != -1);
    return code == lock_code;
}

/* The following function gives you a powerful way of making 'hooks'
 * so that another objects can act when someone knocks, open, closes
 * etc. this door. You can also determine if the action should happen
 * BEFORE or AFTER the normal action (normal action means that texts
 * get printed and the door opens or whatever). In any case we'll first
 * check whether this is the door player means. For example you might use:
 * 'set_door_hook (AFTER, KNOCK, "someone_knocked", this_object());'
 * in your room code. Note that the last argument may be omitted;
 * it is automatically set to the object that called this function.
 * Now everytime someone knocks on the door, the function
 * "someone_knocked" will be called in the room's code. The value
 * 'hook-function' returns has significance if the hook is used
 * BEFORE action; in this case the normal procedure is executed only
 * if 0 is returned; otherwise it's not. This way you may for example
 * prevent the knocking or opening the door. If so, you have to print
 * appropriate texts yourself in that hook. Note also that when the hook
 * gets called, it will get 'this_player()' as an argument.
 * And lastly, its often advisable to use hooks attached to rooms and
 * then use their filenames rather than objectpointers. That's
 * because of the way LPmud cleans unused objects from the memory.
 */

void
set_door_hook(int when, int what, string func, mixed ob)
{
    int i;
    if (!door_hooks || !pointerp(door_hooks)) 
	door_hooks = allocate(NR_OF_ACTIONS * NR_OF_PHASES);
    if (!intp(when) || !intp(what)) return;
    i = what * NR_OF_PHASES + when;
    if (!func || !stringp(func))
	door_hooks[i] = 0;
    else {
	if (!objectp(ob) && !stringp(ob))
	    door_hooks[i] = ({ func, previous_object() });
	else door_hooks[i] = ({ func, ob });
    }
}

/* And with the following func you can check if there is a hook
 * in some action; if there isn't, 0 is returned; otherwise
 * an array: ({ string func_name, mixed ob }) in which the
 * 'ob' may be either string or object.
 * For example: 'hook = query_door_hook (AFTER, KNOCK);'
 * would return ({ "someone_knocked", <objectpointer to the room> })
 * if used after the example given above (in set_door_hook texts).
 */

mixed
query_door_hook(int when, int what)
{
    if (!door_hooks || !pointerp(door_hooks))
	return 0;
    return door_hooks[what * NR_OF_PHASES + when];
}

status
call_door_hook(int when, int what)
{
    mixed *temp_arr;
    if (!door_hooks || !pointerp(door_hooks))
	return 0;
    if (!(temp_arr = door_hooks[what * NR_OF_PHASES + when]))
	return 0;
    if (!pointerp(temp_arr) || sizeof(temp_arr) < 2) return 0;
    if (stringp(temp_arr[1]) || objectp(temp_arr[1]))
	return (status) call_other(temp_arr[1], temp_arr[0], this_player());
    return 0;
}

status
go_cmd(string str)
{
    string s;
    int tmp;
    string verb;
    if ((verb = query_verb()) == "go") {
	if (!str) return notify_fail("Go where?\n"), 0;
	if (!sscanf(str, "through %s", s))
	    str = s;
	if (s = remove_nr(str)) {
	    str = s;
	}
	else if (!check_door(str, "go")) return 1;

    }
    if (query(DOOR_IS_CLOSED)) {
	this_player()->tell_me("You can't do that, the "+query_name()+" is closed.");
	return 1;
    }

    if (call_door_hook(BEFORE, GO)) return 1;
    if (!partner_door || !environment(partner_door)) {
	this_player()->tell_me("ERROR in door object; can't find the\
 opposite door object!");
	return 1;
    }
    this_player()->tell_me("You go through "+ query_name() + ".");
    this_player() -> move_player("through " + query_name(),
      environment(partner_door));
    call_door_hook(AFTER, GO);
    PARTY_D->player_moved(this_player(), verb, str, environment());
    return 1;    
}

private status
check_door(string name, string cmd)
{
    string s, *doors;
    status tmp;
    object ob;
    for (doors = ({ }), tmp = 0, ob = next_inventory(this_object());
      ob; ob = next_inventory(ob)) {
	if (ob -> id(name)) {
	    tmp = 1;
	    doors += ({ (string) ob -> query_name(0, this_player()) });
	}
    }

    if (tmp) {
	doors = ({ query_name(0, this_player()) }) + doors;
	if (cmd == "go")
	    this_player()->tell_me("Through which "+name+" you want to go; "
	      + implode(doors, ", ", " or ") + "?");
	else this_player() -> tell_me(
	      "Which " + name + " you want to " + cmd + ": "
	      +implode(doors, ", ", " or ") + "?");
	return 0;
    }

    return 1;
}

private status
check_key(string name, string cmd, object key)
{
    string s, *keys;
    status tmp;
    object ob;
    for (keys = ({ }), tmp = 0, ob = next_inventory(key);
      ob; ob = next_inventory(ob)) {
	if (ob -> id(name)) {
	    tmp = 1;
	    keys += ({ (string) ob -> query_name(0, this_player()) });
	}
    }

    if (tmp) {
	keys = ({ (string) key ->query_name(0, this_player()) }) + keys;
	this_player() -> tell_me(
	  "With which " + name + " you want to " + cmd + " the " + query_name() + ": "
	  +implode(keys, ", ", " or ") + "?");
	return 0;
    }

    return 1;
}

status
lock_id(string s)
{
    if (Flags & F_CAN_BE_LOCKED)
	return lock_ids && member(lock_ids, s) >= 0;
    return 0;
}

private status
close_or_open(string str, string cmd)
{
    int tmp;
    status nr_given;
    string s, t;
    notify_fail(capitalize(cmd) + " what?\n");

    if (!str) return 0;

    // Let's remove possible number from end of id...

    if (s = remove_nr(str)) {
	str = s;
	nr_given = 1;
    }

    if (lock_id(str)) return 0;
    // Tried to open the lock in this case...

    if (!nr_given && !check_door(str, cmd)) return 1;
    // Had more than one possible doors to be opened/closed...

    tmp = ((cmd == "close") ? 1 : 0);
    if (((nr_given = query(DOOR_IS_CLOSED)) && tmp)
      || (!nr_given && !tmp)) {
	this_player()->tell_me("But why? It's already "
	  + (tmp ? "closed":"open") + "!");
	return 1;
    }

    if (query(DOOR_IS_LOCKED)) {
	this_player()->tell_me(sprintf("You can't %s the %s, it's locked!",
	    cmd, query_name(0, this_player())));
	return 1;
    }

    if (call_door_hook(BEFORE, (tmp ? CLOSE : OPEN)))
	return 1;

    this_player()->tell_me(sprintf("You %s the %s.", cmd,
	query_name(0, this_player())));
    environment()->tell_here(sprintf("%s %ss the %s.",
	(string)this_player()->query_name(), cmd, query_name()), this_player());

    set(tmp ? DOOR_IS_CLOSED : DOOR_IS_OPEN);

    if (partner_door)
	partner_door -> set_closed(tmp, 0, 0);

    call_door_hook(AFTER, (tmp ? CLOSE : OPEN));
    return 1;
}

status close_cmd(string s) { return close_or_open(s, "close"); }
status open_cmd(string s) { return close_or_open(s, "open"); }

private status
lock_or_unlock(string str, string cmd)
{
    object key, ob;
    int tmp;
    status door_number, key_number;
    string door, key2, s2, *keys, *doors;

    if (!str) return
	notify_fail(capitalize(cmd) + " what?\n"), 0;

    if (!sscanf(str, "%s with %s", door, key2)) {
	door = str;
	key2 = 0;
    }

    // Let's take possible number from the end of door name...

    if (s2 = remove_nr(door)) {
	door_number = 1;
	door = s2;
    }

    // Had more than one possible door to be locked/unlocked
    if (!door_number && !check_door(door, cmd)) return 1;

    if (!query(DOOR_CAN_BE_LOCKED)) {
	this_player()->tell_me("You can't see any lock in the "
	  +query_name(0, this_player())+".");
	return 1;
    }

    tmp = ((cmd == "lock") ? 1 : 0);
    door_number = query(DOOR_IS_LOCKED);
    if ((door_number && tmp) || (!door_number && !tmp)) {
	this_player()->tell_me("But why? It's already " + cmd + "ed!");
	return 1;
    }

    // Something like "lock/unlock east door"...

    if (!key2) {

	if (!(key = present("key", this_player())))
	    return notify_fail(sprintf("%s the %s with what?\n",
		capitalize(cmd), query_name(0, this_player()))), 0;

	if (!check_key("key", cmd, key)) return 1;
	// Had more than one key...

    } else {
	// Something like "lock/unlock east door with blue key"

	if (s2 = remove_nr(key2)) {
	    key2 = s2;
	    key_number = 1;
	}

	if (!(key = present(key2, this_player()))) {
	    this_player()->tell_me("But you don't have any \""
	      + key2 + "\".");
	    return 1;
	}

	// More than one possible key to be used...
	if (!key_number && !check_key(key2, cmd, key))
	    return 1;
    }

    if (!is_the_code_ok((string) key -> query_code())) {
	this_player()->tell_me("The key doesn't fit!");
	environment()->tell_here(sprintf("%s tries to %s the %s, but seems to fail.",
	    (string)this_player()->query_name(), cmd,
	    query_name()), this_player());
	return 1;
    }

    if (call_door_hook(BEFORE, (tmp ? LOCK : UNLOCK))) return 1;

    this_player()->tell_me(sprintf("You %s the %s with %s.",
	cmd, query_name(), (string) key -> query_name(0, this_player()) ));
    environment()->tell_here(sprintf("%s %ss %s.",
	(string)this_player()->query_name(), cmd, query_name()),
      this_player());

    set(tmp ? DOOR_IS_LOCKED : DOOR_IS_UNLOCKED);

    if (partner_door)	// Let's be paranoid... -+ Doomdark +-
	partner_door -> set_locked(tmp, 0, 0);
    call_door_hook(AFTER, (tmp ? LOCK : UNLOCK));
    return 1;
}

status lock_cmd(string s) { return lock_or_unlock(s, "lock"); }
status unlock_cmd(string s) { return lock_or_unlock(s, "unlock"); }

status
knock_cmd(string str)
{
    int tmp;
    string tmp2;
    status nr_given;
    notify_fail("Knock what?\n");
    if (!str) return 0;
    if (sscanf(str, "on %s", tmp2))
	str = tmp2;

    if (tmp2 = remove_nr(str)) {
	nr_given = 1;
	str = tmp2;
    } else if (!check_door(str, "knock")) return 1;
    if (call_door_hook(BEFORE, KNOCK)) return 1;
    this_player()->tell_me("You knock on the " + query_name(0, this_player()) + ".");
    environment()->tell_here(sprintf("%s knocks on %s.",
	(string)this_player()->query_name(), query_name()), this_player());
    if (partner_door) partner_door -> tell_this_door(
	  "You hear a knock from the "+(string)partner_door->query_name()+".");
    call_door_hook(AFTER, KNOCK);
    return 1;
}

// Redefine this function if you either don't want this door to be
// lockpickable or want some special effects when player tries to
// to lockpick it.

varargs
int pick_door(int unpick)
{
    if ((pick_level < 1) || query(DOOR_CANT_BE_LOCKED)) return 0;

    // Can't be picked, so do NOT unlock (or lock in case of 'unpick')

    if (!unpick) {
	// 'Normal' picking of the lock (locked -> unlocked)
	if (!query(DOOR_IS_LOCKED))
	    return -1;

	set(DOOR_IS_UNLOCKED);
	partner_door -> set_locked(0, 0, 0);
	return 1;
    }

    if (query(DOOR_IS_LOCKED))
	return -1;

    set(DOOR_IS_LOCKED);
    partner_door -> set_locked(1, 0, 0);

    return 1;
}

string
opposite_dir(string str)        // ie. 'north' -> 'south' etc.
{
    string dir;
    if(!(dir = ([ "up":"down","north":"south","northeast":"southwest"
	  ,"east":"west","southeast":"northwest","down":"up"
	  ,"south":"north","southwest":"northeast","west":"east"
	  ,"northwest":"southeast" ]) [str])) return "unknown";
    return dir; 
}

/* Note that 'd_long', 'l_long', 'd_dir', 'where' may be either strings or
 * arrays of strings (that contain 2 strings). If it's a string, use it on
 * both sides, if an array, the first one is for this side and the
 * second for the other side. Also, 'where' may in some cases be either
 * an object or an array of objects, but this is not recommended.
 * 'K_code' may be either a string or an array of strings. If latter
 * all these codes are accepted, if former, just that code. This
 * makes it possible to make 'master keys', that open many doors,
 * (for example all the doors in some area) in addition to 'normal'
 * keys that only open one door.
 */

// Returns object pointer to either this object, or the existing door,
// if such exists in this room (and this one will be destructed!).

varargs object
add_door(mixed d_long, mixed d_dir, mixed where, string k_type, mixed k_code,
  status d_closed, status d_locked, status d_lockable, int p_level,
  mixed l_long, string d_type)
{
    int i;
    string tmp, tmp2;
    object room, room2;
    object door, door2, p_door;
    Flags |= F_CREATING;
    tmp = object_name(this_object());
    if(sscanf(tmp, "%s#%d", tmp2, i) == 2) tmp = tmp2;
    partner_door = clone_object(tmp2);

    // So that we make 'exact' copy of this side; in effect, this allows us to
    // us inheritted doors easier than without this check (used to be DOOR_FILE

    set(d_locked ? DOOR_IS_LOCKED : DOOR_IS_UNLOCKED);
    set(d_closed ? DOOR_IS_CLOSED : DOOR_IS_OPEN);
    set(d_lockable ? DOOR_CAN_BE_LOCKED : DOOR_CANT_BE_LOCKED);
    set_type(k_type);       // So that lock_id_string will be ok.
    lock_code = k_code;
    if (stringp(d_type))
    {
	set_door_type(d_type, 0);
	partner_door->set_door_type(d_type, 1);
	if(l_long) {
	}
	if(pointerp(l_long)) {
	    set_lock_long(l_long[0]);
	    partner_door -> set_lock_long(l_long[1]);
	} else {
	    set_lock_long(l_long);
	    partner_door -> set_lock_long(l_long);
	}
    }
    pick_level = p_level;
    set_both_status();      // Let's set the same data to both doors.

    if(pointerp(d_long)) {
	set_door_long(d_long[0]);
	partner_door -> set_door_long(d_long[1]);
    } else {
	set_door_long(d_long);
	partner_door -> set_door_long(d_long);
    }

    if(pointerp(d_dir)) {
	set_dir(d_dir[0]);
	partner_door -> set_dir(d_dir[1]);
    } else {
	set_dir(d_dir);
	partner_door -> set_dir(opposite_dir(d_dir));
    }
    Flags &= (~F_CREATING);
    set_id_string();

    // If not otherwise specified, use pairs like east & west etc.

    if(pointerp(where)) {
	where[0] -> load_it();
	where[1] -> load_it();
	room = (stringp(where[0]) ? find_object(where[0]) : where[0]);
	room2 = (stringp(where[1]) ? find_object(where[1]) : where[1]);
    } else {
	where -> load_it();
	room = previous_object();
	room2 = (stringp(where) ? find_object(where) : where);
    }
    // A kludge... :-/
    room->set(NO_CLEANUP);
    room2->set(NO_CLEANUP);
    door = present(query_name(), room);
    door2 = present((string)partner_door -> query_name(), room2);

    if (!door && !door2) { // Everything as it should...
	partner_door -> set_door(this_object());
    }

    if(door && door2) {     // Already both sides there...
	destruct(partner_door);
	destruct(this_object());
	return door;
    }
    if (door2) {    // Other side already, but not this side...
	destruct(partner_door);
	set_door(door2);
	door2 -> set_door(this_object());
	door2 -> set_both_status();
    }
    if (door) {     // This side already but not the other side...
	door -> set_door(partner_door);
	partner_door -> set_door(door);
	move_object(partner_door, room2);
	door -> set_both_status();
	destruct(this_object());
	return door;
    }
    move_object(this_object(),room);
    if (!door2)
	move_object(partner_door,room2);
    return this_object();
}

#ifdef COMPAT_DOOR

/* And then some functions that are no longer needed with this door,
 * but may still be needed by the doors using the old door.c
 */
status
set_all(string str)
{
    string door_room;
    int is_closed, is_locked, can_lock;
    if (!str) return 0;
    sscanf(str, "%s %s %s %s %d %d %d", door_room, direction,
      lock_type, lock_code, is_closed, is_locked, can_lock);
    set(is_closed ? DOOR_IS_CLOSED : DOOR_IS_OPEN);
    set(is_locked ? DOOR_IS_LOCKED : DOOR_IS_UNLOCKED);
    set(can_lock ? DOOR_CAN_BE_LOCKED : DOOR_CANT_BE_LOCKED);
    set_dir(direction);     /* Let's call this so that id_parse_string
		   * will get as it should. */
    if (lock_type == "0")
	lock_type = 0;
    set_type(lock_type); /* And let's be sure also id_lock_string will be ok */
    move_object(this_object(), door_room);
    return 1;
}

void
door_sound(string str)
{
    environment() -> tell_here(str+" is heard from the "+direction+" door.");
}

void
both_door_sound(string str)
{
    door_sound(str);
    partner_door -> door_sound(str);
}
#endif
mixed query_door_hooks() { return door_hooks; }
