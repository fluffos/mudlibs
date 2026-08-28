//	/std/bag_logic.c
//	from the Nightmare mudlib
//	an inheritable container object
//	based on the broken bag_logic.c created by Brian November 1991
//	written by Descartes of Borg 04 October 1992
//	lockable functions added 21 October 1992 by Descartes

#include <std.h>
#include <move.h>
#include <daemons.h>
#include <dirs.h>

inherit CONTAINER;

string open_long_desc;
string closed_long_desc;
mapping lock_data;
nosave int disarm_flag;

void toggle_lock();
void disarm_trap();
void rearm_trap();

void init()
{
   add_action("get_from","get");
   add_action("put_into","put");
   add_action("open_container","open");
   add_action("close_container","close");
   add_action("unlock_container", "unlock");
   add_action("lock_container", "lock");
}

void set_trap_func(string what, string func) {
  if(!lock_data) lock_data = ([]);
  lock_data["trap func"] = func;
  lock_data["trap ob"] = what;
}

void set_trap_arg(mixed what) { 
  if(!lock_data) lock_data = ([]);
  lock_data["trap arg"] = what;
}

int query_trap_level() {
  if(!lock_data || !lock_data["trap level"]) return 0;
  if(disarm_flag) return 0;
  else
    return lock_data["trap level"];
}

string query_key() {
  if(!lock_data || !lock_data["key"]) return 0;
  return lock_data["key"];
}

void set_lock_level(int lev) {
  if(!lock_data) lock_data = ([]);
  lock_data["lock level"] = lev;
}

int query_lock_level() {
  if(!lock_data || !lock_data["lock level"]) return 5;
  else if(!this_object()->query_property("enchantment"))
    return lock_data["lock level"];
  else
    return (int)this_object()->query_property("enchantment") +
            lock_data["lock level"];
}

void spring_trap(object who) {
    if(!who) who = this_player();
    if(!lock_data || !lock_data["trap func"]) return;
    if(!lock_data["trap arg"]) call_other(lock_data["trap ob"], lock_data["trap func"],
                                          who);
    else call_other(lock_data["trap ob"], lock_data["trap func"], who, lock_data["trap arg"]);
    return;
}

void set_trap_level(int lev) {
  if(!lock_data) lock_data = ([]);
  lock_data["trap level"] = lev;
}

void disarm_trap() { disarm_flag = 1; }

void rearm_trap() { disarm_flag = 0; }


int put_into(string str)
{
	int res;
	object ths,tht;
	string this, that;

    if(total_light(this_player())+(int)this_player()->query_sight_bonus()<-1) {
	notify_fail("It is too dark.\n");
	return 0;
    }
	if (stringp(str) && sscanf(str,"%s in %s",this,that) == 2) {
		if (ths=present(this,this_player())) {
		  tht = present(that, this_player());
		  if(!tht) tht = present(that, environment(this_player()));
			if (tht && tht == this_object()) {
                        if(ths == tht) /* Plura 930208 */
                        {
                           notify_fail("Whoa...that's pretty zen!\n");
                           return 0;
                        }
                        if(ths->drop()) {
                        notify_fail("You cannot drop that!\n");
                            return 0;
                        }
			if (tht->receive_objects()) {
				res = (int)ths->move(tht);
				if (res == MOVE_OK) {
					write("You put "+ths->query_short()+" in "+
						tht->query_short()+".\n");
					say(this_player()->query_cap_name()+" puts "
						+ths->query_short()+ " in "+tht->query_short()+".\n");
					return 1;
				}
				if (res == MOVE_NO_ROOM) 
					notify_fail("For some reason it does not fit...\n");
				if (res == MOVE_NOT_ALLOWED)
					notify_fail("You are not allowed to do that...\n");
				return 0;
			}
			write("It is locked");
			return 1;
			}
			notify_fail(capitalize(that)+" is not here.\n");
			return 0;
		}
		notify_fail("You are not carrying "+this+".\n");
		return 0;
	}
	return 0;
}

