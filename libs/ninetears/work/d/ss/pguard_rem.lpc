/* swamp:  lizard king guard */

inherit "/obj/monster";

void setup() {
     set_name("guard");
     add_alias("reptile");
     add_alias("lizardman");
     set_main_plural("guards");
     add_plural("reptiles");
     add_plural("lizardmen");
     set_race("lizardman");
     set_gender(1);
     set_al(random(25) + 20);
     set_random_stats(6, 18);
     set_str(random(10) + 19);
     adjust_con(2);
     set_aggressive(0);
     set_wimpy(0);
     set_guild("/std/guilds/warriors/fighter");
     set_level(random(4) + 9);
     clone_object("/baseobs/armour/chainmail")->move(this_object());
     clone_object("/baseobs/armour/buckler")->move(this_object());
     clone_object("/baseobs/weapons/short_sword")->move(this_object());
     do_command("equip");
     set_short("Guard");
     set_long("This is a personal guard of the Lizard King.  He looks " +
        "like a fierce fighter.\n");
     }
/* void setup ends */
