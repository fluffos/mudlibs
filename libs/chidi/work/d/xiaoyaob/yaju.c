// yaju.c
// by keinxin

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "雅居");
        set("long", @LONG
这是一间不是很大的居室，两边挂着字画，室中摆放着各种奇花异草，
书架上摆满了各种古籍善本。旁边放着一把古琴(qin)。
LONG );

set("item_desc", ([
		"qin" : "一架古琴，可以用来弹(tanqin)\n",
	]));
	set("exits", ([
		"west" : __DIR__"muwu2",
	]));
	set("objects", ([

	]));
	setup();
}

void init()
{
	add_action("do_tanqin","tanqin");
}
int do_tanqin(string arg)
{
       object me=this_player();
       if (me->query("job_lianasked")<1)
        return notify_fail("苏星河没有让你练，你白费力气干什么？\n"); 
         if (me->is_busy() )
       return notify_fail("你正忙练琴啊！\n");
        if (me->query("job_lian")<4)
       return notify_fail("你该去练棋了！\n");
       message_vision(HIC
      "$N手拂琴弦，一阵琴声扬起，悠悠入耳……\n"NOR,me);
       me->improve_skill("art", (int)me->query_skill("art", 1)/3+1);
       me->add("jing",-20);
       me->add("job_lian",-1);
       me->start_busy(3);
       return 1;
}