/*
  Collector.c
  Made by Val == tpelander@kontu.cc.utu.fi
  updated by Flagg 5.5. 95
*/

#include <generic_rooms.h>
#include <treasure.h>
#define MAX 20

int count;

void create_treasure()
{
    set_name("bottle collector");
    set_id(({ "collector" }));
    set_short("A bottle collector");
    set_value(25);
    set_weight(1);
}

string query_long(string x, object ob)
{
    string str; 
    str = "You can fill this collector with empty bottles. There is some "+
    "text on it.\n";
    if (!count)
	str += "The collector is empty.";
    else
    {
	if (count==1) str += "There is 1 bottle";
	else str += "There are "+count+" bottles";
	str +=" in the collector.";
    }
    return str;
}

void init_treasure()
{
    //add_action("read","read");
    add_action("put","put");
    add_action("empty","empty");
}

status read_cmd(string x)
{
    //if (x!="text" && x!="collector") return;
    this_player()->tell_me("You read the instructions from the collector:\n"+
      "  - 'put bottle in collector'\n"+
      "  - 'empty collector' (in shop)\n"+
      "  - max "+MAX+" empty bottles in a collector");
    return 1;
}

status put(string x)
{
    object ob;

    if (!(x && sscanf(x,"%s in collector",x))) return 0;
    if (!((ob = present(x,this_player())) ||
	(ob = present(x,environment(this_player())))))
	return 0;

    if(!ob->is_drink()  ||  ob->query_full())
    {
	this_player()->tell_me(
	  "You can put only empty bottles in the collector.");
	return 1;
    }

    if (count >= MAX)
    {
	this_player()->tell_me("The collector is full.");
	return 1;
    }
    destruct(ob);  /* destruct automatically updates the weight */
    count++;
    this_player()->tell_me("Ok. You now have "+count+" bottles in the "+
      "collector.");
    return 1;
}

status empty(string x)
{
    if (!x || present(x,environment())!=this_object())
	return 0;
    if (!count)
	return notify_fail("The collector is empty.\n"), 0;

    if (object_name(environment(this_player())) == GENERIC_ROOM_SHOP_FNAME)
    {
	this_player()->tell_me("You sell all the bottles from the "+
	  "collector.\nYou get "+ count*10 +" coins.");
	this_player()->add_money(count*10);
	count = 0;
    }
    else
    {
	this_player()->tell_me("You must be in the common shop to empty "+
	  "the collector.");
    }
    return 1;
}

void set_count(int num) { count = num; }
