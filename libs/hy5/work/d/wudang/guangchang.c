//Room: guangchang.c 武当广场
//Date: Sep 22 1997
#include <ansi.h>
inherit ROOM;
int do_zhao(string arg);

void create()
{
      set("short","武当广场");
      set("long",@LONG
这是一个由大石板铺成的广场，是武当弟子学习武功和互相切磋的地点。
周围种满了梧桐树，一到秋天就是满地的落叶。一个年纪轻轻的道童正在打扫。
南边是灵霄宫三清殿。
LONG);
      set("objects", ([
           CLASS_D("wudang") +"/daotong": 2,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"zixiaogate",
          "south"      : __DIR__"sanqingdian",
          "eastdown"   : __DIR__"tyroad1",
          "east"       : __DIR__"shanlu2",
      ]));
//      set("no_clean_up", 0);
set("chu_count", 2);
      set("outdoors", "wudang");
      setup();
//      replace_program(ROOM);
}

void init()
{
	add_action("do_zhao", ({"zhao","find"}));
}

int do_zhao(string arg)
{
	object me;
	me=this_player();
	if ( arg != "yao chu" )
	    return notify_fail("你要找什么？\n");
	if (present("yao chu", me))
	   return notify_fail("你找来找去，发现自己原来已经有了！\n");
	if (objectp(present("yao chu", environment(me))))
	   return notify_fail("地上就有，你还找什么？！\n");

	if (query("chu_count") > 0)
	  {
	   add("chu_count", -1);
	   new(__DIR__"obj/yaochu")->move(me);
	   message_vision("$N在墙脚的杂物堆里翻来翻去找出一把药锄。\n", me);
	   me->start_busy(random(2));

	  }
	else
	   message_vision("$N在墙脚的杂物堆里翻来翻去什么也没找着。\n", me);
     return 1;
}
