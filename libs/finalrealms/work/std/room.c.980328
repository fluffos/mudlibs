
// Taniwha 1995 uncommented clean_up
/* Baldrick started some lobotomizing. sept '96
 * Will reduce the size of this beast.
 */
inherit "/std/basic/light";
inherit "/std/basic/property";
inherit "/std/basic/cute_look";
inherit "/std/basic/desc";
inherit "/std/senses";
#include "room.h"
#include "door.h"
// debugging logs
//#define CLEAN_UP_LOG "clean_up_room"
//#define DOOR_LOG "room_doors.cloned"

#define FAST_CLEAN_UP 10
#define SLOW_CLEAN_UP 480
private static int room_create_time;    // time of creation
private static int room_init_time;      // time of previous init
private static int room_stabilize;      // don't bother call_out


object *query_hidden_objects();
string query_dirs_string();
static mixed *room_clones;

static mapping items,
exit_map,
door_locks,
door_map,
door_control;

static string exit_string,
short_exit_string,
room_zone,
dark_mess,
*dig_where,
*dig_exit,
*dest_direc,
*aliases;

static mixed *dest_other;
int *co_ord;
object *destables,
*hidden_objects;
/* Hamlet -- I'm adding choices for colors with the exit arrays. */
static string exit_color;
static string loginroom;

string set_login_room(string room)
{
    loginroom = room;
   return loginroom;
}

void event_login(object ob)
{
    if(!stringp(loginroom) || !ob) return;
     else ob->move(loginroom);
}

void start_clean_up();
string query_short_exit_string();
object * query_hidden_objects() { return hidden_objects; }

int test_add(object ob, int flag) { return 1; }
int test_remove(object ob, int flag) { return 1; }
int add_weight(int n) { return 1; }

int *query_co_ord() { return co_ord; }
void set_co_ord(int *newc) { co_ord = newc; }
mixed *query_init_data()
{
    return light::query_init_data()+property::query_init_data();
}

object *add_hidden_object(object ob)
{
    hidden_objects += ({ob});
    return hidden_objects;
}
varargs string query_contents(string str,object *ob)
{
   if(!hidden_objects) hidden_objects = ({ });
    if(ob)
	ob -= hidden_objects;
    else ob = all_inventory(TO) - hidden_objects;
    return ::query_contents(str,ob);
}

void reset()
{
    object it;
    int flags;
    if ( room_clones ) // From Laggard RoD
    {
	string thing;

	int i = sizeof(room_clones);
	// processing backwards yields room inventory in order of add_clones.
	// (for those who care)
	flags = 0;
	while ( i-- > 0 )
	{
	    if ( stringp(room_clones[i]) ) // See if it's a tag, if so we use it for now
	    {
		thing = room_clones[i];
		flags = 0;
	    }
	    else if(room_clones[i])
	    {
		flags = room_clones[i];
	    }
	    else if ( !room_clones[i] ) // fill up any empties using the tag
	    {
		//          Taniwha, clone, then TEST then move, so if it's screwed it still works
		room_clones[i] = clone_object(thing);
		if(room_clones[i])
		{
		    room_clones[i]->move(TO);
		    if(flags == 1) add_hidden_object(room_clones[i]);
		}
	    }
	}
    }
}

/* Hamlet -- setting of exit string colors.  Meat is in the handler. */
void set_exit_color(string which) {
    exit_color = ROOM_HAND->exit_string_color(which);
}

varargs void add_clone( string the_file, int how_many,int flags )
{
    // Laggard RoD 1995, minor mods by Taniwha
    //
	if ( !stringp(the_file) )
    {
	log_file("debug.log", ctime(time())
	  + " bad clone file: " + the_file
	  + ", " + file_name(this_object())
	  + "\n");
	return;
    }
    if ( !how_many ) how_many = 1;
    // don't make array unless we have something to put in it!
    if ( !room_clones )
    {
	room_clones = ({ });
    }
    while ( how_many-- > 0 )
    {
	// make space for objects in array
	room_clones += ({ 0 });
    }
    // last, for backward processing.
    if(flags) room_clones += ({ flags });
    room_clones += ({ the_file });
}

mixed *query_room_clones() { return room_clones; }

