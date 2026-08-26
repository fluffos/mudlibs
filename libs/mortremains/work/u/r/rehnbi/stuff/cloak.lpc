// properties are.
// Created by Mobydick@TMI-2, 9-30-92
// Used by Rehnbi, hopefully with permission.......//

#include <mudlib.h>

inherit ARMOR ;

void create() {
       set ("id", ({ "cloak", "cloak of protection" }) ) ;
set("short", "Rehnbi's Super Cloak");
set("long", @Bob
Rehnbi's cloak........ it is of an unworldly color and is
very strange, but seems to be powerful.
Bob
);
        set ("bulk", 1) ;
        set ("mass", 3) ;
        set ("type", "cloak") ;
set("bonus", 10);
set("armor_object", 10);
set("prevent_drop", 1);

set("equip_func", "equip_func");
}

int equip_func() {
this_player()->set("base_stat/strength"+1);

TP->resistance("fire", 0);
TP->resistance("cold", 0);
TP->resistance("crushing", 0);
TP->resistance("dehydration", 0);
TP->resistance("suffocation", 0);
TP->resistance("bleeding", 0);
TP->resistance("acid", 0);
TP->resistance("poison", 0);
TP->resistance("necromancy", 0);
TP->resistance("force", 0);
TP->resistance("electricity", 0);
TP->resistance("slashing", 0);
TP->resistance("piercing", 0);
TP->resistance("bludgeoning", 0);
TP->resistance("magic", 0);
TP->resistance("wizard", 0);
this_player()->set("stat/charisma", 32);
this_player()->set("stat/strength", 32);
this_player()->set("stat/constitution", 32);
this_player()->set("stat/wisdom", 32);
this_player()->set("stat/intelligence", 32);
this_player()->set("stat/dexterity", 32);
TP->time_to_heal(1);
return 1;
}


int spellpts() {
int spmax;
spmax = TP->query("max_sp");
TP->set("spell_points", spmax);
write("Your spell points have been replenished\n");
}

