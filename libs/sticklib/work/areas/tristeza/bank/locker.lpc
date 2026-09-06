#include <armour_defs.h>
#include <conditions.h>

#include "locker_defs.h"

#define IND_OBNAME 0
#define IND_OBDESC 1
#define IND_OBFNAME 2
#define IND_OBVARS 3

inherit "/basic/id";

status moveItem(int ind);
string itemsInLocker();

string owner;
int purchased;
int lastaccess;
int totalvalue;
int spaceAvail;
int spaceUsed;
mixed *itemData;

void
create()
{
    set_name("locker");
    set_short("A locker");
    return;
}

string
query_long()
{
    string s;

    s = "It's a locker for storing items.";
    if((string)this_player()->query_real_name() == owner)
	s += "\n"+itemsInLocker();
    return s;
}

varargs status
configureLocker(string o, int a)
{
    set_id(({"locker",o+"_locker"}));
    if(!restore_object(L_SAVEDIR+o)) {
	owner = o;
	if(a)
	    spaceAvail = a;
	itemData = ({});
	purchased = time();
	totalvalue = 0;
	return 0;	/* created a new locker */
    }
    return 1;	/* restored an old locker */
}

void
init()
{
    if((string)this_player()->query_real_name() == owner) {
	add_action("insertIntoLocker","insert");
	add_action("fetchFromLocker","fetch");
	add_action("returnLocker","return");
	add_action("giveupLocker","giveup");
	add_action("upgradeLocker","upgrade");
	/*
	      add_action("sellLocker","sell");
	*/
    }
    return;
}

status
insertIntoLocker(string str)
{
    object ob;
    string item, obDesc, obFileName, obName;
    mapping obVars;
    int c, tmp, u_conf;

    if(spaceUsed == spaceAvail)
	return notify_fail("The locker is full.\n"),0;
    if(!sscanf(str,"%s into locker",item))
	return notify_fail("Usage: insert <item> into locker\n"),0;
    if(item[0] == '*') {
	u_conf = 1;
	item = item[1..<0]; // extract(item, 1);
    }
    if(!(ob=present(item,this_player())))
	return notify_fail("You don't seem to have a \""+item+"\".\n"),0;
    if(!ob->is_weapon() && !ob->is_armour())
	return notify_fail("Only weapons and armours allowed atm.\n"),0;
    if(ob->drop())
	return notify_fail("That's not a valid item.\n"),0;
    if (ob->is_used())
	return notify_fail(
	  "You are using it; remove it first.\n"), 0;
    if(sscanf(object_name(ob), "%s#%d", obFileName, tmp) < 2)
	return notify_fail("That's not a valid item.\n"),0;

    if(ob->query_unique()) {
	if(!u_conf)
	    return notify_fail("Officer says: You might want to think twice \
before storing such a\nfine item here.\n"),0;
	else
	    this_player()->tell_me("Officer says: Very well, but note that \
you won't get it back in that good a condition.");
    }

    obName = lower_case((string)ob->query_name());
    if(!(obDesc = (string)ob->query_short()))
	if(!(obDesc = (string)ob->short()))
	    if(!(obDesc = obName))
		return notify_fail("That's not a valid item.\n"),0;
    obVars = (mapping)ob->save_variables();
    itemData += ({({obName, obDesc, obFileName, obVars})});
    spaceUsed++;
    c = L_RETVALUE_X*((int)ob->query_value());
    if(c > L_RETMAXVALUE)
	c = L_RETMAXVALUE;
    totalvalue += c;
    this_player()->add_weight(-((int)ob->query_weight()));
    this_player()->tell_me("You insert the "+obName+" into the locker.\n\
It adds "+c+" gc to the total.");
    destruct(ob);
    return 1;
}

status
fetchFromLocker(string str)
{
    string obName;
    int ind, tmp;

    if(!str)
	return notify_fail("Usage: fetch <num|item|all> from locker\n"),0;
    if(!sscanf(str, "%d from locker", ind))
	if(!sscanf(str, "%s from locker", obName))
	    return notify_fail("Usage: fetch <num|item> from locker\n"),0;
    if((!ind || ind > spaceUsed) && !obName)
	return notify_fail("No such item in the locker.\n"),0;
    if(obName) {
	obName = lower_case(obName);
	if(obName == "all") {
	    int i;
	    return notify_fail("Fetch all is disabled for now.\n"),0;
	    tmp = spaceUsed;
	    i = 0;
	    while(ind < tmp) {
		if(!moveItem(i))
		    i++;
		ind++;
	    }
	    save_object(L_SAVEDIR+owner);
	    return 1;
	} else {
	    while(ind < spaceUsed) {
		if(itemData[ind][IND_OBNAME] == obName)
		    break;
		ind++;
	    }
	    if(ind == spaceUsed)
		return notify_fail("No such item in the locker.\n"),0;
	}
    } else
	ind--;
    moveItem(ind);
    save_object(L_SAVEDIR+owner);
    return 1;
}