string query_dark_mess(int lvl)
{
    if(!exit_string) query_dirs_string();
    switch(lvl)
    {
    default:
	return "Hmmph, odd, " + dark_mess;
    case 1: /* Total blackout */
	return dark_mess;
    case 2: /* pretty damn dark */
	return "You can't see much.\n"+ exit_string;
    case 3: /* getting dim */
	return "It's hard to see in this gloom.\n"+ ::short(1)+"\n" + exit_string;
    case 4: /* slightly dazzled */
	return "You are dazzled by the light.\n"+ ::short(0)+"\n"+ exit_string;
    case 5: /* very bright */
	return "The light is painfully bright.\n"+ exit_string;
    case 6:
	return "You are too blinded by the light to see properly.\n";
    }
}

void set_dark_mess(string str) { dark_mess = str; }

void create() {
    string *inh;
    dest_other = ({ });
    dest_direc = ({ });
    door_locks = ([ ]);
    dig_where = ({ });
    dig_exit = ({ });
    exit_map = ([ ]);
    items = ([ ]);
    aliases = ({ });
    destables = ({ });
    hidden_objects = ({ });
    door_control = ([ ]);
    door_map = ([ ]);
    room_zone = "nowhere";
    exit_color = "%^BOLD%^%^CYAN%^";
    seteuid((string)"/secure/master"->creator_file(file_name(this_object())));
    set_dark_mess("It is too dark to see");
    property::create();
    senses::create();
    add_property("location", "inside");
    this_object()->setup();
    reset();
    if(replaceable(this_object())) {
	inh = inherit_list(this_object());
	if(sizeof(inh) == 1)
   room_create_time = time();
   start_clean_up();
	    replace_program(inh[0]);
    }
} /* create() */

string expand_alias(string str);

// moved glance code to the command  (:   Radix 1996
string short(int dark) {
    return ::short(dark);
} /* short() */

int id(string str) {
    int i;

    return 0;
    str = expand_alias(str);
    return items[str];
} /* id() */

string expand_alias(string str)
{
    str = EXIT_HAND->expand_alias(aliases,str);
    return str;
} /* expand_alias() */

//  Thanks to viewers like you this function [insert name here]
//     has been moved to your local exit_handler [Piper 1/5/96]

string query_dirs_string()
{
    object room_ob = this_object();

    exit_string = EXIT_HAND->query_dirs_string(dest_direc,
      dest_other,room_ob,exit_color);
    return exit_string;
}
int reset_short_exit_string() { return short_exit_string = 0; }

/*
 * This creates the exits message you keep getting
 */
string query_short_exit_string() {
    string ret, *dirs;
    int no, i, nostore, add;

    if (short_exit_string)
	return short_exit_string;
    if (!dest_direc || sizeof(dest_direc)==0)
	dest_direc = ({ });
    dirs = ({ });
    for (i=0;i<sizeof(dest_other);i+=2) {
	add = 0;
	if (dest_other[i+1][ROOM_OBV]) {
	    no += 1;
	    add = 1;
	} else if (stringp(dest_other[i+1][ROOM_OBV])) {
	    nostore = 1;
	    add = (int)call_other(this_object(),dest_other[i+1][ROOM_OBV]);
	} else if (pointerp(dest_other[i+1][ROOM_OBV])) {
	    nostore = 1;
	    add = (int)call_other(dest_other[i+1][ROOM_OBV][0],dest_other[i+1][ROOM_OBV][1]);
	}
	if (!add)
	    continue;
	if ((ret=SHORTEN[dest_other[i]]))
	    dirs += ({ ret });
	else
	    dirs += ({ dest_other[i] });
    }
    if (sizeof(dirs)==0) {
	if (nostore)
	    return exit_color+" [none]%^RESET%^";
	return short_exit_string = exit_color+" [none]%^RESET%^";
    }
    if (nostore)
	return exit_color+" ["+implode(dirs,",")+"]%^RESET%^";
    return short_exit_string  = exit_color+" ["+implode(dirs,",")+"]%^RESET%^";
} /* query_short_exit_string() */

string long(string str, int dark) {
    int i;

    if (dark)
	return query_dark_mess(dark)+"\n";
    if(!exit_string) query_dirs_string();
    if (!str)
    {
	return( query_long()+exit_string+"\n"+query_contents("") );
    }
    str = expand_alias(str);
    return items[str];
} /* long() */

