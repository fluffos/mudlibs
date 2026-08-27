/* By Shimmer */


inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(3))
  {
    case 0:
      set_name("goblin");
      set_short("goblin");
      set_long("Es un sucio y malevolo goblin que ronda los caminos buscando alguna victima para sus fechorias.\n");
      add_alias("goblin");
      set_main_plural("goblins");
      add_plural("goblins");
      set_gender(1);
      ataque1="golpea la cadera";
      ataque2="patea el culo";
      ataque3="pisotea un pie";
      set_level(10);
      set_aggressive(3);
      load_a_chat(10,
      ({ 1, "'Dame todo lo que lleves o te lo quitare !!",
         2, "'Muereeeeeee !!",
      }));
      add_clone("/d/driade/shimmer/npcs/equipo/daga",1);
      ::init_equip();
    break;
    case 1:     
      set_name("troll");
      set_short("troll");
      set_long("Un sucio y feo troll, es alto y delgado, sus brazos y piernas son como ramas duras y tu "
               "fea cara austa nada mas verlo.\n");
      add_alias("troll");
      set_main_plural("trolls");
      add_plural("trolls");
      ataque1="golpea en la mandibula";
      ataque2="pega un puntapie";
      ataque3="muerde en un brazo";
      set_level(10+random(5));
      set_gender(1);
    break;
    case 2:
      set_name("ladron");
      set_short("ladron");
      set_long("Es uno de los muchos ladrones que se mueven por estos parajes, su unico "
               "fin es intentar robarte todo lo que lleves encima.\n");
      add_alias("ladron");
      set_main_plural("ladrones");
      add_plural("ladrones");
      set_gender(1);
      adjust_money(5+random(10), "copper");
      set_random_stats(12,16);
      ataque1="golpea en la nuca";
      ataque2="clava el punyal en el brazo";
      ataque3="sacude una patada";
      set_level(10);
      add_clone("/d/driade/shimmer/npcs/equipo/punyal",1);
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



