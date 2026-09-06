void create() {
   "/daemon/recipe"->add_recipe( "wooden fence",
([
   "ingredients": ({ ({ ([ C_RAW, C_WOOD ]), 4 }) }),
   "skills": ([ "craft.carpentry.buildings":10 ]),
   "tools": ({ C_HAMMER, C_SAW }),
   "output": (: return clone_object("/bldg/wall/fence"); :),
   "type": "structure"
]) );
   "/daemon/recipe"->add_recipe( "wooden gate",
([
   "ingredients": ({ ({ ([ C_RAW, C_WOOD ]), 5 }), ({ ([ C_RAW, C_METAL ]), 1 }) }),
   "skills": ([ "craft.carpentry.buildings":10, "craft.smithing.black":20 ]),
   "tools": ({ C_HAMMER, C_SAW }),
   "output": (: return clone_object("/scn/furni/gate"); :),
   "type": "structure"
]) );
}
