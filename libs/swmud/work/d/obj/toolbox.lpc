inherit OBJ;
inherit M_GETTABLE;

void organize_parts();
int query_value();

private mapping parts_count = ([ ]);

void mudlib_setup()
{
   add_save(({ "parts_count" }));
}

varargs void setup(mapping set_parts_count)
{
   if (sizeof(set_parts_count))
   {
      parts_count = set_parts_count;
   }

   set_id("toolbox", "box");
   set_long("A toolbox that can hold many kinds of parts, which can be used for construction and repair.");
}

int query_parts_left(string type)
{
   organize_parts();

   if (parts_count[type])
   {
      return parts_count[type];
   }

   return 0;
}

mapping query_parts_list()
{
   organize_parts();

   return parts_count;
}

int indirect_merge_obj_with_obj() { return 1; }
int deny_alter_value() { return 1; }
int deny_alter_weight() { return 1; }

int use_parts(string type, int amount)
{
   organize_parts();

   if ((parts_count[type] > 0) && (amount > 0))
   {
      parts_count[type] -= amount;

      if (parts_count[type] < 0)
      {
         amount = amount + parts_count[type];
         parts_count[type] = 0;
      }

      return amount;
   }

   return 0;
}

void add_parts(string type, int amount)
{
   organize_parts();

   if (amount > 0)
   {
      if (parts_count[type])
      {
         parts_count[type] += amount;
      }
      else
      {
         parts_count[type] = amount;
      }
   }
}

void remove_parts(string type, int amount)
{
   organize_parts();

   if (amount > 0)
   {
      parts_count[type] -= amount;

      if (parts_count[type] < 0)
      {
         parts_count[type] = 0;
      }
   }
}

int is_toolbox() { return 1; }

void organize_parts()
{
   foreach (string type in keys(parts_count))
   {
      if (parts_count[type] <= 0)
      {
         map_delete(parts_count, type);
      }
   }
}

int query_value_pure()
{
   return query_value();
}

int query_value()
{
   organize_parts();

   if (sizeof(values(parts_count)))
   {
      return array_sum(values(parts_count)) * 5;
   }

   return 0;
}

int query_mass()
{
   organize_parts();

   if (sizeof(values(parts_count)))
   {
      return 3000 + array_sum(values(parts_count)) * 15;
   }

   return 3000;
}

void do_check_obj()
{
   organize_parts();

   if (sizeof(values(parts_count)))
   {
      string parts_list = "The toolbox contains:\n";

      foreach (string type in keys(parts_count))
      {
         parts_list += "  " + parts_count[type] + " " + type + " parts\n";
      }

      write(parts_list);

      return;
   }

   write("The toolbox contains no parts.\n");
}