//.oO JaDe Oo.  Junio'02

inherit "/obj/monster";

void setup() {
      object objeto;
      set_name("posadero");
      set_short("posadero");
      set_main_plural("posaderos");
      set_al(60);
      set_gender(1);
      add_alias("human");
      set_race_ob("/std/races/human");
      set_wimpy(0);
      set_random_stats(14, 18);
      set_str(18);
      set_con(18);
      set_dex(16);
      set_cha(14+random(4));
      set_level(10+random(8));
      set_long("Un hombre de mediana edad, de tez morena y aspecto bonachon.  "
       "Al oirlo hablar te das cuenta de que lleva anyos en la profesion"
       "y eso se nota a la hora de ser atendido.\n");
      adjust_money(random(5), "gold");
      set_aggressive(0);
      load_chat(30,
         ({
               1, "'Deseais algo, senyor?",
               1, ":se coloca detras de una mesa.",
               1, ":malhumorado te indica la salida.",
               1, "'Si no quiere nada no moleste por favor.",
               1, ":se pone a dar vueltas inquieto.",
          }));
      
           
}/*setup*/


//void attack_by(object atacante)
//{
//   atacante->add_timed_property("guardias_anduar", 1, TIEMPO);
//   return ::attack_by(atacante);
