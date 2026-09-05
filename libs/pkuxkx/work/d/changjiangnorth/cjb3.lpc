//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "长江岸边");
        set("long", @LONG
这里是长江北岸，远远向南望去，江面被雾色笼罩。
LONG
        );
        set("exits", ([
             "west" : __DIR__"dkb1a",
             "southeast" : "/d/city/changjiang",
        ]));
       
		set("shediao_place",1);
        set("couldfish",1);

        //set("objects", ([
        //        "/kungfu/class/xingxiu/zhaixing" : 1,
        //]) );

        set("outdoors", "changjiang");

        setup();
}
int arrive(object me)
{
	object room;
	if (!me||!living(me))
	{
		return 1;
	}
	else if (environment(me)->query("inriver"))
	{
		room=load_object("/d/changjiang/cjn3");
		message_vision("$N游到了长江对岸！\n",me);
		tell_room(room,me->name()+"从江里游了上来。\n");
		me->move(room);
		return 1;
	}
	else
	{
		return 1;
	}
}
int tell_me_huang(object me)
{
	if (!me)
	{
		return 1;
	}
	if (!living(me))
	{
		return 1;
	}
	if (!environment(me)->query("inriver"))
	{
		return 1;
	}
	tell_object(me,"你看着身边的黄蓉，我见犹怜，不禁想仔细打量(look)她。\n");
	return 1;
}
int do_swim()
{
	object me=this_player(),inriver;
	object *all,huang;
	if (!me->query("shediaoquest/kanglong/swim"))
	{
		tell_object(me,"只有被黄蓉指点过游泳之后才能横渡长江。\n");
		return 1;
	}
	if (inriver=load_object(__DIR__"inriver"))
	{
		message_vision("$N跳入江中，放松身体，划动手脚，向对岸游去。\n",me);
		me->move(inriver);
		me->add_busy(20);
		call_out("arrive",20,me);
		if (me->query_temp("shediaoquest/kanglong/start")==10)
		{
			tell_object(me,HBBLU+HIW"根据黄蓉的指点，这里可以横渡长江，可别忘记了。\n"+NOR);
			all=all_inventory(this_object());
			for (int i=0;i<sizeof(all);i++)
			{
				if (all[i]->query("shediao_huangrong")&&all[i]->query("owner")==me)
				{
					huang=all[i];
				}
			}
			huang->move(inriver);
			tell_object(me,"黄蓉也跳入江中，和你并肩游向前去。\n");
			call_out("tell_me_huang",3+random(5),me);
			call_out("arrive",19,huang);
		}
	}
	return 1;
}
int valid_leave(object me,string dir)
{  
	if (dir=="southeast")
    {
           return notify_fail("满清鞑子杀过来了，你不要命了？还往上凑？\n");
        
    }
	return ::valid_leave(me, dir);
}
int shediao2(object huang,object me)
{
	object valley;
	if (!me||!huang)
	{
		return 1;
	}
	if (!living(me)||!living(huang))
	{
		return 1;
	}
	if (environment(huang)!=environment(me)||environment(me)->query("shediao_place")!=1)
	{
		return 1;
	}
	if (me->query_temp("shediaoquest/kanglong/start")!=4)
	{
		return 1;
	}
	valley=new(__DIR__"valley");
	if (valley->isroom())
	{
		message_vision("$N笑嘻嘻地道：“快跟我来。”$n赶紧跟上，两人来到一处清溪。\n",huang,me);
		huang->move(valley);
		me->move(valley);
	}
	return 1;
}
int shediao(object me)
{
	int i;
	object *all,huang;
	if (!present("huang rong",this_object()))
	{
		return 3;
	}
	all=all_inventory(this_object());
	for (i=0;i<sizeof(all);i++)
	{
		if (all[i]->query("shediao_huangrong")&&all[i]->query("owner")==me&&me->query_temp("shediaoquest/kanglong/start")==3)
		{
			me->set_temp("shediaoquest/kanglong/start",4);
			huang=all[i];
			message_vision(CYN"$N和$n来到长江江边，$n却未发现$N所说的好玩之处。\n"NOR,huang,me);
			call_out("shediao2",2,huang,me);
			return 1;
		}
	}
	return 2;
}
int she_diao2(object huang,object me)
{
	object valley;
	if (!me||!huang)
	{
		return 1;
	}
	if (!living(me)||!living(huang))
	{
		return 1;
	}
	if (environment(huang)!=environment(me)||environment(me)->query("shediao_place")!=1)
	{
		return 1;
	}
	if (me->query_temp("shediaoquest/kanglong/start")!=10)
	{
		return 1;
	}
	huang->saypass(me);
	return 1;
}
int she_diao(object me)
{
	int i;
	object *all,huang;
	if (!present("huang rong",this_object()))
	{
		return 1;
	}
	all=all_inventory(this_object());
	for (i=0;i<sizeof(all);i++)
	{
		if (all[i]->query("shediao_huangrong")&&all[i]->query("owner")==me&&me->query_temp("shediaoquest/kanglong/start")==9)
		{
			me->set_temp("shediaoquest/kanglong/start",10);
			huang=all[i];
			message_vision("$N望着大江东去，白浪滔滔，四野无穷无尽，直觉胸中豪气干云。\n",me);
			call_out("she_diao2",1,huang,me);
			return 1;
		}
	}
	return 1;
}

void init()
{
	object *all;
	int i;
	all=all_inventory(this_object());
	add_action("do_swim","swim");
	for (i=0;i<sizeof(all);i++)
	{
		if (!userp(all[i]))
		continue;
		if (time()-all[i]->query("killer/time") < 15*60)
		continue;
		if (all[i]->query_temp("shediaoquest/kanglong/start")==3)
		call_out("shediao",1,all[i]);
		if (all[i]->query_temp("shediaoquest/kanglong/start")==9&&userp(all[i]))
		call_out("she_diao",1,all[i]);
	}
	return;
}


