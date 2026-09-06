void create() {
   "/daemon/recipe"->add_recipe( "store sign",
([
   "ingredients": ({
		({ ([ C_WOOD, C_RAW ]), 50 }),
		({ ([ C_LEAD, C_RAW ]), 4 }),
   }),
   "skills": ([ "craft.carpentry.furniture":10, "craft.art.painting":10 ]),
   "output": (: return clone_object("/obj/store_sign"); :)
]) );

   "/daemon/recipe"->add_recipe( "sign",
([
   "ingredients": ({
      ({ ([ C_WOOD, C_RAW ]), 10 }),
      ({ ([ C_LEAD, C_RAW ]), 4 }),
//      ({ ([ C_SILVER, C_RAW ]), 2 })
   }),
   "skills": ([ "craft.carpentry.furniture":10, "craft.art.painting":10 ]),
   "output": (: return clone_object("/items/sign"); :),
   "comment": "Everyone starts with this recipe",
   "type": "structure"
]) );

   "/daemon/recipe"->add_recipe( "condemnation sign",
([
   "ingredients": ({
      ({ ([ C_WOOD, C_RAW ]), 25 }),
      ({ ([ C_LEAD, C_RAW ]), 2 }),
      ({ ([ C_SILVER, C_RAW ]), 2 })
   }),
   "skills": ([ "craft.carpentry.furniture":10, "craft.art.painting":10 ]),
   "output": (: return clone_object("/items/condemn_sign"); :),
   "type": "structure"
]) );

}
