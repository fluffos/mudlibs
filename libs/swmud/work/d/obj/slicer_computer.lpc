// Last edited by deforce on 03-03-2010
inherit OBJ;
inherit M_GETTABLE;
inherit M_VALUABLE;

void do_use();

void setup()
{
   set_id("slicer computer", "computer", "slicer_computer");
   set_long("A specialized, hand-held computer that only slicers know how to use.");
   set_mass(1000);
   set_value(2000);
}

void do_use()
{
   this_body()->simple_action("$N $vuse the slicer computer.");
}

mixed direct_use_obj()
{
   object this_body = this_body();

   if (!present(this_object(), this_body()))
   {
      return "You must be holding this specialized computer in order to use it.\n";
   }

   if (this_body->query_guild_level("slicer"))
   {
      if (!this_body->has_learned_skill("slicing"))
      {
         return "You have not learned how to use this specialized computer.\n";
      }
      else if (this_body->get_target())
      {
         return "You are unable to use this specialized computer while in combat.\n";
      }
   }
   else
   {
      return "Only slicers know how to use this specialized computer.\n";
   }

   return 1;
}