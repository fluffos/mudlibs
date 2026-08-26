/*
** File: nmdoll.c
** Purpose: a toy for no reason at all.
** Date: July 6th, 1997
** Side Note: I like toys, do not try this at home.
*/

#include <mudlib.h>
#define NAME TPN
#include <config.h>


string say_shit();

object ob;

inherit OBJECT;
void create() {
    seteuid(getuid());
    set("short", "a Nightmask doll");
    set("long", @MegaDeth
This is a Nightmask doll. It resembles Nightmask to a tee. There are
a few things that can be done with it. You may "pull string" to make
it talk, or "smack <player>" to hit someone with your doll.
The doll is wearing a red and black nWo shirt.
MegaDeth
    );
    set("id", ({ "doll", "nightmask doll" }) );
    set("value", 300 ) ;
    set("author", "Nightmask, the Thunder Camel") ;
}

void init() {
    add_action("pull_func", "pull");
    add_action("smack_func", "smack");
}

int pull_func(string str) {
    if (!str) {
	write("Pull what?\n");
	return 1;
    }

    if (str == "string") {
	write("You pull the string...\n");
	say(NAME+" pulls the string on the Nightmask doll...\n");
	tell_room(environment(TP), say_shit()+"\n");
	return 1;
    }
    return 1;
}

string say_shit() {
      int num = random(16);
    string str = "The Nightmask doll says: ";

    switch(num) {
    case 0 : str += "\"I like Camels.\""; break;
     case 1 : str += "\"No, I won't touch you for 1 coin!\""; break;
    case 2 : str = "The Nightmask doll kicks you in the ass."; break;
    case 3 : str = "Nightmask smites you with Godly might!"; break;
    case 4 : str +="\"Stop playing with toys and code something!\"";
	break;
    case 5 : str = "The Nightmask doll does the bunghole."; break;
     case 6 : str +="\"Survey says, One more for the good guys!\""; break;
     case 7 : str +="\"I am WolfPack 4 life!\""; break;
     case 8 : str = "The Nightmask doll makes the sign of the WolfPack."; break;
     case 9 : str +="\"It's all about Goldberg!\""; break;
     case 10 : str = "The Nightmask doll tries to powerbomb you!"; break;
     case 11 : str +="\"Cyanide tried to pull my other string once.\""; break;
     case 12 : str +="\"where all the white women at?\""; break;
     case 13 : str +="\"Grunt is my hero.\""; break;
     case 14 : str +="\"They don't call him Megaweapon for nothing!\""; break;
    default : str = "The Nightmask doll is gettin' Jiggy wit it."; break;
    }
    return str;
}

int smack_func(string str) {
    object ob;

    if (!str) return 0;
    ob = present(str, environment(TP));

    if (!ob) {
	write("Smack who??\n");
	return 1;
    }

    write("You smack "+ob->query("cap_name")+" with your "+
      "Inflatable Nightmask Doll (tm)!\n");
    say(TPN+" smacks "+ob->query("cap_name")+" with "+
      possessive(TP->query("gender"))+" Inflatable Nightmask Doll"+
      " (tm)!\n", ({ ob }) );
    tell_object(ob, TPN+" smacks you with "+
      possessive(TP->query("gender"))+" Inflatable Nightmask Doll (tm)!\n");
    return 1;
}
