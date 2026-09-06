void create() {
	"/daemon/recipe"->add_recipe( "new broadsword",
	([
		"ingredients": ({ ({ ([ C_WOOD, C_RAW ]), 2 }), ({ ([ C_IRON, C_RAW ]), 4 }) }),
		"skills": ([ "craft.smithing.black": 40, "craft.smithing.weapons": 20 ]),
		"tools": ({ C_HAMMER, C_ANVIL, C_FORGE }),
		"comment": "Al has much hate for whoever wrote this stupid sword :P",
		"output": (: return clone_object("/items/weapon/broadsword"); :)
	]) );
}
