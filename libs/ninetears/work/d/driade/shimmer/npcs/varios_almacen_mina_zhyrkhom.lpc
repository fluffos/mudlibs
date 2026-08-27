/* By Shimmer */


inherit "/obj/monster";

string ataque1,ataque2,ataque3;


void event_enter(object ob, string mensaje, object donde)
{
   if ((int)ob->query_timed_property("minas_zhyrkhom"))
   {
      if (ob->query_dead())
      {
         do_command("laugh "+ob->query_cap_name());
         do_command("'Asi sabras con quien no debes meterte..");
         ob->remove_timed_property("minas_zhyrkhom");
      }
      else
      {
 this_object()->attack_ob(ob); 
         do_command("say Eh, tu! sucio bastardo! Veras lo que es bueno !!!!!!.\n");
      }
   }
   ::event_enter(ob, mensaje, donde);
}


void setup()
  {
  set_race("monster");
  switch(random(3))
  {
    case 0:
      set_name("esclavo");
      set_short("esclavo");
      set_long("Es un esclavo obligado a trabajar transportando los materiales en la mina.\n");
      add_alias("esclavo");
      set_main_plural("esclavos");
      add_plural("esclavos");
      set_gender(1);
      ataque1="golpea con sus cadenas";
      ataque2="patea el culo";
      ataque3="pisotea un pie";
      set_level(5);
      break;
    case 1:     
      set_name("guardia de la mina");
      set_short("guardia de la mina");
      set_long("Un guardia de la mina, su objetivo es vigilar que los mineros y exclavos "
               "cumplan su trabajo, si es necesario utilizara su fuerza bruta para ello.\n");
      add_alias("guardia");
      set_main_plural("guardias de la mina");
      add_plural("guardias");
      adjust_money(10+random(10), "copper");
      ataque1="golpea en la mandibula";
      ataque2="pega un puntapie";
      ataque3="muerde en un brazo";
      set_level(25+random(5));
      set_gender(1);
      add_clone("/d/driade/shimmer/npcs/equipo/latigo",1);
      add_clone("/d/driade/shimmer/npcs/equipo/armadura_cuero",1);
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
      adjust_money(5+random(10), "copper");
      ataque1="golpea con e pico en la nuca";
      ataque2="clava el pico";
      ataque3="sacude una patada";
      set_level(10);
      add_clone("/d/driade/shimmer/npcs/equipo/pico",1);
      add_clone("/d/driade/shimmer/npcs/equipo/casco_minero",1);
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

void attack_by(object atacante)
{
   atacante->add_timed_property("minas_zhyrkhom", 1, 300);
   ::attack_by(atacante);
}     