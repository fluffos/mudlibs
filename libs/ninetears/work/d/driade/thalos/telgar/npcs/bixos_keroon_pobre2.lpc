// Thalos

inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("duergar");
  switch(random(9))
  {
  case 0:
      set_name("ninyo");
      set_short("ninyo");
      set_long("Es un pequenyo ninyo, su ropas estan sucias y va descalzo, te mira con su cara famelica a la espera de que le des alguna moneda.\n");
      add_alias("ninyo");
      set_main_plural("ninyos");
      add_plural("ninyos");
      set_gender(1);
      ataque1="patea la espinilla";
      ataque2="muerde en un brazo";
      ataque3="sacude una patada";
      set_level(15+random(5));
      ::init_equip();
      break;
  case 1:
      set_name("ninya");
      set_short("ninya");
      set_long("Es una pequenya ninya, su ropas estan sucias y va descalza, te mira con su cara famelica a la espera de que le des alguna moneda.\n");
      add_alias("ninya");
      set_main_plural("ninyos");
      add_plural("ninyos");
      set_gender(2);
      ataque1="patea la espinilla";
      ataque2="muerde en un brazo";
      ataque3="sacude una patada";
      set_level(15+random(5));
      ::init_equip();
      break;
  case 2:
      set_name("trabajador");
      set_short("trabajador");
      set_long("Es un trabajador, disfrutando de un tranquilo paseo por la ciudad despues de una dura jornada de trabajo.\n");
      add_alias("trabajador");
      set_main_plural("trabajadores");
      add_plural("trabajadores");
      set_gender(1);
      set_level(10+random(5));
      set_max_hp(query_level() * 8);
      break;
  case 3:
      set_name("anciano");
      set_short("anciano");
      set_long("Es un anciano duergar, disfrutando de un tranquilo paseo por la ciudad  y esperando continuar vivo hasta el dia siguiente.\n");
      add_alias("anciano");
      set_main_plural("ancianos");
      add_plural("ancianos");
      set_gender(1);
      set_level(10+random(5));
      set_max_hp(query_level() * 8);
      break;
  case 4:
      set_name("anciana");
      set_short("anciana");
      set_long("Es un anciana duergar, disfrutando de un tranquilo paseo por la ciudad  y esperando continuar viva hasta el dia siguiente.\n");
      add_alias("anciana");
      set_main_plural("ancianos");
      add_plural("ancianos");
      set_gender(1);
      set_level(10+random(5));
      set_max_hp(query_level() * 8);
      break;
    }
  add_move_zone("keroon_pobre");
  set_move_after(20+random(10), 20+random(10));
  set_random_stats(8,19); 
  set_al(0);
  set_wimpy(20);
}

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_keroon", 1, 600);
   ::attack_by(atacante);
}


#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()


int unarmed_attack(object target,object me) 
{
  object *att;
  att = (object*)me->query_attacker_list();
  monster::unarmed_attack(att[random(sizeof(att))],me);
} 


valid_attack() 
{
   return([
      "kick"  :({AN+" "+({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".\n",
                 ({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".",
                 AN+" te "+({ataque1,ataque2,ataque3})[random(3)]+".\n"}),
      "knee"  :({AN+" "+({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".\n",
                 ({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".",
                 AN+" te "+({ataque1,ataque2,ataque3})[random(3)]+".\n"}),
      "punch"  :({AN+" "+({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".\n",
                 ({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".",
                 AN+" te "+({ataque1,ataque2,ataque3})[random(3)]+".\n"})]);


}
