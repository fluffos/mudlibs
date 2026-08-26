int object_value = 0;

void mudlib_setup()
{
   this_object()->add_save(({ "object_value" }));
}

void set_value(int value)
{
   object_value = value;
}

int query_value_pure()
{
   return object_value;
}

int query_value()
{
   object this_ob = this_object();
   int value = object_value;

   if (this_ob->is_armor() || this_ob->is_weapon())
   {
      value = value * this_ob->query_durability() / this_ob->query_max_durability();

      foreach (object thing in all_inventory())
      {
         value += thing->query_value();
      }
   }

   return value;
}