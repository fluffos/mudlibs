inherit OBJ;
inherit M_GETTABLE;
inherit M_SALVAGEABLE;


int junk_level = 1;

varargs void mudlib_setup(string material)
{
   ::mudlib_setup();
   if (material)
   {
      set_id(material);
      add_id("junk");
      set_weight(0.01);
      set_long("This is junk item, that can be used for crafting or salvaging.");
   }
}

void set_junk_level(int j)
{
   junk_level = j;
}

int query_junk_level()
{
   return junk_level;
}

int is_junk()
{
   return 1;
}