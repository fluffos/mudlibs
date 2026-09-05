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
        return notify_fail("至于吗？建康府才十三座城门，你这样循环擦，怎么能擦完啊？\n");
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
	if (query("exits/"+dir)&&load_object(query("exits/"+dir))&&load_object(query("exits/"+dir))->query("is_CityWall"))
	return notify_fail("城墙不许随便攀爬。\n");
	return ::valid_leave(me,dir);
}

