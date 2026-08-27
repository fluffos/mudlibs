/* By Shimmer*/


inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(5))
  {
    case 0:
      set_name("espectro");
      set_short("espectro");
      set_long("Es un espectro de la cienaga, lo tienes levitando delante de ti y cuando te"+
	       "fijas en el un escalofrio recorre todo tu cuerpo, puedes ver atraves de el "
               "debido a que es un ser etereo.\n");
      add_alias("espectro");
      set_main_plural("espectros");
      add_plural("espectros");
      set_gender(1);
      ataque1="atraviesa y un escalofrio te recorre el cuerpo";
      ataque2="hace tropezar al pasar por tu lado";
      ataque3="golpea con una fuerza invisible";
      set_level(30+random(10));
      break;
    case 1:
      set_name("cocodrilo");
      set_short("cocodrilo");
      set_long("Es una enorme cocodrilo de unos dos metros de largo que habita las cienagas, "
               "su dentadura afilada sobresale amenazante y su cola no para de moverse brusca y rapidamente.\n");
      add_alias("cocodrilo");
      set_main_plural("cocodrilos");
      add_plural("cocodrilos");
      set_gender(1);
      ataque1="golpea fuertemente en la cadera con su cola";
      ataque2="desgarra una pierna al clavar sus mandibulas en tu pierna";
      ataque3="muerde fuertemente un brazo";
      set_level(10+random(2));
      break;
    case 2:
      set_name("hombre");
      set_short("hombre lodo");
      set_long("Es una masa de lodo con forma humana que se confunde con el barro del suelo.n\n");
      set_main_plural("hombres");
      add_plural("hombres lodo");
      set_gender(1);
      ataque1="golpea en la cara dejandotela embarrada";
      ataque2="pate fuertemente el vientre";
      ataque3="asesta un golpe en la pierna";
      set_level(10+random(5));
      break;
    case 3:
      set_name("mosquito");
      set_short("mosquito");
      set_long("Es uno de los molestos mosquitos fastidiosos de las alcantarillas. "
               "Su temible picadura se transmite en enfermedades alucinogenas que "
               "son bastante dificiles de curar.\n");
      add_alias("mosquito");
      set_main_plural("mosquitos");
      add_plural("mosquitos");
      set_gender(0);
      ataque1="pica";
      ataque2="pica";
      ataque3="pica fuertemente";
      set_level(2);
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
