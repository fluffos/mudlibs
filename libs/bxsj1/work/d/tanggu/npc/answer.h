int answer(string arg)
{
	object me,ob,who,obj;
	me = this_player();
	ob = this_object();
	if(!me->query_temp("quest/bwzh/marry_object")) return 0;
	if(me->query_temp("quest/bwzh/marry_yes"))
	{
		tell_object(me,YEL"你已经回答了。\n"NOR);
		return 1;
	}
	if(query("station")!=6)
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s 程序出现问题answer"NOR,me->query("name"),me->query("id")),me);
		remove_call_out("answer_check");
		command("say");
		init_over();
		return 1;
	}

	if(!arg || ( arg!="yes" && arg!="y" && arg!="Y" && arg!="Yes" && arg!="no"&& arg!="n"&& arg!="N"&& arg!="No")) 
	{
		command("? "+me->query("id"));
		command("say 这比武招亲，你到底愿意不愿意，还是清楚地说个明白。");
		return 1;
	}

	who=me->query_temp("quest/bwzh/marry_object");

	if(!who || environment(who)!=environment(ob)) 
	{
		remove_call_out("answer_check");
		command("chat* ?");	
		if(me->query("gender")=="女性")
			command("chat "+ob->query("bwzh/winner_player/name")+"既不愿娶她，干么下场比武？终身大事，如此轻薄！");
		else
			command("chat "+ob->query("bwzh/host_player/name")+"就算是不甚满意对方，怎能说走就走？终身大事，如此轻薄！");
		command("poor "+me->query("id"));
		if(who)
		{
			who->delete_temp("quest/bwzh");
			who->add("combat_exp",-100000);
			log_file("quest/zhaoqin",sprintf("%-8s%-10s 离开损失十万answer",who->query("name"),who->query("id")),who);
		}
		else
		{
			if(me->query("gender")=="女性")
				log_file("quest/zhaoqin",sprintf(HIY"%-8s%-10s 离开但无损失answer"NOR,ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
			else log_file("quest/zhaoqin",sprintf(HIY"%-8s%-10s 离开但无损失answer"NOR,ob->query("bwzh/winner_player/name"),ob->query("bwzh/winner_player/id")),ob);
		}
		init_over();
		return 1;
	}

	if(arg=="no" || arg=="n" || arg=="N" || arg=="No")
	{
		remove_call_out("answer_check");
		if(me->query("gender")=="女性")
		{
			message_vision(HIR"\n$N脸色惨白，钢牙咬成玉碎，对$n一个万福说到：「承蒙公子错爱，然小女子福德浅薄，配不上公子人品……」\n"NOR,me,who);
			command("chat* sigh "+getuid(me));
			command("chat "+ob->query("bwzh/host_player/name")+"既不愿嫁给他，为什么比武招亲？终身大事，如此轻薄！");
		}
		else
		{
			message_vision(HIR"\n$N撇了撇嘴，双手一摊，嘿嘿一笑：「与$n在拳脚上玩玩，倒也有趣。招亲嘛，哈哈，可多谢了！」\n"NOR,me,who);
			command("chat* hmm "+getuid(me));
			command("chat "+ob->query("bwzh/winner_player/name")+"既不愿娶她，干么下场比武？终身大事，如此轻薄！");
		}
		command("? "+getuid(me));
		command("poor "+getuid(who));
		tell_object(me,"你因为在「比武招亲」中出尔反尔，而被扣除了十万点经验。");
		me->add("combat_exp",-100000);
		me->delete_temp("quest/bwzh");
		if(who) who->delete_temp("quest/bwzh");
		log_file("quest/zhaoqin",sprintf("%-8s%-10s 拒绝损失十万answer",me->query("name"),me->query("id")),me);
		init_over();
		return 1;
	}

	me->set_temp("quest/bwzh/marry_yes",1);

	if(me->query("gender")=="女性")
	{
        message_vision(HIM"$N羞得双脸红烫，却万福答礼，轻若蚊声道：「女儿家……，不是摇头……，便是点头啦……」\n"NOR, me);
		command("say 恭喜，恭喜！");
		if(!who->query_temp("quest/bwzh/marry_yes"))
		{
			command("say "+who->query("name")+"你还发什么呆啊，既然连"+me->query("name")+"都答应了，还不快回答！");
			return 1;
		}
	}
	else
	{
		message_vision(HIG"$N哈哈大笑：「这比武都比过了，如此贤妻，复又何求！」\n"NOR, me);
		command("say 恭喜，恭喜！");

		if(!who->query_temp("quest/bwzh/marry_yes"))
		{
			command("say "+who->query("name")+"妹妹你还发什么呆啊，你比武都输了，可愿意嫁给"+me->query("name")+"么？");
			return 1;
		}
	}
	remove_call_out("answer_check");
	me->delete_temp("apply/short");  
	who->delete_temp("apply/short");  
	obj=new("/d/city/npc/yuelao");
	obj->move(environment(ob));
	message_vision(HIY"\n突然一股清烟消散，一个满脸红光，须眉皆白的老人走了过来。\n"NOR, me);
	command("ah "+obj->query("id"));
	message_vision(HIG"$N面带笑容，对月下老人一抱拳：「你老来了，今天可正好是个好日子！」\n"NOR, me);
	message_vision(HIC"$N点了点头：「我就为这事来的。哈哈哈哈！双方如意，一切齐备，我这就为你们登记！」\n"NOR, obj);
	message_vision(HIW"$N低头把姻缘簿翻了翻，写下些什么。\n\n"NOR,obj);
	who->delete_temp("quest/busy");
	who->delete_temp("quest/bwzh");
	me->delete_temp("quest/busy");
	me->delete_temp("quest/bwzh");

	who->set("marry/id",me->query("id"));
	who->set("marry/name",me->query("name"));
	me->set("marry/id",who->query("id"));
	me->set("marry/name",who->query("name"));

	me->set_temp("marrying",1);
	me->set_temp("bride", ob->query("id"));
	who->set_temp("groom", ob->query("id"));

	command("say 恭喜，恭喜！");
	message_vision("$N说道：「恭喜，恭喜！」\n\n", obj);
	new("/clone/misc/marry-token")->move(me);
	new("/clone/misc/marry-token")->move(who);
	me->save();
	who->save();
	command("chat "+HIR"恭喜，恭喜！"NOR);
	CHANNEL_D->do_channel(obj,"chat",HIR"恭喜，恭喜！"NOR);
	CHANNEL_D->do_channel(this_object(),"chat",HIY""NOR+me->short("1")+HIY"与"NOR+who->short(1)+HIY"比武招亲，玉成良缘！"NOR);
	message_vision(HIM"\n$N和$n交换了定情信物。\n"NOR, me, who);
	message_vision("\n$N站起身来，一抱拳道：「事情有了了结，我先行告退了！」\n",obj);
	message_vision("突然一阵烟幕弥漫，$N已经消失了。\n\n",obj);

	destruct(obj);
	log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s %-8s%-10s成亲，特此纪录！"NOR,me->query("name"),me->query("id"),who->query("name"),who->query("id")),ob);
	init_over();
	return 1;
}