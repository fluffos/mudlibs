//Cracked by Kafei
//xiaojian May25,2000

//#include <localtime.h>


string ask_tiaoshui()
{
	object me, ob;
	string event;
	string fam;
	mapping my_fam;
	me = this_player();
	ob = this_object();
	event = NATURE_D->outdoor_room_event();
	fam = me->query("family/family_name");
	my_fam = me->query("family");
	if (!fam || fam != "少林派")
		return "阿弥陀佛,这位施主不是少林寺的，贫僧可不敢劳动大驾。";
	if (me->query("combat_exp") > 500000)
		return "这位"+RANK_D->query_respect(ob)+"已经是高手了，不用在做这种粗话了! ";
	/*if ((string)me->query("class")!="bonze" && my_fam["family_name"] == "少林派")
		return "施主是俗家弟子, 这种事还是留给出家弟子吧。";*/
	if (event == "event_night" || event == "event_midnight")
		return "阿弥陀佛,本寺的山门夜晚不开,"+RANK_D->query_respect(me)+ "还是等天亮在来吧。";
	if (me->query("shaolin/job_asked")&& (me->query_condition("shaolin/job_busy") > 0))
		return RANK_D->query_respect(me)+ "不是问过了吗，怎么还在这里偷懒? ";
	if(me->query_condition("shaolin/job_fail") > 0)
		return "目前还找不到什么活儿给你干，你等等再来吧。";
	if(me->query_condition("shaolin/job_wait") > 0)
		return "现在还没什么活给你干，迟一点在来吧。";
	command("nod");
	command("say 你来的正好，这几天厨房里正缺水呢，你去山下挑些水吧! \n");
	command("say 你先去找烧饭僧要上挑水的工具吧。\n");
	me->set("shaolin/job_asked",1);
	me->apply_condition("shaolin/job_busy", 90+ random(30));
	return "早去早回，厨房里还等着水用呢。";

}

string ask_piao()
{
	object me,ob,obj;
	me = this_player();
	ob = this_object();
	obj = present("shui piao", me);
	if(obj)
		return "你身上不是有水瓢吗, 要那么多干吗? ";
	if (!me->query("shaolin/job_asked") && !me->query_condition("shaolin/job_busy"))
		return "你要瓢来干什么? ";
	if (me->query_temp("piao_asked"))
		return "你不是刚刚要过瓢吗，怎么又来要了? ";

	command("say 又丢了水瓢? 下次小心点! ");
	obj = new("/d/shaolin/obj/piao");
	obj->move(me);
	message_vision("$n给$N一个水瓢。\n",me, ob);
	me->set_temp("piao_asked");
	return "记得用完后还回来啊。";
	
	
}

string ask_tong()
{
	object me,ob,obj;
	me = this_player();
	ob = this_object();
	obj = present("shui tong", me);
	if (obj) 
		return "你身上不是有水桶吗? ";
	obj = present("shui tong", environment(me));
	if (obj && obj->query("onwer") == me->query("id"))
		return "地上不是有你的水桶吗，怎么还不干活去? ";
	if (me->query("shaolin/tool_assigned"))
		return "你不是已经领到工具了吗，怎么又来要了? ";
	if (!me->query("shaolin/job_asked") && !me->query_condition("shaolin/job_busy"))
		return "你现在没有领任务，要什么工具? ";
	command("nod");
	command("say 难得你愿意为本寺解决困难，这太好了! ");
	command("say 这是挑水用的水桶，你拿去用吧。");
	obj = new("/d/shaolin/obj/tong");
	obj->set("owner", me->query("id"));
	//obj->set_owner(me);
	obj->move(me);
	message_vision("$N交给$n一个水桶。\n", ob, me);
	me->set("shaolin/tool_assigned", 1);
	return "早去早回，我还等着水用呢。";
}

int accept_object(object ob, object obj)
{
	object me;
	me = this_player();
	if(obj->query("id") == "shui piao"){
	        call_out("destroy_dest", 1, me, obj);
		return 1;
	}
	if(obj->query("id") =="shui tong"){
		if(me->query("shaolin/job_asked")&& me->query_condition("shaolin/job_busy")){
			if(obj->query("full")){
				call_out("reward_dest",1,me,obj);
				return 1;
			}
				else{
				command("hmm "+me->query("id"));
				command("say 你怎么还在这里偷懒? 还不快去挑水, 小心我告诉方丈! \n");
				return 0;
				}
		}

		else{
			command("faint "+me->query("id"));
			command("say 你怎么现在才回来? 已经有别人抢先挑好了水。\n");
			me->delete("shaolin/job_asked");
			me->delete("shaolin/tool_assigned");
			me->apply_condition("shaolin/job_busy",0);
			me->apply_condition("shaolin/job_fail",20+ random(5));
			call_out("dest_tool",1,me,obj);
		}
		return 1;
}


        command( "hmm" );
        command( "say 你给我这东西做什麽？\n" );
        return 0;
}
void destroy_dest(object me, object obj)
{
	command("nod");
	command("say 辛苦了! \n");
	me->delete_temp("piao_asked");
	destruct(obj);
	return;
}
void dest_tool(object me, object obj)
{
	destruct(obj);
	return;
}
void reward_dest(object me, object obj)
{
	command("thank "+me->query("id"));
	command("say 辛苦你了，下去休息一下吧。\n");
	destruct(obj);
	me->delete("shaolin/job_asked");
	me->delete("shaolin/tool_assigned");
	me->clear_condition("shaolin/job_busy");
	me->apply_condition("shaolin/job_wait",10+random(10));
	me->add("combat_exp", 100+ random(50));
	me->add("potential", 60+ random(20));
	if(me->query("potential") > me->query("max_potential"))
		me->set("potential", me->query("max_potential"));
	return;
}





		
