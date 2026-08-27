inherit "obj/monster";
void setup() 
  {
  object weapon, armour;

   set_name("wulfgar");
   add_alias("barbarian");
   set_main_plural("barbarians");
   add_property("determinate","");
   set_short("Wulfgar");
   set_long("Wulfgar is a huge, strong barbarian.  He's grown a bit sloppy "+
     "over the years however, and seems to have inherited some beer-fat from "+
     "a couple of hundred barrels of mead and beer.\n");
   set_race("human");
  set_join_fights();
  set_join_fight_mess("Wulfgar shouts: Finally, smashing-time!!!\n");
   set_class("fighter");
   set_level(80);
   set_wimpy(0);
   set_gender(1);
   set_al(200);
   set_str(28);

/*equipping Wulfgar for battle*/   
   
   weapon = clone_object("/items/weapon/battle_axe");
   armour = clone_object("/items/armour/hide");
   weapon->move(this_object());
   armour->move(this_object());

   command("wield battleaxe");
   command("wear hide");
  
}

/*
int write_message(int dam,object him,object me,string type,string attack) {
   string what;
   ::write_message(dam, him, me, type, attack);
}
*/
          
