
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"水没都市"NOR);
	set("long", GRN @LONG
    这个城市尽然在湖中,脚底下是三□来许的『水板』而两旁都是千丈高的水
墙。两旁水声轰隆隆地快要把你的耳膜震破, 挟带著漫天的水气,不禁把你的全
身都给濡湿了。 水墙里一些七彩斑斓的鱼儿正悠闲地追逐玩耍,有时游近你身
旁,一点也不怕你的样子,你不禁伸手想要穿过水墙去触摸它们,却似乎有股力
量阻挡著你。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_npc",1);
set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"dong23",
		"north" : __DIR__"dong71",
	]));
         set("objects", ([
              __DIR__"npc/player" : random(2),
         ]));

	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
       if ( !present("water jian", me) && dir == "north" )
        return notify_fail("一个士兵拦住了你：你通过水之力量使的考验了吗??\n");
       if ( !present("water cloth", me) && dir == "north" )
        return notify_fail("一个士兵拦住了你：你通过水之精灵王的考验了吗??\n");

	if (dir =="north")
	{

		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你想进去拐卖人口？\n");
       		
		}
		
	}

	return ::valid_leave(me, dir);
}