void calc_co_ord() {
    int *old_co_ord, i, j, k;

    for (i=0;i<sizeof(dest_other) && !co_ord;i+=2)
	if (find_object(dest_other[i+1][ROOM_DEST]))
	    if (!catch((old_co_ord = (int *)dest_other[i+1][ROOM_DEST]->query_co_ord())))
		if (old_co_ord) {
		    co_ord = old_co_ord + ({ });
		    if ((j=member_array(dest_other[i], STD_ORDERS)) != -1)
			for (k=0;k<3;k++)
			    co_ord[k] += STD_ORDERS[j+1][k];
		}
		/* Set a default later -- Hamlet */
    if(!co_ord)
	call_out("default_calc_co_ord",0);
} /* calc_co_ord() */

void default_calc_co_ord() {
    /* Defaults are a good thing. -- Hamlet */
    if(!co_ord)
	co_ord = ({ 0, 0, 0 });
}

void init() {
    int i, j;
    mapping done;

    if (!dest_direc)
	return 0;

    done = ([ ]);
    for (i=0;i<sizeof(dest_direc);i++) {
	if (!done[dest_direc[i]])
	    add_action("do_exit_command", dest_direc[i]);
	done[dest_direc[i]] = 1;
	if ((j=member_array(dest_direc[i], aliases)) != -1) {
	    string *al;
	    al = aliases;

	    do {
		if (!(j%2)) {
		    if (!done[al[j+1]]) {
			add_action("do_exit_command", al[j+1]);
			done[al[j+1]] = 1;
		    }
		} else
		    j++;
		al = al[j+2..sizeof(al)];
	    } while ((j=member_array(dest_direc[i], al)) != -1);
	}
    }
    add_action("do_search", "search");
    add_action("do_dig","dig");
    if (!pointerp(co_ord))
	calc_co_ord();

    hidden_objects -= ({ 0 });

    for (i=0;i<sizeof(hidden_objects);i++)
	hidden_objects[i]->init();

    senses::init();
   start_clean_up();

} /* init() */

void start_clean_up()
{
    int old_call_out;
#ifdef FAST_CLEAN_UP
    // when folk in room, update timers {Laggard}
    old_call_out = remove_call_out( "clean_up_room" );
#endif
    room_init_time = time();
#ifdef FAST_CLEAN_UP
    if ( old_call_out < FAST_CLEAN_UP
      &&  (room_init_time - room_create_time) < FAST_CLEAN_UP )
    {
        // was merely passing through {Laggard}
        call_out( "clean_up_room", FAST_CLEAN_UP, 0 );
    }
    else if ( !room_stabilize )
    {
        call_out( "clean_up_room", old_call_out, 0 );
    }
#endif

} /* init() */
/*
 * not particularly useful.
 * But here just the same, great for debugging purposes.
 */
string *query_direc() { return dest_direc; }

/*
 * It IS useful to get directions+where they go to
 * BTW this is not a frog.
 */
nomask mixed *query_dest_dir() {
    int i;
    string *retval;

    retval = ({ });
    for (i=0;i<sizeof(dest_other);i+=2)
	retval += ({ dest_other[i], dest_other[i+1][ROOM_DEST] });
    return  retval;
} /* query_dest_dir() */

mixed *query_dest_other() { return dest_other; }

void set_zone(string str) {
    room_zone = str;
} /* set_zone() */

string query_zone() {
#ifdef FAST_CLEAN_UP
    // monsters call this to move, but may not actually come here,
    // so potential clean_up_room {Laggard}
    if ( !room_stabilize  &&  !room_init_time )
    {
	room_init_time = time();
	call_out( "clean_up_room", FAST_CLEAN_UP, 0 );
    }
#endif

    return room_zone;
} /* query_zone() */

/*
 * this function puts the directions into the thingy list
 * I am sure you know what I mean
 */
string expand_direc(string str) {
    string s1,s2;

    if (sscanf(str,"%s %s",s1,s2)==2)
	return s1;
    return str;
} /* expand_direc() */

//  Externalized exit portions of room.c (Piper 12/24/95)
//      Now look in lock_handler.c & exit_handler.c

