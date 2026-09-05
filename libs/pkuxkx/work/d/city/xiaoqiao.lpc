// 小桥
// edit: by zine Sep 9 2010

inherit __DIR__"skfroom1";
#include <ansi.h>

void create()
{
	set("short", HIW"小桥"NOR);
	set("long", @LONG
一座窄窄的小石桥，仅容一人通过，一个翩翩少年站在桥上玩耍。桥头有一
个大李树(tree)。
LONG
	);
	set("exits", ([ 
		"eastup" : __DIR__"milin",
		"north" : __DIR__"xiagu",
		
    ]));
	set("item_desc", ([
		"tree" : "李树上长满李子，有着诱人的色泽。你可以摘(zhai)下来\n", 
	]));
	set("objects", ([(__DIR__"npc/xiaohuaidan") : 1,
	]));
	set("no_task",1);
	set("shaonian_place",1);
	setup();
	::create();
}

void init()
{	
	add_action("do_zhai", ({ "zhai", }));
	::init();
}

int found2(object me)
{
	object ob;
	if (random(10)>7)
	{
		if (ob=new("/d/city/obj/lizi"))
		{
			ob->move(me);
			me->add_busy(random(2));
			message_vision("$N爬上李树，摘了一枚$n下来。\n", me,ob);
		}
		else
		{
			message_vision("$N在树上找了找，发现李子看起来很诱人，但很多都已经烂掉了。\n", me);
		}
	}
	else
	{
		message_vision("$N在树上找了找，发现李子看起来很诱人，但很多都已经烂掉了。\n", me);
		me->add_busy(1);
	}
	return 1;
}

int do_zhai()
{
	object me = this_player();
	if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着哪！\n");
    if(present("li zi", me) && present("shao nian", environment(me))) 
	return notify_fail(HIR"少年恶作剧地大叫，快来人啊，有人偷李子啊！\n"NOR);
    else 
	found2(me);
	return 1; 
}
