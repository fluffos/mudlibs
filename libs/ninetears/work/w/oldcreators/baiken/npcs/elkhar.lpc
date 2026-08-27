//Hecho por Paris en Feb'98

inherit "/obj/monster";
#include "../path.h"

int query_res(string str)
{
 return 50;
}

int query_total_ac()
{
 return -85;
}
 
void setup()
{
  
  set_name("elkhar");
  set_short("Elkhar Maestro de las Runas");
  set_long("Elkhar es un medio elfo de gran estatura. Tiene el pelo"
     " largo y moreno. Sus ojos, penetrantes y sobrios, son de "
     "color miel, moteados por manchas amarillas y rosadas. Su "
     "complexion no es muy poderosa, pero se le ve trabajada "
     "por los anyos y por las practicas. En cualquier caso, "
     "Elkhar, seguro que es un enemigo formidable.\n");

  set_main_plural("Elkhars, Los Maestros de las Runas");
  add_plural("elkhars");
  add_alias("elkhar");
  set_race_ob("/std/races/half-elf");
  set_gender(1);
  set_random_stats(20,25);
  set_cha(20+random(6));
  set_guild_ob("/std/guilds/multi/wizwar");
  adjust_money(30,"platinum");
  add_clone(ITEMS+"capa_w",1);
  add_clone(ITEMS+"hach_run",1);
  add_clone(ITEMS+"pod_ring",1);
  add_clone(ITEMS+"ar_esp",1);
  load_chat(35,({
      1,"'Si aprendes de las runas, tu poder sera inmenso !",
      1,"'Tienes suerte de poder pertenecer a este gremio !",
      1,":alisa su capa",
      1,":afila su hacha",
      1,":ensaya algunos pases de un nuevo hechizo",
      1,"'Aprender a meditar, ese es el camino",
   }));
  load_a_chat(30,({
      1,"'Siente mi furia !!",
      1,":haze unos pases magicos\nUna bola de color negro impacta en tu pecho !!",
      1,"'No seas necio y abandona ahora que aun puedes",
      1,":usa su anillo y brilla con una leve luz rojiza",
  }));
  set_level(66+random(11));
   set_max_hp(2500+random(155));
  set_hp((TO->query_max_hp()),(TO->query_max_hp()));
  set_max_gp(2000);
  set_gp(TO->query_max_gp());
  init_equip();
}

void init()
{
   ::init(); 
    add_attack_spell(65,"mayor misil magico",({"/std/spells/wizard/mmmissile",
   "cast_spell",0}));
/*
   "/std/spells/wizard/stoneskin"->cast_spell(TO->query_name(),TO,0,1);
*/
}

/*
void attack_by(object ob)
{
 if(((ob->query_timed_property("Combate") || ob->query_timed_property("Combate2")) && !(ob->query_death())) )
 {
  tell_object(ob,"\nIntruso!!!, Has deshonrado la confianza que habia puesto en ti!!!!.\n");
 }
 else
 {
  ob->add_timed_property("Combate2",200);
  tell_object(ob,"Nunca quise llegar a las armas.\n");
 }
}
*/
 
  
