/*
   /std/living/follow.c
*/

nosave object *followers;
nosave mixed remember_follow;

void follow_commands()
{
   add_action("follow", "follow");
   add_action("lose", "lose");
   add_action("unfollow", "unfollow");
   add_action("follow_dummy", "FOLLOW_DUMMY");
}

mixed *query_followers() { return followers; }

mixed *do_follow_command(string dir)
{
   remember_follow = ({ previous_object(), dir });
   this_object()->ignore_from_history("FOLLOW_DUMMY");
   command("FOLLOW_DUMMY");
   return remember_follow;
}

void reset_remember_follow()
{
   remember_follow = 0;
}

int follow_dummy()
{
   // Wonderflug, passed out stops following
   if(this_object()->query_property("passed out"))
   {
      tell_object(this_object(), "You're in no condition to follow" 
		  " anyone.\n");
      return 0;
   }
   if((sizeof(remember_follow)>1)&&remember_follow[0]&&remember_follow[1])
      remember_follow=environment()->do_exit_command(0,remember_follow[1], 
			this_object(), remember_follow[0]);
   if(remember_follow && sizeof(remember_follow)) 
      return 1;
   else 
      return 0;
}

int add_follower(object ob) 
{
   if(ob == this_object())
      return 0;
   if(member_array(ob, this_object()->query_attacker_list()) != -1)
      return 0;
   if(member_array(ob, followers) == -1)
      followers += ({ ob });
   return 1;
}

int remove_follower(object ob) 
{
   int i;
   if((i=member_array(ob, followers)) != -1) 
   {
      followers = delete(followers, i, 1);
      return 1;
   }
   return 0;
}

int follow(string str) 
{
   mixed obs;
   object ob;
   if(!str) 
   {  
      notify_fail("Syntax: follow <person>\n");
      return 0;
   }
   if(this_object()->query_property("just followed and failed") )
   {
      notify_fail("You're too tired of trying to keep up to "
		  "people to try and follow someone again.\n");
      return 0;
   }
   obs = find_match(str, environment());
   if(!sizeof(obs)) 
   {
      notify_fail("Could not find "+str+".\n");
      return 0;
   }
   ob = obs[0];
   if(!ob->query_consent("follow") &&
      random((int)ob->query_dex())<random((int)this_object()->query_dex()))
   {
      tell_object(ob,this_object()->query_cap_name()+" tries to follow " 
	  "you, but you manage to evade "+
	  this_object()->query_objective()+".\n");
       this_object()->add_timed_property("just followed and failed",1,10);
       notify_fail("You try to follow "+ob->query_cap_name()+", but "
	  "you can't keep up to "+ob->query_pronoun()+".\n");
       return 0;
   }
   if(!ob->add_follower(this_object()))
   {
      notify_fail("You can only follow living things.\n");
      return 1;
   }
   write("You follow "+ob->query_cap_name()+".\n");
   tell_room(environment(this_object()), this_object()->query_cap_name()+
      " follows "+ob->query_cap_name()+".\n", ({ ob, this_object() }) );
   tell_object(ob, this_object()->query_cap_name()+" follows you.\n");
   return 1;
}

int unfollow(string str) 
{
   int i;
   object *ok, *obs;
   string s;
   if(!str) 
   {
      notify_fail("Syntax: unfollow <person>\n");
      return 0;
   }
   obs = find_match(str, environment());
   if(!sizeof(obs)) 
   {
      notify_fail("I cannot find "+str+" to unfollow.\n");
      return 0;
   }
   ok = ({ });
   for(i=0;i<sizeof(obs);i++)
      if(obs[i]->remove_follower(this_player()))
	 ok += obs[i..i];
   if(!sizeof(ok)) 
   {
      notify_fail("You are not following "+query_multiple_short(obs)+
		  ".\n");
      return 0;
   }
   write("You stop following "+(s=query_multiple_short(ok))+".\n");
   say(this_player()->query_cap_name()+" stops following "+s+".\n", ok);
   ok += ({ "you" });
   for (i=0;i<sizeof(ok)-1;i++)
      tell_object(ok[i], this_player()->query_cap_name()+
	 " stops following "+query_multiple_short(ok - ({ ok[i] }))+".\n");
   return 1;
}

int lose(string str) 
{
   int i;
   object *ok, *obs;
   string s;
   if(!str)
   {
      notify_fail("Syntax: lose <person|everyone>\n");
      return 0;
   }
   if(str == "everyone")
      obs = followers;
   else
      obs = find_match(str, environment());
   if(!sizeof(obs)) 
   {
      notify_fail("I cannot find "+str+" to lose.\n");
      return 0;
   }
   ok = ({ });
   for(i=0;i<sizeof(obs);i++)
      if(remove_follower(obs[i]))
	 ok += obs[i..i];
   if(!sizeof(ok)) 
   {
      notify_fail("You are not being followed by "+
	 query_multiple_short(obs)+".\n");
      return 0;
   }
   write("You lose "+(s=query_multiple_short(ok))+".\n");
   say(this_player()->query_cap_name()+" loses "+s+".\n", ok);
   ok += ({ "you" });
   for(i=0;i<sizeof(ok)-1;i++)
      tell_object(ok[i], this_player()->query_cap_name()+
	 " loses "+query_multiple_short(ok - ({ ok[i] }))+".\n");
   return 1;
}

