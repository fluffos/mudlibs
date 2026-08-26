#include <mudlib.h>
inherit WEAPON ;

void create() {
    set ("author","Gothmog");
    set ("id", ({ "weapon", "sword", "blade"}));
    set("short", "Sword of Felayshono");
    set("long", "A massive blade, constructed of solifified flame.\n");
    set_weapon_type("sword/long");
    set("size", 6);
    set("damage", ({ 5,15}));
    set("name", "sword of flame");
    set_verbs( ({ "attack", "slice", "crush", "hack"}));
    set_verbs2(({"attacks", "slices", "crushes", "hacks"}));
    set("second", 0) ;
    set("nosecond", "@@query_ns");
    set("light", 1);
    set_bonus(4);
    set("value", 8000);
}

int query_ns() {
    if ((int)TP->query("size") > 7) return 0;
    return 1;
}

int hit_func( object ob, int dam ) {
    ob->receive_damage(random(10), "fire",
      environment(TO), 1);
    return dam;
}

/* EOF */
