int cast_spell(string str)
{
 tell_object(this_player(), "You cast Recall.\n");
 say(this_player()->query_cap_name()+" vanishes in a puff of smoke.\n",
     this_player());
 this_player()->move("d/fr/daggerford/mu");
 this_player()->set_gp(0);
 this_player()->adjust_hp(-((int)this_player()->query_hp()/2));
 say(this_player()->query_cap_name()+ " recalls back here.\n",this_player());      
 return -((int)this_player()->query_level()*10);
}
