inherit "/std/barkeep";

create() {
 ::create();
   set_name("vlandross");
   set_id( ({ "vlandross", "barkeep", "bartender" }) );
   set_short("vlandross, the barkeep.");
   set("aggressive", 0);
   set_level(100);
   set_long("Leering with an evil smirk, Vlandross waits to fulfill your order.");
   set_gender("male");
   set_alignment(-200);
   set("race", "human");
   add_money("gold", random(200));
   set_body_type("human");
   set_currency("gold");
 set_menu( ([
  "scones" : ([
    "type" : "food",
    "strength" : 70,
    "short" : "hearty scones",
    "long" : "Large biscuits with nuts and honey",
  ]),
  "boar" : ([
    "type" : "food",
    "strength" : 90,
    "short" : "wild boar",
    "long" : "A shank of wild boar cooked to perfection.",
  ]),
  "boilermaker" : ([
    "type" : "alcoholic",
    "strength" : 70,
    "short" : "boilermaker",
    "long" : "A firebreather dropped into mead.",
  ]),
  "turpentine" : ([
    "type" : "alcoholic",
    "strength" : 90,
    "short" : "turpentine",
    "my_mess" : "You gag on the shot of turp!",
    "your_mess" : "gags on the shot of turp!",
  ]),
  "juice" : ([
    "type" : "soft drink",
    "strength" : 70,
    "short" : "fruit juice",
    "long" : "Freshly squeezed fruit juice.",
  ]),
  "tonic" : ([
    "type" : "soft drink",
    "strength" : 90,
    "short" : "fruit tonic",
    "long" : "Fruit juice seltzer.",
  ]),
]) );
}
