// /d/xingxiu/silk4.c
// Jay 3/17/96

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "丝绸之路");
          set("long", @LONG
这是一条中原和西域之间的商道。西面是一望无际的大沙漠，
传说那里常有盗匪出没。西北则通向一片连绵的山脉，东面就是通
向中原的路。路边有一块石碑(shibei)。
LONG );
        set("outdoors", "xingxiuhai");

        set("exits", ([
                "east" : __DIR__"silk3",
		"west" : __DIR__"shamo1",
                "northwest" : __DIR__"shanjiao",
        ]));

        set("item_desc", ([
                "shibei" : "北至西域，东达中原。谁若西行，格杀勿论。白驼山主人启。\n",
        ]));

        setup();
}

void init()
{
        add_action("do_push", "push");
        add_action("do_push", "tui");
        add_action("do_west", "west");
}


int do_push(string arg)
{
	object me;
	mapping fam;

	me = this_player();

	if( !arg || arg=="" ) return 0;

        if( arg=="shibei" ||arg=="bei" ||arg=="石碑")
	{
		if( (fam = me->query("family")) && fam["family_name"] == "丐帮" ) 
		{
			message_vision("$N推开石碑，只见泥沙纷纷跌落，地面上露出一个小洞。\n", me);
			message("vision",
				me->name() + "运起丐帮缩骨功，一弯腰往洞里钻了进去。\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/underxx");
                	message("vision",
				me->name() + "从洞里走了进来。\n",
                		environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("这么小的洞，你钻得进去吗？\n");
	}
}	
int valid_leave(object me, string dir)
{
        if(dir != "west")
               return ::valid_leave(me, dir);
        if(me->query("age") < 17 && me->query("family/family_name") != "白驼山")
                return notify_fail(HIR"你年岁尚小，又不是白驼山弟子，还是别冒这个险了。石碑上的字使你暗生怯意。\n"NOR);
        if(me->query("combat_exp") < 500000)
                return notify_fail(HIR"茫茫大漠荒无人烟，备好饮水食物之后再往西走(west)罢。\n"NOR);
        return ::valid_leave(this_player(), dir);
}

int do_west(string arg)
{
        return ::valid_leave(this_player(), "west");
}
