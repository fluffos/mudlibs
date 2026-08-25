object *users()
{
   object *all = efun::users();
   int i;
   if(this_player() && this_player()->query_lord())
      return all;
   for(i=0; i<sizeof(all); i++)
      if(all[i]->query_invis() == 2) 
         all -= ({ all[i] });
   return all;
}
