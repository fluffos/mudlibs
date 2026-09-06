void create() {
   "/daemon/recipe"->add_recipe( "carrot seed",
([
   "ingredients": ({ ({ ([ C_CROP, C_CARROT, C_FOOD ]), 1 }) }),
   "skills": ([ "craft.farming": 20 ]),
   "output": (: clone_object("/econ/seed/carrot") :)
]) );

   "/daemon/recipe"->add_recipe( "onion seed",
([
   "ingredients": ({ ({ ([ C_CROP, C_ONION, C_FOOD ]), 1 }) }),
   "skills": ([ "craft.farming": 10 ]),
   "output": (: clone_object("/econ/seed/onion") :)
]) );

   "/daemon/recipe"->add_recipe( "lettuce seed",
([
   "ingredients": ({ ({ ([ C_CROP, C_LETTUCE, C_FOOD ]), 1 }) }),
   "skills": ([ "craft.farming": 20 ]),
   "output": (: clone_object("/econ/seed/lettuce") :)
]) );

   "/daemon/recipe"->add_recipe( "potato seed",
([
   "ingredients": ({ ({ ([ C_CROP, C_POTATO, C_FOOD ]), 1 }) }),
   "skills": ([ "craft.farming": 10 ]),
   "output": (: clone_object("/econ/seed/potato") :)
]) );

   "/daemon/recipe"->add_recipe( "tomato seed",
([
   "ingredients": ({ ({ ([ C_CROP, C_TOMATO, C_FOOD ]), 1 }) }),
   "skills": ([ "craft.farming": 0 ]),
   "output": (: clone_object("/econ/seed/tomato") :)
]) );

   "/daemon/recipe"->add_recipe( "pumpkin seed",
([
   "ingredients": ({ ({ ([ C_CROP, C_PUMPKIN, C_FOOD ]), 1 }) }),
   "skills": ([ "craft.farming": 0 ]),
   "output": (: object ob = clone_object("/econ/seed/pumpkin");
                ob->set_quantity(6);
			    return ob;	:)
]) );
}
