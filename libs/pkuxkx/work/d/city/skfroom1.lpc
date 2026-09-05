// Zine 26 Sep 2010 史可法任务房间配置

inherit ROOM;
#include <ansi.h>
void create()
{
	set("no_die",1);
	set("no_task",1);
    set("outdoors", "city");
}

void init()
{
    object me=this_player();
    me->listen_to_die(this_object());
	add_action("do_dig", ({ "wa", "dig"}));
    if (userp(me)&&!wizardp(me) && !me->query("skf/jobasked"))
    {
        tell_object(me,"此地危险重重，不宜久留！\n");
        me->move(__DIR__"beimen");
    }
}

int found(object me)
{
	object ob;
	if (random(10)>5)
	{
		if (ob= new("/d/city/obj/tudou"))
		{
			ob->move(me);
			me->add_busy(random(2));
			message_vision("$N在路边地里刨了半天，找到一块土豆。\n", me);
		}
		else
		{
			message_vision("$N在路边地里刨了半天，除了十指的鲜血，其他什么也没得到。\n", me);
		}	
	}
	else
	{
		message_vision("$N在路边地里刨了半天，除了十指的鲜血，其他什么也没得到。\n", me);
	}
	return 1;
}

int do_dig()
{
	object me = this_player();
	if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着哪！\n");
    else if(present("tu dou", me)) 
	return notify_fail("你是来帮助转移难民的还是专业挖土豆的？\n");
    else 
	found(me);
	return 1; 
}
int addneili(object me)
{
    int neili=me->query("max_neili");
	if (me->query("neili")>me->query("max_neili")*2)
    {
        return 1;
    }
    else if (me->query("neili")<me->query("max_neili"))
    {
        neili=random(neili)*2/3;
        me->add("neili",neili);
        return 1;
    }
    else
    {
        neili=random((me->query("max_neili")*2)-(me->query("neili")))/5;
        me->add("neili",neili);
        return 1;
    }
}

int valid_leave(object me,string dir)
{  
	object qing1=present("xi zuo",environment(me));
	object qing2=present("niulu ezhen",environment(me));
	object qing3=present("duo",environment(me));
	if (present("xi zuo", environment(me))&& qing1->query("target")==me->query("id"))
	return notify_fail("你刚准备离开，发现女真细作"+qing1->query("name")+"正虎视眈眈看着你，你只得回来应战。\n");
	if (present("niulu ezhen", environment(me))&& qing2->query("target")==me->query("id"))
	return notify_fail("你刚准备离开，发现女真牛录额真"+qing2->query("name")+"正虎视眈眈看着你，你只得回来应战。\n");
	if (present("duo ergun", environment(me))&& qing3->query("target")==me->query("id"))
	return notify_fail("你刚准备离开，发现"+qing3->query("name")+"正虎视眈眈看着你，你只得回来应战。\n");
	if (dir=="eastup" &&this_object()->query("shaonian_place") && !me->query_temp("skf/huaquanpass")&& present("shao nian", environment(me)))
	return notify_fail(WHT+"少年站在桥上，完全没有给你让路的意思。\n"+NOR);
	if (!me->query_temp("skf/refugeeasked")&&this_object()->query("qinjun_place"))
	return notify_fail(WHT+"亲兵看着你，冷冷道：你不护送难民来这玩吗？\n"+NOR);
	if (dir=="south" && userp(me) && !me->query_temp("skf/skf2")&&this_object()->query("milin_place"))
	{
		if(!present("nan min",environment(me)))
		return notify_fail("你刚准备离开，发现难民竟不在你身边，你只得回头寻找。\n");
		else 
		{
			tell_object(me,HIC+"你终于走出了这一片一望无际的密林。\n"+NOR);
			me->add_temp("skf/credit",5);
			if (!me->query_temp("skf/milinpass"))
			{
				tell_object(me,HIG"出了密林，你一阵放松，身心又充满活力。\n"NOR);
                addneili(me);
				me->set_temp("skf/milinpass",1);
			}
		}
	}
	me->remove_listen_to_die(this_object()); 
	return ::valid_leave(me, dir);
}

int shikefa_room()
{
	return 1;
}