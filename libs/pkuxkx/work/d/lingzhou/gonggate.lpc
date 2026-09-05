// Room: /lingzhou/gonggate.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "皇宫大门");
	set("long", @LONG
这里就是西夏皇宫正门，四扇宽阔的朱红大门，上面包着拳头大的
铜钉。门的两边站着两排衣甲鲜明的武士，戒备深严。
LONG );
	set("exits", ([
		"north"  : __DIR__"gongsquare",
		"south"  : __DIR__"beidajie",
	]));
//        set("no_fight",1)
	set("objects", ([
		__DIR__"npc/gongweishi" : 4,
	]));
	setup();
//        create_door("north" , "红漆宫门", "south" , DOOR_CLOSED);
}
void init()
{

        add_action("do_answer","answer");      

}


int valid_leave(object me, string dir)
{
	object he = present ("xu zhu",environment(me));
	object room;
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);  
       if (dir == "north" && !me->query_temp("lingzhou/ask") &&
            objectp(present("wei shi", environment(me)))&& living(present("wei shi",environment(me))))
           return notify_fail("卫士对你大吼一声：站住，干什么的？(answer)\n");
		room = load_object(__DIR__"gongsquare");
		if (me->query_temp("lingjiu/leading") && present ("xu zhu",environment(me)))
		{
 	        	he = present ("xu zhu",environment(me));
 			he->move(room);
		}
        return ::valid_leave(me, dir);
}

int do_answer(string arg)          
{
     object p;
     object me= this_player();
	
       if(arg=="送信")
	{
		if (me->query_temp("lingjiu/find")!=1)
            		return notify_fail("卫士对你大吼一声：我看你是奸细吧，还不快滚？\n"); 
 		me->set_temp("lingzhou/ask",1);
    		write("卫士对你说：“原来是给公主送信的，快请进！”\n");
     		return 1;
        }
       write("你在胡说些什么，快滚！\n");
	return 1;

}
