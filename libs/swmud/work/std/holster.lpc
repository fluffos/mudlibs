inherit OBJ;
inherit M_GETTABLE;
inherit M_VALUABLE;
inherit M_WEARABLE;

private nosave string holster_relation = "holstered";

void set_holster_relation(string value)
{
   if (strlen(value))
   {
      holster_relation = value;
   }
}

int is_holster() { return 1; }

int has_weapons() { return sizeof(all_inventory(this_object())); }

string long()
{
   string long_desc = object::get_base_long();

   foreach (object thing in all_inventory(this_object()))
   {
      long_desc += "  " + thing->short() + " (" + holster_relation + ")\n";
   }

   return long_desc + object::get_extra_long() + this_object()->get_desc_properties();
}