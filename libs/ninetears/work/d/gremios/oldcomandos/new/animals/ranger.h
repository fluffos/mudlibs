void init()
{
   object *obs;
   ::init();

   if(!my_player || !environment())
      return;

   if(!my_player&&!this_object()->query_timed_property("just_summoned"))
   {
      tell_room(environment(this_object()),this_object()->query_cap_name()+

         " realizes "+this_object()->query_possessive()+" master is no "
         "longer around, and wanders off.\n");
      this_object()->dest_me();
   }
   if(this_object()->query_name()=="Bengal Tiger")
   {
      obs=all_inventory(environment(this_object()));
      for(int i=0;i<sizeof(obs);i++)
      {
         if(obs[i]->query_hide_shadow()&&obs[i]!=my_player)
         {
            tell_room(environment(this_object()),this_object()->query_cap_name()+
            " pounces on the hidden "+obs[i]->query_cap_name()+".\n",
            ({this_object(),obs[i]}));
            tell_object(obs[i],"Bengal Tiger notices you hiding, and "
            "pounces on you!\n");
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
      tell_room(environment(this_object()),
         obs[i]->query_cap_name()+"\n");
      if(obs[i]==my_player)
         my_player->add_timed_property("KILLED_OWN_ANIMAL",1,500);
   }
   my_player->remove_static_property("animal_summoned");
   ::do_death(att);
}
