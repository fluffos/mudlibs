void create() {
   "/daemon/recipe"->add_recipe( "paper",
([
   "ingredients": ({ ({ ([ C_WOOD, C_RAW ]), 1 }), ({ ([ C_LIQUID, C_WATER, C_RAW ]), 300 })  }),
   "skills": ([ "knowledge.herbology":10 ]),
   "output": (: return clone_object("/items/paper"); :)
]) );

	"/daemon/recipe"->add_recipe( "spellbook",
	([
		"ingredients": ({ ({ ([ C_LEATHER, C_THIN, C_RIGID, C_RAW ]), 2 }),
						  ({ ([ C_PAPER, C_RAW ]), 20 }) }),
        "skills": ([ "craft.leatherworking":20,
				     "knowledge.arcana":20,
					 "magic.item.scroll":80,
					 "magic.item.misc":30 ]),
		"output": (: return clone_object("/magic/obj/spellbook"); :)
	]) );
}
