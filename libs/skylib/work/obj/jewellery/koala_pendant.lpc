inherit CLOTHING_OBJ;

void setup() {
  set_name("pendant");
  set_short("gold Koala pendant");
  set_long("The gold is forged in the shape of a cute Koala hanging onto the "
           "branch of a eucalyptus tree.  The Koala appears to be smiling "
           "and sparkling like a star.\n");
  add_plural("jewellery");
  add_alias("jewellery");
  set_type("badge");
  add_property("shop type", "jewellers");
  set_value(2000);
  setup_clothing(1000);
  set_damage_chance(2);
  add_read_mess("Quality fluff designs.", "carefully etched writing", 
                "common", 1);
  set_weight(1);
} /* setup() */

void init() {
  add_command("model", "<direct:object> for <indirect:living>");
  add_command("snuggle", "<direct:object>");
} /* init() */

int do_model(object *obs) {
  add_succeeded_mess("$N $V $D to $I.\n", obs);
  return 1;
} /* do_model() */

int do_snuggle() {
  add_succeeded_mess("$N $V $D which snuggles back up to them.\n");
  return 1;
} /* do_snuggle() */
