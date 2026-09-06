void create() {
   "/daemon/recipe"->add_recipe( "smith",
([
   "ingredients": ({ ({ ([ C_RAW, C_WOOD ]), 1000 }), ({ ([ C_RAW, C_STONE ]), 150 }), ({ ([ C_RAW, C_IRON ]), 20 }) }),
   "skills": ([ "craft.masonry":40, "craft.carpentry.buildings":30, "craft.smithing.black":20, "knowledge.architecture":20 ]),
   //"tools": ({ C_HAMMER }),
   "output": (: return clone_object("/bldg/smith"); :),
   "comment": "A smithy is a single-room building appropriate for crafting "+
              "metal products. Eventually, the places will come furnished "+
			  "with an anvil, forge, and other required furniture, but until "+
			  "then, the place will just look cool.",
   "type": "structure"
]) );

   "/daemon/recipe"->add_recipe( "house",
([
   "ingredients": ({ ({ ([ C_RAW, C_WOOD ]), 3200 }), ({ ([ C_RAW, C_STONE ]), 200 }) }),
   "skills": ([ "craft.masonry":30, "craft.carpentry.buildings":20 ]),
   "output": (: return clone_object("/bldg/house"); :),
   //"tools": ({ C_HAMMER }),
   "comment": "Houses are currently the largest player-built residences in "+
              "the game. They are divided up into six different rooms split "+
			  "over two floors.",
   "type": "structure"
]) );

   "/daemon/recipe"->add_recipe( "cottage",
([
   "ingredients": ({ ({ ([ C_RAW, C_WOOD ]), 750 }), ({ ([ C_RAW, C_STONE ]), 75 }) }),
   "skills": ([ "craft.masonry":10, "craft.carpentry.buildings":10 ]),
   "output": (: return clone_object("/bldg/cottage"); :),
   //"tools": ({ C_HAMMER }),
   "comment": "Cottages are the middle-class player's housing of choice. "+
              "Weighing in at two rooms, they are inexpensive and roomy "+
			  "enough for almost all of one's possible storage and "+
			  "entertaining needs.",
   "type": "structure"
]) );

   "/daemon/recipe"->add_recipe( "farmhouse",
([
   "ingredients": ({ ({ ([ C_RAW, C_WOOD ]), 650 }), ({ ([ C_RAW, C_STONE ]), 50 }), ({ ([ C_RAW, C_IRON ]), 5 }) }),
   "skills": ([ "craft.masonry":8, "craft.carpentry.buildings":8 ]),
   "output": (: return clone_object("/bldg/farm"); :),
   //"tools": ({ C_HAMMER }),
   "comment": "Farmhouses are only useful if you can find a cooperative person to " +
      "act as the farmer. If you can, however, they gradually produce food. Farms " +
      "eventually produce children, which can grow up, be hired, and work elsewhere.",
   "type": "structure"
]) );

   "/daemon/recipe"->add_recipe( "barracks",
([
   "ingredients": ({ ({ ([ C_RAW, C_WOOD ]), 400 }), ({ ([ C_RAW, C_STONE ]), 750 }) }),
   "skills": ([ "craft.masonry":50, "craft.carpentry.buildings":25, "knowledge.architecture":15 ]),
   "output": (: return clone_object("/bldg/barracks"); :),
   //"tools": ({ C_HAMMER }),
   "comment": "Barracks are where guards and soldiers are housed.",
   "type": "structure"
]) );

   "/daemon/recipe"->add_recipe( "mine",
([
   "ingredients": ({ ({ ([ C_RAW, C_WOOD ]), 800 }) }),
   "skills": ([ "knowledge.science.geology":20, "craft.carpentry.buildings":10 ]),
   "output": (: return clone_object("/bldg/mine"); :),
   "tools": ({ C_PICK }),
   /* "comment": "Everyone starts with this recipe\n"+
              "Mines must be built into a mountain face. ,*/
   "type": "structure"
]) );

   "/daemon/recipe"->add_recipe( "shack",
([
   "ingredients": ({ ({ ([ C_RAW, C_WOOD ]), 400 }) }),
   "skills": ([ "craft.carpentry.buildings":0 ]),
   "output": (: return clone_object("/bldg/shack"); :),
   "comment": "Everyone starts with this recipe",
   "type": "structure"
]) );

   "/daemon/recipe"->add_recipe( "shop",
([
   "ingredients": ({ ({ ([ C_RAW, C_WOOD ]), 1000 }), ({ ([ C_RAW, C_STONE ]), 50 }), ({ ([ C_RAW, C_LEAD ]), 10 }) }),
   "skills": ([ "craft.masonry":30, "craft.carpentry.buildings":20 ]),
   //"tools": ({ C_HAMMER }),
   "output": (: return clone_object("/bldg/shop"); :),
   "comment": "Everyone starts with this recipe",
   "type": "structure"
]) );

   "/daemon/recipe"->add_recipe( "stall",
([
   "ingredients": ({ ({ ([ C_RAW, C_WOOD ]), 12 }),
		  			 ({ ([ C_RAW, C_CLOTH ]), 16 }) }),
   "skills": ([ "craft.carpentry.buildings":0 ]),
   "output": (: return clone_object("/bldg/stall"); :),
   "type": "structure"
]) );

   "/daemon/recipe"->add_recipe( "store",
([
   "ingredients": ({ ({ ([ C_RAW, C_WOOD ]), 2000 }), ({ ([ C_RAW, C_STONE ]), 75 }), ({ ([ C_RAW, C_IRON ]), 20 }), ({ ([ C_RAW, C_LEAD ]), 10 }) }),
   "skills": ([ "craft.masonry":30, "craft.carpentry.buildings":30 ]),
   //"tools": ({ C_HAMMER }),
   "output": (: return clone_object("/bldg/store"); :),
   "type": "structure"
]) );

   "/daemon/recipe"->add_recipe( "foundstone",
([
   "ingredients": ({ ({ ([ C_RAW, C_WOOD ]), 5 }), ({ ([ C_RAW, C_STONE ]), 20 }), ({ ([ C_RAW, C_IRON ]), 5 }), ({ ([ C_RAW, C_LEAD ]), 5 }) }),
   "skills": ([ "craft.masonry":10, "craft.carpentry.buildings":10, "craft.art.sculpture":10 ]),
   //"tools": ({ C_HAMMER }),
   "output": (: return clone_object("/bldg/foundstone"); :),
   "type": "structure"
]) );
   "/daemon/recipe"->add_recipe( "field",
([
   "ingredients": ({ ({ ([ C_SEED, C_CROP ]), 15 }), ({ ([ C_RAW, C_WOOD ]), 10 }) }),
   "pure": 1,
   "skills": ([ "craft.farming":0 ]),
   //"tools": ({ C_PLOW }),
   "output": (: return clone_object("/bldg/field"); :),
   "comment": "Everyone starts with this recipe",
   "type": "structure"
]) );
}
