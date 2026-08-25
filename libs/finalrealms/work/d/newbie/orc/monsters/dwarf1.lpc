// Dwarf made by Goodfoot 07-04-95

inherit "/obj/monster";

void setup()
{
   set_name("dwarf");
   set_race("dwarf");
   set_gender(1);
   set_main_plural("dwarfs");
   add_plural("angry dwarfs");
   set_al(-20);
   set_aggressive(0);
   set_guild("fighter");
   set_random_stats(10,15);
   set_con(18);
   set_level(3+random(2));
   set_wimpy(0);
   set_short("angry dwarf");
   set_long("A young adventures dwarf. He seems to have lost something, "
                " and is searching around for it, he's not in a good mood.\n\n");
   load_chat(30,
      ({
         1,"'Where is that bloody treasure.\n\n",
         1,":Pats the walls.\n\n",
         1,"'Where is it.\n\n"
      }));
   load_a_chat(40,
      ({
         1,":looks angry around him.\n\n",
         1,":hurts his hand while beating you.\n\n",
         1,":swears over his lost equipment.\n\n"
      }));
   set_join_fight_mess("An angry dwarf joins the fight.\n\n");
   new("/baseobs/weapons/war_hammer")->move(this_object());
   new("/baseobs/armours/large_shield")->move(this_object());
   this_object()->init_equip();
}
