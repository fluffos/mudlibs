inherit "/obj/monster";
#define TIEMPO 100

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(3))
  {
    case 0:
      set_name("caballo");
      set_short("Caballo");
      set_long("Es un caballo grande y fuerte que esta pastando.\n");
      add_alias("Caballo");
      set_main_plural("Caballos");
      add_plural("Caballos");
      set_gender(1);
      ataque1="da una coz en el estomago";
      ataque2="golpea en la pierna";
      ataque3="machaca el brazo con un gran movimiento";
      set_level(15);
      break;
    case 1:
      set_name("oveja");
      set_short("Oveja");
      set_long("Es una oveja lanuda de algun propetario de Ormerod.\n");
      add_alias("oveja");
      set_main_plural("ovejas");
      add_plural("Ovejas");
      set_gender(2);
      ataque1="patea";
      ataque2="clava sus patas";
      ataque3="muerde en la mano";
      set_level(10+random(2));
      break;
    case 2:
      set_name("vaca");
      set_short("vaca");
      set_long("Es una vaca tranquila que disfruta del tiempo pastando por la zona.\n");
      set_main_plural("vacas");
      set_gender(2);
      ataque1="pega en las costillas";
      ataque2="desgarra la pierna de una cornada";
      ataque3="clava los cuernos en el estomago";
      set_level(10+random(5));
      break;
  }
  set_random_stats(6,17); 
  set_al(0);
  set_wimpy(20);
} /* setup */


#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()


int unarmed_attack(object target,object me) 
{
  object *att;
  att = (object*)me->query_attacker_list();
  monster::unarmed_attack(att[random(sizeof(att))],me);
} 


mixed valid_attack() 
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

void attack_by(object atacante)
{
   atacante->add_timed_property("vaqueros_ormerod", 1, TIEMPO);
   ::attack_by(atacante);
}
