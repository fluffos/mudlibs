
#include <std.h>

inherit FOOD;

void create() {
  ::create();
  switch (random(4)) {
    case 0:
    case 3:
      set_short("a breadfruit");
      set_long("This round, green, bumpy fruit has fallen "
	       "from one of the trees. Its skin is still intact however, "
	       "so it should be fine to eat.");
      set_id( ({ "breadfruit", "bread fruit", "fruit", "bread" }) );
      set_strength(20);
      set_my_mess("You crack open the raw breadfruit and "
	          "manage to eat some of the starchy fruit.");
      set_your_mess("$N cracks open a breadfruit and manages to "
	            "eat some of the starchy fruit.");
      set_taste("default", "The bumpy skin doesn't have much taste at all.");
      set_weight(1);
    break;

    case 1:
      set_short("a jackfruit");
      set_long("An oval, pale green, and bumpy fruit that looks very similar to "
	       "the breadfruit, but a little smaller. This one has no cracks "
	       "and is safe to eat.");
      set_id( ({ "jackfruit", "jack fruit", "fruit" }) );
      set_strength(30);
      set_my_mess("You crack open the jackfruit and nibble at the sweet "
	          "fruit within.");
      set_your_mess("$N cracks open a jackfruit and nibbles at the sweet "
	            "fruit within.");
      set_taste("default", "The bumpy skin doesn't have much taste at all.");
      set_weight(1);
    break;

    case 2:
      set_short("a large durian fruit");
      set_long("This fruit is a couple feet long, dark green, and covered in "
	       "short thorns. It is rather heavy. This particular fruit seems "
	       "unharmed from having fallen from a tree.");
      set_id( ({ "durian", "durian fruit", "large durian",
	         "large durian fruit" }) );
      set_strength(45);
      set_my_mess("You crack open the durian fruit, hold your nose, and "
	          "slurp down the sweet custardy flesh.");
      set_your_mess("$N cracks open the durian fruit, holds $P nose, and "
	          "slurps down the sweet custardy flesh.");
      set_taste("default", "You hurt your tongue on the thorns!");
      set_smell("default", "An amazingly strong, almost rancid odor "
	                   "nearly overcomes you. Phew!");
      set_weight(3);
    break;
  }
  set_curr_value("gold", 0);
  set_servings(1);
}

