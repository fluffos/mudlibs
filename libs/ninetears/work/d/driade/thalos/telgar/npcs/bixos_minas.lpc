// Thalos

inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(4))
  {
    case 0:
      set_name("esclavo");
      set_short("minero esclavo");
      set_long("Es un esclavo capturado y obligado a trabajar transportando los materiales de la mina.\n");
      add_alias("esclavo");
      add_alias("minero");
      add_alias("mineros");
      set_main_plural("mineros esclavos");
      add_plural("esclavos");
      set_gender(1);
      ataque1="golpea con sus cadenas";
      ataque2="patea el culo";
      ataque3="pisotea un pie";
      set_level(15+random(5));
      add_clone("/d/driade/thalos/telgar/npcs/equipo/pico",1);
      add_clone("/d/driade/thalos/telgar/npcs/equipo/casco_minero",1);
      ::init_equip();
      break;
    case 1:     
      set_name("guardia de la mina");
      set_short("guardia de la mina");
      set_long("Un guardia de la mina, su objetivo es vigilar que los mineros y exclavos "
               "cumplan su trabajo, si es necesario utilizara su fuerza bruta para ello.\n");
      add_alias("guardia");
      set_main_plural("guardias de la mina");
      add_plural("guardias");
      adjust_money(1+random(5), "gold");
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
      set_name("minero");
      set_short("minero");
      set_long("Es uno de los mineros que etrabajan en la mina, "
               "estan constantemente picando la roca para extraer el material.\n");
      add_alias("minero");
      set_main_plural("mineros");
      add_plural("mineros");
      set_gender(1);
      adjust_money(15+random(15), "silver");
      ataque1="golpea con el pico en la nuca";
      ataque2="clava el pico";
      ataque3="sacude una patada";
      set_level(15+random(5));
      add_clone("/d/driade/thalos/telgar/npcs/equipo/pico",2);
      add_clone("/d/driade/thalos/telgar/npcs/equipo/casco_minero",1);
      ::init_equip();
      break;
   case 3:
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
      set_level(10+random(5));
      set_max_hp(query_level() * 8);
      break;
  }
  add_move_zone("minas");
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
