inherit "/std/barkeep";

create() {
 ::create();
   set_name("waitress");
   set_id( ({ "waitress", "friendly waitress" }) );
   set_short("a friendly waitress");
   set("aggressive", 0);
   set_level(12);
   set_long("The young girl was hired by the Weeping Willow to serve the "
     "customers. She happily does her job, and waits to help you.");
   set_gender("female");
   set_alignment(164);
   set("race", "nymph");
   add_money("copper", random(200));
   set_skill("melee", 90);
   set_body_type("human");
   set_hp(300);
   set_currency("gold");
set_menu( ([
  "venison" : ([
    "type" : "food",
    "strength" : 55,
    "servings" : 2,
    "short" : "grilled venison",
    "long" : "The venison was grilled in the "
      "Weeping Willow Restaurant, it looks great!",
  ]),
  "stew" : ([
    "type" : "food",
    "strength" : 40,
    "servings" : 3,
    "short" : "a bowl of stew",
    "long" : "A thick broth with vegetables and spices.",
  ]),
  "duck" : ([
    "type" : "food",
    "strength" : 32,
    "servings" : 3,
    "short" : "BBQ duck",
    "long" : "Barbequed to perfection. It looks a lot like chicken.",
  ]),
  "fries" : ([
    "type" : "food",
    "strength" : 12,
    "servings" : 4,
    "short" : "some fries",
    "my_mess" : "You eat the fries one by one.",
    "your_mess" : "eats some fries one by one.",
  ]),
  "quail" : ([
    "type" : "food",
    "strength" : 21,
    "servings" : 2,
    "short" : "roasted quail",
    "long" : "Roasted on the Weeping Willow grills, quail makes a good meal.",
  ]),
  "water" : ([
    "type" : "soft drink",
    "strength" : 17,
    "servings" : 3,
    "short" : "ice cold water",
  ]),
]) );
}