varargs int add_exit(string direc,mixed dest,string type,
  string material)
{
    mixed *m;
    if(!dest_other) dest_other = ({ });

    m = EXIT_HAND->add_exit(door_control,exit_map,            //mappings
      dest_other,dest_direc,hidden_objects, //arrays
      direc,dest,type,material             //data
    );

    if(sizeof(m) > 0)
    {

	door_control = m[0];
	exit_map = m[1];
	dest_other = m[2];
	dest_direc = m[3];
	hidden_objects = m[4];
	query_dirs_string();
	return(1);
    }


    return 0;
}

// Query for exit type... [Piper 12/24/95]
string query_ex_type(string direc)
{
    if(!exit_map[direc]) { return 0; }
    return exit_map[direc][1];
}

// Query for the exit material [Piper 12/24/95]
string query_ex_material(string direc)
{
    if(!exit_map[direc]) { return 0; }
    return exit_map[direc][2];
}
//Locks... again.. much better this time   [Piper 12/24/95]

varargs int door_lock(string direc, string type,
  int str, int pub, int trap)
{
    door_locks = LOCK_HAND->add_lock(door_locks,direc,type,str,pub,trap);
    return(1);
}

int query_lock_dir(string direc)
{
    int lock_chk = LOCK_HAND->query_lock_index(door_locks,direc);
    return lock_chk;
}

string query_lock_type(string direc)
{
    string lock_typ = LOCK_HAND->query_lock_type(door_locks,direc);
    return lock_typ;
}

int query_lock_str(string direc)
{
    int str_chk = LOCK_HAND->query_lock_str(door_locks,direc);
    return str_chk;
}

int query_lock_notify(string direc)
{
    int pub_chk = LOCK_HAND->query_lock_notify(door_locks,direc);
    return pub_chk;
}

int query_trap(string direc)
{
    int trap = LOCK_HAND->query_trap(door_locks,direc);
    return trap;
}

int remove_lock(string direc)
{
    door_locks = LOCK_HAND->remove_lock(door_locks,direc);
    return(1);
}

// modify_eixt... "now showing in an exit_handler near you"
//  [Piper 12/30/95]

mixed *_BT_;
mixed *query_bt() { return _BT_; }

int modify_exit(string direc, mixed *data)
{
    mixed *m;

    m = EXIT_HAND->modify_exit(door_control,door_map,dest_other,
      hidden_objects,direc,data);

    if(sizeof(m) > 0)
    {
	_BT_ = m;
	if(sizeof(m) > 0 )
	{
	    door_control = m[0];
	    door_map = m[1];
	    dest_other = m[2];
	    hidden_objects = m[3];
	    query_dirs_string();
	    return(1);
	}
    }
    return 0;
}

int remove_exit(string direc)
{
    mixed *m;
    // Radix
    // is an idiot.  Checked door_map.  Doormap contains nothing.
    // Fixed by Wonderflug.
    if ( member_array(direc, dest_other) == -1 )
	return(0);

    m = EXIT_HAND->remove_exit(door_control,door_map,exit_map,dest_other,
      dest_direc,hidden_objects,direc);

    door_control = m[0];
    door_map = m[1];
    exit_map = m[2];
    dest_other = m[3];
    dest_direc = m[4];
    hidden_objects = m[5];
    door_locks = LOCK_HAND->remove_lock(door_locks,direc);
    query_dirs_string(); // Update the exit string
    reset_short_exit_string();  //so glance works, Anirudh


    return(1);
}

int query_exit(string direc) {
    return (member_array(direc, dest_other) != -1);
} /* query_exit() */

int query_size(string direc)
{
    int size;
    object room_ob = this_object();
    size = EXIT_HAND->query_size(dest_other,direc,room_ob);
    return size;
}

