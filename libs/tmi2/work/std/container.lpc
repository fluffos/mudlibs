// container.c
// Hacked together by Mobydick@TMI-2 on 9-29-92 from two pre-existing files.
// The first, bag_logic.c, was mostly written by Brian@TMI. The second,
// container.c, was written by Sulam@TMI. Original documentation follows:
/*
 * bag_logic.c
 * Written by Brian Nov 1991
 * Added get all from container Feb 6 1992
 *
 * This works in conjunction with my move and container to make it very easy
 * to make containers.
 *
 * set possible_to_close = 1; if you want the container to be closable.
 *
 * somewhat modifed by Truilkan@TMI - 92/04/21
 *
 * this has a query_long() that will be checked for when you call 
 * query("long").  any object inheriting std/bag_logic should not directly
 * inherit std/Object or /std/container.
 */
// Mobydick made some major changes while getting mass and bulk to work properly
// Mobydick added money functions, 10-12-92
// Mobydick cleaned out some unused variables and functions, 10-14-92.
// Watcher added prevent_get and prevent_drop aspect checks, 3-5-93.
// Watcher added vision checks and made a few bug fixes, 4-13-93.

#include <move.h>
#include <mudlib.h>
#include <money.h>

inherit OBJECT ;

string open_long_desc;
string closed_long_desc;
private nosave int possible_to_close;
private nosave int is_closed;

int receive_objects();

void create()
{
	seteuid(getuid()) ;
	set("long", "@@query_long");
}

void init()
{
   add_action("get_from","get");
   add_action("put_into","put");
   add_action("open_container","open");
   add_action("close_container","close");
}

int put_into(string str) {
	int res, num, has, mass ;
	object ths,tht,ob ;
	string this,that, word ;

	if (!str) {
		notify_fail("Put what in what?\n") ;
		return 0 ;
	}
 
	//  Check to make sure the person can see what they are doing.

	if(!this_player()->query("vision")) {
	write("Put what where?  You can't see anything!\n");
	return 1; }
 
	//  Check for the form "put 10 gold in bag".
 
	if (sscanf(str,"%d %s in %s",num,this,that)==3) {
		if(num < 1) {
		notify_fail ("You must put positive amounts of coins into things.\n") ;
		return 0 ;
		}
		tht = present(that,this_player()) ;
		if (!tht) tht = present(that,environment(this_player())) ;
		if (!tht) {
			notify_fail ("I don't see a "+that+" to put money into.\n") ;
			return 0 ;
		}
	// Is the container open?
		if (!receive_objects()) {
			notify_fail ("The container is closed.\n") ;
			return 0 ;
		}
		if (tht!=this_object()) return 0 ;
		has = this_player()->query("wealth/"+this) ;
		if (has<num) {
			notify_fail ("You don't have that many "+this+" coins.\n") ;
			return 0 ;
		}
		ob = clone_object(COINS) ;
		ob->set_type(this) ;
		ob->set_number(num) ;
		res = ob->move(tht) ;
		if (res!=MOVE_OK) {
			notify_fail ("Not enough room!\n") ;
			ob->remove() ;
			return 0 ;
		}
		this_player()->set("wealth/"+this,has-num) ;
		this_player()->set("capacity", this_player()->query("capacity") + num) ;
// Make the mass of the container go up.
		set ("mass", query("mass")+num) ;
// If the player is carrying the container, then make his capacity go down.
		if (environment(this_object())==this_player())
			this_player()->set("capacity",(int)this_player()->query("capacity")-num) ;
		if (num==1) word= "coin" ; else word="coins" ;
		write ("You put "+num+" "+this+" "+word+" in "+that+".\n") ;
		say (this_player()->query("cap_name")+" puts "+num+" "+this+" "+word+" in "+that+".\n") ;
		return 1 ;
	}
 
	//  Check for the stand "put thingy in bag" format.
 
	if(!stringp(str) || (sscanf(str, "%s in %s", this, that) != 2 &&
	   sscanf(str, "%s into %s", this, that) != 2))  return 0;
 
	ths = present(this, this_player());
 
	if(!ths) {
	write("You do not have a " + this + ".\n");
	return 1; }
 
	tht = present(that, this_player());

	if(!tht)  tht = present(that, environment(this_player()));
 
	if (ths == tht) {
	    write("You can't put " + this + " in itself.\n");
	    return 1;
	}

	if(!tht) {
	write("There is no " + that + " here.\n");
	return 1; }
 
	if(tht != this_object())  return 0;	// Keep on looking ...

	if((int)ths->query("prevent_drop")) {
	write("You can't move that object.\n");
	return 1; }
 
	if((int)ths->query("prevent_insert")) {
	write("You can't put that object inside a container.\n");
	return 1; }
 
	if(!tht->receive_objects()) {
	write("That object is closed.\n");
	return 1; }
 
		mass = ths->query("mass");
		word = ths->query("short") ;
		res = (int)ths->move(tht);
 
		if (res == MOVE_OK) {
 
// When we put the object into the container, the mass of the container has
// to go up, but the bulk does not go up.
 
		set ("mass", query("mass")+mass) ;
 
// If the player is carrying the container, his capacity has to go down.
 
		if (environment(this_object())==this_player())
		this_player()->set("capacity", 
			(int)this_player()->query("capacity") - mass);
		write("You put " + word + " in " +tht->query("short")+ ".\n");
		say((string)this_player()->query("cap_name") + " puts " +
		    word + " in " + tht->query("short") + ".\n");
		return 1; }
 
		if(res == MOVE_NO_ROOM) 
		write("There isn't enough room left to put that in.\n");
 
		else if(res == MOVE_TOO_HEAVY) 
		write("It is too heavy.\n");
 
		else if(res == MOVE_NOT_ALLOWED) 
		write("You cannot do that.\n");
 
return 1; }
 