int get_from(string str) {

    int res, i;
    object ob, tmp, *inv;
    string what, where;

    if(!stringp(str)) return 0;
    if(this_player()->query_ghost()) return 0;
    if(total_light(this_player())+(int)this_player()->query_sight_bonus()<-1) {
	notify_fail("It is too dark.\n");
	return 0;
    }
    if(sscanf(str, "%s from %s", what, where) != 2) return notify_fail("Get what from what?\n");
    tmp = present(where, this_player());
    if(!tmp)
      tmp = present(where, environment(this_player()));
    if(!tmp || tmp != this_object()) return notify_fail("Can't find '"+where+"' here.\n");
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


void set_closed_long(string str)
{
	closed_long_desc = str;
}

void set_open_long(string str)
{
	open_long_desc = str;
}

string query_long(string str)
{
	object *inv;
	int i;
	string desc;

desc = container::query("long");
	if ((int)this_object()->receive_objects() || (int)this_object()->clear()) {
		inv = all_inventory(this_object());
		if (sizeof(inv) > 0 ) {
			desc += "  It contains:\n";
			for(i=0;i<sizeof(inv);i++)
				desc += "  "+ (string)inv[i]->query_short()+"\n";
		}
	}
	return desc;
}

string query_short() {
  if(is_closed) return ::query_short() + " (closed)";
  else return ::query_short() + " (open)";
}

int open_container(string str)
{
	if (stringp(str) && this_object() == present(str, environment())) {
		if(lock_data) {
		    if(lock_data["status"] == "locked") {
			write("It is locked.");
			return 1;
		    }
		}
		if (this_object()->receive_objects()) write("It is already open.");
		else {
			if (open_long_desc)
				set_long(open_long_desc);
			this_object()->toggle_closed();
			write("You open "+this_object()->query_short()+".");
			say(this_player()->query_cap_name()+
				" opens "+this_object()->query_short()+ ".");
		}
		return 1;
	}
	return 0;
}

int close_container(string str)
{
  int res;
  string err;
  
	if (stringp(str) && this_object() == present(str, environment())) {
		if (!this_object()->receive_objects()) write("It is already closed.");
  else if(err=catch(res=this_object()->toggle_closed())) {
    if(this_object()->query_is_locker()) {
      write("An error has occurred while closing this locker."+
      "\nReport this message to an arch IMMEDIATELY:\n"+err);
    }
  }
	else if (!res) write("It cannot be closed.");
		else {
			if (closed_long_desc)
				set_long(closed_long_desc);
			write("You close "+this_object()->query_short()+".");
			say(this_player()->query_cap_name()+" closes "+
				this_object()->query_short()+".");
		}
		return 1;
	}
	return 0;
}

int lock_container(string str) {
    if(!str) {
	notify_fail("Lock what?\n");
	return 0;
    }
    if(this_object() != present(str, environment(this_player()))) {
      if(present(str, this_player()))
        notify_fail("You must drop the chest to lock it.\n");
      else notify_fail("There is no '"+str+"' here.\n");
	return 0;
    }
    if(!lock_data) {
	notify_fail("You can't lock that!\n");
	return 0;
    }
    if(this_object()->receive_objects()) {
	notify_fail("It must be closed before you can lock it.\n");
	return 0;
    }
    if(lock_data["status"] == "locked") {
	notify_fail("It is already locked!\n");
	return 0;
    }
    if(lock_data["key"] && present(lock_data["key"], this_player())) {
	write("You lock the "+str+".\n");
	say(this_player()->query_cap_name()+" locks the "+str+".\n");
	toggle_lock();
	rearm_trap();
    if(this_object()->query_is_locker()) {
      SAVE_ITEMS_D->update_lockers(environment(this_object()));
     }
	return 1;
    }
    else if(!lock_data["key"]) {
	write("You lock the "+str+".\n");
	say(this_player()->query_cap_name()+" locks the "+str+".\n");
	toggle_lock();
	rearm_trap();
    if(this_object()->query_is_locker()) {
      SAVE_ITEMS_D->update_lockers(environment(this_object()));
     }
	return 1;
    }
    else {
	notify_fail("Lock the "+str+" with what?\n");
	return 0;
    }
}

int unlock_container(string str) {
    if(!str) {
	notify_fail("Unlock what?\n");
	return 0;
    }
    if(this_object() != present(str, environment())) {
	return 0;
    }
    if(!lock_data) {
	notify_fail("It does not have a lock.\n");
	return 0;
    }
    if(lock_data["status"] != "locked") {
	notify_fail("It is not locked.\n");
	return 0;
    }
    if(!lock_data["key"]) {
	write("You unlock the "+str+".\n");
	say(this_player()->query_cap_name()+" unlocks the "+str+".\n", this_player());
	toggle_lock();
	return 1;
    }
    if(!present(lock_data["key"], this_player())) {
	notify_fail("Unlock the "+str+" with what?\n");
	return 0;
    }
    write("You unlock the "+str+".\n");
    say(this_player()->query_cap_name()+" unlocks the "+str+".\n", this_player());
    toggle_lock();
    return 1;
}

void toggle_lock() {
    if(!lock_data) return;
    if(lock_data["status"] == "locked") lock_data["status"] = "unlocked";
    else lock_data["status"] = "locked";
    disarm_flag = 0;
}

int query_locked() {
    if(!lock_data) return 0;
    if(lock_data["status"] == "locked") return 1;
    else return 0;
}

int pick_lock(object who) {


    if(!who) who = this_player();
    if(!lock_data) return 0;
    if(!disarm_flag && lock_data["trap func"] && 
       lock_data["trap ob"]) {
      message("info", "%^RED%^%^BOLD%^There is a trap on the lock!%^RESET%^",
              who);
      message("info", "%^RED%^"+who->query_cap_name()+
              " springs a trap on "+
              lower_case(this_object()->query_short())+"!",
              environment(who), ({ who }) );
      if(!lock_data["trap arg"]) call_other(lock_data["trap ob"], lock_data["trap func"],
                                            who);
      else call_other(lock_data["trap ob"], lock_data["trap func"], who, lock_data["trap arg"]);
    }
    toggle_lock();
    return 1;
}

void set_lock(string stat) {
    if(stat != "locked" && stat != "unlocked") {
	if(!lock_data) lock_data = ([ "status": "locked" ]);
	else lock_data["status"] = "locked";
	return;
    }
    if(!lock_data) lock_data = ([ "status": stat ]);
    else lock_data["status"] = stat;
}

void set_key(string str) {
    if(!lock_data) lock_data = ([]);
    lock_data["key"] = str;
}

int is_bag() { return 1; }