int do_exit_command(string str,mixed verb,object ob,object foll)
{
    mixed zip;
    int old_call_out;
    object room_ob = this_object();
    zip = EXIT_HAND->do_exit_command(door_control,door_locks,
      exit_map,dest_direc,dest_other,
      aliases,str,verb,ob,foll,room_ob);
#ifdef FAST_CLEAN_UP
    old_call_out = remove_call_out( "clean_up_room" );  // multiple folks in room

    if ( old_call_out > 0
      &&  old_call_out < FAST_CLEAN_UP
      &&  (time() - room_create_time) < FAST_CLEAN_UP )
    {
	// was merely passing through {Laggard}
	call_out( "clean_up_room", FAST_CLEAN_UP, 0 );
    }
    else if ( !room_stabilize )
    {
	call_out( "clean_up_room", SLOW_CLEAN_UP, 0 );
    }
#endif

    return zip;
}

/* Here is the add_item stuff, what I don't understand is why this is objects..
 * could it help if we used just a mapping? not too sure tho.
 * Baldrick.
 */

/*
 * Ok we have done all the exit junk, now for the item bits and pieces
 * share and enjoy your plastic pal who is fun to be with
 */
int add_item(string str,string desc) {
    object ob;
    int i;

    if (!items)
	items = ([ ]);

    ob = items["The object"];
    if (!ob) {
	ob = clone_object(ITEM_OBJECT);
	items["The object"] = ob;
    }
    ob->setup_item(str, desc);
    return 1;
} /* add_item() */

/*
 * Ok.  Remove item is nasty :(  But....  We will add it.
 * It will remove all things that reference the given desc.
 */
int remove_item(string str) {
    object ob;

    if (!items)
	items = ([ ]);

    ob = items["The object"];
    if (!ob)
	return 0;
    return (int)ob->remove_item(str);
} /* remove_item() */

/*
 * Change all descs...  It does a match and goes wimble.
 */
int modify_item(string str, string new_desc) {
    object ob;

    if (!items)
	items = ([ ]);

    ob = items["The object"];
    if (!ob)
	return 0;
    return (int)ob->modify_item(str, new_desc);
} /* modify_item() */

mapping query_items() { return items; }

/*
 * The alias junk
 */
int add_alias(mixed name,string str) {
    int i;

    if (!aliases)
	aliases = ({ });

    if (pointerp(name)) {
	for (i=0;i<sizeof(name);i++)
	    add_alias(name[i], str);
	return 1;
    }

    aliases += ({ str, name });
    return 1;
} /* add_alias() */

int modify_alias(string str,string name) {
    int i;

    if (!aliases)
	return 0;

    if ((i=member_array(str, aliases))==-1 || !(i%2))
	return 0;

    aliases[i+1] = name;
    return 1;
} /* modify_alias() */

int remove_alias(string str) {
    int i;

    if (!aliases)
	return 0;

    if ((i=member_array(str, aliases))==-1 || !(i%2))
	return 0;

    aliases = delete(aliases, i, 2);
    return 1;
} /* remove_alias() */

int query_no_writing() { return 1; }


object * query_destables() { return destables; }
static int empty_room(object ob)
{
    object *olist;
    int i;
    if(!environment(ob)) return 1;
    // TEMP fix I think, - Radix
    if(!environment(ob)->query_property("location")) return 0;
    olist = all_inventory(environment(ob));
    for( i = 0; i < sizeof(olist) ; i++)
    {
	if(interactive(olist[i])) return 0; // Player in room
    }
    return 1; // dest it
}

void dest_me() {
    object *arr;
    int i;

    if (!destables)
	destables = ({ });
    if (mappingp(items))
	destables += m_values(items);
    for (i=0;i<sizeof(destables);i++)
	if (destables[i])
	    destables[i]->dest_me();
	// Isthar@Aurora 10-dec-1994, destruct everything here
    arr = all_inventory(this_object());
   arr -= ({ 0});
    for (i=0;i<sizeof(arr);i++) {
	if (interactive(arr[i])) arr[i]->move("/room/void");
	else arr[i]->dest_me();
    }
    // Wandering NPC hunt, Taniwha 1996
    for( i = 0; i < sizeof(room_clones); i++)
    {
	if(objectp(room_clones[i]))
	{
	    if(empty_room(room_clones[i])) room_clones[i]->dest_me();
	}
    }
    destruct(this_object());
} /* dest_me() */


