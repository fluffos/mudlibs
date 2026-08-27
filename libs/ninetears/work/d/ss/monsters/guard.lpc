
inherit "obj/monster";

void setup() {
   object arm, weap;
   set_name("guard");
   add_adjective("village");
   set_main_plural("village guards");
   add_plural("guards");
   set_short("village guard");
   set_long(
      "This is your typical tall, well-muscled guard.\n");
   set_race("human");
   set_class("fighter");
   set_level(5);
   set_gender(1);
   set_al(15);
   arm = clone_object("d/ss/items/leather");
   weap = clone_object("d/ss/items/shortsword");
   arm->move(this_object());
   weap->move(this_object());
   init_equip();
}

