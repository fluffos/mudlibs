#include <room.h>
#include "locker_defs.h"

int booted;

void
set_booted()
{
    booted = (time() - query_uptime());
    return;
}

int
query_booted()
{
    return booted;
}

void
create_room()
{
    object ob;

    set_light_level(LT_LIGHTS);
    set_outdoors(WD_NONE);
    set(NO_PK);
    set_short("Basement vault");
    set_long("A chilly underground room with a desk at the bottom of \
the stairs and hundreds of lockers along the wallsides. There's \
an important looking plaque on one wall.");
    add_item("lockers","There are awfully many of them.");
    add_item("desk","It's the officer's desk.");
    add_item("plaque","Perhaps you should read it.");
    add_monster(L_DIR+"officer","Officer arrives",1);
    add_exit("up", L_EXITLOCATION);
    if(!find_object(L_EXITLOCATION))
	call_other(L_EXITLOCATION, "???");
    if(!present("staircase",(ob=find_object(L_EXITLOCATION))))
	move_object(L_DIR+"staircase", ob);

    call_out("set_booted",2);
    return;
}

void
init_room()
{
    add_action("buyLocker","buy");
    add_action("retrieveLocker","retrieve");
    add_action("readPlaque","read");
    return;
}

status
buyLocker(string str)
{
    string n;
    int cost, size;
    object locker, tp;

    if(!present("officer"))
	return notify_fail("The officer is not here.\n"),0;
    if(present(this_player()->query_real_name()+"_locker"))
	return notify_fail("You already have a locker.\n"),0;
    if(!str || !sscanf(str,"locker %d",size))
	return notify_fail("Usage: buy locker <size>\n"),0;
    if(size < 1 || size > L_MAXSIZE)
	return notify_fail("Illegal locker size, must be 1.."+
	  L_MAXSIZE+".\n"),0;
    locker = clone_object(L_DIR+"locker");
    n = (string)(tp=this_player())->query_real_name();
    if(locker->configureLocker(n, size)) {
	destruct(locker);
	return notify_fail("You already have a locker.\n"),0;
    }
    cost = L_BASECOST+(size-1)*L_COSTPERUNIT;
    if((int)tp->query_money() < cost)
	return notify_fail("You don't have enough money.\n"),0;
    tp->add_money(-cost);
    tp->tell_me("You buy a locker. \
Remember to 'return' it before leaving.");
    tell_here(tp->query_name()+" buys a locker.", tp);
    move_object(locker, this_object());
    write_file(L_DIR+L_BUYLOG, ctime(time())+", "+n+", "+size+"\n");
    return 1;
}

status
retrieveLocker(string str)
{
    object locker;
    string owner;
    int cost, tmp;

    if(!present("officer"))
	return notify_fail("The officer is not here.\n"),0;
    owner = (string)this_player()->query_real_name();
    if(present(owner+"_locker"))
	return notify_fail("You've already done that.\n"),0;
    locker = clone_object(L_DIR+"locker");
    if(!locker->configureLocker(owner)) {
	destruct(locker);
	return notify_fail("You don't have a locker.\n"),0;
    }
    cost = (int)locker->query_totalvalue();
    if(cost && (tmp=(int)locker->query_lastaccess()) && tmp < booted) {
	if(str && str == "items") {
	    if((int)this_player()->query_money() < cost) {
		destruct(locker);
		return notify_fail("You don't have enough money.\n"),0;
	    }
	    this_player()->add_money(-cost);
	} else if(str && str == "empty") {
	    locker->cleanLocker();
	} else {
	    this_player()->tell_me("It would cost you "+cost+" gc to retrieve \
your items. To do this, do 'retrieve items'. If you don't want to pay, \
do 'retrieve empty'.");
	    destruct(locker);
	    return 1;
	}
    } else if(str && str=="empty")
	locker->cleanLocker();
    move_object(locker, this_object());
    this_player()->tell_me("Retrieved your locker. \
Remember to 'return' it before leaving.");
    return 1;
}

status
readPlaque(string str)
{
    if(!str || str != "plaque")
	return 0;
    this_player()->tell_me("New lockers: "+L_BASECOST+" + ("+
      L_COSTPERUNIT+" * (size - 1)) gc\n\t-> buy locker <size> \
(max size "+L_MAXSIZE+")\nExisting lockers:\n\t\
-> retrieve [items|empty]\n\t\
-> insert <[*]item> into locker (see note)\n\t\
-> fetch <item|num|all> from locker\n\t\
-> return (don't forget this)\n\t\
-> giveup (you will LOSE YOUR LOCKER)\n\
Upgrading: "+L_UPBASECOST+" + ("+L_COSTPERUNIT+" * (size - current size - 1)) \
gc\n\t-> upgrade <size>\n\n\
NOTE: Use the leading '*' if you want to store an exquisite item.\n\n");
    return 1;
}
