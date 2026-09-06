void create() {
   "/daemon/recipe"->add_recipe( "4-sided die",
	([
		"ingredients": ({ ({ ([ C_WOOD, C_RAW ]), 1 }) }),
		"skills": ([ "craft.carpentry.furniture":10, "knowledge.science.mathematics":10 ]),
		"tools": ({ C_KNIFE }),
		"output": (: object obj = clone_object("/items/die");
                     obj->set_num_sides(4); return obj; :)
	]) );
   "/daemon/recipe"->add_recipe( "6-sided die",
	([
		"ingredients": ({ ({ ([ C_WOOD, C_RAW ]), 1 }) }),
		"skills": ([ "craft.carpentry.furniture":10 ]),
		"tools": ({ C_KNIFE }),
		"output": (: clone_object("/items/die") :)
	]) );
   "/daemon/recipe"->add_recipe( "8-sided die",
	([
		"ingredients": ({ ({ ([ C_WOOD, C_RAW ]), 1 }) }),
		"skills": ([ "craft.carpentry.furniture":20, "knowledge.science.mathematics":10 ]),
		"tools": ({ C_KNIFE }),
		"output": (: object obj = clone_object("/items/die");
                     obj->set_num_sides(8); return obj; :)
	]) );
   "/daemon/recipe"->add_recipe( "10-sided die",
	([
		"ingredients": ({ ({ ([ C_WOOD, C_RAW ]), 1 }) }),
		"skills": ([ "craft.carpentry.furniture":30, "knowledge.science.mathematics":20 ]),
		"tools": ({ C_KNIFE }),
		"output": (: object obj = clone_object("/items/die");
                     obj->set_num_sides(10); return obj; :)
	]) );
   "/daemon/recipe"->add_recipe( "12-sided die",
	([
		"ingredients": ({ ({ ([ C_WOOD, C_RAW ]), 1 }) }),
		"skills": ([ "craft.carpentry.furniture":30, "knowledge.science.mathematics":20 ]),
		"tools": ({ C_KNIFE }),
		"output": (: object obj = clone_object("/items/die");
                     obj->set_num_sides(12); return obj; :)
	]) );
   "/daemon/recipe"->add_recipe( "20-sided die",
	([
		"ingredients": ({ ({ ([ C_WOOD, C_RAW ]), 1 }) }),
		"skills": ([ "craft.carpentry.furniture":40, "knowledge.science.mathematics":30 ]),
		"tools": ({ C_KNIFE }),
		"output": (: object obj = clone_object("/items/die");
                     obj->set_num_sides(20); return obj; :)
	]) );
}
