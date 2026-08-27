int cast_spell(string str)
{
   tell_object(this_player(), "You cast Withdraw.\n");
   say(this_player()->query_cap_name()+" casts a spell and vanishes!\n",
       this_player());
   this_player()->move("d/fr/daggerford/tymora");
   say(this_player()->query_cap_name()+" withdraws back here.\n",this_player());
   this_player()->set_gp(0);
   this_player()->adjust_hp(-((int)this_player()->query_hp()/2));
   return 1;
}