// function called by the driver before swapping.
int clean_up( int flag )
{
    object *arr = deep_inventory( this_object() );
    int i = sizeof( arr );
    int elapsed_time = time() - room_create_time;

    /* next line is mine -- Hamlet */
    if(this_object()->query_property("no_clean_up"))  return 1;
    if(this_object()->query_property("corpse_here"))  return 1;
#if 1
    // check for inherited room
    if ( flag )
    {
#ifdef CLEAN_UP_LOG
	log_file( CLEAN_UP_LOG, ctime( time() )
	  + " inherited "
	  + (room_init_time ? time() - room_init_time : "*0*")
	  + "/"
	  + elapsed_time
	  + " seconds ("
	  + memory_info( this_object() )
	  + " bytes) "
	  + file_name( this_object() )
	  + ".\n" );
#endif
	return 0;
    }
#endif

    // Loop to find if user inside the room somehow {Begosh}
    // Also check for longer term room usage {Laggard}
    while( i-- )
    {
	if ( userp( arr[i] )
	  ||  elapsed_time > SLOW_CLEAN_UP )
	{
#ifdef CLEAN_UP_LOG
	    log_file( CLEAN_UP_LOG, ctime( time() )
	      + " stabilized "
	      + (room_init_time ? time() - room_init_time : "*0*")
	      + "/"
	      + elapsed_time
	      + " seconds ("
	      + memory_info( this_object() )
	      + " bytes) "
	      + file_name( this_object() )
	      + ".\n" );
#endif
	    // room is frequently used, stop cleaning up
	    room_stabilize = 1;
	    return 1;
	}
    }

#ifdef CLEAN_UP_LOG
    log_file( CLEAN_UP_LOG, ctime( time() )
      + " clean_up "
      + (room_init_time ? time() - room_init_time : "*0*")
      + "/"
      + elapsed_time
      + " seconds ("
      + memory_info( this_object() )
      + " bytes) "
      + file_name( this_object() )
      + ".\n" );
#endif
    dest_me();
    return 0;    // don't call back
}


#ifdef FAST_CLEAN_UP
// use call_out to attempt faster clean up {Laggard}
// this is almost but not quite the same as the preceeding function.
// the differences are not subtle.
int clean_up_room( int flag )
{
    object *arr = deep_inventory( this_object() );
    int i = sizeof( arr );
    int elapsed_time = time() - room_init_time;

    /* Next line is mine -- Hamlet */
    if(this_object()->query_property("no_clean_up"))  return 1;
    if(this_object()->query_property("corpse_here"))  return 1;

    if (room_stabilize)
    {
	return 0;
    }
    remove_call_out( "clean_up_room" );

    // Loop to find if user inside the room somehow {Begosh}
    // Also check for recent living (monster?) arrival {Laggard}
    while( i-- )
    {
	if ( userp( arr[i] )
	  ||  living( arr[i] )
	  &&  elapsed_time < SLOW_CLEAN_UP )
	{
	    // we do a call_out to kill the room later if we can ;)
	    call_out( "clean_up_room", SLOW_CLEAN_UP, 0 );
	    return 1;
	}
    }

#ifdef CLEAN_UP_LOG
    log_file( CLEAN_UP_LOG, ctime( time() )
      + " "
      + elapsed_time
      + "/"
      + (time() - room_create_time)
      + " seconds ("
      + memory_info( this_object() )
      + " bytes) "
      + file_name( this_object() )
      + ".\n" );
#endif
    dest_me();
    return 0;    // don't call back
}
#endif





object *find_inv_match(string str) {
    if(!sizeof(hidden_objects))
    {
	return(object *)all_inventory(this_object()) + m_values(items);
    }
    return (object *)all_inventory(this_object()) + (object *)hidden_objects + m_values(items);
} /* find_inv_match() */

