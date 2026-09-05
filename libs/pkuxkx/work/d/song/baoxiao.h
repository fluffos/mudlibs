#include <ansi.h>
#define MONEY_LOW_LIMIT 500000
#define MONEY_LIMIT 10000000
#define GUWAN_LIMIT 11000000
#define EXCELLENT 5000000
#define GOOD 2500000
int baoxiao_require(object me,int point)
{
	float *index=({1.3,1.25,1.2,1.18,1.15,1.1,1.08,1.05});
	int pin=DASONG_D->get_my_pin(me);
	if (pin<=0||pin>=9)
	return point;
	return to_int(to_float(point)*index[pin-1]);
}
int getid(object me,string guanid,int value,int t_value,int flag)
{
	me->set("song/suikao/renmaitime",me->query("age"));
	me->add("song/suikao/renmaipoint",value);
    me->set("song/suikao/renmai/"+guanid,time());
	if (flag==1)
	{
		me->add("song/suikao/huilu/money",value);
		me->add("song/suikao/huilu/guwan",-value);
	}
	if (flag==2)
	{
		me->add("song/suikao/huilu/money",-value);
		me->add("song/suikao/huilu/guwan",value);
	}
	DASONG_D->multi_record(me,t_value,"报效",1);
	message_vision("$N在这里为大宋报效了约"+MONEY_D->money_str(t_value)+"。\n",me);
	if (me->query("song/suikao/renmaipoint")>baoxiao_require(me,EXCELLENT))
	tell_object(me,"你为国家已经报效了足够多的财物了。\n");
	else if (me->query("song/suikao/renmaipoint")>baoxiao_require(me,GOOD))
	tell_object(me,"你为国家已经报效了一定的财物，足够拿个中档的评价。\n");
	else
	tell_object(me,"国家危难之际，还需要更多的帮助啊。\n");
	return 1;
}

int dest(object ob)
{
    ob->move(VOID_OB);
    destruct(ob);
    return 1;
}

int do_baoxiao(string arg)
{
    object guan=this_object(),me=this_player(),ob;
    string guanid=guan->query("yamen_id"),type;
	int t_value,value,amount=0;
    if (!me->query("song/pro"))
    {
        return notify_fail("阁下报效国家的拳拳之心可嘉，但大宋暂时还不需要百姓出钱。\n");
    }
    if (time()-me->query("song/suikao/renmai/"+guanid)<3600*24)
    {
        return notify_fail("你今年已经报效过"+guanid+"了，去看看其他衙门还有无需要吧。\n");
    }
	if (!arg)
	{
		return notify_fail("你要拿什么东西报效国家？\n");
	}
	if (!ob=present(arg,me))
	{
		if (sscanf(arg,"%s for %d",type,amount)!=2)
		return notify_fail("你要拿什么东西报效国家？\n");
	}

	if (!ob&&((type&&!ob=present(type,me))||!type))
	return notify_fail("你要报效国家的东西并不在你身上。\n");
    else if (ob->query("money_id")&& ob->query("base_value")*amount >= MONEY_LOW_LIMIT)
    {
		if (me->query("song/suikao/huilu/money")>MONEY_LIMIT)
		return notify_fail("这段时间"+guanid+"倒是银钱不缺，但部门公务还需要些古玩字画。\n");
		if (amount<=0)
		amount=1;
		value=ob->query("base_value")*amount;
		t_value=value;
		if (!MONEY_D->player_pay(me,value))
		return notify_fail("你的心意是好的，可你身上暂时拿不出那么多的现钱。\n");
		if (me->query("song/pro")=="文")
		value=value*2/3;
		getid(me,guanid,value,t_value,1);
        return 1;
    }
    else if (ob->query("is_guwanzihua"))
    {
		if (me->query("song/suikao/huilu/guwan")>GUWAN_LIMIT)
		return notify_fail(guanid+"堆满了各种古玩字画，需要现钱打理公务。\n");
		value=ob->query("value");
		t_value=value;
		if (me->query("song/pro")!="文")
		value=value*2/3;
        getid(me,guanid,value,t_value,2);
        dest(ob);
        return 1;
    }
    else 
    {
        return notify_fail("报效各部门一次至少"+MONEY_D->money_str(MONEY_LOW_LIMIT)+"以上或实物。\n报效现钱的格式例：baoxiao gold for 100，则捐出100两金。\n");
    }
}

void init()
{
	add_action("do_baoxiao","baoxiao");
	add_action("do_look",({"look","l"}));
}

int do_look(string arg)
{
	if (!arg&&this_player()->query("song/pro"))
	{
		"/cmds/std/look.lpc"->mudlook_room(this_player(),this_object(),0);
		tell_object(this_player(),"    "HBCYN+HIR"这里的衙门接受官员的捐款(baoxiao)以筹军资。\n"+NOR);
		return 1;
	}
	return 0;
}