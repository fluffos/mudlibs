#include <std.h>
#include <daemons.h>
#include <arlon.h>
#include <security.h>
#define MAX_SPEED 3 //  Max Speed
#define MAX_ARMOUR 3 //  Max Armour
#define MAX_CANNONS 2 //  Max Cannons
#define CANNON_PRICE 25000// Base Price.  Double per point
#define SPEED_PRICE 40000// Base Price.  Double per point
#define ARMOUR_PRICE 35000 // Base Price.  Double per point
#define RESCUE_PRICE 75000 // If your sunk
#define NEWBIE_PRICE 50000 // Give < 20 players a break on Rescue
#define REPAIR_PRICE 20000 // Gold to repair 5% dmg
#define DESCRIBE_PRICE 10000 //  Gold to change describe
#define NUM ({ "zero", "one", "two", "three", "four" })
#define OPTIONS ({"cannons","armour","speed"})
inherit MONSTER;
void create() {
    ::create();
    set_name("john");
    set_short("John, the boat master");
    set_level(30);
    set_race("human");
    set_body_type("human");
    set_gender("male");
    set_id(({ "shop keeper", "shopkeeper", "boat master", "john" }));
    set_long( "He is away at work building boats.  You may "
      "<buy ship>, <repair ship>, <view status>, <set>, or <rescue ship> your boat.");
}
void init() {
    ::init();
    add_action("buy_boat", "buy");
    //    add_action("upgrade_boat", "upgrade");
    add_action("rescue", "rescue");
    add_action("repair", "repair");
    add_action("view", "view");
    add_action("f_set", "set");
}
int buy_boat(string str) {
    string line;
    if (str!="ship") {
	write("Buy what?");
	return 1;
    }
    if(file_size(DIR_BOATS+"/"+this_player()->query_name()+".o") > 0) {
	this_object()->force_me("say You already own a boat, my friend.");
	return 1;
    }
    if(this_player()->query_level() < 10) {
	this_object()->force_me("say Newbies should stay off the ocean.\n");
	return 1;
    }
    if (this_player()->query_money("gold") < 20000) {
	this_object()->force_me("say You're too poor to buy a boat.");
	return 1;
    }
    write("You are the owner of a brand new boat.");
    seteuid(UID_BOATSAVE);
    write_file("/adm/save/boats/"+this_player()->query_name()+".o", 
      "#"+ctime(time())+"\nowner \""+this_player()->query_name()+"\"\n"
      "armour 1\ncannons 0\nspeed 0");
    seteuid(geteuid());
    this_player()->add_money("gold", -20000);
    return 1;
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
int rescue(string s) {
    int amt;
    object ob;
    if(s != "ship") return notify_fail("Rescue what?\n");
    if(!file_exists(DIR_BOATS+"/"+this_player()->query_name()+".o")) {
	this_object()->force_me("say You do not own a boat.");
	return 1;
    }
    ob=OCEAN_D->find_player_ship(this_player()->query_name());
    if(!ob) ob=new("/std/obj/boat");
    if(!ob->query_owner()) ob->set_owner(this_player()->query_name());
    ob->load();
    if(!ob->query_sunk()) return notify_fail("Why would you need "
	  "to resue your ship while it still floats?\n");
    if(this_player()->query_level() < 20) amt=NEWBIE_PRICE;
    else amt=RESCUE_PRICE;
    if(this_player()->query_money("gold") < amt) {
	write("You do not have the "+amt+" gold "
	  "required to rescue your ship.\n");
	return 1;
    }
    if(this_player()->query_level() < 20) this_object()->force_me(
	  "say Since you are a low-level player, you pay half price.");
    write("Your ship has been rescued.\n");
    this_player()->add_money("gold", -amt);
    ob->set_sunk(0);
    ob->save();
    return 1;
}
int repair(string s) {
    int amt, price;
    float tmp;
    object ob;
    if(s != "ship") return notify_fail("Repair what?\n");
    if(!file_exists(DIR_BOATS+"/"+this_player()->query_name()+".o")) {
	this_object()->force_me("say You do not own a boat.");
	return 1;
    }
    ob=OCEAN_D->find_player_ship(this_player()->query_name());
    if(!ob) ob=new("/std/obj/boat");
    if(!ob->query_owner()) ob->set_owner(this_player()->query_name());
    ob->load();
    if(ob->query_hp() <= 0) return notify_fail("Your ship is not damaged.\n");
    if(this_player()->query_money("gold") < REPAIR_PRICE) {
	write("You do not have the "+REPAIR_PRICE+" gold "
	  "required to rescue your ship.\n");
	return 1;
    }
    tmp=ob->query_max_hp() * 0.05;
    amt=to_int(tmp);
    ob->add_hp(-amt);
    if(ob->query_hp() < 0) while(ob->query_hp() < 0) ob->add_hp(1);
    write("Your ship has been repaired 5% of the damage dealt to it.\n");
    this_player()->add_money("gold", -REPAIR_PRICE);
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
    write("Your ship is "+to_int(percent(ob->query_hp(), ob->query_max_hp()))+"% Damaged.\n");
    return 1;
}
int f_set(string s) {
    object ob;
    if(!s) return notify_fail("Syntax: <set [description]>\n");
    ob=OCEAN_D->find_player_ship(this_player()->query_name());
    if(!ob) ob=new("/std/obj/boat");
    if(!ob->query_owner()) ob->set_owner(this_player()->query_name());
    ob->load();
    if(ob->query_valid_long(s)) { 
	    write("Your description contains illegal words.  Please remove all swear words.\n"); 
	return 1; 
    }
    if(this_player()->query_money("gold") < DESCRIBE_PRICE) {
	write("You do not have the "+DESCRIBE_PRICE+" gold required to "
	  "change the description of your ship.");
	return 1;
    }
    this_player()->add_money("gold", -DESCRIBE_PRICE);
    write("You change the description of your ship.\n");
    ob->set_long_short(s);
    return 1;
}
