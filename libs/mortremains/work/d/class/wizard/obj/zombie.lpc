/* 
** FILE:    zombie.c
** DATE:    August 26, 1996
**
** PURPOSE: The zombie created when a corpse is animated.
**
** CHANGES: 
**   26 Aug 96  Cyanide    Created the file.
**   04 Jun 98  Cyanide    Foun dthe file and breathed life into it.
*/

#include <mudlib.h>

inherit MONSTER;

void create() {
    ::create();
    seteuid(geteuid());

    set ("author", "cyanide");

    //All the happy stuff concerning identification:
    set("short", "@@query_short");
    set("long", "@@query_long");
    set("id", ({"zombie","skeleton","undead","corpse"}) );
    set("gender", "neuter");
    set("name", "noone");

    //Mass and other physical info
    set("mass", 0);

    //Combat stuff
    set ("weapon_name", "rotting fists");
    set_verbs( ({ "swing at", "swipe", "bludgeon" }) );
    set_skill("Unarmed", 2, "strength");

    //Other stuff
    set ("creator", "noone");
    set ("undead", 1);

}

void init() {
    /*
      add_action("command_func", "to");
      add_action("command_func", "say");
      add_action("command_func", "deadsay");
    */
    command("equip");
}

string query_short() {
    string str, name;

    name = this_object()->query("name");

    str = "animated zombie of "+capitalize(name);
    return str;
}

string query_long() {
    string str, name;
    name = TO->query("name");

    str = "This is the corpse of "+name+", denied eternal "+
"rest by "+capitalize(query("creator"))+".";

    return wrap(str);
}
