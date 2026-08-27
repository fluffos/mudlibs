/* By Shimmer */


inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(2))
  {
    case 0:
      set_name("oso");
      set_short("oso polar");
      set_long("Es un gigantesco oso polar, su piel es blanca para camuflarse y "+
		      "protegerse de la nieve y del frio.\n");
      add_alias("oso");
      set_main_plural("osos polares");
      add_plural("osos");
      set_gender(1);
      ataque1="se levanta sobre sus patas traseras y te cae encima rasgandote el cuerpo";
      ataque2="muerde una pierna";
      ataque3="golpea con sus zarpas en la cadera";
      set_level(25);
      break;
    case 1:
      set_name("lobo");
      set_short("lobo blanco");
      set_long("Es un lobo blanco de las montanyas, se caracteriza por su pelo blanco, "
               "con el cual pasa inadvertido en la nieve.\n");
      add_alias("lobo");
      set_main_plural("lobos blancos");
      add_plural("lobos");
      set_gender(1);
      ataque1="golpea con su cuerpo";
      ataque2="clava sus colmillos en la pierna";
      ataque3="muerde un brazo";
      set_level(15+random(5));
      break;

  }
  set_random_stats(6,17); 
  set_al(0);
  set_wimpy(10);
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
