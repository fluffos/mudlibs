int bury(string str)
{
   object *target;
   int counter,i;

   counter = 0;
   if (!str || str == "") str = "corpse";

   target = all_inventory(environment(this_player()));

   for (i=0;i<sizeof(target);i++)
      if(target[i]->query_corpse() &&
        (string)target[i]->query_name() == str)
      {
         target[i]->dest_me(); // Allow them to clean up themselves.
         counter++;
      }

   if (counter)
      write("You bury the corpse"+(counter == 1?"":"s")+
            " deep within the earth.\n");
   else
      notify_fail("You can't find the corpse!\n");

   return counter;
}
