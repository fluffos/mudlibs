// /u/beyond/mr/hhyuan.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",MAG"后花园"NOR);
	set ("long",@long
后花园和庄中其它地方一样种满了山茶花, 参杂在假山巨石, 绿竹小溪
中, 此所谓: `千呼万唤始出来, 犹报琵琶半遮面` 更增姿媚。 抬头望去, 
只见藏书阁的窗户半开着,一根古藤蜒伸在墙上。一股清泉从假山上涌出，
尝一口沁人心脾。
long);
         set("resource/water", 1);
         set("exits",([
             "north" : __DIR__"yunjinlou",
             "west" : __DIR__"hffang",
             "east" : __DIR__"zahuoshi",
]));
         set("item_desc",([
             "teng" : "一条顺着墙壁攀延而上的绿树藤。\n"
]));
	setup();
}

int init()
{
	add_action("do_pa","pa");
	add_action("do_say","say");
}

int do_say(string arg)
{
          object me;
	 me = this_player();
         if( !arg || arg != "漆叶云差密, 茶花雪忌艳")
         return notify_fail("什么？\n");
        if (me->query("family/family_name")!="姑苏慕容")
        return notify_fail("什么？\n");
        if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 50) {
		write("你想背别人进娘缳玉洞恐怕没这么容易吧？\n", me);
		return 0;
}
         message_vision("树藤里边一堵墙缓缓移了开来，原来是道小木门，$N顺着小门走了进去。\n", me);
         me->move(__DIR__"midao");
         return 1;
}
                
int do_pa(string arg)
{
         object me;
         me = this_player();
         if (arg != "teng")
         return notify_fail("你要做什么？\n");
         if ( arg =="teng")
         { 
         write("你沿着大树藤爬了上去。\n");
         message("vision",
         me->name() + "沿着大树藤爬了上去。\n",
                     environment(me), ({me}) );
         me->move(__DIR__"shuteng");
         message("vision",
                  me->name() + "从沿着树藤爬了上来。\n",
                             environment(me), ({me}) );
                }
                return 1;
            }

         