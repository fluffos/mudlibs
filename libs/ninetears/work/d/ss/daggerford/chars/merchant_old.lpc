inherit "obj/monster";
void setup() {
   set_name("merchant");
   add_alias("trader");
   set_main_plural("merchants");
   add_plural("traders");
   set_short("merchant");
   set_long("This merchant is simply a non-descript little man who visits "+
    "Daggerford to sell his valueless vares.  You shouldn't pay much "+
    "to him since he's hardly got anything to offer an adventurer like "+
    "yourself.  Just normal household items and perhaps a fruit or two.\n");
   set_race("human");
   set_level(1);
   set_wimpy(50);
   set_gender(1+random(2));
   set_al(100);

   new("/items/weapon/knife")->move(this_object());
   command("equip");
}