int get_from(string str)
{
	int res, i, num, has, mass ;
	object ths, tht, *contents;
	object ob2 ;
	string this, that, word ;

	if (!str) {
		notify_fail ("Get what from what?\n") ;
		return 0 ;
	}
 
	//  Check to see if the user can see what they are doing.
 
	if(!this_player()->query("vision")) {
	write("Get what from where?  You can't see anything!\n");
	return 1; }
 
// Check for the form "get 20 gold from sack".
	if (sscanf(str,"%d %s from %s",num,this,that)==3) {
		tht = present(that,this_player()) ;
		if (!tht) tht = present(that,environment(this_player())) ;
		if (!tht) {
			notify_fail ("Put what in what frog?\n") ;
			return 0 ;
		}
 
	// Is it closed?
		if (!tht->receive_objects()) {
			notify_fail ("That container is closed.\n") ;
			return 0 ;
		}
		if((int)tht->query("prevent_get")) {
		notify_fail("You can't get that object.\n");
		return 0; }
 
		if (!tht) {
			notify_fail ("I don't see a "+that+" here.\n") ;
			return 0 ;
		}
		if (tht!=this_object()) return 0 ;
		ths = present(this,tht) ;
		if (!ths) {
			notify_fail ("There aren't any "+this+" coins in "+that+".\n") ;
			return 0 ;
		}
		if (ths->query_number()<num) {
			notify_fail ("There aren't that many "+this+" coins in "+that+".\n") ;
			return 0 ;
		}
		ob2 = clone_object(COINS) ;
		ob2->set_type(ths->query_type()) ;
		ob2->set_number(num) ;
// If the player is carrying the container, then his capacity needs to go
// up, because removing the object from the container makes the container
// lighter.
		if (environment(this_object())==this_player())
		this_player()->set("capacity", this_player()->query("capacity")+num) ;
		ob2->move(this_player()) ;
		if (res!=MOVE_OK) {
			notify_fail ("You don't feel good about doing that. Tell a wizard.\n") ;
		this_player()->set("capacity", (int)this_player()->query ("capacity")-num) ;
			return 0 ;
		}
		ths->set_number((int)ths->query_number()-num) ;
		if (num==1) word="coin" ; else word = "coins" ;
		write ("You get "+num+" "+this+" "+word+" from "+that+".\n") ;
		say (this_player()->query("cap_name")+" gets "+num+" "+this+" "+word+" from "+that+".\n") ;
// Reduce the mass of the container.
		set ("mass", query("mass")-num) ;
		set ("capacity", query("capacity")+num) ;
		return 1 ;
	}
// Check for the form "get thingy from sack".
// This may or may not be choking on money. I hope not...
	if (stringp(str) && sscanf(str,"%s from %s",this,that) == 2) {
		if (present(that,this_player()) ||
				present(that, environment(this_player()))) {
			tht = present(that);
			if (tht!=this_object()) return 0 ;
			if (tht->receive_objects()) {
			if (this != "all") {
			ths = present(this, tht);
			if (!ths) {
				notify_fail("There is no "+this+" in the "+that+".\n") ;
				return 0 ;
			}

			if((int)ths->query("prevent_get")) {
			notify_fail("You can't get that object.\n");
			return 0; }
 
			if (ths) {
				mass = ths->query("mass") ;
				word = ths->query("short") ;
// When the player removes the object, the container gets lighter, so we
// need to increase the player's capacity.
				if (environment(this_object())==this_player())
				this_player()->set("capacity",(int)this_player()->query("capacity")+mass) ;
				res = (int)ths->move(this_player());
				if (res == MOVE_OK) {
// When we get an object out of a container, the mass of the container goes
// down, but the bulk does not go down.
					set ("mass", query("mass")-mass) ;
					write ("You get "+word+" from "+
						tht->query("short")+".\n");
					say(this_player()->query("cap_name")+" gets "+
						word + " from "+tht->query("short")+".\n") ;
					return 1;
				}
			if (res == MOVE_NOT_ALLOWED) 
				notify_fail("You are not allowed to do that...\n");
			if (res == MOVE_NO_ROOM)
				notify_fail("There is not enough room to do that...\n");
// This should never happen.
			if (res == MOVE_TOO_HEAVY)
				notify_fail ("It is too heavy.\n") ;
			if (environment(this_object())==this_player())
			this_player()->set("capacity",(int)this_player()->query("capacity")-mass) ;
			return 0;
			}
			notify_fail(capitalize(this)+" is not in "+tht->query("short")+".\n");
			return 0;
			}
// If we got here, it means we're doing a "get all from container".
			contents = all_inventory(tht);
			if (sizeof(contents) > 0 ) {
				for (i=0;i<sizeof(contents);i++) {
					ths = contents[i];
 
				if((int)ths->query("prevent_get"))
					continue;
 
					mass = contents[i]->query("mass") ;
					word = contents[i]->query("short") ;
// When the object is removed from the container, if the player is holding
// the container then his capacity goes up.
					if (environment(this_object())==this_player())
					this_player()->set("capacity", (int)this_player()->query("capacity")+mass) ;
					res = (int)ths->move(this_player());
					if (res == MOVE_OK) {
// Change the mass of the container.
						set ("mass", query("mass")-mass) ;
						write ("You take "+word+" from "+tht->query("short")+".\n") ;
						say(this_player()->query("cap_name")+" gets "+
						word+" from "+tht->query("short")+".\n") ;
				}
				if (res == MOVE_NO_ROOM) {
					write("Can't carry "+ths->query("short")+".\n");
					if (environment(this_object())==this_player())
					this_player()->set("capacity", (int)this_player()->query("capacity")+mass) ;
			}
			}
			return 1;
		}
		notify_fail("Nothing in "+tht->query("short")+".\n");
		return 0;
		}
		notify_fail(capitalize(this)+" is not here.\n");
		return 0;
		}
		notify_fail(capitalize(that)+" is closed.\n");
		return 0;
	}
	return 0;
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
	mixed desc;
	if (this_object()->receive_objects()) desc = open_long_desc ; else desc = closed_long_desc ;
	if ((int)query("lock")>0) {
		desc = desc + "It is locked.\n" ;
	}
	if ((int)this_object()->receive_objects() || (int)this_object()->clear()) {
		inv = all_inventory(this_object());
		if (sizeof(inv) > 0 ) {
			desc += "It contains:\n";
			for(i=0;i<sizeof(inv);i++)
				desc += "  "+ (string)inv[i]->query("short")+"\n";
		}
	}
	return desc;
}

