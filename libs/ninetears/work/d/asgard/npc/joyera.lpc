//.oO JaDe Oo.  Junio'02

inherit "/obj/monster";

void setup() {
      object objeto;
      set_name("joyera");
      set_short("joyera");
      set_main_plural("joyeras");
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
      set_long("Una mujer de mediana edad ,sus ojos te inspiran confianza "
       "ya que al mirarla observas una candidez extrema en su mirada."
       "Su vestimenta es algo extranya aunque lo que mas destaca son sus numerosos collares.\n");
      adjust_money(random(5), "gold");
      set_aggressive(0);
      load_chat(30,
         ({
               1, "'Deseais comprar algo, senyor?",
               1, ":ordena tranquilamente sus joyas.",
               1, ":abre un cofre, saca un collar y te lo ensenya.",
               1, "'Tomese su tiempo para examinar los objetos, estoy segura de que seran de su agrado.",
               1, ":te mira con deseo.",
          }));
      
           
}/*setup*/


//void attack_by(object atacante)
//{
//   atacante->add_timed_property("guardias_anduar", 1, TIEMPO);
//   return ::attack_by(atacante);
