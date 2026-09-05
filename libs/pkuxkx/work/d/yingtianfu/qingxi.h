//清洗城门，quest江南 By Zine
#include <ansi.h>
void init()
{
    add_action("do_qingxi", ({"qingxi","清洗"}));
}

int rebuild(object ob)
{
    ob->delete("clean");
    ob->delete("rebuild");
    ob->set("dirty",5+random(5));
    return 1;
}

int do_qingxi()
{
    object ob=this_object();
    object me=this_player();
    
    if (ob->query("clean") && ob->query("clean")!=me->query("id"))
    {
        return notify_fail("这座城门刚被清洗过。\n");
    }
    if (me->query_temp("jn/step8a")>13)
    {
        return notify_fail("至于吗？应天府才十三座城门，你这样循环擦，怎么能擦完啊？\n");
    }
    if (me->is_busy() || me->is_fighting())
	{
		return notify_fail("你正忙着哪！\n");
    }
    if (!me->query_temp("jn/step8a"))
    {
        return notify_fail("守门的官兵不认识你，还以为你是奸细呢。不让你靠近城门。\n");
    }
    if (ob->query("dirty")<=1)
    {
        return notify_fail("这座城门似乎已经完全干净了。\n");
    }
    ob->set("clean",me->query("id"));
    if (!ob->query("rebuild"))
    {
        call_out("rebuild",600,ob);
        ob->set("rebuild",1);
    }
    
    ob->add("dirty",-1);
    message_vision("$N在认真的清洗这座城门。\n",me);
    me->add_busy(1);
        if (ob->query("dirty")==1)
        {
            tell_object(me,"这座城门似乎已经完全被你洗干净了。\n");
            me->add_temp("jn/step8a",1);
            tell_object(me,sprintf("你已经清洗了%s座城门。\n",chinese_number(me->query_temp("jn/step8a"))));
        }
    return 1;
    
}
int valid_leave(object me,string dir)
{  
	if (dir==query("inbound"))
    {
		if (me->query("mingpin"))
		{
			if (me->query("mingpin")==1)
			{
				message_vision(HIW+"守城的士兵将半开的大门全部打开，向$N恭敬地行礼：恭送大人入城。\n"+NOR,me);
				return ::valid_leave(me,dir);
			}
			message_vision("守城的士兵躬下身去，向$N行礼：恭送大人。\n",me);
			return ::valid_leave(me,dir);
		}
		if (me->query("ming/tj/pin"))
		{
			message_vision("守城的士兵向$N行礼：见过公公。\n",me);
			return ::valid_leave(me,dir);
		}
		if (me->query("jiangnanquest/step8"))
		{
			message_vision("守城的士兵对$N挥了挥手，快进去吧。\n",me);
			return ::valid_leave(me,dir);
		}
		if (query("mj_inbound")&&me->query("mingjiaonewbiejob/daming"))
		{
			message_vision("守城的士兵核对了$N的身份：大明的客卿，进去吧。\n",me);
			return ::valid_leave(me,dir);
		}
		if (me->query_temp("mingtasks/libu/theone")&&query("mingtask_inbound"))
		{
			message_vision("守城的士兵对$N挥了挥手：既有吏部邀请文书，快进去吧。\n",me);
			return ::valid_leave(me,dir);
		}
		if (present("entry permit",me))
		{
			message_vision("守城的士兵检查了$N身上的通行证，予以放行。\n",me);
			return ::valid_leave(me,dir);
		}
        return notify_fail("应天府现在防备倭寇，大门半开着，守城的士兵拦住了所有闲杂人等。\n");
    }
	return ::valid_leave(me, dir);
}


