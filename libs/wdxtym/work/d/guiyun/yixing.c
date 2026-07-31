// Room: /guiyun/yixing.c
// Date: Nov.18 1998 by Winder

#include <ansi.h>

inherit ROOM;

int do_cut(string arg);

void create()
{
	set("short", "宜兴");
	set("long", @LONG
这儿便是天下闻名的陶都，青山绿水之间掩映着一堆堆紫砂陶坯，
另有一番景色。向东行，不远处就是太湖边。南方便是湖州府了。
LONG );
	set("max_room", 3);
	set("outdoors", "guiyun");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"tiandi",
		"south"     : __DIR__"nanxun",
		"northwest" : "/d/wudang/wdroad2",
	]));
		set("action_list", ([
		HIG"割草"NOR:"kan grass",
	]));
	
	setup();
//	replace_program(BUILD_ROOM);
}

void init()
{
	add_action("do_kan", "kan");
}

int do_kan(string arg)
{
	object me,ob;
	me = this_player();
    
	if (! arg || arg == "")
	return 1;
	
	if (me->is_busy())
			return notify_fail("你的动作还没有完成，不能移动。\n");
			
	if (objectp(ob = present("quest grass",me))&&ob->query_amount()>=10)
		return notify_fail("你一次性背那么多草料不累吗？下次再来吧！\n");
		
 	ob=new("/d/bangpai/obj/grass");
 	ob->move(me);
	 tell_object(me,HIW"你辛苦的割草，获得了"+ob->query("name")+"。" NOR "\n");
	 me->start_busy(1+random(10));
	
	return 1;
}