/*  Golden Sickle  *
 *     Belraath    *
 *     April 97    */

inherit "/obj/weapon";

void setup() {
  set_name("sickle");
  set_short("golden sickle");
  add_adjective("golden");
  set_long("This is a vicious-looking, crescent shaped, golden "
           "sickle, intricately carved with a mushroom and "
           "bonfire pattern.  The blade is coated with a greasy, "
           "sticky-looking substance.\n");
  new_weapon(5000);
  set_damage_chance(10);
  set_weight(10);
  set_value(2000);
  add_property("no recycling", 1);
  add_attack("slice", 75, ({ 20, 5, 30 }), "sharp",  "sharp", "poison");
  add_attack("stab", 50, ({ 20, 4, 45 }), "pierce", "sharp", "poison");
} /* setup() */

void poison(int, object him, object me, string, string) {
  if(random(5) == 1) {
    tell_room(environment(me),
      him->the_short()+" suddenly pales, and doesn't look "
        "at all well!\n", him);
    tell_object(him,
      "You feel yourself weakening, and realise you suddenly "
      "don't feel at all well!\n");
    him->add_effect("/std/effects/poisons/spider_venom", 100);
  }
} /* poison() */
