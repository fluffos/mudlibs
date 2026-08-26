inherit OBJ;
inherit M_GETTABLE;

string key_type;

void mudlib_setup()
{
   object::mudlib_setup();
   add_save( ({ "key_type" }) );
}

void set_key_type(string type)
{
   if (strlen(type))
   {
      key_type = type;
   }
}

mixed get_key_type()
{
   return key_type;
}

int is_key() { return 1; }
int indirect_lock_obj_with_obj() { return 1; }
int indirect_unlock_obj_with_obj() { return 1; }