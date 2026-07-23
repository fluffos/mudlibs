
void init()
{
	object ob = this_player();
	object me = this_object();
	
	::init();
	
	if(interactive(ob) && wizardp(ob)
	     && ob->query("family/family_name") == me->query("family/family_name") 
	     && (int)ob->query_condition("same_family_killed"))
	{
		message_vision(HIM"$N盯住$n，说道：“就是你残害同门吧，那么我们也来较量一下！\n"NOR
		                 , me, ob);
		remove_call_out("fight_ob");
		call_out("fight_ob", 1, ob);
	}
}
	
	
