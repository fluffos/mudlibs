// by luoyun_微笑
// Prison.c

inherit ROOM;

void create()
{
	set("short", "大牢");
	set("long", "这里黑乎乎的，地上的茅草也是湿漉漉的，让你感到极不舒服，想起在监外自由自在的日子，你心里真是万分难过。");
	set("no_fight","1");
	set("action_list",([
		"打点狱卒":"maitong",
		"查看时间":"ptime",
	]));
	setup();
}

void init()
{
	add_action("cha_ptime","ptime");
	add_action("maitong_yuzu","maitong");
}

int maitong_yuzu(string arg)
{
	int cost,num;
	string type,str;
	object me = this_player();

	num = me->query_time_to_leave()/10;
	if(!arg)
	{
		str = ZJOBLONG"你要用现金还是存款打点狱卒？\n";
		str += ZJOBACTS2+ZJMENUF(3,3,10,30);
		str += "现金打点:maitong 现金";
		str += ZJSEP"存款打点:maitong 存款";
		tell_object(me,str+"\n");
		return 1;
	}
	else if(sscanf(arg,"%s %d",type,cost)!=2)
	{
		if(arg != "现金" && arg != "存款")
		{
			tell_object(me,"命令格式错误！\n");
			return 1;
		}
		str = INPUTTXT("花费"+num+"黄金打点上下可以直接放你出去！想花费多少金币的"+arg+"贿赂狱卒？","maitong "+arg+" $txt#\n");
		str += ZJOBACTS2+ZJMENUF(3,3,10,30);
		str += "直接买通:maitong "+arg+" 0";
		tell_object(me,str+"\n");
		return 1;
	}

	if(cost == 0) cost = num;

	if(cost < 10)
	{
		tell_object(me,"起码也得10个金币才拿得出手吧！\n");
		return 1;
	}

	if(type == "存款")
	{
		if(me->query("balance")<cost*10000)
		{
			tell_object(me,"你钱庄的存款没那么多钱！\n");
			return 1;
		}
		me->add("balance",-cost*10000);
	}
	else if(type == "现金")
	{
		if(!MONEY_D->player_pay(me,cost*10000))
		{
			tell_object(me,"你身上没带那么多钱！\n");
			return 1;
		}
	}
	else
	{
		tell_object(me,"命令格式错误！\n");
		return 1;
	}

	tell_object(me,HIG"你用"+cost+"金币贿赂了狱卒！"NOR"\n");
	log_file("pay/prison", sprintf("%s:%s(%s)花%d黄金贿赂了狱卒。\n",ctime(time()),me->query("name"),me->query("id"),num));
	if(cost==num)
	{
		me->leave_prison(0,0);
	}
	else
	{
		tell_object(me,HIG"你的坐牢时间缩短了"+cost/6+"分钟！"NOR"\n");
		me->leave_prison(0,cost/6);
	}
	return 1;
}

int cha_ptime()
{
	if(this_player()->query_time_to_leave()>1)
		tell_object(this_player(),"你还有"HIR+appromix_time(this_player()->query_time_to_leave(), 1)+NOR"才能出去。\n");
	else
		tell_object(this_player(),HIG"你马上就能出去了，别急。"NOR"\n");
	return 1;
}

int free_ob(object me)
{
	string startroom;
	message_vision("两个狱卒从门外走了出来，架起$N，道：好了，你可以走了，要是再敢犯案，哼哼...\n\n", me);
	message("vision", "两个狱卒和" + me->name() +"走了出去... 你不禁叹了一口气。\n",environment(me), ({ me }));

	tell_object(me, HIR "你被两个狱卒架着走了出大牢..."NOR"\n");

	if (me->is_ghost())
		startroom = "/d/death/gate";
	else
		startroom = "/d/changan/baihu1";

	me->set("startroom", startroom);
	me->move(startroom);
	message("vision", "两个狱卒架着一脸憔悴的" + me->name() + "走了出来，打开枷锁，哼了一声就回去了。\n",environment(me), ({ me }));
	return 1;
}

void catch_back(object me)
{
	message_vision(HIM "忽然几个捕快赶了过来，团团围住$N"HIM "就是一顿痛殴，边打边骂道：“好家伙！我让你跑...”"NOR"\n", me);

	message("vision", HIY "这群捕快把" + me->name() + HIY "打得昏死过去，然后套上枷锁押走了。"NOR"\n",environment(me), ({ me }));
}

void catch_ob(object me)
{
	message_vision(HIM "忽然章召重赶了过来，一把抓住$N，用铁链锁住，恶狠狠的叫道：“站住！你犯案了，快跟我走吧！”"NOR"\n",me);

	message("vision", HIY "章召重三拳两脚把" + me->name() +	"打晕拎走了。"NOR"\n",environment(me), ({ me }));
}
