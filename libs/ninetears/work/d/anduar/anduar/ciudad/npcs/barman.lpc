// Barman 
// Krom 11-8-97

#include "path.h"
inherit "/obj/monster";

void setup()
{
      object objeto;
      set_name("koskar");
      set_short("Koskar el cocinero");
      set_al(250);
      set_gender(1);
      add_alias("barman");
      add_alias("humano");
      add_alias("human");
      add_alias("cocinero");
      set_race_ob("/std/races/human");
      set_wimpy(0);
      set_random_stats(15, 18);
      set_str(25);
      set_dex(18);
      set_con(18); 
      set_cha(15+random(3));
      set_level(20+random(10));
      set_long("Koskar es el barman de la %^GREEN%^Taberna de Anduar%^RESET%^."
         " Este humano pelirrojo tiene un bigote del mismo color, tiene"
         " una estatura fuera de lo comun. En uno de sus brazos "
         " puedes ver el tatuaje de una jarra de cerveza." 
         " Esta muy ocupado intentando mantener el orden en el bar. Pero"
         " te servira lo que pidas.\n");
      adjust_money(random(100), "silver");
      set_aggressive(0);
      load_chat(30,         ({
               1, "'Oye tu, que quieres tomar?.",
               1, ":empieza a frotar las jarras de cerveza con un panyo.",
               1, ":grita : El que vuelva a decir que mis asados son una"
                  " porqueria se la carga."
          }));

      add_clone(OBJETOS+"jarra",1);
      ::init_equip();         
}/*setup*/

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_anduar", 1, TIEMPO);
   return ::attack_by(atacante);
}
