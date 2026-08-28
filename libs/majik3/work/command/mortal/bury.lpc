// Bury.c - For burying the corpses
// By: drAnil, revised by Namhas
main(string arg)
{
   object obu, *all;
   if (obu=present(arg))
   {
      if (obu->query_is_corpse())
      {
         message("0","You perform a short ritual to honor the dead and then "
         + "bury " + obu->query_short() + ".\n",THIS);
         act(THIS, "$n performs a short ritual and buries "+obu->query_short()+".");

         all = all_inventory(obu);

         if (all && sizeof(all) > 0)
           all->move (ENV(THIS));

         if(obu->query_race() == THIS->query_race() || obu->query_race() == THIS->query_subrace() )
         {
            THIS->add_alignx(1 + random(3));
            THIS->add_aligny(1 + random(3));
         }
         else
         {
            THIS->add_alignx(1 + random(3));
            THIS->add_aligny(0 + random(2));
         }
         destruct(obu);

         return 1;
      }
      write("But "+ obu->query_short()+" is not a corpse!\n");
      return 1;
   }
   notify_fail ("Bury what?\n");
   return 0;
}

query_author ()
{
  return "dranil";
}

query_synopsis ()
{
  return "bury <corpse>";
}

query_help ()
{
  return "This command buries specified corpse. Useful for lawful characters.";
}

query_position ()
{
  return POS_STANDING;
}

