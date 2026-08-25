inherit "/obj/monster";

void setup() {

   set_name("kobold");
   set_short("Kobold");
   add_alias("kobold");
   set_long("   The kobold is a cowardly, sadistic, and ugly dog-like"
            " humanoid.\n"
            "\n");
   set_main_plural("kobolds");
   set_gender(1);
   set_race("kobold");
   set_random_stats(6,14);
   set_aggressive(1);
   add_triggered_action("bing", "event_death", this_object(), "death");
   set_join_fight_mess("The kobold attacks you.\n");
   set_level(5);
   set_max_hp(20);
   set_kill_xp(155);
   set_al(60);
   set_wimpy(0);
   switch(random(5)+1)
     {
      case 1:
       new("/baseobs/weapons/short_sword")->move(this_object());
       break;
      case 2:
       new("/baseobs/weapons/club")->move(this_object());
       break;
      case 3:
       new("/baseobs/weapons/hand_axe")->move(this_object());
       break;
      case 4:
       new("/baseobs/weapons/javelin")->move(this_object());
       break;
      case 5:
       new("/baseobs/weapons/spear")->move(this_object());
       break;
     } 
   new("/baseobs/armours/leather")->move(this_object());
   this_object()->init_equip();  
   load_a_chat(30,
       ({
               1, "@kick $hcname$"
        }));
   adjust_money(random(20), "brass");
} /* setup */
