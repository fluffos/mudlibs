/*
** File: leaded.c
** Author: Lady Nsd
** Other comments: the evilest thing I've made :-P
*/

#include <mudlib.h>
inherit WEAPON ;

void create() {
    seteuid(getuid() );
    set("author", "nsd");
    set("id", ({"whip", "leaded whip" }) );
    set("short" , "The fearsome leaded whip");
    set("long", @EndText
This is the most horrible torture whip ever made. It exists
since the roman empire, perhaps earlier. This whip has three
thin whips coming from the handle. Each end has a lead ball
with a sharp hook. Makes you pity whomever gets whipped with
this...
EndText);
    set_weapon_type("whip");
    set("name" , "leaded whip");
    set_verbs( ({"whip", "tear", "strip", "rip", "disjoin",
      "carcass"}) );
    set_verbs2( ({"whips", "tears", "strips", "rips", "disjoins",
      "carcasses"}) );
    set("nosecond", 0);
    set("value" , 1000);
    set("damage", ({8, 15}) );
    set("damage_type", "slashing");
}
void init () {
    add_action("whip", "whip");
    add_action("show", "show");
    add_action("crack", "crack");
}

int whip(string str) {
    object ob;
    if (!str) return 0;
    ob = present(str, environment(TP));
    if (!ob) {
	write ("Who do you want to torture?\n");
	return 1;
    }
    if (!living(ob)) {
	notify_fail ("That person is not here with you!\n");
	return 0;
    }
    write(wrap(
	"You rip open the flesh of "+ob->query("cap_name")+
	" with your leaded whip,\n"+
	"and "+possessive(ob->query("gender") )+" blood "+
	"spills althrough the floor...\n"+
	"YOU ARE EVIL!!\n"));
    say(
      TPN+" rips open the flesh of "+ob->query("cap_name")+
      " with "+POSS+" leaded whip,\n"+
      "and "+possessive(ob->query("gender") )+" blood "+
      "spills althrough the floor...\n"+
      TPN+" IS EVIL!!\n", ({ ob }) );
    tell_object(ob,
      TPN+" rips open your flesh with "+POSS+" leaded whip\n"+
      "and your blood spills althrough the floor...\n"+
      TPN+" IS EVIL!!\n");
    ob->receive_damage(ob->query_level()*6, "slashing");
    return 1;
}
int show(string str) {
    write("You show your horrible leaded whip, and cause some panic.\n");
    say(TPN+" shows "+POSS+" horrible leaded whip, causing panic.\n");
    return 1;
}
int crack(string str) {
    write("You crack your leaded whip on the floor, and the sharp hooks\n"+
      "rip the ground open... Terror invades whomever is watching!\n");
    say(TPN+" cracks "+POSS+" leaded whip on the floor, and the sharp hooks\n"+
      "rip the ground open... Imagine what it can do to you!\n");
    return 1;
}

/* EOF */
