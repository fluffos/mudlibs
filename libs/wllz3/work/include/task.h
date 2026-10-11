
void start_timer()
{
	call_out("return_back",300);
}
void return_back()
{
	object me;
	
	me = environment();
	if(!objectp(me))
		return;

	while (objectp(environment(me)) && ! playerp(me))
		me = environment(me);

	if(playerp(me))
	{
		message_vision(query("owner_name") +"走了过来，对$N说道：「据悉这位"+ RANK_D->query_respect(me) +"已"
			       "找到了"+ name() +"，不知可有此事？」\n"
			       "$N想了想，这才点了点头道："+ name() +"正为"+ RANK_D->query_self(me) +"所得，既然您已"
			       "经来了，"+ RANK_D->query_self(me) +"\n"
			       "势必完璧归赵。说完，把"+ name() +"交到了"+ query("owner_name") +"手中。\n",me);
		me->delete_temp("counts");
	}
	else
		message("vision",query("owner_name") +"走了过来，捡起"+ name() +"，脸上露出一阵欣喜。\n",me);

	destruct(this_object());
}
