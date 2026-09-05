inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "练武场");
        set("long", 
"这里是一座练武场，放了一些简单的器械，可供联系，东面是一片莲池。\n"

        );
        set("exits", ([
                
                "east" : __DIR__"shuichi",
                "north" : __DIR__"houting",
               // "west" : __DIR__"dating",
                "south" : __DIR__"dating",
                
        ]));
        set("objects", ([
		//"/d/yingtiannorth/npc/wujiang" : 1,
        __DIR__"obj/jia" : 1,
        
        ]));
        set("outdoors", "yingtianfu");
        setup();
   
}
int valid_leave(object me,string dir)
{
	if (dir=="east")
	return notify_fail("你要在都统制府投水自杀吗？\n");
	return ::valid_leave(me,dir);
}

void init()
{
	add_action("do_swing", "huiwu");
}
int improve(object me,string type)
{
	object ob=this_object();
	if (!me)
	return 1;
	if (environment(me)!=ob)
	return 1;
	message_vision("不多时，$N已经挥汗如雨。\n",me);
	me->improve_skill(type, 3*(int)me->query_skill(type, 1)+random((int)me->query_skill(type, 1)));
	return 1;
}
int do_swing()
{
	object me=this_player(),ob=this_object();
	int i, jing_cost, qi_cost,error=0;
	string type;
	jing_cost = 1200 / (int)me->query("int");
	qi_cost = 1000 / (int)me->query("int");
	if(((int)me->query("jing") <= jing_cost+100) || ((int)me->query("qi") <= qi_cost+100))
	{
		return notify_fail("你现在精气不足，练习有害无益。\n");
	}
	if (me->is_busy()||me->is_fighting())
	{
		return notify_fail("你现在正忙着呢。\n");
	}
	if (!me->query_temp("weapon")&&!me->query_temp("secondary_weapon"))
	{
		return notify_fail("你要找件兵器来挥舞。\n");
	}
	if (objectp(me->query_temp("weapon"))&&me->query_temp("weapon")->query("meng_weapon"))
	type=me->query_temp("weapon")->query("skill_type");
	if (objectp(me->query_temp("secondary_weapon"))&&me->query_temp("secondary_weapon")->query("meng_weapon"))
	type=me->query_temp("secondary_weapon")->query("skill_type");
	if (member_array(type,({"sword","blade","spear"}))==-1)
	return notify_fail("这件武器无法在这里练习挥舞。\n");
	if (me->query_skill(type,1)>50)
	return notify_fail("你再挥舞也无法提高了。\n");
	message_vision("$N挥舞着手中的兵刃。\n", me);
	me->add("jing",-jing_cost);
	me->add("qi",-qi_cost);
	me->add_busy(4);
	call_out("improve",4,me,type);
	return 1;
}