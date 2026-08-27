/* Thalos */


inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(2))
  {
    case 1:
      set_name("rata");
      set_short("rata");
      set_long("Es una inmensa rata, que no hace mas que observarte con su rojillos ojos, intentando calcular tus fuerzas.\n");
      add_alias("rata");
      set_main_plural("ratas");
      add_plural("ratas");
      set_gender(1);
      ataque1="muerde";
      ataque2="clava sus garras";
      ataque3="salta hacia ti y te muerde la oreja";
      set_level(3+random(5));
      set_max_hp(query_level() * 8);
      add_move_zone("camkeroon");
      break;
    case 4:
      set_name("murcielago");
      set_short("murcielago");
      set_long("Es un murcielago, negro, drande y colgado del techo a la espera de que pase la presa idonea.\n");
      add_alias("murcielago");
      set_main_plural("murcielagos");
      add_plural("murcielagos");
      set_gender(1);
      ataque1="clava sus colmillos en tu cuello";
      ataque2="aranya una mano";
      ataque3="muerde la pierna";
      set_level(5+random(5));
      set_max_hp(query_level() * 8);
      add_move_zone("camkeroon");
      break;
          
  }
  set_random_stats(7,17); 
  set_al(50+random(-100));
  set_wimpy(0+random(20));
  add_move_zone("camkeroon");
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
