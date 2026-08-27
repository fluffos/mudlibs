/* File upgraded by Grimbrand 2-11-96                                   */

inherit "/obj/monster";

void setup(){
   set_level(14);
   set_max_hp(56);
   set_wimpy(0);
   set_name("drider");
   set_aggressive(0);
   set_race("drider");
   set_gender(1);
   set_al(-100);
   set_short("drider");
   set_random_stats(6,18);
   set_kill_xp(1500);
   adjust_money(6,"oro");
   this_object()->adjust_money(3+random(2), "plata");
   set_long("   Ves ante ti lo que queda de un drider.  Esta "
            "criatura parece haber opuesto una gran resistencia a "
            "su captura.  Su torso esta cubierto por numerosas "
            "heridas abiertas, esta cubierto de sangre y le falta "
            "alguna pierna.  Desde luego el bicho ha tenido mejores "
            "epocas. Es interesante su aspecto hibrido, con "
	    "la parte superior de un drow, y la inferior de una  "
            "aranya gigante."
            "\n\n");
   set_heart_beat(1);
   new("/baseobs/weapons/scimitar")->move(this_object());
   this_object()->init_equip();
   reset_get();
   reset_drop();
//   add_language("drow");
//   do_command("speak drow");
   load_a_chat(80,({
               1,"'Asi el sol te abrase!\n",
               1,":te muerde y chupa tu sangre.\n",
              }));
}
