inherit ROOM;
#include <ansi.h>
string look_xiang();
void create()
{
	set("short", "药铺");
	set("long", @LONG
这里是新近开的一家药铺，老板据说是相当有关系的一个人。
LONG);
     

	set("exits", ([
		"enter" : __DIR__"yaopu2",
		//"east" : __DIR__"yaopu",
		"east" : __DIR__"xiaoxiang",
		//"north" : __DIR__"beijie3",
	]));

	set("objects", ([
		__DIR__"npc/yaolaoban" : 1,
        ])); 
	setup();
}

int valid_leave(object me,string dir)
{
	object rm;
	if (dir=="enter")
	{
		if (me->is_busy()||me->is_fighting())
		return notify_fail("你正忙着呢。\n");
		if(userp(me)&&time() - me->query("killer/time") < 900)
		return notify_fail("你刚刚杀了人，别想躲进药铺隔间里。\n");
		if (time()>=me->query_temp("PermitAlchemy3")&&time()>=me->query_temp("PermitAlchemy4"))
		return notify_fail("你要租药炉需要跟药铺老板打招呼了。\n");
		if (time()<me->query_temp("PermitAlchemy4"))
		rm=new(__DIR__"yaopu3");
		else if (time()<me->query_temp("PermitAlchemy3"))
		rm=new(__DIR__"yaopu2");
		message_vision("$N和老板打过招呼后，向药铺后堂的小隔间离去。\n",me);
		me->move(rm);
		rm->set("user",me->query("id"));
		return notify_fail("你来到了药铺的小隔间。\n");
	}
	return ::valid_leave(me,dir);
}