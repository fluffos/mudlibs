#include <std.h>
#include <daemons.h>
#include <guild.h>
#include <dirs.h>
#include <boat.h>
#include <security.h>
#define MAX_SPEED 4 //  Max Speed
#define MAX_ARMOUR 3 //  Max Armour
#define MAX_CANNONS 2 //  Max Cannons
#define CANNON_PRICE 25000// Base Price.  Double per point
#define SPEED_PRICE 40000// Base Price.  Double per point
#define ARMOUR_PRICE 35000 // Base Price.  Double per point
#define RESCUE_PRICE 100000 // If your sunk
#define NEWBIE_PRICE 50000 // Give < 20 players a break on Rescue
#define REPAIR_PRICE 20000 // Gold to repair 5% dmg
#define NUM ({ "zero", "one", "two", "three", "four" })
#define OPTIONS ({"cannons","armour","speed"})
inherit MONSTER;
void create() {
    ::create();
    set_name("Jill");
    set_short("Jill");
    set_long("This is the ship sellers sister, and also sister of the shipkeeper Jack.  Unlike John, who only repairs and sells ships; and much like Jack, she allows you to upgrade your ship.  Just %^BOLD%^%^WHITE%^<%^RED%^upgrade list%^WHITE%^> %^RESET%^to see a list of availible upgrades, as well as %^BOLD%^%^WHITE%^<%^RED%^upgrade %^WHITE%^[%^RED%^option%^WHITE%^]> %^RESET%^to upgrade an option.");
    set_id(({ "jill", "keeper", "ship keeper", "monster" }));
    set_race("human");
    set_gender("female");
    set_property("passive", 1);
}
void init() {
    ::init();
    add_action("upgrade_boat", "upgrade");
    add_action("view", "view");
}
int upgrade_boat(string str) {
    object ob;
    int tmp;
    if(!file_exists(DIR_BOATS+"/"+this_player()->query_name()+".o")) {
	this_object()->force_me("say You do not own a boat.");
	return 1;
    }
    if(!str || str=="") return notify_fail("Syntax: <upgrade list> or <upgrade [option]>\n");
    ob=OCEAN_D->find_player_ship(this_player()->query_name());
    if(!ob) ob=new("/std/obj/boat");
    if(!ob->query_owner()) ob->set_owner(this_player()->query_name());
    ob->load();
    if(ob->query_sunk()) return notify_fail("You cannot upgrade your ship why it is wrecked.");
    if(str == "list") {

	write("**************************************************************");
	write("   You have "+NUM[ob->query_actual_speed()]+" speed points out of a possible "+NUM[MAX_SPEED]+".");
	write("   You have "+NUM[ob->query_armour()]+" armour points out of a possible "+NUM[MAX_ARMOUR]+".");
	write("   You have "+NUM[ob->query_cannons()]+" cannons out of a possible "+NUM[MAX_CANNONS]+".");

	write("**************************************************************");
	write("\nTo upgrade an option, type <upgrade [option]>.\n");
	return 1;
    }
    if(member_array(str, OPTIONS)==-1) return notify_fail("The only upgradeable options "
	  "are cannons, armour, and speed.\n");
    switch(str) {
    case "cannons":
	if(ob->query_cannons() >= MAX_CANNONS) {
	    write("You may only have "+NUM[MAX_CANNONS]+" cannons.\n"); 
	    return 1;
	}
	tmp=ob->query_cannons();
	tmp++;
	if(this_player()->query_money("gold") < (tmp*CANNON_PRICE)) {
	    write("You do not have the "+(tmp*CANNON_PRICE)+" gold "
	      "required to upgrade that option.\n");
	    return 1;
	}
	this_player()->add_money("gold", -(tmp*CANNON_PRICE));
	write("You upgrade your ship in cannons.\n");
	ob->set_cannons(ob->query_cannons() + 1);
	ob->save();
	return 1;
	break;
    case "speed":
	if(ob->query_actual_speed() >= MAX_SPEED) {
	    write("You may only have "+NUM[MAX_SPEED]+" speed points.\n"); 
	    return 1;
	}
	tmp=ob->query_actual_cannons();
	tmp++;
	if(this_player()->query_money("gold") < (tmp*SPEED_PRICE)) {
	    write("You do not have the "+(tmp*SPEED_PRICE)+" gold "
	      "required to upgrade that option.\n");
	    return 1;
	}
	this_player()->add_money("gold", -(tmp*SPEED_PRICE));
	write("You upgrade your ship in speed.\n");
	ob->set_speed(ob->query_actual_speed() + 1);
	ob->save();
	return 1;
	break;
    case "armour":
	if(ob->query_armour() >= MAX_ARMOUR) {
	    write("You may only have "+NUM[MAX_ARMOUR]+" armour points.\n"); 
	    return 1;
	}
	tmp=ob->query_armour();
	tmp++;
	if(!ob->query_cannons()) return notify_fail("You must purchase "
	      "cannons before you can upgrade your armour.\n");
	if(this_player()->query_money("gold") < (tmp*ARMOUR_PRICE)) {
	    write("You do not have the "+(tmp*ARMOUR_PRICE)+" gold "
	      "required to upgrade that option.\n");
	    return 1;
	}
	this_player()->add_money("gold", -(tmp*ARMOUR_PRICE));
	write("You upgrade your ship in armour.\n");
	ob->set_armour(ob->query_armour() + 1);
	ob->save();
	return 1;
	break;
    default: write("Unknown upgrade option.\n"); return 1; break;
    }
}
int view(string s) {
    object ob;
    if(s != "status") return notify_fail("View what?\n");
    if(!file_exists(DIR_BOATS+"/"+this_player()->query_name()+".o")) {
	this_object()->force_me("say You do not own a boat.");
	return 1;
    }
    ob=OCEAN_D->find_player_ship(this_player()->query_name());
    if(!ob) ob=new("/std/obj/boat");
    if(!ob->query_owner()) ob->set_owner(this_player()->query_name());
    ob->load();
    write("Your ship has "+(ob->query_max_hp() - ob->query_hp())+" out of "+ob->query_max_hp()+" hit points.  ("+to_int(percent(ob->query_hp(), ob->query_max_hp()))+"% Damaged)");
    return 1;
}
