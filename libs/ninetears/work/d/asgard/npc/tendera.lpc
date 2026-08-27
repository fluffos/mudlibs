//.oO JaDe Oo.  Junio'02

inherit "/obj/monster";

void setup() {
      object objeto;
      set_name("tendera");
      set_short("Tendera");
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
      set_long("Una joven muchacha de rubios y rizados cabellos. Te mira jovialmente "
       "y sonrie dulcemente. Con estos gestos y su gracia pretende ganarse la"
       " confianza de sus clientes para asi poder camelarlos y vender mas.\n");
      adjust_money(random(5), "gold");
      set_aggressive(0);
      load_chat(30,
         ({
               1, "'Deseais comprar algo, senyor?",
               1, ":ordena tranquilamente sus baratijas.",
               1, ":se atusa su melena rubia haciendo que quedes ensimismado.",
               1, "'Tomese su tiempo para examinar los objetos, estoy segura de que seran de su agrado.",
               1, ":te sonrie amigablemente.",
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
