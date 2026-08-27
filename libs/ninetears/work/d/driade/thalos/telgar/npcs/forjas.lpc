// Thalos

inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("duergar");
  switch(random(2))
  {
  case 0:
      set_name("ayudante");
      set_short("ayudante");
      set_long("Es un joven duergar, que trabaja en las forjas de Keroon a las ordenes de algun maestro fojador, debido al gran calor que hace trabaja con su torso descubierto ensenyando los poderosos musculos de su torso. Lo unico que lamenta es que por su trabajo no puede dejarse la barba como el resto de sus congeneres, porque si se le prendiera fuego podria resultar fatal.\n");
      add_alias("ayudante");
      set_main_plural("ayudantes");
      add_plural("ayudantes");
      set_gender(1);
      load_chat(30,         ({
               1, "'Condenado calor, si no fuera porque amo mi trabajo.",
               1, ":acarrea mas carbon para alimentar los fuegos.",
               1, ":se seca el sudor que corre por su frente.",
               1, ":aprovecha que no lo mira nadie para urgarse las narices."
          }));
      ataque1="patea la espinilla";
      ataque2="muerde en un brazo";
      ataque3="sacude una patada";
      set_level(10+random(5));
      ::init_equip();
      break;
  case 1:
      set_name("maestro forjador");
      set_short("maestro");
      set_long("Es un maestro forjador que trabaja en las forjas de Keroon, tiene a sus ordenes a varios ayudantes a los cuales les esta ensenyando el oficio.\n");
      add_alias("maestro");
      set_main_plural("maestros forjadores");
      add_plural("maestros");
      set_gender(1);
      load_chat(30,         ({
               1, "'He tu, no te cruces de brazos y alimenta los fuegos.",
               1, ": Grita: Pandilla de vagos, mas vale que os movais, cuando yo era ayudante no estaba parado un segundo.",
               1, ":se seca el sudor que corre por su frente.",
               1, ":pega un pescozon a un ayudante distraido que se urgaba la nariz.",
               1, "'Si quieres que te fundan algo tendras que hablar Muzandabil, el jefe de las forjas.",
          }));
      ataque1="patea la espinilla";
      ataque2="muerde en un brazo";
      ataque3="sacude una patada";
      set_level(15+random(5));
      ::init_equip();
      break;
    }
  add_move_zone("forjas");
  set_move_after(20+random(10), 20+random(10));
  set_random_stats(8,19); 
  set_al(0);
  set_wimpy(20);
}

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_keroon", 1, 600);
   ::attack_by(atacante);
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
