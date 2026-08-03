int ask_biwu()
{
	object me=this_player();
	if(me->query("gender")=="女性")
	{
		if(!me->query_temp("quest/bwzh/can_marry"))
		{
			if(time()-ask_time<ASKTIME)
			{
				command("pat "+me->query("id"));
				command("say 等等，我刚处理一个玩家信息，还没忙过来呢。");	
				return 1;
			}
			ask_time=time();
			command("say 武林女子可以在此地以武招夫，如果你有意将自己终身托付给一位盖世英雄！");
			command("whisper "+me->query("id")+" 是不是想找个如意郎君？");
			command("say 你可以在此旗上书（Write）下自己的名字，你可以使用 help quest bwzq 获得这方面的帮助！");
			me->delete_temp("quest/bwzh");
			me->set_temp("quest/bwzh/can_marry",1);
		}
		command("addoil "+me->query("id"));
	}
	else if(me->query("gender")=="男性")
	{
		if(!me->query_temp("quest/bwzh/can_yingzhao"))
		{
			if(time()-ask_time<ASKTIME)
			{
				command("pat "+me->query("id"));
				command("say 等等，我刚处理一个玩家信息，还没忙过来呢。");	
				return 1;
			}
			command("say 经常有武林女子可以在此地以武招夫，以将自己终身托付给一位盖世英雄！");
			command("whisper "+me->query("id")+" 是不是这个想找个花样少女？");
			if(query("bwzh/fail_player") && query("bwzh/fail_player/id")==me->query("id"))
			{
				command("hmm");
				command("say 等等，你已经上去过了吧，而且被痛扁？？.......");
				command("laugh");
			}
			else
			{
				ask_time=time();
				command("say 你可以在此地参加比武应招（Yingzhao）！");
				command("say 你可以使用 help quest bwzq 获得这方面的帮助！也可以（Look qi）获得招亲信息。");
				me->delete_temp("quest/bwzh");
				me->set_temp("quest/bwzh/can_yingzhao",1);
			}
		}
		command("addoil "+me->query("id"));
	}
	else
	{
		if(time()-ask_time<ASKTIME)
		{
			command("pat "+me->query("id"));
			command("say 等等，我刚处理一个玩家信息，还没忙过来呢。");	
			return 1;
		}
		command("say 经常有武林女子可以在此地以武招夫，以将自己终身托付给一位盖世英雄！");
		command("say 也有各地的武林俊杰可以在此地参加比武应招（Yingzhao）！");
		command("whisper "+me->query("id")+" 只是你是想找个如意郎君呢，还是如花少女？");
		command("tsk "+me->query("id"));
		command("addoil");
	}
	return 1;
}