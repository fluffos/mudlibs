// Gestur'98 (En mita de los examenes)
inherit "/obj/monster";

void setup()
{
   set_name("zombie");
   set_short("zombie");
   set_main_plural("zombies");
   add_plural("zombies");
   set_race_ob("/std/races/undead");
   set_long("Ante ti tienes una criatura realmente espantosa. Se trata de "
   "un alto y fuerte zombie. Su aspecto es el de un humanoide bastante "
   "deteriorado con una mirada realmente demoniaca. Sus dedos tienen unas "
   "unyas enormes que hacen de garras y seguramente doleran bastante.\n");
   add_property("undead", 1);
   set_al(1500);
   set_random_stats(6,18);
   set_str(16+random(6));
   set_cha(6+random(10));
   set_con(19);
   set_level(30+random(5));
   set_gender(1+random(2));
   load_chat(50, 
   ({ 1, "'Ourk, queeyey, haacceeeiiihsh, aaquuuiii?",
      2, "'FFooueeeerraaa, dee aaquuii!!",
   }));
   load_a_chat(60,
   ({ 1, "'OOOaaaaaarrrRRrrkK!!",
      2, "'MMuuuUueeeree!!",
   }));
}
