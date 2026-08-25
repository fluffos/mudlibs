inherit "obj/monster";

void setup() {
   set_name("ogre");
   add_alias("Ogre");
   add_alias("fighter");
   set_short("Captive Ogre");
   set_long("   This huge ogre has dark, mottled brown skin and "
            "irregular tufts of black hair. It grins at you with "
            "a maw half-filled with sickening yellow teeth.\n"
            "\n");
   set_race("ogre");
   set_join_fights();
   set_guild("warrior");
   set_level(5);
   set_aggressive(0);
   set_random_stats(10,18);
   set_kill_xp(155);
   set_max_hp(20);
   set_gender(1);
   set_al(-75);
   adjust_money(2,"gold");
   clone_object("/baseobs/armours/leather")->move(this_object());
   clone_object("/baseobs/weapons/short_sword")->move(this_object());
   this_object()->init_equip();
}
