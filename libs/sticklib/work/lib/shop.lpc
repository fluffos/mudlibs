/****************************************************************
*								*
* Module:							*
*	/lib/shop.c						*
* Description:							*
*	The standard shop that should always be used when	*
*	building other generic shops. There are specialized	*
*	base rooms to be used for some special shops ('food	*
*	shops'). Use the one appropriate for your shop;		*
*	inherit the base room object and configure it.		*
* Version:							*
*	1.0a (for StickLib), Aug-98.				*
* Last update:							*
*	25-Aug-98 by Doomdark					*
*								'
* Modifications:						*
*								*
****************************************************************/


#include <room.h>

#include <generic_items.h>

#define	SHOP_RESET_USED	1
#define	SHOP_INIT_USED	2

mixed Store; /* string or object */
private int shop_functions_used;	// Used std-functions.

void
init_room()
{
    if (shop_functions_used & SHOP_INIT_USED)
	this_object()->init_shop();
}

void
reset_room()
{
    if (shop_functions_used & SHOP_RESET_USED)
	this_object()->reset_shop();
}

void
create_room()
{
#ifdef UIDS
    seteuid(getuid());
#endif
    set_light_level(LT_LIGHTS);
    set_outdoors(WD_INDOORS);
    set(NO_CLEANUP);
    set_short("Shop");
    set_long(
      "You are in a shop. You can buy and sell things here. There is a plaque on\
 the wall."
    );
    this_object()->create_shop();
    add_item("plaque", "Small bronze plaque. It contains some writing.");
    add_item("writing","Try reading it.");

    add_command("i",    "inventory_cmd");
    add_command("read", "read_cmd");
    add_command("list", "cmd");
    add_command("buy",  "cmd");
    add_command("sell", "cmd");
    add_command("value","cmd");    

    add_object(GENERIC_TRASHCAN,
      "Shopkeeper says: Oh, I forgot to put this out.",1);

    shop_functions_used = 0;
    if (function_exists("reset_shop"))
	shop_functions_used |= SHOP_RESET_USED;
    if (function_exists("init_shop"))
	shop_functions_used |= SHOP_INIT_USED;
}

/* Redefine when needed */
int
shop_open()
{
    return 1; /* Default: always open */
}

int
inventory_cmd(string str)
{
    object ob, *keeped;
    string name, text;
    int value, i;

    if (!shop_open()) return 0;

    if (str)
	ob = present(str, this_player());

    if (!(keeped = (object *) this_player()->query_keep_items()))
	keeped = ({ });

    ob = first_inventory( (ob ? ob : this_player()) );
    text = "Value\tItem";
    while(ob) {
	i = (member(keeped, ob) >= 0);
	if (name = (string)ob->short()) {
	    value = (int)Store->count_value(ob);
	    name += ".";
	    if (!value) {
		if (i) text = sprintf("%s\n\t%-32s (keeping)", text, name);
		else text = sprintf("%s\n\t%s", text, name);
	    } else {
		if (i) text = sprintf("%s\n%5d\t%-32s (keeping)", text, value, name);
		else text = sprintf("%s\n%5d\t%s", text, value, name);
	    }
	}
	ob = next_inventory(ob);
    }
    this_player()->tell_me(text);
    return 1;
}


int
cmd(string item)
{
    if(!shop_open()){
	return notify_fail("Shop doesn't seem to be open.\n"), 0;
    }

    return (int)call_other(Store, query_verb()+"_item",item);
}


int
read_cmd(string arg)
{
    if (arg == "plaque" || arg == "writing") {
	this_player()->tell_me(
	  "There are following commands:\n\
\ti [container]            -  show values of items\n\
\tlist [what]              -  list items [called what]. 'list weapons'\n\
\t                            and 'list armours' are special cases\n\
\tsell <what>              -  sell items you are carrying\n\
\tsell <what> from <where> -  sell items from a container\n\
\tbuy <what>               -  buy an item\n\
\tvalue <what>             -  what price you would get from selling\n\n\
Some examples:\n\
\t'i bag', 'list amulets', 'sell all from bag',\n\
\t'sell bottle 2 from bag','buy short sword', 'value rope'"
	);
	return 1;
    }
}

void set_store(mixed st) { if(!Store) Store = st; }
