/* By Shimmer */

#define CREATOR "shimmer";

#include "../../../path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("Alcalde Theod");
   set_short("Alcalde Theod");
   set_al(-100);
   set_gender(random(2));
   set_main_plural("Alcaldes Theod");
   add_alias("theod");
   add_alias("alcalde");
   add_alias("humano");
   add_alias("hombre");
   add_plural("humanos");
   add_plural("alcaldes");

   set_race_ob("/std/races/human");
   set_guild("paladin");
   set_guild_ob("/std/guilds/warriors/paladin");
   add_attack_spell(60, "cargar", ({"/std/commands/carga", "carga",0,1}));
   add_property("NO_BUDGE", 1);

   set_max_hp(650 );
   set_hp(650);
   set_max_gp(300); 
   set_gp(300);
   set_wimpy(0);
   set_random_stats(18, 20);
   set_level(30+random(10));   
   
   set_long("Theod Slaz, Alcade de Brethem desde hace ya muchos anyos, es un viejo humano de pelo canoso, barbas "
            "largas y elevada estatura. Corpulento, robusto y agil a pesar de su edad, fue antanyo un gran "
            "paladin defensor del bien, ahora, ya lejos aquellos tiempos de aventuras y peligros, es el encargado "
            "de gobernar la ciudad y hacerla mas prospera y para sus habitantes y mantener el orden en ella, cosa "
            "dificil de conseguir debido a las numerosas razas que la habitan y los conflictos que entre ellas se "
            "generan.\n");
            
   set_aggressive(0);

   adjust_money(random(40), "platinum");

   load_a_chat(100,({
       1, "'Bienvenido a Brethem. Que honrados asuntos le traen por aqui?.",
       1, ":golpea el suelo con su baston mientras comunica algo a uno de los concejales.",
       1, "'Aqui en la alcaldia estamos muy ocupados intentando regir bien la ciudad.",
       1, ":sonrie a la vez que firma unos importantes documentos.",
   }));
       

  add_property("fire", 50);
  add_property("cold", 50);
  add_property("air", 50);
  add_property("magical", 50);
  add_property("poison", 50);
  add_property("electrical", 50);
  add_property("acid", 50);





//   add_clone("/baseobs/armours/cape",1);
//   ::init_equip();
}

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_brethem", 1, 300);
   ::attack_by(atacante);
}
