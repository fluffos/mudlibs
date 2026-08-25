// Henchmen - Radix, June 1996

nosave object *henchmen;

create()
{
   henchmen = ({ });
}

object *query_henchmen() { return henchmen; }
void set_henchmen(object *obs) { henchmen = obs; }

void add_henchman(object ob)
{
   if(!ob || !ob->query_henchman())
      return;
   henchmen += ({ ob });
   return;
}

void remove_henchman(object ob)
{
   if(!ob || !ob->query_henchman())
      return;
   henchmen -= ({ ob });
   return;
}

// This should only be called by /global/player upon quitting.
void saving_henchmen()
{
   int i;
   henchmen -= ({ 0 });
   for(i=0; i<sizeof(henchmen); i++)
      if(environment() != environment(henchmen[i]))
      {
         henchmen[i]->owner_left();
         if(henchmen[i]) 
            destruct(henchmen[i]);
      }
   henchmen -= ({ 0 });
   return;
}
