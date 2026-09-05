//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "长江岸边");
        set("long", @LONG
这里是长江南岸，远远向北望去，江面被雾色笼罩。
LONG
        );
        set("exits", ([
             "west" : __DIR__"dkn1a",
             "southeast" : __DIR__"cjn2",
             "southwest" : "d/zhenjiang/xiaosha",
        ]));
        set("couldfish",1);

        
		set("shediao_place",3);
        //set("objects", ([
        //        "/kungfu/class/xingxiu/zhaixing" : 1,
        //]) );

        set("no_clean_up", 0);
        set("outdoors", "changjiang");

        setup();
}

int valid_leave(object me,string dir)
{  
	if (dir=="southwest")
    {
           return notify_fail("你只能远远看到一座小沙堆，可惜没有路过去。\n");
        
    }
	return ::valid_leave(me, dir);
}
int shediao(object me)
{
	object *all,huang;
	int i;
	if (!me)
	{
		return 1;
	}
	if (!living(me))
	{
		return 1;
	}
	if (environment(me)->query("shediao_place")!=3)
	{
		return 1;
	}
	if (!present("huang rong",this_object()))
	{
		return 3;
	}
	all=all_inventory(this_object());
	for (i=0;i<sizeof(all);i++)
	{
		if (all[i]->query("shediao_huangrong")&&all[i]->query("owner")==me&&me->query_temp("shediaoquest/kanglong/start")==11)
		{
			me->set_temp("shediaoquest/kanglong/start",12);
			huang=all[i];
			message_vision("$N道：“好饿，我去找点吃的，你去附近找点柴火来生火吧。”\n",huang);
			message_vision("$N转身离开。\n",huang);
			huang->move("/d/city/hideroom");
			me->set_temp("shediaoquest/kanglong/huang",huang);
			return 1;
		}
	}
}
void init()
{
	object *all;
	int i;
	all=all_inventory(this_object());
	add_action("do_swim","swim");
	for (i=0;i<sizeof(all);i++)
	{
		if (all[i]->query_temp("shediaoquest/kanglong/start")==10)
		{call_out("shediao",1,all[i]);all[i]->set_temp("shediaoquest/kanglong/start",11);}
	}
	return;
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
		room=load_object("/d/changjiangnorth/cjb3");
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
		me->add_busy(18);
		call_out("arrive",18,me);
	}
	return 1;
}
