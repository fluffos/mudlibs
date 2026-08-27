// Thalos

inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("duergar");
  switch(random(5))
  {
    case 0:
      set_name("borracho");
      set_short("Borracho");
      set_long("Es un borracho que anda pegando tumbos por la calle en busca de la taberna mas cercana, esta bastante desalinyado y restos de sus vomitos cubren su barba.\n");
      add_alias("borracho");
      add_alias("duergar");
      add_alias("borrachos");
      set_main_plural("Borrachos");
      add_plural("borrachos");
      adjust_money(15+random(15), "plata");
      set_gender(1);
      ataque1="golpea con sus punyos";
      ataque2="patea el culo";
      ataque3="pisotea un pie";
      set_level(15+random(5));
      add_clone("/d/driade/thalos/telgar/npcs/equipo/pico",1);
      add_clone("/d/driade/thalos/telgar/npcs/equipo/casco_minero",1);
      ::init_equip();
      break;
    case 1:     
      set_name("ladronzuelo");
      set_short("Ladronzuelo");
      set_long("Ves a un joven duergar de unos ochenta anyos amenazandote con romperte las narices si no le entregas tu bolsa con todo tu oro.\n");
      add_alias("ladron");
      set_main_plural("Ladronzuelos");
      add_plural("ladronzuelos");
      add_alias("ladrones");
      adjust_money(1+random(5), "oro");
      ataque1="golpea en la mandibula";
      ataque2="pega un puntapie";
      ataque3="muerde en un brazo";
      set_level(25+random(15));
      set_gender(1);
      add_clone("/d/driade/thalos//telgar/npcs/equipo/latigo",1);
      add_clone("/d/driade/thalos/telgar/npcs/equipo/hacha_guardia",1);
      add_clone("/d/driade/thalos/telgar/npcs/equipo/cota_guardia",1);
      ::init_equip();
    break;
    
  case 2:
      set_name("mendigo");
      set_short("mendigo");
      set_long("Es uno de los muchos mendigos, que no conocen otra profesion ni medio de subsistencia que la de vagabundear por las calles de Keroon, en busca de alguna alma caritativa le de alguna monedilla.\n");
      add_alias("mendigo");
      set_main_plural("mendigos");
      add_plural("mendigos");
      adjust_money(0+random(3), "oro");
      set_gender(1);
      set_level(10+random(5));
      set_max_hp(query_level() * 8);
      break;
  case 3:
      set_name("esclavo");
      set_short("esclavo goblin");
      set_long("Es un esclavo goblin, es raro verlos por esta zona de la ciudad, mirandolo mas detenidamente te das cuenta de que no hace na mas que mirar por encima de lhombro como si lo persiguieran, seguramente sera un esclavo fugitivo.\n");
      add_alias("esclavo");
      add_alias("goblin");
      set_main_plural("esclavos goblins");
      add_plural("goblins");
      add_plural("esclavos");
      adjust_money(15+random(15), "cobre");
      set_gender(1);
      set_level(10+random(5));
      set_max_hp(query_level() * 8);
      break;
   case 4:
      set_name("maton");
      set_short("maton");
      set_long("Es un maton duergar, es raro verlos por la calle ya que siempre suelen estar prestando servicios de proteccion a sus jefes.\n");
      add_alias("maton");
      set_main_plural("matones");
      add_plural("matones");
      adjust_money(random(15), "oro");
      set_gender(1);
      set_level(10+random(5));
      set_max_hp(query_level() * 8);
      break;
  }
  add_move_zone("keroon_pobre");
  set_move_after(20+random(10), 20+random(10));
  set_random_stats(8,19); 
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
