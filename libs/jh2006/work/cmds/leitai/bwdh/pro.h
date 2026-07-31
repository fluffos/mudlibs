// Purpose : Ready to fight
// Creator : Numa@Sj 2000-5-4 11:28

int start_trace(object me, object local)
{
	object obj = this_object();
	object ob;
	
	ob = load_object(__DIR__"obj/snooper"+local->query("snoop"));
    ob->set("pp",obj->query("party"));
    if (ob->query("pp") == local->query_temp("p1")) {
		ob->set("p/i1",local->query_temp("p1/i1"));
		ob->set("p/i2",local->query_temp("p1/i2"));
		ob->set("p/i3",local->query_temp("p1/i3"));
	}
	else {
		ob->set("p/i1",local->query_temp("p2/i1"));
		ob->set("p/i2",local->query_temp("p2/i2"));
		ob->set("p/i3",local->query_temp("p2/i3"));
	}
		
	ob->do_snoop(me->query("id"));
	return 1;
}

int do_ok()
{
	object me = this_player();
	object ob = this_object();
    object *pl = ({me,me,me}), *obje, obj, local;
	string *group;
	int i, ready = 0;
	
	if (!me->query_temp("leitai"))
		return notify_fail("你又不参加比武，怎么混进来的？！哦，你是巫师！\n");
        if (me->query_temp("ready"))
                return notify_fail("你已经准备好了，还ok什么呀！！\n");
	if (!ob->query("packet"))
		return notify_fail("快通知巫师，数据丢失！！\n");
    if (ob == load_object(__DIR__"xiuxishi1"))
		obj = load_object(__DIR__"xiuxishi2");
	else
		obj = load_object(__DIR__"xiuxishi1");
	me->set_temp("ready",1);
	group = explode(ob->query("packet")," ");
	for (i=0;i<sizeof(group);i++) {
		if (!(pl[i] = present(group[i],ob)))
			return notify_fail(group[i]+"不在此地！！\n");
		if (pl[i]->query_temp("ready"))
			ready += 1;
	}
        ob->set("ready",ready);
	local = load_object(__DIR__"ctrl");
	if (!local->query("snoop"))
		local->set("snoop",1);
	else
		local->add("snoop",1);
	call_out("start_trace", 1, me, local);
	if (ready == 3) {
		message_vision(HIY"\n$N看了一下大家，见大家都准备好了应战，于是大喝一声：“咱们走！”\n"HIR"喝罢，便用手去推大门，可是大门纹丝不动！\n"NOR,me);
		if (obj->query("ready") == 3) {
			tell_room(ob,HIG"【天外之音】大门即将打开，具体规则如下！\n一，个人进入山庄后，只要死亡即算个人退出，其余人可继续比赛。\n二，比赛胜利者是最后活着呆在山庄内的一组。\n"NOR);
			tell_room(obj,HIG"【天外之音】大门即将打开，具体规则如下！\n一，个人进入山庄后，只要死亡即算个人退出，其余人可继续比赛。\n二，比赛胜利者是最后活着呆在山庄内的一组。\n"NOR);
			tell_room(local,HIR"\n【巫师组织】 两边的玩家都已准备好应战，请用(press button)开门！\n"NOR);
			obje = ({load_object(__BWDH__"view1"),
		        	load_object(__BWDH__"view2"),
        			load_object(__BWDH__"view3"),
		        	load_object(__BWDH__"view4"),
        			load_object(__BWDH__"view5"),
        			load_object(__BWDH__"view6")});
        		for(i=0;i<sizeof(obje);i++)
				obje[i]->set("start",1);
			return 1;
		}
		tell_room(ob,HIG"【天外之音】另一组尚未准备就绪，请稍侯！\n"NOR);
		tell_room(obj,HIG"【天外之音】「"+ob->query("party")+"」已经准备就绪，请抓紧时间！！\n"NOR);
		tell_room(local,HIR"\n【巫师组织】 「"+ob->query("party")+"」已经准备就绪！\n"NOR);
		return 1;
	}
	message_vision(GRN"\n$N整理了一下随身装备，看来已经准备好应战了！\n"NOR, me);
	return 1;
}

int do_chuanyin(string arg)
{
	object me = this_player();
	object ob = this_object();
	object obj;
	
    if (ob == load_object(__DIR__"xiuxishi1"))
		obj = load_object(__DIR__"xiuxishi2");
	else
		obj = load_object(__DIR__"xiuxishi1");	

        if (me->query_temp("stop_cy"))
                return notify_fail("你正在使用千里传音。\n");
	if (!arg)
        tell_room(obj,HIR"〖千里传音〗"HIY+ob->query("party")+"的"+me->name(1)+"轻咳了一声。\n"NOR);
	else
        tell_room(obj,HIR"〖千里传音〗"HIY+ob->query("party")+"的"+me->name(1)+"说道："+arg+"。\n"NOR);
	tell_object(me,"您的话语已传送至"+obj->query("party")+"的房间。\n");
	me->set_temp("stop_cy",1);
    call_out("start_cy",4,me);
	return 1;
}

void start_cy(object me)
{
	if (!me)
		return;
	me->delete_temp("stop_cy");
}
