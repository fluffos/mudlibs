inherit "obj/monster";

void setup() {
   set_name("ogro");
   add_alias("Ogro");
   add_alias("fighter");
   set_short("Ogro cautivo");
   set_long("   Este enorme ogro tiene la piel oscura y moteada "
            "de manchones marrones,con irregulares mechones de "
            "pelo oscuro .Te sonrie con su boca abierta, puedes "
	    "ver sus pocos dientes, todos ellos amarillentos.\n"
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
   adjust_money(2,"oro");
   clone_object("/baseobs/armours/leather")->move(this_object());
   clone_object("/baseobs/weapons/short_sword")->move(this_object());
   this_object()->init_equip();
}
