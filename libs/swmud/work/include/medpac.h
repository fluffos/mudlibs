int check_medpacs_for_bacta(int amount)
{
   int found_bacta = 0;

   foreach (object medpac in filter_array(all_inventory(environment(this_body())) + all_inventory(this_body()), (: $1->is_medpac() :)))
   {
      found_bacta += medpac->query_bacta_left();

      if (found_bacta >= amount)
      {
         return found_bacta;
      }
   }

   return found_bacta;
}

int remove_bacta_from_medpacs(int amount)
{
   int removed_bacta = 0;

   foreach (object medpac in filter_array(all_inventory(environment(this_body())) + all_inventory(this_body()), (: $1->is_medpac() :)))
   {
      removed_bacta += medpac->use_bacta(amount - removed_bacta);

      if (removed_bacta >= amount)
      {
         return removed_bacta;
      }
   }

   return removed_bacta;
}

int check_total_bacta()
{
   int total_bacta = 0;

   foreach (object medpac in filter_array(all_inventory(environment(this_body())) + all_inventory(this_body()), (: $1->is_medpac() :)))
   {
      total_bacta += medpac->query_bacta_left();
   }

   return total_bacta;
}