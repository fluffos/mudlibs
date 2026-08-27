//.oO JaDe Oo.  Junio'02

inherit "/obj/monster";

void setup() {
      object objeto;
      set_name("tendero");
      set_short("Tendero");
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
      set_long("Un tipo algo mayor, maltratado por la edad y el trabajo. "
       "Sus ojos reflejan la desidia y el cansancio producido por el esfuerzo."
       " Al mirar sus manos ves las tipicas marcas de un sastre que lleva"
      " una dura vida de trabajo.\n");
      adjust_money(random(5), "gold");
      set_aggressive(0);
      load_chat(30,
         ({
               1, "'Deseais comprar algo, senyor?",
               1, ":enhebra una aguja habilmente.",
               1, ":alcanza una tela de calidad y te la muestra.",
               1, "'Nobles y caballeros compran aqui sus ropas usted no va a ser menos",
               1, "'Mis telas son las mejores de la region.",
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
