void create() {
   "/daemon/recipe"->add_recipe( "key",
([
   "ingredients": ({ ({ ([ C_METAL, C_RAW ]), 1 }) }),
   "skills": ([ "craft.smithing.white":10, "craft.smithing.locks":10]),
   "tools": ({ C_HAMMER }),
   "output": (: return clone_object("/obj/key"); :)
]) );

   "/daemon/recipe"->add_recipe( "lock",
([
   "ingredients": ({ ({ ([ C_METAL, C_RAW ]), 2 }) }),
   "skills": ([ "craft.smithing.black":10, "craft.smithing.white":20, "craft.smithing.locks":20]),
   "tools": ({ C_HAMMER }),
   "output": (: return clone_object("/obj/lock"); :)
]) );

   "/daemon/recipe"->add_recipe( "keyring",
([
   "ingredients": ({ ({ ([ C_METAL, C_RAW ]), 2 }) }),
   "skills": ([ "craft.smithing.black":10, "craft.smithing.white":15]),
   "tools": ({ C_HAMMER }),
   "comment": "Keyrings can be used to hold keys or other keyrings.",
   "output": (: return clone_object("/obj/keyring"); :)
]) );

}