int open_container(string str)
{
 
	//	Check to see if the user can actually see anything.

	if(!this_player()->query("vision")) {
	notify_fail("Open what?  You can't see anything!\n");
	return 0; }
 
	if (stringp(str) && this_object()->id(str)) {
		if (this_object()->receive_objects()) write("It is already open.\n");
		else {
			if ((int)query("lock")>0) {
				write ("It's locked!\n") ;
				return 1 ;
			}
			this_object()->toggle_closed();
			write("You open "+this_object()->query("short")+".\n");
			say(this_player()->query("cap_name")+
				" opens "+this_object()->query("short")+ ".\n");
		}
		return 1;
	}
	return 0;
}

int close_container(string str)
{
	
	//	Check to see if the user can see what they are doing.
	
	if(!this_player()->query("vision")) {
	notify_fail("Close what?  You can't see anything!\n");
	return 0; }
 
	if (stringp(str) && this_object()->id(str)) {
		if (!this_object()->receive_objects()) write("It is already closed.\n");
	else if (!this_object()->toggle_closed()) write("It cannot be closed.\n");
		else {
			write("You close "+this_object()->query("short")+".\n");
			say(this_player()->query("cap_name")+" closes "+
				this_object()->query("short")+".\n");
		}
		return 1;
	}
	return 0;
}

void set_possible_to_close(int pos) {
    possible_to_close = pos;
}

int toggle_closed() {
    if (possible_to_close) {
      if (is_closed) is_closed = 0;
      else is_closed = 1;
      return 1;
    }
    else return 0;
}

int query_is_closed() {
	return is_closed ;
}


// This function is called from move()

int receive_objects() {
    if (is_closed) return 0;
    return 1;
}

/* EOF */
