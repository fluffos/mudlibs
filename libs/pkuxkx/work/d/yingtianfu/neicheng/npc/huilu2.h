int getid(object me,object guan,object ob,int pin,int flag)
{
    string guanid=guan->query("id");
	int value=(int)ob->query("value")/4*(4-pin)+ob->value();
	command("haha");
	me->set("ming/suikao/renmaitime",me->query("age"));
	me->add("ming/suikao/renmaipoint",value);
    me->set("ming/suikao/renmai/"+guanid,time());
	if (flag==1)
	{
		me->add("ming/suikao/huilu/money",value);
		me->add("ming/suikao/huilu/guwan",-value);
	}
	if (flag==2)
	{
		me->add("ming/suikao/huilu/money",-value);
		me->add("ming/suikao/huilu/guwan",value);
	}
    return 1;
}

int dest(object ob)
{
    if (ob)
    destruct(ob);
    return 1;
}

int accept_object(object me,object ob)
{
    object guan=this_object();
    string guanid=guan->query("id");
    int pin=guan->query("mingpin");
    if (!pin)
    {
        pin=3;
    }
    if (!me->query("mingpin"))
    {
        return notify_fail("这是何意？贿赂本官吗？\n");
    }
    if (time()-me->query("ming/suikao/renmai/"+guanid)<3600*24)
    {
        return notify_fail("你今年已经送过重礼给"+guan->name()+"，再这样，未免会被别人看轻。\n");
    }
    else if (ob->query("money_id")&& ob->value() >= 500000)
    {
		if (me->query("ming/suikao/huilu/money")>10000000)
		{
			return notify_fail("你这段时间总是送钱，已经被人瞧不起，玩点高雅的吧。\n");
		}
		command("say 能和"+me->name()+"大人同殿为官，我辈之幸事啊。");
        getid(me,guan,ob,pin,1);
        me->add_busy(1);
        call_out("dest",1,ob);
        return 1;
    }
    else if (ob->query("is_guwanzihua"))
    {
		if (me->query("ming/suikao/huilu/guwan")>10000000)
		{
			return notify_fail("你这段时间总是送字画古玩，已经被人笑话附庸风雅，直接点吧。\n");
		}
        command("say "+me->name()+"大人，真是上道啊。");
        getid(me,guan,ob,pin,2);
        me->add_busy(1);
        call_out("dest",1,ob);
        return 1;
    }
    else 
    {
        return notify_fail(me->name()+"大人，请自重。\n");
    }
}