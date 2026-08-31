#include <std.h>
#include <move.h>

inherit CONTAINER;

void create() {
    ::create();
    set_name("sheath");
    set("id", ({"sheath", "leather sheath"}) );
    set_short("%^BOLD%^BLACK%^Leather Sheath%^RESET%^");
    set_long("A %^GREEN%^durable%^RESET%^ %^BOLD%^BLACK%^leather sheath%^RESET%^ that ties to your upper leg.  It appears that it can accomodate any sized %^RED%^knife%^RESET%^ or %^BOLD%^RED%^dagger%^RESET%^.");
    set_max_internal_encumbrance(10);
}

void init() {
    ::init();
    add_action("sheath_into", "sheath");
    add_action("unsheath_from", "unsheath");

}

int sheath_into(string str)
{
    int res;
    object ths, tht;
    string this, that;

    if(total_light(this_player())+(int)this_player()->query_sight_bonus()<-6) {
	notify_fail("It is too dark.\n");
	return 0;
    }
    if (stringp(str) && sscanf(str,"%s into %s",this,that) == 2) {
	if (present(this,this_player())) {
	    if (present(that,this_player()) || present(that,
		environment(this_player()))) {
		ths = present(this,this_player());
		tht = present(that, this_player());
		if(ths == tht) /* Plura 930208 */
		{
		    notify_fail("Get real!\n");
		    return 0;
		}
		if(ths->is_bag() && this_object()->is_bag())
		    return notify_fail("Put a container in a container?\n");
		if(!tht) tht = present(that, environment(this_player()));
		if(ths->drop()) {
		    notify_fail("You cannot drop that!\n");
		    return 0;
		}       
		if(this_player()->query_paralyzed()) {
		    return notify_fail(this_player()->query_paralyze_message());
		}
		if(tht != this_object()) return 0;                
		if (tht->receive_objects()) {
		    res = (int)ths->move(tht);
		    if (res == MOVE_OK) {
			write("You put "+ths->query_short()+" in "+ tht->query_short()+".\n");
			say(this_player()->query_cap_name()+" puts "+ths->query_short()+" in "+tht->query_short()+".\n");
			return 1;
		    }
		    if (res == MOVE_NO_ROOM)
			notify_fail("For some reason it does not fit...\n");
		    if (res == MOVE_NOT_ALLOWED)
			notify_fail("You are not allowed to do that...\n");
		    return 0;
		}
		notify_fail("You are unable to do that.\n");
		return 0;
	    }
	    notify_fail(capitalize(that)+" is not here.\n");
	    return 0;
	}
	notify_fail("You are not carrying "+this+".\n");
	return 0;
    }
    return 0;
}

int unsheath_from(string str) {
    int res, i;
    object ob, tmp, *inv;
    string what, where;
    if(!stringp(str)) return 0;
    if(this_player()->query_ghost()) {
	write("You cannot do that as a ghost.");
	return 1;
    }
    if(total_light(this_player())+(int)this_player()->query_sight_bonus()<-1) {
	notify_fail("It is too dark.\n");
	return 0;
    }
    if(sscanf(str, "%s from %s", what, where) != 2) return 0;
    if(id(where)) tmp = this_object();
    else tmp = parse_objects(environment(this_object()), where);
    if(tmp != this_object()) return 0;
    if(this_object()->receive_objects()) {
	if(what != "all") {
	    ob = present(what, this_object());
	    if(!ob) ob = parse_objects(this_object(), what);
	    if(!ob) {
		write("There is no "+what+" in "+this_object()->query_short()+".");
		return 1;
	    }
	    res = (int)ob->move(this_player());
	    if(res == MOVE_OK) {

		write("You get "+ob->query_short()+" from "+this_object()->query_short()+".");

		say(this_player()->query_cap_name()+" gets "+ob->query_short()+" from "+this_object()->query_short()+".", this_player());
		return 1;
	    }
	    if(res == MOVE_NOT_ALLOWED) write("You can't do that!");
	    if(res == MOVE_NO_ROOM) write("You can't carry that!");
	    return 1;
	}
	inv = all_inventory(this_object());
	if(!sizeof(inv)) {
	    write("There is nothing in "+this_object()->query_short()+".");
	    return 1;
	}
	for(i=0; i<sizeof(inv); i++) {
	    res = (int)inv[i]->move(this_player());
	    if(res == MOVE_OK) {
		write("You get "+inv[i]->query_short()+" from "+this_object()->query_short()+".");
		say(this_player()->query_cap_name()+" gets "+inv[i]->query_short()+" from "+this_object()->query_short()+".", this_player());
	    }
	    if(res == MOVE_NO_ROOM) write(inv[i]->query_short()+": Too heavy.\n");
	}
	return 1;
    }
    write(query_short()+" is closed.");
    return 1;
}

string query_long()
{
    object *inv;
    int i;
    int per;
    string desc;
    string *key=({});
    desc = container::query_long(0);

    if ((int)this_object()->receive_objects() || (int)this_object()->clear()) {
	inv = all_inventory(this_object());

	if (sizeof(inv) > 0 ) {
	    i = sizeof(inv);
	    for(i=0; i<sizeof(inv); i++)
		key += ({ inv[i]->query_short() });
	    key = consolidate_string( key );
	    desc += "  It contains:\n";
	    for(i=0;i<sizeof(key);i++)
		desc += " "+capitalize((string)key[i]);
	}

	per = to_int(percent(this_object()->query_internal_encumbrance(),
	    this_object()->query_max_internal_encumbrance()));
	if (per == 0) {
	    desc += "\nThe sheath is %^BOLD%^BLUE%^empty%^RESET%^.";
	}
	else {
	    desc += "\nThe sheath is %^BOLD%^GREEN%^full%^RESET%^.";
	}
	return desc;
    }
}       

int query_auto_load() {
    if (this_player()->query_name() == "beleqwaya") return 1;
}
