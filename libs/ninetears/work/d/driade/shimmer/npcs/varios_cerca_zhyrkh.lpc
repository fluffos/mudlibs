/* By Shimmer */


inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(3))
  {
    case 0:
      set_name("ninyo orco");
      set_short("ninyo orco");
      set_long("Es un pequenyo ninyo orco que pasa el rato mirando para los guardias "+
		      "atontado..\n");
      add_alias("ninyo");
      add_alias("orco");
      set_main_plural("ninyos orcos");
      add_plural("ninyos");
      add_plural("orcos");
      set_race_ob("/std/races/orc");      
      set_race("orc");
      set_gender(1);
      add_move_zone("zhyrkh");
      ataque1="golpea en la cara";
      ataque2="patea el culo";
      ataque3="quiebra una pierna";
      set_level(5);
      set_wimpy(30);
      load_chat(40,
         ({
               1, "@corretea de un lado a otro pateando una piedra.",
               1, "@te mira asustado. ",
          }));      
      break;
    case 1:
      set_name("ninya orca");
      set_short("ninya orca");
      set_long("Es una joven ninya orca de piel oscura y pequenyos brazos y piernas, "+
		      "la ves tan inofensiva que sonries cuando te mira.\n");
      add_alias("ninya");
      add_alias("orco");
      set_main_plural("ninyas orcos");
      add_plural("ninyas");
      add_plural("orcos");
      set_race_ob("/std/races/orc");      
      set_race("orc");
      set_gender(2);
      add_move_zone("zhyrkh");
      ataque1="golpea en la cara";
      ataque2="patea el culo";
      ataque3="quiebra una pierna";
      set_level(5);
      set_wimpy(30);
      load_chat(40,
         ({
               1, "@silba inocentemente una cancioncilla.",
               1, "@te mira asustado. ",
          }));     
    case 2:
      set_name("mujer orca");
      set_short("mujer orca");
      set_long("Es una mujer orca de mediana edad, no para de moverse de un lado a otro "+
		      "gritandole a los ninyos orcos y reprimiendolos.\n");
      add_alias("mujer");
      add_alias("orco");
      set_main_plural("mujeres orcas");
      add_plural("mujeres");
      add_plural("orcos");
      set_race_ob("/std/races/orc");      
      set_race("orc");
      set_gender(2);
      add_move_zone("zhyrkh");
      ataque1="golpea en la cara";
      ataque2="patea el culo";
      ataque3="quiebra una pierna";
      set_level(10);
      set_wimpy(30);
      load_chat(40,
         ({
               1, "@corre detras de los ninyos.",
               1, "@te mira y sonrie. ",
          }));     
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
