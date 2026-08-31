#include <std.h>
#include <amun.h>
#include <move.h>
// Added move.h for error defines, specifically MOVE_OK.
// shouldn't need #include <security.h> for anything

inherit ARMOUR;

// Need this for move() to work, apparently.
inherit CONTAINER;

#define LONG_DESC "%^BOLD%^%^WHITE%^The %^BLUE%^Belt of %^YELLOW%^C%^BLACK%^a%^YELLOW%^ndles %^WHITE%^is made from a soft, wax that is abnormally strong, but somehow flexible. There are many %^YELLOW%^golden stars%^WHITE%^, that are placed around the belt, that are used used to magically hold waxes.%^RESET%^"

mapping waxes;

void add_wax(object wax);
void remove_wax(object wax);

void create() {
    ::create();
    set_id( ({ "belt", "belt of candles", "candles" }) );
    set_name("belt of candles");
    set_short("%^BOLD%^%^BLUE%^Belt of %^YELLOW%^C%^BLACK%^a%^YELLOW%^ndles%^RESET%^");
    set_long(LONG_DESC);
    set_type("belt");
    set_limbs( ({ "torso" }) );
    set_ac(2);
    set_max_internal_encumbrance(20); // should allow 5 waxes; they weigh 4 each
    // making the value a bit more random. Should be
    // 9,500-10,500 now, instead of the 10,000-10,024 that it was
    set_curr_value("gold", 9500+random(1001));
    // On create, waxes will *ALWAYS* be 0, thus it will always return true
    // and make a new mapping. create_waxes() will never get called here.
    // create() is done before init_args() is.
    /*
    if(!waxes)
	waxes = ([ ]);
    else
	   create_waxes();
	*/

    waxes = ([]);
}

void init() {
    ::init();
    add_action("put_in", "put");
    add_action("get_out", "get");
}

int put_in(string str) {
    string thing, bag;
    object ob;

    if(stringp(str) && sscanf(str,"%s in %s", thing, bag) != 2)
	return notify_fail("Put what where?");
    if(present(bag, this_player()) != this_object())
	return notify_fail("Put what where?");
    // Just adding () around all of the ob = blah to make sure the !
    // doesn't apply until after the = has been done.
    if( !(ob = present(thing, this_player())) )
	return notify_fail("Put what where?");
    // The name on them is actually "ball of wax", at least
    // on the player port.
    if(ob->query_name() != "ball of wax")
	return notify_fail("The belt can only be used to hold waxes.\n");
    // Nesoo notes: Great job on the above. Now to move it. Can't rely
    // on put_into(), as that's a bag specific function, so...
    if( ob->move(this_object()) == MOVE_OK )
    {
	write("You put " + thing + " in your " + query_short() + ".");
	say(this_player()->query_cap_name() + " puts " + ob->query_short() +
	  " in " + this_player()->query_possessive() + " " +
	  query_short() + ".");
	add_wax(ob);
    }
    else
    {
	return notify_fail("It won't fit!\n");
    }
    return 1;

}

int get_out(string str) {
    object old_wax;
    string thing, where;

    if(sscanf(str, "%s from %s", thing, where) != 2)
	return notify_fail("Get what from where?");
    if(present(where, this_player()) != this_object())
	return notify_fail("Get what from where?");
    if(!(old_wax = present(thing, this_object())))
	return notify_fail("There is no "+thing+" in your Belt of Candles.\n");
    if( old_wax->move(this_player()) == MOVE_OK )
    {
	write("You get " + old_wax->query_short() + " from " +
	  this_object()->query_short() + ".");
	say(this_player()->query_cap_name() + " puts " + old_wax->query_short()
	  + " in " + this_player()->query_possessive() + " " +
	  query_short() + ".");
	remove_wax(old_wax);
    }
    else
    {
	return notify_fail("You don't have enough room for that!\n");
    }
    return 1;
}

void add_wax(object wax) {
    // Long story short, we want to store the properties of the wax but
    // query_props() doesn't exist. You can get the values the wax needs
    // using... query_auto_load().
    waxes[file_name(wax)] = wax->query_auto_load() ;
}

// This should be good as is
void remove_wax(object wax) {
    map_delete(waxes, file_name(wax));
}

// Renamed create_waxes() to void init_arg(mixed *stuff)
// To simplify things, basically this function is called when a player
// returns to the game... It passes whatever query_auto_load() returns to it.
void init_arg(mixed stuff) {
    int i;
    object tmp;
    string *_keys;

    // Stop if stuff is not a mapping.
    if( !mapp(stuff) )
	return;

    // Going to work right out of stuff, and build up a new waxes mapping.
    _keys = keys(stuff);
    i = sizeof(_keys);

    // file_name() will return different values now, so we can't just do
    // waxes = stuff. So, go thru stuff, make a new wax, and add it to waxes
    while(i--) {
	if( !(tmp = new("/d/nopk/tirun/obj/misc/seal_blank")) )
	    continue;

	tmp->init_arg((stuff[_keys[i]])[1]);
	// Only adding it to waxes if the move worked.
	if( tmp->move(this_object()) == MOVE_OK)
	    waxes[file_name(tmp)] = tmp->query_auto_load();
	else
	    tmp->remove();
	// I'm not sure that this_player() or write() work at this stage. If
	// they do, you could also do an error message if the move() failed.
    }
}

string query_long() {
    // Not sure what this is about, as it's exactly the same as above...
    /*
    if (this_player()->query_level() >= 10)
	   return "%^BOLD%^%^WHITE%^The %^BLUE%^Belt of %^YELLOW%^C%^BLACK%^a%^YELLOW%^ndles %^WHITE%^is made from a soft, wax that is abnormally strong, but somehow flexible. There are many %^YELLOW%^golden stars%^WHITE%^, that are placed around the belt, that are used used to magically hold waxes.%^RESET%^";
    else
	   return ::query_long();
	*/
    string str = LONG_DESC + "\nIt contains:\n";
    string *key = ({});
    // Gets all the items inside this one.
    object *obs = all_inventory(this_object());
    int i;

    // Note that we don't want to do the i = sizeof(), while(i--) thing here,
    // as we want them in the correct order, not backwards
    for( i = 0; i < sizeof(obs); i++ )
    {
	key += ({ (obs[i]->query_short()) });
    }

    // This will take 5 different "ball of wax" entries and turn it into
    // "five balls of wax"
    key = consolidate_string(key);

    // Now lets capitalize them all
    i = sizeof(key);
    while( i-- )
    {
	key[i] = capitalize(key[i]);
    }

    // implode() will put the "\n" in between everything in key
    return str + implode(key, "\n");

}

mixed query_auto_load() {
    if (this_player()->query_level() >= 10)
	return ({ base_name(this_object()), waxes });
}
