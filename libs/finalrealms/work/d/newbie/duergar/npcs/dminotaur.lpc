/*  Text edited by Grimbrand 2-2-96                                    */

inherit "/obj/monster";

void setup() {
      set_name("minotaur");
      add_adjective("brutal");
      add_adjective("big");
      set_race("minotaur");
   set_level(4);
      set_wimpy(0);
      set_random_stats(12, 18);
      set_al(50);
   set_max_hp(16);
   set_kill_xp(94);
      set_short("big minotaur");
      set_main_plural("big minotaurs");
   set_long("   This is a big ox-like humanoid.  It seems that it "
            "wants to challenge you to a fight.  It does look "
            "incredibly brutal, maybe you would be better off "
            "swallowing your pride and bother someone else."
            "\n\n");
      load_chat(10,
         ({
               1, "'Ghutt upp wuppun, un fuut.",
               1, "'Luttschee huw good yuu arch in cumbutt.",
               1, "'Grub uurch archmch and fuut, suckur!",
               1, ":twirls it's axe.",
               1, ":roars a challenge to $lname$",
          }));
      load_a_chat(20,
         ({
               1, "'Funnnulii a fuut!",
               1, "'Juur bruuv!",
               1, "'Juur suun dudd! HU!",
          }));
      new("/baseobs/weapons/hand_axe")->move(this_object());
      set_join_fight_mess("A minotaur happily exclaims: A FUUT!.\n");
      add_triggered_action("bing2", "event_death", this_object(), "death");
      this_object()->init_equip();
   adjust_money(3,"gold");
} /* setup() */
