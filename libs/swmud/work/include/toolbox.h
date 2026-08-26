int check_toolboxes_for_parts(string type, int amount)
{
   int found_parts = 0;

   foreach (object toolbox in filter_array(all_inventory(environment(this_body())) + all_inventory(this_body()), (: $1->is_toolbox() :)))
   {
      found_parts += toolbox->query_parts_left(type);

      if (found_parts >= amount)
      {
         return found_parts;
      }
   }

   return found_parts;
}

int remove_parts_from_toolboxes(string type, int amount)
{
   int removed_parts = 0;

   foreach (object toolbox in filter_array(all_inventory(environment(this_body())) + all_inventory(this_body()), (: $1->is_toolbox() :)))
   {
      removed_parts += toolbox->use_parts(type, amount - removed_parts);

      if (removed_parts >= amount)
      {
         return removed_parts;
      }
   }

   return removed_parts;
}

int check_total_parts(string type)
{
   int total_parts = 0;

   foreach (object toolbox in filter_array(all_inventory(environment(this_body())) + all_inventory(this_body()), (: $1->is_toolbox() :)))
   {
      total_parts += toolbox->query_parts_left(type);
   }

   return total_parts;
}