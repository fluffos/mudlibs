void create() {
   "/daemon/recipe"->add_recipe( "wooden bridge",
([
   "ingredients": ({ ({ ([ C_RAW, C_WOOD ]), 1200 }), ({ ([ C_RAW, C_IRON ]), 15 }) }),
   "skills": ([ "craft.carpentry.buildings":20, "craft.smithing.black":10, "knowledge.architecture":20, "knowledge.science.mathematics":20 ]),
   "tools": ({ C_HAMMER, C_AXE }),
   "output": (: return clone_object("/bldg/road/bridge"); :),
   "type": "structure",
   "road": 1
]) );

   "/daemon/recipe"->add_recipe( "road",
([
   "ingredients": ({ ({ ([ C_RAW, C_STONE ]), 10 }) }),
   "skills": ([ "craft.masonry":10, /*"knowledge.technology":10*/ ]),
   "output": (: return clone_object("/bldg/road/road"); :),
   "type": "structure",
   "road": 1
]) );
}
