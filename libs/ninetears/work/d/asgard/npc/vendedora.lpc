//.oO JaDe Oo.  Junio'02

inherit "/obj/monster";

void setup() {
      object objeto;
      set_name("vendedora");
      set_short("vendedora");
      set_main_plural("vendedoras");
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
      set_long("Una mujer de avanzada edad,las arrugas de su cara "
       "te hacen quedarte perplejo la pensar lo dura que ha de ser"
       "la vida de esta anciana.\n");
      adjust_money(random(5), "gold");
      set_aggressive(0);
      load_chat(30,
         ({
               1, "'Deseais algo, senyor?",
               1, ":parece temblorosa.",
               1, ":estornuda.",
               1, "'Si no quiere nada no moleste por favor, necesito calma.",
               1, ":mete una pieza de carne al fuego.",
          }));
      
           
}/*setup*/


//void attack_by(object atacante)
//{
//   atacante->add_timed_property("guardias_anduar", 1, TIEMPO);
//   return ::attack_by(atacante);
