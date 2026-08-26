/*
** File: citizen.c
** Date: The day after Easter year 2k.
** Purpose: I don't feel like making monsters, so this will have to do
*/

#include <mudlib.h>
string query_race();
string query_gender();

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "nightmask");
    set("short", "A citizen of Hill Valley");
    set("id", ({ "citizen", query_race() }) );
    set_name("a citizen");
    set("gender", query_gender());
    set("race", query_race());
    set("damage", ({ 1,4 }) );
    set("weapon_name", "fists");
    set_verbs( ({ "attack", "swing", "bitchslap" }) );
    set_level(random(4)+1);
}
string query_gender() {
    string str;
    int num = random(2);

    switch(num) {
    case 0 : str = "male";break;
    case 1 : str = "female";break;
    }

    return str;
}

string query_race() {
    string blah;
    int boo = random(6);

    switch(boo) {
    case 0 : blah = "dwarf";break;
    case 1 : blah = "elf";break;
    case 2 : blah = "halfling";break;
    case 3 : blah = "half-elf";break;
    case 4 : blah = "gnome";break;
    case 5 : blah = "human";break;
    }

    return blah;
}
