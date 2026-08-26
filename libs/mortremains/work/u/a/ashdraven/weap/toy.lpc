/*
** File: Toy.c
** Purpose: To Show Cyanide.
** Date: I miss my Girlfriend... April 5, 2000
** Other: I'm sick.
*/

#include <mudlib.h>
#include <config.h>

inherit WEAPON;


void create() {
    seteuid(getuid());
    set_weapon_type("quarterstaff");
    set_material_type("stone");
    set_bonus(5);
    set ("id", ({ "staff" }) );
    set("name", "Ashdraven's Staff");
    set("short", "Ashdraven's Staff");
    set("long", @BlowMe
This is Ashdraven's staff..... Put it down...
NOW!!
BlowMe
    );
    set_verbs ( ({ "smash", "beat" }) );
    set("nosecond", 1);
    set("prevent_get", 1);
    set("prevent_drop", 1);
    set("prevent_clean", 1);
}
int query_auto_load() {return 1;}
