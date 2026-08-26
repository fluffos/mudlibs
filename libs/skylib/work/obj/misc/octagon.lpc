
#define CREATOR "Ceres"
/*
 * A magical octagon that when worn will prevent things hurting you or
 * fighting you.
 */

#define PATH "/obj/misc/"
inherit "/obj/armour";

object shadow, player;

void setup() {
   set_name("octagon");
   add_adjective("octiron");
   set_short("octiron octagon");
   set_long("This is an octagonal medallion made of octiron. It is "
                 "highly magical and will protect the wearer from being "
                 "attacked.\n");
   set_type("necklace");
   set_wear_remove_func(this_object(), "wear_remove");
   set_value(1);
   setup_armour(50000);
   set_damage_chance(0);
   set_weight(1);
   add_property( "no recycling", 1 );
}

void dest_me() {
  if(shadow)
    shadow->dest_shadow();
  ::dest_me();
}

void wear_remove(object ob) {
  if(!ob) {
    write("As you remove the Octagon you feel its protection leave you.\n");
    if(shadow)
      shadow->dest_shadow();
  } else {
    if(!creatorp(ob)) {
      write("As you try to wear the octagon it disappears with a flash.\n");
      this_object()->dest_me();
      return;
    }
    
    shadow = clone_object( PATH+"octagon_shadow");
    shadow->setup_shadow(this_player());
    write("As you wear the octagon you feel a sense of peace and safety.\n");
  }
}
