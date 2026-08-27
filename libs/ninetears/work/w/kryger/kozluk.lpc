/* Thalos */


inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("human");
      set_name("kozluk");
      set_short("kozluk");
      set_long("Es el guardaespaldas del inmortal kryger.\n");
      add_alias("kozluk");
      set_main_plural("kozluks");
      add_plural("kozluk");
      set_gender(1);
      ataque1="Te mete 25 campanillas 1 a 1 por el culo";
      ataque2="te arranka un trozo de oreja de un bokado";
      ataque3="te pega un punyetazo en la mandibula,te parte to los pinyos y con un cuidado extremo recoge todas las piezas las pega con pegamento y te raja la yugular";
      set_level(70);
      set_max_hp(10000);
	   load_chat(20,
            ({
              1,":Vacia sus manos y las frota.",
              1,"'tienes demasiadas cosas, me dejas k te alijere la carga?",
              1,":acaricia a su daga ocultandola un pokillo.",
             }));
          
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
