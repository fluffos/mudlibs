#include "../priest.h"
#include <guild.h>
#include <std/container.h>

int chest_is_open;

void
create_container()
{
    set_name("chest");
    set_long("An old oak chest mounted on the floor.");
    set_value(0);
    set_max_weight(1000);
    set_weight(0);
    chest_is_open = 0;
}

varargs string
query_long(string s, object who)
{
    string tmp, *keys;
    int i, *n;
    object *things;
    mapping potions;

    tmp = ::query_long();
    if(!chest_is_open) return tmp + "\nIt is closed.";
    call_out("my_open_chest",1);
    chest_is_open = 0;


    potions = ([]);
    things = all_inventory();
    if(sizeof(things)>0)
	tmp += "\nIt contains:";
    else {
	return tmp + "\nIt is open.";
    }
    for(i=sizeof(things);--i>=0;) {
	potions[things[i]->query_short()]++;
    }
    keys = m_indices(potions);
    n = m_values(potions);
    for(i=sizeof(potions); --i>=0;) {
	tmp += sprintf("\n%s: %d pcs", keys[i], n[i]);
    }
    return tmp;
}

status can_put_and_get(string s) { return chest_is_open; }

void my_open_chest() { chest_is_open = 1; }

status
close_cmd(string str)
{
    if (!chest_is_open) this_player() -> tell_me("It's already closed.");
    else {
	chest_is_open = 0;
	this_player() -> tell_me("Ok.");
    }
    return 1;
}

status
open_cmd(string str)
{
    if (chest_is_open) this_player() -> tell_me("It's already open.");
    else {
	if(this_player()->query_guild() != GN_PRIEST)
	    return notify_fail("You don't seem to be able to open the \
chest.\n"),0;
	chest_is_open = 1;
	this_player() -> tell_me("Ok.");
    }
    return 1;
}

status
refuse_item(object item, object pl) {
    if(!item->is_priest_bottle()) {
	pl->tell_me("You don't want to put that in the chest, it is meant \
only for potions, distillations and empty sample bottles.");
	return 1;
    }
    if(!item->is_property_of_hob()) {
	item->set_hob();
	CASH_D->from_shop((item->query_value()*2)/9+1);
    }
    return 0;
}

status get() { return 0; }
