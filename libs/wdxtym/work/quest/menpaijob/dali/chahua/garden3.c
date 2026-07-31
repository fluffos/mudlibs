//Cracked by Kafei
// Room: /d/dali/garden3.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIY"茶花院"NOR);
	set("long", @LONG
这里满地遍是茶花，五颜六色，绚丽夺人。花丛中时时有
蜜蜂采蜜其间。碎石路边却长了一，两品异种茶花(flower)。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "flower" : RED"十八学士
十八学士，是天下的极品，一株上共开十八朵花，朵朵颜色
颜色不同，红的就是全红，紫的便是全紫，决无半分混杂。
而且十八朵花形状业朵朵不同，各有各的妙处，开时齐开谢
时齐谢。
 "NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"garden5",
  "southwest" : __DIR__"garden2",
]));


        set("objects", ([
                __DIR__"npc/huajiang": 1,
                __DIR__"npc/huachu": 2,
        ]));                                                                  
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}


int valid_leave(object me, string dir)
{
	if (me->query_temp("garden_working"))      
 	  return notify_fail("没干完活儿就想溜，没门儿！\n");  
          return ::valid_leave(me, dir);
}                                                                             
