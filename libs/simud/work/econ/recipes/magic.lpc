void create() {
	"/daemon/recipe"->add_recipe( "ebony wand",
	([
		"ingredients": ({ ({ ([ C_WOOD, C_APPLEWOOD, C_RAW ]), 1 }),
						  ({ ([ C_CRYSTAL, C_FIRE_MANA ]), 1 }) }),
		"skills": ([ "craft.carpentry.furniture":20,
					 "magic.item.wand":20,
					 "magic.mana.fire":50 ]),
		"output": (: clone_object("/items/wand_fire") :)
	]) );

	"/daemon/recipe"->add_recipe( "plum staff",
	([
		"ingredients": ({ ({ ([ C_WOOD, C_PLUMWOOD, C_RAW ]), 8 }),
						  ({ ([ C_CRYSTAL, C_ICE_MANA ]), 3 }),
						  ({ ([ C_RAW, C_SILVER ]), 15 }) }),
		"skills": ([ "craft.carpentry.furniture":30,
				     "magic.item.staff":20,
					 "magic.mana.earth":40,
					 "magic.technique.enchanting":40,
					 "magic.technique.animating":20,
					 "magic.mana.ice":60 ]),
		"output": (: clone_object("/items/weapon/plum_staff") :)
	]) );
	
   "/daemon/recipe"->add_recipe( "mana potion",
([
   "ingredients": ({
		({ ([ C_CRYSTAL, C_SPIRIT_MANA ]), 1 }),
   		({ ([ C_RAW, C_LEAD ]), 8 }),
		({ ([ C_RAW, C_WATER, C_LIQUID ]), 160 }),
   }),
   "skills": ([ "knowledge.alchemy":20, "craft.smithing.white":10,
		        "magic.mana.spirit":40 ]),
   //"tools": ({ C_VAT }),
   "output": (: object ob = clone_object("/items/alchemy/blue_potion");
		        ob->set_quantity(6 + random(3));
				return ob;
		      :),
   "comment": "This recipe produces 6-8 potions per batch."
]) );

   "/daemon/recipe"->add_recipe( "heal potion",
([
   "ingredients": ({
		({ ([ C_CRYSTAL, C_EARTH_MANA ]), 1 }),
   		({ ([ C_RAW, C_LEAD ]), 8 }),
		({ ([ C_RAW, C_WATER, C_LIQUID ]), 160 }),
   }),
   "skills": ([ "knowledge.alchemy":20, "craft.smithing.white":10,
		        "magic.mana.earth":40 ]),
   "output": (: object ob = clone_object("/items/alchemy/white_potion");
		        ob->set_quantity(6 + random(3));
				return ob;
		      :),
   "comment": "This recipe produces 6-8 potions per batch."
]) );

   "/daemon/recipe"->add_recipe( "aid potion",
([
   "ingredients": ({
		({ ([ C_CRYSTAL, C_WATER_MANA ]), 1 }),
   		({ ([ C_RAW, C_LEAD ]), 4 }),
		({ ([ C_RAW, C_WATER, C_LIQUID ]), 80 }),
   }),
   "skills": ([ "knowledge.alchemy":30, "craft.smithing.white":10,
		        "magic.mana.water":60 ]),
   "output": (: object ob = clone_object("/items/alchemy/bright_yellow_potion");
		        ob->set_quantity(3 + random(2));
				return ob;
		      :),
   "comment": "This recipe produces 3-4 potions per batch."
]) );

   "/daemon/recipe"->add_recipe( "potential potion",
([
   "ingredients": ({
		({ ([ C_CRYSTAL, C_CHAOS_MANA ]), 1 }),
   		({ ([ C_RAW, C_LEAD ]), 1 }),
		({ ([ C_RAW, C_WATER, C_LIQUID ]), 20 }),
   }),
   "skills": ([ "knowledge.alchemy":40, "craft.smithing.white":10,
		        "magic.mana.chaos":80 ]),
   "output": (: return clone_object("/items/alchemy/bubbling_orange_potion"); :),
   "comment": "This recipe produces only one potion at a time."
]) );

	/*
   "/daemon/recipe"->add_recipe( "wooden golem",
	([
		"ingredients": ({ ({ ([ C_WOOD, C_RAW ]), 4000 }) }),
		"skills": ([ "craft.carpenter":70 ]),
		"output": (: object obj = clone_object("/magic/obj/golem_body");
                     obj->set_golem_type("wood"); return obj; :)
	]) );
   "/daemon/recipe"->add_recipe( "stone golem",
	([
		"ingredients": ({ ({ ([ C_STONE, C_RAW ]), 4000 }) }),
		"skills": ([ "craft.sculptor":70 ]),
		"output": (: object obj = clone_object("/magic/obj/golem_body");
                     obj->set_golem_type("stone"); return obj; :)
	]) );
   "/daemon/recipe"->add_recipe( "iron golem",
	([
		"ingredients": ({ ({ ([ C_IRON, C_RAW ]), 4000 }) }),
		"skills": ([ "craft.blacksmith":70 ]),
		"output": (: object obj = clone_object("/magic/obj/golem_body");
                     obj->set_golem_type("iron"); return obj; :)
	]) );
	*/
}
