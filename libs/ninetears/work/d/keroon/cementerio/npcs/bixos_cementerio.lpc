/* Thalos */


inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(6))
  {
    case 0:
      set_name("zombie");
      set_short("zombie");
      set_long("Es un zombie de color verdoso, que debido a su estado de descomposicion tiene ciertas dificultades en sus movimientos.\n");
      add_alias("zombies");
      set_main_plural("zombies");
      add_plural("zombies");
      set_gender(1);
      ataque1="golpea fuertemente en el estomago";
      ataque2="escupe a la cara una sustancia pegajosa";
      ataque3="patea la entrepierna";
       set_level(15+random(10));
      set_max_hp(query_level() * 8);
      add_move_zone("cementerio");
      break;
    case 1:
      set_name("espectro");
      set_short("espectro");
      set_long("Es un alma errante en busca del descanso eterno que la muerte no logro otorgarle.\n");
      add_alias("espectro");
      set_main_plural("espectros");
      add_plural("espectros");
      set_gender(1);
      ataque1="atraviesa con su mano el pecho";
      ataque2="envuelve en una ola de frio";
      ataque3="atraviesa";
      set_level(20+random(5));
      set_max_hp(query_level() * 8);
      add_move_zone("cementerio");
      break;
    case 2:
      set_name("fantasma");
      set_short("fantasma");
      set_long("Es un alma errante en busca del descanso eterno que la muerte no logro otorgarle.\n");
      set_main_plural("fantasmas");
      add_alias("fantasmas");
	add_plural("fantasmas");
      set_gender(1);
      ataque1="atraviesa con su mano el pecho";
      ataque2="envuelve en una ola de frio";
      ataque3="atraviesa";
      set_level(10+random(5));
      set_max_hp(query_level() * 8);
      add_move_zone("cementerio");
      break;
    case 3:
      set_name("ghoul");
      set_short("ghoul");
      set_long("Es un ghoul, esta rebuscando entre las tumbas abandonadas, esperando encontrar algun resto que puedan comer.\n");
      add_alias("ghoul");
      set_main_plural("ghouls");
      add_plural("ghouls");
      set_gender(2);
      ataque1="golpea fuertemente en el estomago";
      ataque2="muerde fuertemente el brazo";
      ataque3="patea la entrepierna";
      set_level(17+random(8));
      set_max_hp(query_level() * 8);
      
      add_move_zone("cementerio");
      break;
 case 4:
      set_name("esqueleto");
      set_short("esqueleto");
      set_long("Es un esqueleto, a decir verdad no sabes como se las apanya para mantener en pie, pero no dispones de tiempo para preguntarselo.\n");
      add_alias("esqueletos");
      set_main_plural("esqueletos");
      add_plural("esqueletos");
      set_gender(1);
      ataque1="golpea fuertemente en el estomago";
      ataque2="lanza su cabeza, golpeandote con ella";
      ataque3="patea la entrepierna";
      set_level(10+random(10));
      set_max_hp(query_level() * 8);
      
      add_move_zone("cementerio");
      break;          
  case 5:
      set_name("aparecido");
      set_short("aparecido");
      set_long("Es un aparecido, un ente venido de lmas alla en busca de las almas y el calor de los vivos.\n");
      add_alias("aparecidos");
      set_main_plural("aparecidos");
      add_plural("aparecidos");
      set_gender(1);
      ataque1="atraviesa con su mano el pecho";
      ataque2="envuelve en una ola de frio";
      ataque3="atraviesa";
      set_level(13+random(10));
      set_max_hp(query_level() * 8);
      
      add_move_zone("cementerio");
      break;          
  }
  set_random_stats(7,17); 
  set_str(30);
  set_al(100);
  set_wimpy(0+random(20));
  set_aggressive(1);
  set_move_after(20+random(10), 20+random(10));
}
 /* setup */
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
