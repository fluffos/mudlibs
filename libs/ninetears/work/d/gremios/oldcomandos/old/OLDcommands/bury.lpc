int bury(string str,object x)
{
   object me;
   object *target;
   int counter,i;
 
 /*  SOMEONE wibbled this badly...Didn't use consistant variable names
     throughout the thing.   I fixed it and made the messages smoother.
     Timion 22 MAR 95 
 */

   if(x) me = x;
     else
      {
       me = this_player();
     }
   counter = 0;
   if(!str || str == "") str = "corpse";

   if(me->query_property("dead"))
   {
      tell_object(me,"You, a disembodied ghost, "
                  "expect to bury your own corpse ?.\n"
                  "Cyric pats you on the head and tells you: Nice try.\n ");
      return 1;
   }

   target = all_inventory(environment(me));

   for (i=0;i<sizeof(target);i++)
   {
      if(target[i]->query_corpse() &&
        (string)target[i]->query_name() == str)
      {
         target[i]->dest_me(); // Allow them to clean up themselves.
         counter++;
      }
   }
   if (counter)
      tell_object(me,"You bury the corpse"+(counter == 1?"":"s")+
            " deep within the earth.\n");
   else
      tell_object(me,"You can't find the corpse!\n");

    return 1;
}