int do_search(string str)
{
    /* Cute, useful add_sign. */
    object ob;
    // Fix by wonderflug.  ghosts shouldn't search.
    if ( this_player()->query_dead() )
    {
	notify_fail("A ghost cannot do that.\n");
	return 0;
    }
    // A bit of gp to do this -- Wf, oct 95
    if ( this_player()->adjust_gp(-1) < 0 )
    {
	notify_fail("You are too tired to search right now.\n");
	return 0;
    }
    hidden_objects -= ({ 0 });
    if(sizeof(hidden_objects) && random(TP->query_cha()) > 10)
    {
	ob = hidden_objects[0];
	hidden_objects -= ({ob});
	if(present(ob,TO))
	    write("You search round and find a "+ob->query_short()+"\n");
    }
    else
    {

	write( ({
	    "You search around for a while but dont find anything.\n",
	    "You scrounge around, the ground does look interesting you decide.\n",
	    "You look carefully at everything, but you find nothing.\n",
	    "After a while of intensive searching you find nothing.\n" })[random(4)]);
    }
    say(this_player()->query_cap_name()+" searches around the room a bit.\n");
    event(this_object(), "player_search");
    return 1;
} /* do_search() */
/*
 * add_sign(string long, string read_mess, string short, string name)
 * [short and name are optional]
 * This file can be inherited and will return a sign that can be used
 * by a room or object in any way it sees fit.  This function was the
 * brainchild of Wyrm - 7 Feb '92
 * If the short is left out.. The sign isnt moved into the room,
 * but it can still be looked at and read.
   * This facility was removed by Taniwha 1995, as recent driver and
   * lib changes means thats these objects are scavenged as "dead" now
   *
 */

varargs object add_sign(string long, string mess, string short, string sname) {
    object sign;

    sign = clone_object("/std/object");

    if(!sname) sname = "sign";
    sign->set_name(sname);
    sign->set_main_plural(pluralize(sname));
    if (short)
	sign->set_short(short);
    else sign->set_short("Sign");
    sign->set_long(long);
    sign->set_read_mess(mess);
    sign->reset_get();
    //if (short && short != "")
    sign->move(this_object());
    //else
    //  hidden_objects += ({ sign });
    destables += ({ sign });
    return sign;
} /* add_sign() */

mapping query_door_control() { return door_control; }

void tell_door(string dir, string mess) {
    if (!door_control[dir])
	return;
    door_control[dir][0]->tell_door(mess);
} /* tell_door() */

mixed call_door(string dir, string func, mixed arg1, mixed arg2, mixed arg3) {
    if (!door_control[dir])
	return;
    return (mixed)call_other(door_control[dir][0], func, arg1, arg2, arg3);
} /* call_door() */


mixed query_door(mixed dest) {
    mixed bing;

    if ((bing = door_control[dest]))
	if (!pointerp(bing))
	    return bing;
    if (objectp(dest))
	if ((bing = door_control[file_name(dest)]))
	    if (!pointerp(bing))
		return bing;
    return 0;
} /* query_door() */

mixed stats() {
    mixed *exits, *tmp;
    int i;

    exits = ({ });
    for (i=0;i<sizeof(dest_other);i+=2)
	exits += ({ ({ "Direction", dest_other[i], }),
	  ({ "Destination", dest_other[i+1][ROOM_DEST] }) });
    if (co_ord)
	tmp = ({ ({ "co-ord x", co_ord[0] }),
	  ({ "co-ord y", co_ord[1] }),
	  ({ "co-ord z", co_ord[2] }), });
    else
	tmp = ({ });
    return ({ ({ "short", short(0), }),
      ({ "location", query_property("location"), }),
      ({ "move zone", room_zone }),
    }) + tmp + exits + ::stats();
} /* stats() */

int query_decay() { return 10; }

/* Number of move points used by an attack... */
int attack_speed() { return 15; }

//This is the function to include IF you add_exit with a
//  add_action, while other players are in the same room as
// the add_action triggerer...  Piper (9/29/95)

int renew_exits()
{
    int i;
    object *olist = all_inventory(this_object());
    for(i=0;i<sizeof(olist);i++)
    {
	olist[i]->move(this_object());
    }
   reset_short_exit_string(); 
} /*renew_exits() */


//  Here lies the dig stuff... much smaller and little used
// Piper [1/26/96]

int add_dig_exit(string direc, mixed dest)
{
    mixed *m;

    m = DIG_HAND->add_dig_exit(dig_exit,dig_where,direc,dest);

    dig_exit = m[0];
    dig_where = m[1];

    return(1);
}

string *query_dig_dest() { return dig_where; }

string *query_pos_dig() { return dig_exit; }

int do_dig(string direc)
{
    object room_ob = this_object();
    DIG_HAND->do_dig(dig_exit,dig_where,room_ob,direc);

    return(1);
}
