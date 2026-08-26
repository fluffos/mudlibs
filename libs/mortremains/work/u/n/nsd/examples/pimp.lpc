#include <mudlib.h>
#include <where.h>

inherit MONSTER;
object pimprobe;

void create () {
    ::create();
    seteuid(getuid());
    set("author","cattt");
    set("short", "Corsch");
    set("long", @Endtext
He is a very stylish pimp. He wears a bright, rich purple
robe that seems to hide his musclular body.  A scar is visible
on his face just below his chin. By his size and demeanor 
you think he could have been a boxer or wrestler at some time. 
Endtext
    );
    set("id", ({ "orc", "pimp", "corsch" , "Corsch" }) );
    set_name ("Corsch");
    enable_commands();
    set("gender", "male");
    set("race", "orc");
    set("spell_points", 30);
    set("max_sp", 30);
    set("armor_class", 3);
    set("aggressive", 0); 
    set("damage", ({ 1,3 }) );
    set("weapon_name", "fists");
    set("stat/strength", 15);
    set("stat/dexterity", 17);
    set_size(6);
    set_verbs( ({ "swing at" , "jab at" }) );
    set_verbs2( ({ "swings at", "jabs at" }) );
    set("chat_chance", 2);
    set("chat_output", ({
      "Crosch wanders about looking for his women. \n",
      "The pimp complains about this and that.\n",
    }));
    set("att_chat_output", ({
      "Corsch calls you a pansy and laughs at you.\n",
    }));

    pimprobe = clone_object(M_ARM+"pimprobe");
    wear(pimprobe);
    set("prevent_summon", 1);
    set_level(14);
}

// Cyanide added a quick hack.
void init() {
    command("equip");
}
