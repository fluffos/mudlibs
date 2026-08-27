//.oO JaDe Oo.  Junio'02

inherit "/obj/monster";

void setup() {
      object objeto;
      set_name("mago");
      set_short("Mago");
      set_main_plural("magos");
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
      set_long("Un hechicero retirado que ahora dedica su tiempo a elaborar y vender pociones. "
       "A pesar de su avanzada edad se conserva bastante bien,parece que"
       " aun posee magicos poderes. Puedes apreciar un extranyo brillo en sus ojos.\n");
      adjust_money(random(5), "gold");
      set_aggressive(0);
      load_chat(30,
         ({
               1, "'Deseais comprar algo, senyor?",
               1, ":mezcla ingredientes para una pocion.",
               1, ":vierte cuidadosamente un liquido azul en un pequenyo matraz.",
               1, "'Tengo gran variedad de artefactos para aprendices.",
               1, ":se atusa la barba mientras te observa detenidamente.",
          }));
      
//      add_clone("/baseobs/weapons/short_sword",1);
//      add_clone("/baseobs/armours/leather",1);
//      add_clone("/baseobs/armours/helmet",1);
      ::init_equip();
           
}/*setup*/


//void attack_by(object atacante)
//{
//   atacante->add_timed_property("guardias_anduar", 1, TIEMPO);
//   return ::attack_by(atacante);
//}
