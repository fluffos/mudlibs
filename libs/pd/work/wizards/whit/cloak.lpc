//  Created by Whit

#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("whit's cloak");
    set_long("This is Whit's cloak, and it should be descriptive enough!");
    set_short("black cloak");
    set_id(({ "cloak", "black cloak" }));
}

void init() {
    ::init();
    add_action("f", "flourish");
    add_action("punish", "punish");
    add_action("storm", "storm");
}

int f(string str) {
    if(!str || str != "cloak") return notify_fail("Flourish what?\n");
    if(this_player()->query_name() != "whit") {
	write("You are forsaken for trying to use Whit's Cloak!\n");
	say("The cloak "+this_player()->query_cap_name()+"'s is holding burns "+
	  objective(this_player())+" and disintegrates.\n");
	this_object()->remove();
	return 1;
    }
    write("You flourish your cloak.\n");
    message("environment", this_player()->query_cap_name()+" flourishes "+
      this_player()->query_possessive()+" cloak.\n",
      environment(this_player()), 
      ({this_player()}) );   
    return 1;
}

int punish(string str) {
    object ob;
    string reason;

    if(!str) return notify_fail("Punish who?\n");
    if(this_player()->query_name() != "whit") {
	write("You are forsaken for trying to use Whit's Cloak!\n");
	say("The cloak "+this_player()->query_cap_name()+"'s is holding burns "+
	  objective(this_player())+" and disintegrates.\n");
	this_object()->remove();
	return 1;
    }
    if( sscanf(str, "%s %s", str, reason) !=2) return notify_fail("You "
	  "must supply a reason.\n");
    if(!ob=find_player(str)) return notify_fail("Cannot find player!\n");
    if(!interactive(ob)) return notify_fail(str+" is not interactive!\n");
    write("You punish "+ob->query_cap_name()+".\n");
    message("environment", "You are being punished by "
      +this_player()->query_cap_name()+
      " for the reason of: "+reason, ob);
    ob->move_player("/wizards/whit/punish", "into thin air");
    return 1;
}

int storm(string str) {
    if(!str) return notify_fail("Syntax: <storm [dir]>\n");
    if(!strsrch(str, "$N")) str = "$N"+str;
    str = replace_string(str, "$N", this_player()->query_cap_name());
    message("environment", str, environment(this_player()), ({ this_player() }) );
    this_player()->move("/wizards/whit/workroom");
    return 1;
}

