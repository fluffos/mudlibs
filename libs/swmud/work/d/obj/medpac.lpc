inherit OBJ;
inherit M_GETTABLE;

int query_value();

private int bacta_count = 25;

void mudlib_setup()
{
   add_save(({ "bacta_count" }));
}

varargs void setup(int set_bacta_count)
{
   if (set_bacta_count)
   {
      bacta_count = set_bacta_count;
   }

   set_id("medpac", "pac");
   set_long("A medpac for storing vials of bacta, which can be used for first aid and surgery.");
}

int query_bacta_left() { return bacta_count; }

int indirect_merge_obj_with_obj() { return 1; }
int deny_alter_weight() { return 1; }
int deny_alter_value() { return 1; }

int use_bacta(int amount)
{
   if ((bacta_count > 0) && (amount > 0))
   {
      bacta_count -= amount;

      if (bacta_count < 0)
      {
         amount = amount + bacta_count;
         bacta_count = 0;
      }

      return amount;
   }

   return 0;
}

void add_bacta(int amount)
{
   if (amount > 0)
   {
      bacta_count += amount;
   }
}

void remove_bacta(int amount)
{
   if (amount > 0)
   {
      bacta_count -= amount;

      if (bacta_count < 0)
      {
         bacta_count = 0;
      }
   }
}

int is_medpac() { return 1; }

int query_value_pure()
{
   return query_value();
}

int query_value()
{
   if (bacta_count > 0)
   {
      return bacta_count * 6;
   }

   return 0;
}

int query_mass()
{
   return 1000 + (bacta_count * 10);
}

void do_check_obj()
{
   write("The medpac contains " + bacta_count + " vial" + (bacta_count != 1 ? "s" : "") + " of bacta.\n");
}