status
moveItem(int ind)
{
    object ob;
    string err, s;
    int c;


    UNIQUE_D->lock_unique(1); /* prevent from creating a unique item */
    err = catch(ob = clone_object(itemData[ind][IND_OBFNAME]));
    UNIQUE_D->lock_unique(0); /* release */

    if(err) {
	write_file(L_DIR+L_ERRLOG,"Fetch#"+owner+"#"+
	  itemData[ind][IND_OBFNAME]+":\n"+err);
	this_player()->tell_me("Error in cloning \""+itemData[ind][IND_OBNAME]+
	  "\". Item is either unique or buggy. To clean your locker do 'return' and \
'retrieve empty' (take out other items first).");
	return 0;
    }

    if(!ob->query_unique(1))
	ob->restore_variables(itemData[ind][IND_OBVARS]);
    c = L_RETVALUE_X*itemData[ind][IND_OBVARS]["value"];
    if(c > L_RETMAXVALUE)
	c = L_RETMAXVALUE;
    totalvalue -= c;
    if(totalvalue < 0)
	totalvalue = 0;
    itemData -= ({itemData[ind]});
    spaceUsed--;
    if(!this_player()->add_weight((int)ob->query_weight())) {
	s = "You couldn't carry it.";
	move_object(ob, environment(this_player()));
    } else {
	s = "Ok.";
	move_object(ob, this_player());
    }

    // Okay, let's fix those old silver rings:
    if(ob->id("free action") && ob->id("silver")) { //let's make sure
	ob->add_special_property(ARM_SP_RESIST_CONDITION, C_UNCONSCIOUS, 0);
    }

    this_player()->tell_me(s+"\nIt reduces "+c+" gc from the total.");
    return 1;
}

status
returnLocker()
{
    this_player()->tell_me("You return your locker.");
    lastaccess = time();
    save_object(L_SAVEDIR+owner);
    destruct(this_object());
    return 1;
}

status
giveupLocker()
{
    if(spaceUsed)
	return notify_fail("It's not empty.\n"),0;
    this_player()->tell_me("You give up your locker.");
    rm("/"+L_SAVEDIR+owner+".o");
    write_file(L_DIR+L_GIVEUPLOG, ctime(time())+", "+
      this_player()->query_real_name()+", "+
      spaceAvail+"\n");
    destruct(this_object());
    return 1;
}

status
upgradeLocker(string str)
{
    int cost, size;

    if(!str)
	return notify_fail("Usage: upgrade <size>\n"),0;
    if(!sscanf(str,"%d",size) || size < 2 || size > L_MAXSIZE)
	return notify_fail("Illegal size.\n"),0;
    if(size <= spaceAvail)
	return notify_fail("You call that upgrading?\n"),0;
    cost = L_UPBASECOST+((size-spaceAvail-1)*L_COSTPERUNIT);
    if((int)this_player()->query_money() < cost)
	return notify_fail("You can't afford that.\n"),0;
    this_player()->add_money(-cost);
    write_file(L_DIR+L_UPGRADELOG, ctime(time())+", "+
      this_player()->query_real_name()+", "+spaceAvail+
      " -> "+size+"\n");
    spaceAvail = size;
    this_player()->tell_me("Upgraded your locker to "+size+".");
    save_object(L_SAVEDIR+owner);
    return 1;
}

status
sellLocker()
{
    int origcost;

    if(spaceUsed)
	return notify_fail("It's not empty.\n"),0;
    this_player()->tell_me("Sold your locker.");
    rm("/"+L_SAVEDIR+owner+".o");
    write_file(L_DIR+L_GIVEUPLOG, ctime(time())+", "+
      this_player()->query_real_name()+", "+
      spaceAvail+", sold\n");
    origcost = L_BASECOST+(L_COSTPERUNIT*(spaceAvail-1));
    this_player()->add_money(75*origcost/100);
    destruct(this_object());
    return 1;
}

string
itemsInLocker()
{
    string s;
    int i, c, tot;

    if(!spaceUsed)
	return "It's empty.";
    s = "The locker contains:\n";
    while(i < spaceUsed) {
	c = L_RETVALUE_X*itemData[i][IND_OBVARS]["value"];
	if(c > L_RETMAXVALUE)
	    c = L_RETMAXVALUE;
	tot += c;
	s += (i+1)+"\t"+itemData[i][IND_OBDESC]+" \t("+c+")\n";
	i++;
    }
    s += "Total retrieve cost (after reboot): "+tot+" gc\n";
    return s;
}

int
query_totalvalue()
{
    int i, c, tot;

    while(i < spaceUsed) {
	c = L_RETVALUE_X*itemData[i][IND_OBVARS]["value"];
	if(c > L_RETMAXVALUE)
	    c = L_RETMAXVALUE;
	tot += c;
	i++;
    }
    return (totalvalue = tot);
}

void
cleanLocker()
{
    totalvalue = 0;
    spaceUsed = 0;
    itemData = ({});
    lastaccess = time();
    return;
}

string
query_owner()
{
    return owner;
}

int
query_lastaccess()
{
    return lastaccess;
}
