/* By Shimmer */


inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(5))
  {
    case 0:
      set_name("bandido");
      set_short("bandido");
      set_long("Es un bandido en busca de alguna posible victima que pase por la zona "+
		      "para intentar robarle o hacerle de las suyas.\n");
      add_alias("bandido");
      set_main_plural("bandidos");
      add_plural("bandidos");
      set_gender(1);
      add_move_zone("hagn");
      adjust_money(10+random(10), "copper");
      ataque1="golpea en la cara";
      ataque2="patea el culo";
      ataque3="quiebra una pierna";
      set_level(10);
      break;
    case 1:
      set_name("explorador");
      set_short("explorador");
      set_long("Un explorador en busca de aventuras que dedica su tiempo a la busqueda de "
               "nuevas zonas por las que no haya pasado antes con fin de conocerlas mejor.\n");
      add_alias("explorador");
      set_main_plural("explorador");
      add_plural("exploradores");
      set_gender(1);
      add_move_zone("hahn");
      adjust_money(10+random(10), "copper");
      ataque1="golpea en la mandibula";
      ataque2="pega un puntapie";
      ataque3="muerde en un brazo";
      set_level(10+random(2));
      break;
    case 2:
      set_name("exploradora");
      set_short("exploradora");
      set_long("Un exploradora en busca de aventuras que dedica su tiempo a la busqueda de "
               "nuevas zonas por las que no haya pasado antes con fin de conocerlas mejor.\n");
      set_main_plural("exploradoras");
	add_plural("exploradoras");
      set_gender(1);
      add_move_zone("hahn");
      adjust_money(10+random(10), "copper");
      ataque1="golpea con el bolso";
      ataque2="escupe a la cara";
      ataque3="tira de los pelos";
      set_level(8+random(2));
      break;
    case 3:
      set_name("mercenario");
      set_short("mercenario");
      set_long("Es uno de los molestos mercenarios que encuentran en estas zonas "
               "un lugar tranquilo y lejos de los guardias y la justicia, se aporvechara de "
               "cualquiera que ande despistado por su zona.\n");
      add_alias("mercenario");
      set_main_plural("mercenarios");
      add_plural("mercenarios");
      set_gender(1);
      add_move_zone("hahn");
      adjust_money(10+random(10), "copper");
      ataque1="golpea en la nuca";
      ataque2="agarra fuertemente";
      ataque3="sacude una patada";
      set_level(12);
      add_clone("/baseobs/weapons/dagger",1);
      add_clone("/baseobs/armours/leather",1);
      ::init_equip();
      break;
   
  }
  set_random_stats(6,17); 
  set_al(0);
  set_wimpy(20);
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
