//.oO JaDe Oo.  Junio'02
//#include "path.h" -> NO HAY PATH.H AKI!

inherit "/obj/monster";

void setup() {
      object objeto;
      set_name("herrero");
      set_short("Narid-Na-Gost");
      set_al(60);
      set_gender(1);
      add_alias("human");
      set_race_ob("/std/races/human");
      set_guild_ob("/d/gremios/guerreros/caballerojade");
      set_wimpy(0);
      set_random_stats(14, 18);
      set_str(18);
      set_con(18);
      set_dex(16);
      set_cha(14+random(4));
      set_level(10+random(8));
      set_long("Te encuentras ante un fornido trabajador del metal.  "
         "Duros musculos forman el cuerpo de este humano, y el martillo "
         "es ya como una parte mas de si cuerpo.\n");
      adjust_money(random(5), "gold");
      set_aggressive(0);
      load_chat(30,
         ({
               1, "'Deseais comprar algo, senyor?",
               1, ":golpea una barra de metal incandescente.",
               1, ":introduce en el agua una pieza recien forjada y empieza "
               "a salir vapor.",
               1, ":coge un mazo de la estanteria.",
               1, "'Aqui podeis arreglar las armas, senyor.",
          }));
      
      add_clone("/baseobs/weapons/short_sword",1);
      add_clone("/baseobs/armours/leather",1);
      add_clone("/baseobs/armours/helmet",1);
      ::init_equip();
           
}/*setup*/


//void attack_by(object atacante)
//{
//   atacante->add_timed_property("guardias_anduar", 1, TIEMPO);
//   return ::attack_by(atacante);
//}
