#include <room.h>
#include <areas.h>
#include <generic_items.h>

#define TP this_player()

void create_room() 
{
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set_short("Lords' Shop");
    set_long(
      "In this shop the Ladies and Lords may buy some very fine magic "+
      "items which are not available to ordinary mortals. Commands: "+
      "'list' and 'buy'.");
    set(NO_PK);
    set(IN_CITY);
    set_exits(([ "east" : AREA_TRISTEZA+"shops/lords_pub"]));
}

void
init_room()
{
    add_action("read","read");
    if(TP && (!TP->query_lord() &&
	!TP->query_coder_level())) return;
    add_action("list", "list");
    add_action("buy", "buy");
}

list() {
    tell_here("Available items:\n" +
      "Potion of Remove Scars         70000 gc (buy remove)\n" +
      "Potion of Make Scars           70000 gc (buy make)\n" + 
      "Enhanced Feelings (saveable)  100000 gc (buy feelings)\n");
    return 1;
}
buy(str) {
    object ob;
    int cost;

    if(!str) { notify_fail("Buy what?\n"); return 0; }

    str=lower_case(str);

    if(str!="remove" && str!="make" && str!="feelings") {
	tell_here("No such thing in this shop.\n");
	list();
	return 1;
    }

    if(str == "feelings") cost = 100000;
    if(str == "remove" || str == "make") cost = 70000;
    if(TP->query_money() < cost) {
	tell_here("Unfortunately don't have enough money.\n");
	TP->tell_here(capitalize(TP->query_real_name())+" sighs deeply.\n");
	return 1;
    }

    if(str == "feelings") {
	if(present("enhanced",TP)) {
	    tell_here("You already have that.\n");
	    return 1;
	}
	tell_here("You buy the Enhanced Feelings.\n");
	TP->tell_here(TP->query_name() + " buys Enhanced Feelings.\n");
	ob = clone_object(GENERIC_ENHANCED_FEELINGS);
	log_file("funfeel",TP->query_real_name()+" "+ctime(time())+"\n");
    }
    if(str == "make" || str == "remove") {
	tell_here("You buy Potion of "+capitalize(str)+" Scars.\n");
	TP->tell_here(TP->query_name() + " buys Potion of "+capitalize(str)+" Scars.\n",TP);
	if(str == "remove")
	    ob = clone_object(GENERIC_SCAR_REMOVAL_POTION);
	else
	    ob = clone_object(GENERIC_SCAR_ADD_POTION);
    }

    transfer(ob,TP);
    TP->add_money(-cost);
    return 1;
}

int query_prevent_shout() { return 1; }
