string look_boat()
{
	object me=this_player();
	if (me->query_temp("shediaoquest/guiyun/step")!=1)
	{
		return "几条小船被整齐的系在岸边。\n";
	}
	return "你既然征得了渔民的同意，可以上船(enter boat)荡舟太湖了。\n";
}
string look_view()
{
	return "太湖襟带三州，东南之水皆归于此，周行五百里，古称五湖。\n";
}
int do_enter(string arg)
{
	string *boats=({"boat","Boat","小船","小舟","船","chuan"});
	object boat,me=this_player(),huang;
	int x,y;
	if (member_array(arg,boats)==-1)
	{
		tell_object(me,"你要进哪里？\n");
		return 1;
	}
	if (userp(me)&&time()-me->query("killer/time") < 15*60)
	{
		tell_object(me,"你杀了人，渔民不会把船借给你的。\n");
		return 1;
	}
	if (me->query_temp("songtasks/xingbu/task")==3)//大宋刑部任务
	{
		message_vision(HIW"$N征用了一条渔民的小船。\n"NOR,me);
		boat=new(__DIR__"boat2");
		boat->set("x",this_object()->query("x"));
		boat->set("y",this_object()->query("y"));
		message_vision("$N踏上了小船。\n",me);
		me->move(boat);
		x=random(40)-20;
		y=random(40)-20;
		boat->set("xingbu_robber_x",x);
		boat->set("xingbu_robber_y",y);
		return 1;
	}
	if (me->query("shediaoquest/guiyun"))
	{
		message_vision(HIW"$N征得渔民的同意，借了一条小船。\n"NOR,me);
		boat=new(__DIR__"boat2");
		boat->set("x",this_object()->query("x"));
		boat->set("y",this_object()->query("y"));
		message_vision("$N踏上了小船。\n",me);
		me->move(boat);
		return 1;
	}
	if (me->query_temp("shediaoquest/guiyun/step")!=1)
	{
		tell_object(me,"你没有征得渔民的同意，想偷船吗？\n");
		return 1;
	}
	if (!huang=present("huang rong",this_object()))
	{
		tell_object(me,"黄蓉呢？你自己去荡舟吗？\n");
		return 1;
	}
	if (huang&&huang->query("owner")!=me)
	{
		tell_object(me,"蓉儿呢？你自己去荡舟吗？\n");
		return 1;
	}
	boat=new(__DIR__"boat2");
	boat->set("x",this_object()->query("x"));
	boat->set("y",this_object()->query("y"));
	if (me->query_temp("shediaoquest/guiyun/step")==1)
	{
		x=random(80)-40;
		y=random(80)-40;
		boat->set("lu_x",x);
		boat->set("lu_y",y);
	}
	message_vision("$N踏上了小船。\n",me);
	me->move(boat);
	if (huang&&me->query_temp("shediaoquest/guiyun/step")==1)
	{
		message_vision("$N紧跟着也上了小船。\n",huang);
		me->set_temp("shediaoquest/guiyun/step",2);
		huang->move(boat);
	}
	me->set_temp("taihu/hua",0);
	return 1;
}
int shediao2(object me,object huang)
{
	if (!me||!living(me))
	{
		return 1;
	}
	if (environment(me)!=this_object())
	{
		return 1;
	}
	if (!huang||!living(huang))
	{
		return 1;
	}
	if (environment(huang)!=this_object())
	{
		return 1;
	}
	message_vision("$N从未见过如此大水，与$n携手立在湖边，只见长天远波，放眼皆碧，\n七十二峰苍翠，挺立于三万六千顷波涛之中，不禁仰天大叫，极感喜乐。\n",me,huang);
	huang->hi(me,huang);
	return 1;
}

int shediao(object me)
{
	object huang;
	if (!me||!living(me))
	{
		return 1;
	}
	if (environment(me)!=this_object())
	{
		return 1;
	}
	huang=new("/d/guiyunzhuang/npc/huang");
	huang->set("owner",me);
	huang->move(this_object());
	message_vision(HIG+"$N见你至此，也跟了过来。\n"+NOR,huang);
	call_out("shediao2",1,me,huang);
	return 1;
}

void init()
{
	object me=this_player();
	add_action("do_enter","enter");
	if (me->query("shediaoquest/kanglong/finish")&&!me->query_temp("shediaoquest/guiyun/start")&&!me->query_temp("shediaoquest/guiyun/step")&&!me->query("shediaoquest/guiyun"))
	{
		if (present("huang rong",this_object()))
		{
			return;
		}
		me->set_temp("shediaoquest/guiyun/start",1);
		call_out("shediao",2+random(3),me);
	}
	return;
}