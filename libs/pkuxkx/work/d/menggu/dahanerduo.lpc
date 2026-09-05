inherit ROOM; 
#include <ansi.h>


void create() 
{ 
        set("short", "部落大门");
        set("long", @LONG
这里是大翰耳朵，铁木真的部落，也算是草原上的大部落了。
LONG
        );
	
        set("exits", ([ "east" : __DIR__"dahanerduo_path",
                        "west" :  __DIR__"kongdi",
                        "north" : __DIR__"machehang",
]));
		set("objects", ([
        	__DIR__"npc/banker" : 1,
	]));
        set("outdoors", "menggu_e");
		setup();
}
int farewell3(object me,object hua)
{
	if (!hua||!me)
	{
		return 1;
	}
	if (!living(hua)||!living(me))
	{
		return 1;
	}
	if (environment(me)!=environment(hua))
	{
		return 1;
	}
	hua->bye(me);
	return 1;
}

int farewell2(object me,object tuo,object hua)
{
	if (!tuo||!hua||!me)
	{
		return 1;
	}
	if (!living(tuo)||!living(hua)||!living(me))
	{
		return 1;
	}
	if (environment(me)!=environment(tuo)||environment(me)!=environment(hua))
	{
		return 1;
	}
	tuo->bye(me);
	call_out("farewell3",1,me,hua);
	return 1;
}

int farewell(object me)
{
	object tuo=new(__DIR__"npc/tuolei2");
	object hua=new(__DIR__"npc/huazheng2");
	message_vision("$N走出十余里，只见两头白雕在头上盘旋飞翔，拖雷和华筝并骑驰来送行。\n",me);
	tuo->move(this_object());
	hua->move(this_object());
	call_out("farewell2",1,me,tuo,hua);
	return 1;
}
void init()
{
	object me=this_player();
	if (me->query_temp("shediaoquest/zjk/bye_liping")&&me->query_temp("shediaoquest/zjk/farewell")&&me->query_temp("shediaoquest/zjk/bye_tie"))
	{
		if (me->query("shediaoquest/zjk")>=2)
		{
			return;
		}
		if (present("tuo lei",this_object())||present("huazheng gongzhu",this_object()))
		{
			return;
		}
		farewell(me);
	}
	return;
}