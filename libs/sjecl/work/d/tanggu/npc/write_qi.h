int write_qi(string arg)
{
	object me,ob;
	me = this_player();
	ob = this_object();
	if(!me->query_temp("quest/bwzh/can_marry")) return 0;
    message_vision(HIY"\n$N秀眉一竖，紧抿双唇，准备上前去在锦旗上书上自己的名字。\n"NOR,me);
	if(query("station")>0)
	{
		command("smile "+me->query("id"));
		message_vision(HIY"\n$n轻轻地将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		command("say 已经有人正在比武招亲，你可以（Look qi）获得相关信息。");	
		return 1;
	}
    if(check_player(me,0)) return 1;

	if(time()-over_time<WAIT_TIME)
	{
		command("pat "+me->query("id"));
		message_vision(HIY"\n$n轻轻地将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		command("say 刚才有人才比武招亲结束，你稍候再来吧。");	
		return 1;
	}
	if(arg!="myself" && arg!=me->query("id"))
	{
		message_vision(HIY"\n$n轻轻地将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		command("smile "+me->query("id"));	
		command("say 为别人报名功能暂时没有开通。");	
		return 1;
	}
	message_vision(HIR"虽说是江湖儿女，不做旖旎之态，到底羞得你双颊绯红。\n"NOR,me);
	command("smile "+me->query("id"));
	command("addoil "+me->query("id"));
	delete("bwzh");
	set("bwzh/host_player/id",me->query("id"));
	set("bwzh/host_player/name",me->query("name"));
	set("bwzh/host_player/object",me);//标记美女
	set("station",1);//busy 

	log_file("quest/zhaoqin",sprintf("%-8s%-10s 开始比武招亲write_qi",me->query("name"),me->query("id")),me);
    tell_object(me,HIW"\n你可以在旁边注明你心目中的夫君的部分要求：\n\n"NOR);
    if(!query("bwzh/exp")) tell_object(me,WHT"  1、【经验】"NOR);
	if(!query("bwzh/per")) tell_object(me,WHT"  2、【相貌】"NOR);
    if(!query("bwzh/age")) tell_object(me,WHT"  3、【年龄】"NOR);
    tell_object(me,HIW"\n\n你可以选择数字，你也可以Q键取消。\n"NOR);
	input_to( (: choose_mode :), me );
	return 1;
}