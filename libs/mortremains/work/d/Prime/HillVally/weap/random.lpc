/*
** File: random.c
**
** Date : Febuary, 25th, 2000
**
** Purpose : Being that i am a lazy mother fucker, I wrote this so
**           I wouldn't have to write 15 or 20 bullshit no bonus
**           Weapons, this will do it all for me.
**
** Other Notes: I like camels.
*/

#include <mudlib.h>

string query_name();

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "nightmask");
    set("short", query_name());
    set_material_type("metal/steel");
    set_verbs( ({ "slice", "slash", "cut into" }) );
    set_verbs2( ({ "slices", "slashes", "cuts into" }) );

}
string query_name() {
    string str;
   int num = random(15);

    switch(num) {
    case 0 : str = "a dagger";break;
    case 1 : str = "a battle axe";break;
    case 2 : str = "a two handed axe";break;
    case 3 : str = "a hand axe";break;
    case 4 : str = "a short sword";break;
    case 5 : str = "a long sword";break;
    case 6 : str = "a scimitar";break;
    case 7 : str = "a two handed sword";break;
    case 8 : str = "a mace";break;
    case 9 : str = "a staff";break;
    case 10 : str = "a warhammer";break;
    case 11 : str = "a lance";break;
    case 12 : str = "a club";break;
    case 13 : str = "a sickle";break;
    case 14 : str = "a morning star";break;
    }
    if (str == "a dagger") {
	set("long", (wrap("This is a small steel dagger, you could do \n"+
	      "much better than this, you might just want to toss it.\n")) );
	set_weapon_type("dagger");
	set("id", ({ "dagger" }) );
	set("name", "dagger");
	set("value", 10);
    }
    if (str == "a battle axe") {
	set("long", (wrap("This is a small hand axe. It looks like a \n"+
	      "piece of shit.\n")) );
	set_weapon_type("axe/hand");
	set("id", ({ "axe", "hand axe" }) );
	set("name", "hand axe");
	set("value", 15);
    }

    if (str == "a two handed axe") {
	set("long", (wrap("This is a huge two handed axe made of steel.\n"+
	      " You do however feel there are better weapons out there.\n")) );
	set_weapon_type("axe/two handed");
	set("id", ({ "axe", "two handed axe" }) );
	set("name", "two handed axe");
	set("value", 150);
    }
    if (str == "a battle axe") {
	set("long", (wrap("This is a double edged battle axe, you have \n"+
	      "seen better.\n")) );
	set_weapon_type("axe/battle");
	set("value", 200);
	set("name", "battle axe");
	set("id", ({ "battle axe", "axe" }) );
    }
    if (str == "a short sword") {
	set("long", (wrap("This is a steel short sword. You could do \n"+
	      "much better.\n")) );
	set_weapon_type("sword/short");
	set("value", 100);
	set("name", "short sword");
	set("id", ({ "sword", "short sword", "shortsword" }) );
    }
    if (str == "a long sword") {
	set("long", (wrap("This is a long sword of steel. It looks \n"+
	      "like a good solid weapon.\n")) );
	set_weapon_type("sword/long");
	set("value", 125);
	set("name", "long sword");
	set("id", ({ "sword", "long sword", "longsword" }) );
    }
    if (str == "a scimitar") {
	set("long", (wrap("This is a steel scimitar, it looks neat, \n"+
	      "but you have seen better.\n")) );
	set_weapon_type("scimitar");
	set("name", "scimitar");
	set("id", ({ "scimitar", "sword" }) );
	set("value", 75);
    }
    if (str == "a two handed sword") {
	set("long", (wrap("This is a two handed sword of steel. You \n"+
	      "have seen better, but it looks solid.\n")) );
	set_weapon_type("sword/two handed");
	set("id", ({ "two handed sword", "sword" }) );
	set("name", "two handed sword");
	set("value", 200);
    }

    if (str == "a mace") {
	set("long", (wrap("This is a mace of steel. Not a bad weapon \n"+
	      "but you have wielded better.\n")) );
	set_weapon_type("mace");
	set("id", ({ "mace" }) );
	set("name", "mace");
	set("value", 50);
    }

    if (str == "a staff") {
	set("long", (wrap("This is a staff made of steel, as far as \n"+
	      "staves go, this looks like a kick ass staff.\n")) );
	set_weapon_type("quaterstaff");
	set("name", "staff");
	set("id", ({ "staff" }) );
	set("value", 20);
    }

    if (str == "a warhammer") {
	set("long", (wrap("This is a steel warhammer. Not a bad weapon \n"+
	      "but you could do better.\n")) );
	set_weapon_type("mace");
	set("name", "warhammer");
	set("value", 25);
	set("id", ({ "warhammer", "hammer" }) );
    }
    if (str == "a lance") {
	set("long", (wrap("This is a steel lance. It looks like it \n"+
	      "could do some damage.\n")) );
	set_weapon_type("trident");
	set("name", "lance");
	set("id", ({ "lance" }) );
	set("value", 45);
    }
    if (str == "a club") {
	set("long", (wrap("This is a steel club. You can do much better.\n")) );
	set("name", "club");
	set("id", ({ "club" }) );
	set_weapon_type("club");
	set("value", 10);
    }
    if (str == "a sickle") {
	set("long", (wrap("This is a sickle of steel. Not much to look at \n"+
	      "but it might do somthing if you wield it.\n")) );
	set_weapon_type("sickle");
	set("name", "sickle");
	set("id", ({ "sickle" }) );
	set("value", 35);
    }
    if (str == "a morning star") {
	set("long", (wrap("This is a morning star, if you have ever seen \n"+
	      "one before, you know what it can do.\n")) );
	set_weapon_type("morning star");
	set("name", "morning star");
	set("id", ({ "morning star" }) );
	set("value", 65);
    }
    return str;
}
