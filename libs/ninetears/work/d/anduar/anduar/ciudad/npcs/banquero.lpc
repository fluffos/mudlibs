// Banquero...

inherit "/obj/monster";

void setup() {
      object objeto;
      set_name("banquero");
      set_short("el banquero");
      set_al(-60);
      set_gender(1);
      set_main_plural("banqueros");
      add_alias("human");
      set_race_ob("/std/races/human");
      set_wimpy(10);
      set_random_stats(12, 18);
      set_dex(17);
      set_cha(12+random(6));
      set_level(6+random(8));
      set_long("Es un banquero bien alimentado. Se nota que trabaja en "
                "el banco.\n");
      adjust_money(random(20), "platinum");
      set_aggressive(0);
      load_chat(30,
         ({
               1, "'De uno en uno, por favor!!",
               1, ":firma un documento energicamente.",
               1, ":te mira de forma indiferente.",
               1, ":tamborilea con los dedos en la mesa.",
               1, ":te mira con miedo.",
          }));

      add_clone("/baseobs/weapons/dagger",1);
}/*setup*/
