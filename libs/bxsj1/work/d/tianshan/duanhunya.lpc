// Room: /d/tianshan/duanhunya.c
// By Linux

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "断魂崖");
	set("long",
"爬上悬崖，是一片很小的立足之地，寒风呼啸，吹的你的身体不由的左右
摇摆。你不由的擦了把汗，回头看看来路，已经湮没在云雾之中了。右手上三
个大字"HIW"断魂崖"NOR"正是你现实心情的写照。当面一块巨岩，有四、五丈高，因长时
间在这里受风雪侵蚀，已是滑不留手，上面有一行小字(zi)。    
");
	 set("exits", ([
                "east" :__DIR__"banshan",
	        "northup" :__DIR__"shizhuyan",
	        "westdown":__DIR__"shanjian",
        ]));
	 set("objects", ([
                __DIR__"npc/lu" : 1,
        ]));  
	 set("item_desc", ([                    
                "zi":HIR"
\t一   回
\t失   头
\t足   才
\t成   知
\t千   性
\t古   命
\t恨   真\n\n"NOR,
		"down":"下面云雾飘渺似乎有个巨大的水潭。\n",
        ])
        );
	set("outdoors", "天山");
	setup();
}

void init()
{
	add_action("do_jump",({"tiao","jump"}));
}

int do_jump(string arg)
{
	object me = this_player();
	
	if(!arg) return notify_fail("你要往哪里跳？\n");
	if(arg=="down")
	{
		object tmp;
		object room;
		if(!me->query_temp("comfy_tiao"))
		{
			me->set_temp("comfy_tiao",1);
			return notify_fail(HIR"虽然下面是个水潭，不过此处太高跳下去很危险的，你想清楚了再跳吧。\n"NOR);
		}
		me->delete_temp("comfy_tiao");
		tell_object(me,"那好吧……永别了……\n");
		tell_object(me,HIR"你只觉得耳边呼呼风声作响，身体飞快的象下缀去....\n"NOR);
		room=find_object(__DIR__"longtan")?find_object(__DIR__"longtan"):load_object(__DIR__"longtan");
		tell_object(room,me->name()+"从上面的断魂崖跳了下来。\n");
		me->move(room);
		message_vision(HIW"由于速度太快$N一头扎进水潭里。\n"NOR,me);
		tell_object(me,"你只觉得呼吸越来越艰难。\n");
		me->set_temp("last_damage_from","跳进龙潭淹");
		me->unconcious();
        	me->die();
        	if (tmp = present("corpse", room )) {
        		object* ob;int i;
        		ob = deep_inventory(tmp);
        		i = sizeof(ob);        	
        		while (i--) if (userp(ob[i])){
        			ob[i]->move(room);
        			ob[i]->set_temp("last_damage_from","摔下断魂崖跌");
        			ob[i]->die();
			}
			destruct(tmp);
			if (me)
			{
				tell_room(this_object(), me->name()+"的尸骨都找不到了。\n");
				tell_room(room, me->name()+"的尸骨都找不到了。\n");
			}
		}
		return 1;
	}
	return 0;	
}
