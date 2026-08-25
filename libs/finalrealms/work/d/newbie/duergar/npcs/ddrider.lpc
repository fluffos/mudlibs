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
   adjust_money(6,"gold");
   this_object()->adjust_money(3+random(2), "silver");
   set_long("   Before you stands of what remains of a Drider.  This "
            "creature appears to have put up quite a bit of resistance "
            "during its capture.  The driders upper torso is covered "
            "with many scars, giving it a bloated appearance and is "
            "missing a few legs.  This creature has definately seen "
            "better days. It is interesting to see a Centaur-like creature"
	    " with the upper body of a Drow, and the lower like a giant "
            "spider."
            "\n\n");
   set_heart_beat(1);
   new("/baseobs/weapons/scimitar")->move(this_object());
   this_object()->init_equip();
   reset_get();
   reset_drop();
   add_language("drow");
   do_command("speak drow");
   load_a_chat(80,({
               1,"'Light upon you!\n",
               1,":bites you and sucks your blood.\n",
              }));
}
