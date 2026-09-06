void create() {
   "/daemon/recipe"->add_recipe( "flour",
   ([
       "ingredients": ({ ({ ([ C_GRAIN, C_SEED ]), 250 }) }),
      // really is 'milling', but yeah
      "skills": ([ "craft.cooking":20 ]),
      "output": (:
         object ob = clone_object("/items/food/flour");
         ob->set_quantity(250);
         return ob;
      :),
      "liquid": 250,
      "pure": 1,
      "aspect": ([ C_BARLEY, C_CORN, C_OATS, C_RICE, C_RYE, C_WHEAT ]),
    ]) );

   // This is for things like olive, corn, soy, etc...
   "/daemon/recipe"->add_recipe( "oil",
   ([
      "ingredients": ({ }),
      "skills": ([ "craft.cooking": 20 ]),
      "output": 0,
      "liquid": 250,
      "pure": 1,
      "aspect": ([ ])
   ]) );

   "/daemon/recipe"->add_recipe( "fruit juice",
   ([
       "ingredients": ({ ({ ([ C_RAW, C_SEED, C_FRUIT ]), 1 }),
                       ({ ([ C_RAW, C_WATER, C_LIQUID ]), 450 }) }),
      "skills": ([ "craft.cooking":20 ]),
      "aspect": ([ C_APPLE, C_BANANA, C_ORANGE, C_PLUM ]),
      "liquid": 500,
      "pure": 1
   ]) );

   "/daemon/recipe"->add_recipe( "grain",
   ([
       "ingredients": ({ ({ ([ C_CROP, C_GRAIN ]), 1 }) }),
      "skills": ([ "craft.farming":10 ]),
      "output": (: object ob = clone_object("/items/food/grain");
                ob->set_quantity(100);
                return ob; :),
      "liquid": 100,
      "aspect": ([ C_BARLEY, C_OATS, C_RICE, C_RYE, C_WHEAT, C_CORN ]),
      "comment": "This resultant grain is usable as seed for crops under the normal system, one ml of grain counting as one seed. You do the math."
   ]) );

   "/daemon/recipe"->add_recipe( "jerky",
   ([
      "ingredients": ({ ({ ([ C_MEAT, C_RAW ]), 1 }),
                       ({ ([ C_FOOD, C_SALT ]), 1 }) }),
      "skills": ([ "craft.cooking":10 ]),
      "output": (:
         object ob = clone_object("/items/food/jerky");
         ob->set_quantity(10);
         return ob;
      :)
   ]) );

   "/daemon/recipe"->add_recipe( "lemonade",
   ([
       "ingredients": ({ ({ ([ C_RAW, C_SEED, C_LEMON ]), 3 }),
                       ({ ([ C_RAW, C_WATER, C_LIQUID ]), 400 }),
                    ({ ([ C_FOOD, C_SUGAR ]), 10 }) }),
      "skills": ([ "craft.cooking":30 ]),
      "liquid": 500,
      "pure": 1
   ]) );

   "/daemon/recipe"->add_recipe( "roast pumpkin seed",
   ([
       "ingredients": ({ ({ ([ C_PUMPKIN, C_SEED ]), 3 }),
                       ({ ([ C_FOOD, C_SALT ]), 1 })   }),
      "skills": ([ "craft.cooking":10 ]),
      "output": (:
         object ob = clone_object("/items/food/pumpkin_seed");
         ob->set_quantity(3);
         return ob;
      :)
   ]) );

   "/daemon/recipe"->add_recipe( "salt",
   ([
       "ingredients": ({ ({ ([ C_RAW, C_SALT ]), 1 }) }),
      "skills": ([ "craft.cooking":0 ]),
      "output": (: object ob = clone_object("/items/food/salt");
                ob->set_quantity(220);
                return ob; :),
      "liquid": 220,
   ]) );

   // most decidedly un-scientifical
   "/daemon/recipe"->add_recipe( "sea salt",
   ([
       "ingredients": ({ ({ ([ C_RAW, C_WATER, C_SALT ]), 1000 }) }),
      "skills": ([ "craft.cooking":20,
                   "magic.mana.dark":10 ]),
      "output": (: object ob = clone_object("/items/food/salt");
                ob->set_quantity(3);
                return ob; :),
      "liquid": 3,
   ]) );

   "/daemon/recipe"->add_recipe( "sugar",
   ([
       "comment": "This recipe is available in the CH Municipal Library.",
       "ingredients": ({ ({ ([ C_CROP, C_SUGAR_BEET ]), 1 }) }),
      "skills": ([ "craft.cooking":30 ]),
      "output": (: object ob = clone_object("/items/food/sugar");
                ob->set_quantity(250);
                return ob; :),
      "liquid": 250,
   ]) );
}
