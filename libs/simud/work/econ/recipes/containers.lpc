void create() {
   "/daemon/recipe"->add_recipe( "waterskin",
([
   "ingredients": ({ ({ ([ C_LEATHER, C_RAW ]), 2 })  }),
   "skills": ([ "craft.leatherworking":20 ]),
   "tools": ({ C_NEEDLE }),
   "output": (: return clone_object("/items/container/skin"); :)
]) );
   "/daemon/recipe"->add_recipe( "paper box",
([
   "ingredients": ({ ({ ([ C_PAPER, C_RAW ]), 6 })  }),
   "skills": ([]),
   "output": (: return clone_object("/items/container/paper_box"); :),
   "comment": "Everyone gets this recipe."
]) );
   "/daemon/recipe"->add_recipe( "disposable cup",
([
   "ingredients": ({ ({ ([ C_PAPER, C_RAW ]), 2 })  }),
   "skills": ([]),
   "output": (: return clone_object("/items/container/disposable_cup"); :),
   "comment": "Everyone gets this recipe."
]) );
   "/daemon/recipe"->add_recipe( "bag",
([
   "ingredients": ({ ({ ([ C_LEATHER, C_RAW ]), 4 })  }),
   "skills": ([ "craft.leatherworking":10 ]),
   "tools": ({ C_NEEDLE }),
   "output": (: return clone_object("/items/bag"); :)
]) );
   "/daemon/recipe"->add_recipe( "shop crate",
([
   "ingredients": ({ ({ ([ C_WOOD, C_RAW ]), 10 })  }),
   "skills": ([ "craft.carpentry.furniture":10 ]),
   "tools": ({ C_HAMMER }),
   "output": (: return clone_object("/items/container/price_crate"); :)
]) );
   "/daemon/recipe"->add_recipe( "metal bowl",
([
   "ingredients": ({ ({ ([ C_METAL, C_RAW ]), 2 })  }),
   "skills": ([ "craft.smithing.black":20 ]),
   "tools": ({ C_HAMMER, C_ANVIL }),
   "output": (: return clone_object("/items/metal_bowl"); :),
   "pure": 1
]) );
}
