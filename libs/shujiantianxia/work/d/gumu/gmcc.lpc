// Room: /u/xdd/gumu/gmchucang.c
// Modify By River 98/10
#include <room.h>
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIC"储藏室"NOR);
	set("long", @LONG
古墓生活甚是清苦，储藏室堆着些日常用品，都整整齐齐堆放在墙角，看
来经常有古墓弟子前来打扫，其余别无他物。
LONG  
	);

	set("exits", ([
		"north" : __DIR__"fang",
	]));    

	setup();
}

void init()
{
	add_action("do_search", ({"search","zhao"}));
}

int do_search(string arg)
{
	object me=this_player();
	if ( arg == "qiangjiao"){
		if (me->query_temp("firefind"))
			return notify_fail("你已经拿了火折了，怎么这么贪心？\n");
		if (me->query_temp("fire") < 3 ){
			if(objectp(present("fire", me)))        
				return notify_fail("你已经拿了火折了，怎么这么贪心？\n");
			me->add_temp("fire", 1);
			message_vision(YEL"$N在墙脚的物品堆里翻来翻去什么也没找着。\n"NOR, me);
			return 1;
		}
		message_vision(HIY"$N在墙脚的物品堆里翻来翻去找出一把火折。\n"NOR, me);
		me->delete_temp("fire");
		me->set_temp("firefind", 1);
		new(MISC_D("fire"))->move(me);
		return 1;
	}
	return notify_fail("你要找什么？\n");      
}
