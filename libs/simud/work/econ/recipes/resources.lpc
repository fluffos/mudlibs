void create() {
	"/daemon/recipe"->add_recipe( "adamant",
	([
		"ingredients": ({ ({ ([ C_RAW, C_ADAMANTORE ]), 1 }) }),
		"skills": ([ "craft.smithing.black":100,
					 "knowledge.science.geology":75 ]),
		"output": (: return clone_object("/econ/raw/adamant"); :)
	]) );

	"/daemon/recipe"->add_recipe( "aluminum",
	([
		"ingredients": ({ ({ ([ C_RAW, C_ALUMINUMORE ]), 1 }) }),
		"skills": ([ "craft.smithing.white":100,
					 "knowledge.science.geology":90 ]),
		"output": (: return clone_object("/econ/raw/aluminum"); :)
	]) );

	"/daemon/recipe"->add_recipe( "brass",
	([
		"ingredients": ({ ({ ([ C_RAW, C_COPPER ]), 2 }),
			   			  ({ ([ C_RAW, C_ZINC ]), 1 }) }),
		"skills": ([ "craft.smithing.white":50,
					 "craft.smithing.black":60 ]),
		"output": (: object ob = clone_object("/econ/raw/brass");
					 ob->set_quantity(3);
					 return ob; :)
	]) );

	"/daemon/recipe"->add_recipe( "bronze",
	([
		"ingredients": ({ ({ ([ C_RAW, C_TIN ]), 1 }),
			   			  ({ ([ C_RAW, C_COPPER ]), 1 }) }),
		"skills": ([ "craft.smithing.white":20,
					 "craft.smithing.black":40 ]),
   		"comment": "Everyone starts with this recipe, for now...",
		"output": (: object ob = clone_object("/econ/raw/bronze");
					 ob->set_quantity(2);
					 return ob; :)
	]) );

	"/daemon/recipe"->add_recipe( "copper",
	([
		"ingredients": ({ ({ ([ C_RAW, C_COPPERORE ]), 1 }) }),
		"skills": ([ "craft.smithing.black":10,
					 "knowledge.science.geology":10 ]),
   		"comment": "Everyone starts with this recipe",
		"output": (: return clone_object("/econ/raw/copper"); :)
	]) );

	"/daemon/recipe"->add_recipe( "electrum",
	([
		"ingredients": ({ ({ ([ C_RAW, C_GOLD ]), 3 }),
			   			  ({ ([ C_RAW, C_SILVER ]), 1 }) }),
		"skills": ([ "craft.smithing.white":90 ]),
		"output": (: object ob = clone_object("/econ/raw/electrum");
					 ob->set_quantity(4);
					 return ob; :)
	]) );
	
	"/daemon/recipe"->add_recipe( "gold",
	([
		"ingredients": ({ ({ ([ C_RAW, C_GOLDORE ]), 1 }) }),
		"skills": ([ "craft.smithing.white":80,
					 "knowledge.science.geology":25 ]),
		"output": (: return clone_object("/econ/raw/gold"); :)
	]) );

	"/daemon/recipe"->add_recipe( "hardened steel",
	([
		"ingredients": ({ ({ ([ C_RAW, C_STEEL ]), 3 }),
			   			  ({ ([ C_RAW, C_NICKEL ]), 1 }) }),
		"skills": ([ "craft.smithing.black":90 ]),
		"output": (: object ob = clone_object("/econ/raw/hardened_steel");
					 ob->set_quantity(4);
					 return ob; :)
	]) );
	
	"/daemon/recipe"->add_recipe( "iron",
	([
		"ingredients": ({ ({ ([ C_RAW, C_IRONORE ]), 1 }) }),
		"skills": ([ "craft.smithing.black":50,
					 "knowledge.science.geology":25 ]),
		"output": (: return clone_object("/econ/raw/iron"); :)
	]) );

	"/daemon/recipe"->add_recipe( "lead",
	([
		"ingredients": ({ ({ ([ C_RAW, C_LEADORE ]), 1 }) }),
		"skills": ([ "craft.smithing.white":1,
					 "knowledge.science.geology":10 ]),
   		"comment": "Everyone starts with this recipe",
		"output": (: return clone_object("/econ/raw/lead"); :)
	]) );
	
	"/daemon/recipe"->add_recipe( "mithril",
	([
		"ingredients": ({ ({ ([ C_RAW, C_LEADORE ]), 1 }) }),
		"skills": ([ "craft.smithing.black":90,
				     "craft.smithing.white":50,
					 "knowledge.science.geology":50 ]),
   		"comment": "Everyone starts with this recipe",
		"output": (: return clone_object("/econ/raw/lead"); :)
	]) );
	
	"/daemon/recipe"->add_recipe( "nickel",
	([
		"ingredients": ({ ({ ([ C_RAW, C_NICKELORE ]), 1 }) }),
		"skills": ([ "craft.smithing.black":70,
					 "knowledge.science.geology":25 ]),
		"output": (: return clone_object("/econ/raw/nickel"); :)
	]) );
	
	"/daemon/recipe"->add_recipe( "orichalcum",
	([
		"ingredients": ({ ({ ([ C_RAW, C_ORICHALCUMORE ]), 1 }) }),
		"skills": ([ "craft.smithing.white":100,
					 "magic.mana.fire":50,
					 "magic.mana.earth":50,
					 "magic.mana.wind":50,
					 "magic.mana.water":50 ]),
		"output": (: return clone_object("/econ/raw/orichalcum"); :)
	]) );

   "/daemon/recipe"->add_recipe( "pewter",
	([
 		"ingredients": ({ ({ ([ C_RAW, C_TIN ]), 3 }),
						  ({ ([ C_RAW, C_LEAD]), 1 }) }),
		"skills": ([ "craft.smithing.white":30 ]),
   		"output": (: object ob = clone_object("/econ/raw/pewter");
			   		 ob->set_quantity(4);
				 	 return ob; :)
	]) );

	"/daemon/recipe"->add_recipe( "platinum",
	([
		"ingredients": ({ ({ ([ C_RAW, C_PLATINUMORE ]), 1 }) }),
		"skills": ([ "craft.smithing.white":90,
					 "knowledge.science.geology":50 ]),
		"output": (: return clone_object("/econ/raw/platinum"); :)
	]) );

	"/daemon/recipe"->add_recipe( "silver",
	([
		"ingredients": ({ ({ ([ C_RAW, C_SILVERORE ]), 1 }) }),
		"skills": ([ "craft.smithing.white":60,
					 "knowledge.science.geology":25 ]),
		"output": (: return clone_object("/econ/raw/silver"); :)
	]) );

   // carbon content is between 0.10 and 2% in steel, 2.5 and 6% in cast iron.
   "/daemon/recipe"->add_recipe( "steel",
	([
 		"ingredients": ({ ({ ([ C_RAW, C_IRON ]), 5 }),
						  ({ ([ C_RAW, C_COAL ]), 1 }) }),
		"skills": ([ "craft.smithing.black":80,
					 "knowledge.science.geology":25 ]),
   		"output": (: object ob = clone_object("/econ/raw/steel");
			   		 ob->set_quantity(6);
				 	 return ob; :)
	]) );

	"/daemon/recipe"->add_recipe( "tin",
	([
		"ingredients": ({ ({ ([ C_RAW, C_TINORE ]), 1 }) }),
		"skills": ([ "craft.smithing.white":10,
					 "knowledge.science.geology":10 ]),
		"output": (: return clone_object("/econ/raw/tin"); :)
	]) );

   // in parts per thousand: Gold 750, Silver 40, Copper 40, Palladium 170
   // Update -
   //   there are actually plenty of different types of 'white gold' out there,
   //   I am implementing something much more simple for reasons of basic
   //   game playability - Al [Jul 10, '05]
   "/daemon/recipe"->add_recipe( "white gold",
	([
	"ingredients": ({ ({ ([ C_RAW, C_GOLD ]), 4 }),
		   			  ({ ([ C_RAW, C_PLATINUM ]), 1 }),
					  ({ ([ C_RAW, C_SILVER ]), 1 }) }),
	"skills": ([ "craft.smithing.white":100 ]),
	"output": (: object ob = clone_object("/econ/raw/white_gold");
		   		 ob->set_quantity(6);
				 return ob; :)
	]) );

	"/daemon/recipe"->add_recipe( "zinc",
	([
		"ingredients": ({ ({ ([ C_RAW, C_ZINCORE ]), 1 }) }),
		"skills": ([ "craft.smithing.white":50,
					 "knowledge.science.geology":25 ]),
		"output": (: return clone_object("/econ/raw/zinc"); :)
	]) );
}

/* References:
 *  - http://www.archimetal.com/British/produits/acier/cadres/cadres_que_acier.htm
 *  - http://www.24carat.co.uk/whatiswhitegold.html
 */
