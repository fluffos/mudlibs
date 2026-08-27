/* Thalos */


inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(2))
  {
    case 1:
      set_name("sirvienta");
      set_short("sirvienta");
      set_long("Es una sirvienta del castillo,esta esperando k le pidan algo para cumplirlo\n");
      add_alias("sirvienta");
      set_main_plural("sirvientas");
      add_plural("sirvientas");
      set_gender(1);
      ataque1="Te pega un manotazo en la cara";
      ataque2="clava sus unyas";
      ataque3="te pega con un plumero";
      set_level(3+random(5));
      set_max_hp(query_level() * 8);
      add_move_zone("camkeroon");
      break;
    case 4:
      set_name("camarero");
      set_short("camarero");
      set_long("Es un camarero trajeado,tiene una pose fija,con una bandeja de canapes en la mano esperando k alguien le coja alguno.\n");
      add_alias("camarero");
      set_main_plural("camareros");
      add_plural("camareross");
      set_gender(1);
      ataque1="clava su abridor en el cuello";
      ataque2="aranya una mano";
      ataque3="aplasta la cabeza con la bandeja";
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
