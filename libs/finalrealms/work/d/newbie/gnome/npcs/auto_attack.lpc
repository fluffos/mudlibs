int npc_attack(object victim)
{
   int i;
   object *olist;
   olist = all_inventory(this_object());
   for(i = 0; i < sizeof(olist); i++)
   {
      if(!interactive(olist[i]) && olist[i]->query_aggressive() )
      {
         olist[i]->attack_by(victim);
      }
   }
}
nomask int test_add(object victim,int flag)
{
   int i;
   object *olist;
   /* see if it's an NPC loaded, if so scan for players and mug them */
   if(!interactive(victim))
   {
      /* but only if the beast IS aggressive */
      if(victim->query_aggressive())
      {
         olist = all_inventory(this_object());
         for(i = 0; i < sizeof(olist); i++)
         {
            if(interactive(olist[i]) )
            {
               olist[i]->attack_by(victim);
            }
         }
      }
   }
   /* else just mug it */
   npc_attack(victim);
   return 1;
}
