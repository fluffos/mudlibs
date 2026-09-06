void create() {
   "/daemon/recipe"->add_recipe( "axe",
([
   "ingredients": ({ ({ ([ C_WOOD, C_RAW ]), 3 }), ({ ([ C_COPPER, C_RAW ]), 3 }) }),
   "skills": ([ "craft.smithing.black": 20, "craft.smithing.weapons": 20 ]),
   "tools": ({ C_HAMMER, C_ANVIL, C_FORGE }),
   "comment": "Everyone starts with this recipe",
   "output": (: return clone_object("/items/weapon/axe"); :)
]) );

   "/daemon/recipe"->add_recipe( "flint and steel",
([
   "ingredients": ({ ({ ([ C_RAW, C_FLINT ]), 1 }), ({ ([ C_RAW, C_STEEL ]), 1 }) }),
   //"skills": ([ "knowledge.science.geology":10 ]),
   "skills": ([]),
   "output": (: return clone_object("/items/tool/flint"); :)
]) );

   "/daemon/recipe"->add_recipe( "hatchet",
([
   "ingredients": ({ ({ ([ C_WOOD, C_RAW ]), 2 }), ({ ([ C_COPPER, C_RAW ]), 1 }) }),
   "tools": ({ C_HAMMER, C_ANVIL, C_FORGE }),
   "skills": ([ "craft.smithing.black": 20 ]),
   "output": (: return clone_object("/items/weapon/hatchet"); :)
]) );

   "/daemon/recipe"->add_recipe( "knife",
([
   "ingredients": ({ ({ ([ C_WOOD, C_RAW ]), 1 }), ({ ([ C_COPPER, C_RAW ]), 2 }) }),
   "tools": ({ C_HAMMER, C_ANVIL, C_FORGE }),
   "skills": ([ "craft.smithing.black": 20 ]),
   "comment": "Everyone starts with this recipe",
   "output": (: return clone_object("/items/weapon/knife"); :)
]) );

   "/daemon/recipe"->add_recipe( "pitchfork",
([
   "ingredients": ({ ({ ([ C_WOOD, C_RAW ]), 4 }), ({ ([ C_COPPER, C_RAW ]), 1 }) }),
   "tools": ({ C_HAMMER, C_ANVIL }),
   "skills": ([ "craft.smithing.black": 20 ]),
   "output": (: return clone_object("/items/weapon/pitchfork"); :)
]) );

   "/daemon/recipe"->add_recipe( "pick",
([
   "ingredients": ({ ({ ([ C_WOOD, C_RAW ]), 2 }), ({ ([ C_COPPER, C_RAW ]), 1 }) }),
   "tools": ({ C_HAMMER, C_ANVIL }),
   "skills": ([ "craft.smithing.black": 20 ]),
   "comment": "Everyone starts with this recipe",
   "output": (: return clone_object("/items/weapon/pick"); :)
]) );
}
