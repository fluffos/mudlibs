/*
** File: nm_mon.c
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

    set("author", "nsd");
    set ("short", "Lord Nightmask The Lore Master (Lawful Evil)");
    set ("long",@EndText
His blood stained lips twist into a smirk as he looks back at you.
Your gaze meets his white eyes that seem to pierce your soul.
His long flowing robes are black in color and adourned with runes.
His eyes sparkle with love for Nsd.
He's carrying:
A leather belt (equipped).
Long black flowing robes (equipped).
EndText);
    set ("id", ({ "Nightmask", "nightmask", "NM", "admin", "vampire" }) );
    set_size(6);
    set_name ("Nightmask");
    set ("gender", "male");
    set ("race", "vampire admin");
    enable_commands() ;
    set_living_name("Nightmask");
    set ("natt", 2);
    set("chat_chance", 30);
    set("chat_output", ({
      "A bat comes flying out of nowhere and transforms into Nightmask.\n",
      "Nightmask bares his fangs in a twisted grin.\n",
      "Nightmask . o O ( hmm...)\n",
      "Nightmask says: I'm the law admin.\n",
      "Nightmask says: go nutz!\n",
      "Nightmask says: Are you threatening me???\n",
      "Nightmask equips a leather belt.\n",
    }) );
    set("alive", 1);
    set("damage", ({8, 20}) );
    set("damage_type", "piercing");
    set("weapon_name", "sharp fangs");
    set_verbs( ({ "attack", "swing at", "peer at", "bite" }) );
    set_level(90);
    set("stat/strength", 25);
    set("stat/intelligence", 25);
    set("stat/constitution", 25);
    set("stat/wisdom", 25);
    set("stat/dexterity", 25);
    set("stat/charisma", 25);
    set("armor_class", 4);
    set("prevent_summon", 1);
}
/* End of File */
