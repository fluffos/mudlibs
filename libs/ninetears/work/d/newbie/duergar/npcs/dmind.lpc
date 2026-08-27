/*  File upgrade by Grimbrand 2-11-96                                   */

#include "unarmed_combat.h"
inherit "/obj/monster";

int att_count;

void setup() {
   object ob;

   set_name("mind flayer");
   add_alias("flayer");
   add_alias("mind");
   set_short("Mind Flayer");
   set_long("   Se dice que esta criatura vive y se alimenta de las "
            "las mentes de otros seres inteligentes.  Este se encuentra "
            "en mal estado.  Ha perdido uno de sus grandes ojos negros  "
            "dejando a la vista un feo hueco oscuro. Y dos de los cuatro "
            "tentaculos que rodean su boca caen flacidos sin fuerza. Tal "
            "vez intento atacar a un duergar y recibio una leccion."
            "\n\n");
   set_race("mind flayer");
   set_level(8);
   set_random_stats(10,18);
   set_al(200);
   set_max_hp(34);
   adjust_money(5,"oro");
   set_kill_xp(431);

}

mapping valid_attack() {
  return([
        "punch" : ({ AN+" fustiga a "+DN+" con un tentaculo.\n",
                     "Fustigas a "+DN+" con un tentaculo.",
                     AN+" te fustiga con un tentaculo.\n" }),
        "kick"  : ({ AN+" abofetea a "+DN+" con su mano macilenta.\n",
                     "Abofeteas a "+DN+" con tu mano macilenta.",
                     AN+" te abofetea con su mano macilenta.\n"   }),
        "knee"  : ({ AN+" raspa a  "+DN+" con su gran zarpa.\n",
                     "Raspas a "+DN+" con tu zarpa.",
                     AN+" te raspa con su gran zarpa.\n" }),
        "headbutt" : ({ AN+" mira fijamente a  "+DN+", que recula como golpeado.\n",
                        "Miras fijamente a "+DN+".",
                        AN+" te mira fijamente, lacerandote con su mente.\n" })
        ]);
}
