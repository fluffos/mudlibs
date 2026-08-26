/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_GETTABLE;

varargs void mudlib_setup(string material)
{
   ::mudlib_setup();
   if (material)
      set_id(material);
   add_id("material");
   set_weight(0.01);
   set_long("This is a crafting material used at a crafting bench.");
}

int is_material()
{
   return 1;
}
