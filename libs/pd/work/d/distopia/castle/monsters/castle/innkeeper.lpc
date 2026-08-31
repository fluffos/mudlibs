inherit "/std/barkeep";
create() {
 ::create();
   set_name("inn keeper");
set_id( ({ "keeper", "inn keeper", "Aimee", "aimee" }) );
   set_short("Aimee");
   set("aggressive", 0);
set_exp(0);
set_level(215);
   set_long("Aimee is the owner and keeper of the Mad Cow Inn.  She is a delightful and cheerful "
     "young girl that is always willing to help those in need.  However, a glow from her eyes betrays "
     "a very bright spark of power.\n\n%^RED%^%^BOLD%^Warning: Do *not* try to kill Aimee, you will regret it.\n%^RESET%^");
   set_gender("female");
   set_alignment(2000);
   set("race", "nymph");
   add_money("gold", random(800));
   set_body_type("human");
   set_currency("gold");
set_menu( ([
  "mutton" : ([
    "type" : "food",
    "strength" : 50,
    "short" : "roasted mutton",
    "long" : "Roasted sheep... very good.",
    "my_mess" : "That really hit the spot.",
  ]),
  "stew" : ([
    "type" : "food",
    "strength" : 37,
    "short" : "beef stew",
    "my_mess" : "You take a quick slurp, then tip the bowl "
      "and gulp it all down.",
    "your_mess" : "gulps down some stew.",
  ]),
  "ale" : ([
    "type" : "alcoholic",
    "strength" : 9,
    "short" : "a fresh cup of ale",
    "long" : "Frosty and good.",
    "empty" : "cup",
  ]),
  "beer" : ([
    "type" : "alcoholic",
    "strength" : 21,
    "short" : "a pint of beer",
    "long" : "A perfectly chilled pint of beer.",
  ]),
  "special" : ([
    "type" : "alcoholic",
    "strength" : 80,
    "short" : "house special",
    "long" : "A strange looking drink made by Aimee.",
    "my_mess" : "You take a long drink and suddenly start to convulse!",
    "your_mess" : "takes a drink of a house special and starts to convulse.",
  ]),
]) );
}
