void init()
{
   object *obs;
   ::init();

   if(!my_player || !environment())
      return;

   if(!my_player&&!this_object()->query_timed_property("just_summoned"))
   {
      tell_room(environment(this_object()),this_object()->query_cap_name()+

         " se da cuenta de que su amo no esta por aqui"
         "y se va a vivir su vida.\n");
      this_object()->dest_me();
   }
   if(this_object()->query_name()=="Tigre de Bengala")
   {
      obs=all_inventory(environment(this_object()));
      for(int i=0;i<sizeof(obs);i++)
      {
         if(obs[i]->query_hide_shadow()&&obs[i]!=my_player)
         {
            tell_room(environment(this_object()), "El "+this_object()->query_cap_name()+
            " nota la presencia de "+obs[i]->query_cap_name()+" y le ataca.\n",
            ({this_object(),obs[i]}));
            tell_object(obs[i],"El Tigre de Bengala nota tu presencia "
            "y te ataca!\n");
            obs[i]->attack_by(this_object());
         }
      }
   }
}
int test_add(object ob, int i) { return 0; }
void do_death(object att)
{
   object *obs;
   if(!my_player) return ::do_death(att);

   obs=this_object()->query_attacker_list();
   for(int i=0;i<sizeof(obs);i++)
   {
      /*tell_room(environment(this_object()),
         obs[i]->query_cap_name()+"\n");*/
      if(obs[i]==my_player)
         my_player->add_timed_property("KILLED_OWN_ANIMAL",1,500);
   }
   my_player->remove_static_property("animal_summoned");
   ::do_death(att);
}
