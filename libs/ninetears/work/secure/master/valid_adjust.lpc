/*
   Checks for validity of objects to adjust certain
   stats in another object

   Radix : May 19, 1997
*/

int immortal_create_me(object origin)
{
   if(member_array(get_dir("/w/"), origin->query_create_me()) > -1)
      return 1;
   return 0;
}

int valid_adjust_xp(object origin, object destination, int amt)
{
   if(!origin || !destination)
      return 0;
   if(immortal_create_me(origin) || !origin->query_npc()
   // || !origin->query_qced()
      || !origin->query_sacroom())
   {
      log_file("ADJUST", "XP: create_me "+origin->query_create_me()+
         " "+real_filename(origin)+" calling "+real_filename(destination)+
         " for "+amt+"\n");
      return 0;
   }
   return 1;
}
