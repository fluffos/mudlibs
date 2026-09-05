// Room: /city2/aobai6.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
int do_move(string arg);
void create()
{
	set("short", HIY"鳌拜卧房"NOR);
	set("long", 
HIC"	这是鳌拜的卧房。只见地上铺着虎皮豹皮(pi)，墙上挂满弓矢刀剑，
不脱满洲武士的粗犷本色。房中站着一人，正是号称“满洲第一勇士”的鳌拜。\n"NOR
	);
	set("exits", ([
		"east" : __DIR__"aobai4",
	]));
	set("item_desc", ([
		"pi" : "虎皮下似乎有古怪。\n",
	]));
	set("objects", ([
		__DIR__"npc/aobai" : 1,
              "/clone/npc/camel1": 0,
	]));
	setup();
}
void init()
{
	add_action("do_move", "move");
        add_action("do_open", "open");
}
int do_move(string arg)
{
	object aobai, me;
	me = this_player();
	if (arg == "pi")
	{
		if(this_object()->query_temp("mark"))	return 0;
                if(!userp(this_player()))   return 0;
		if (objectp(aobai = present("ao bai", environment(me))))
		{
			message_vision("$N对$n大喝一声：“干什么？”\n", aobai, me);
			aobai->fight_ob(me);
			return 1;
		}

		message_vision("$N将虎皮掀开，扔到一旁，只见虎皮下现出一道铁板门来。\n",this_player());
		this_object()->	set("long", 
HIC"	这是鳌拜的卧房。只见地上铺着的虎皮豹皮已被掀开，\n地上露出一个很厚的铁板门(door)。\n"NOR);
		this_object()->	set("item_desc", ([
		"door" : "这是一扇极厚的铁板门，看来需要很大的力气才能打开。\n",
			]));
		this_object()->set_temp("mark", 1);

                remove_call_out("close");
                call_out("close", 60, this_object());

		return 1;
	}
	else return notify_fail("你要掀开什么？\n");
}

int do_open(string arg)
{
        object me, room;
        me = this_player();
	if(!this_object()->query_temp("mark"))	return 0;
        if (!arg || arg!="door") return notify_fail("你要打开什么？\n");
        if (me->query("neili") < 1000)
        {
		message_vision("$N想运功掀开铁板门无奈内力不济始终无法奏效。\n", me);
		me->add("neili", -1000);
		if (me->query("neili") < 0)
		{
			message_vision("$N气血翻滚，心神恍惚，一下晕了过去。\n", me);
			me->set("neili", 0);
			me->unconcious();
        	}
        	return 1;
	}
	message_vision("$N暗运内功，轻松掀开的铁板门。\n", me);
	me->add("neili", -1000);
	if(!( room = find_object(__DIR__"aobai9")) )
        room = load_object(__DIR__"aobai9");

    	if(objectp(room))
    	{
	        room->set("exits/up", __FILE__);
        	message("vision", "上面传来一阵响声，有人掀开了铁板门！！\n", room);
        	message("vision","你心中一阵狂喜：哈哈！又可以出去了！\n" , room );
	}

        set("exits/down", __DIR__"aobai9");
	return 1;
}

void close(object room)
{
	object room1;
        message("vision","只见虎皮自动恢复原位，盖住了地下的铁板门。\n", room);
        room->set("long", 
HIC"	这是鳌拜的卧房。只见地上铺着虎皮豹皮(pi)，墙上挂满弓矢刀剑，
不脱满洲武士的粗犷本色。房中站着一人，正是号称“满洲第一勇士”的鳌拜。\n"NOR
	);
	room->set("item_desc", ([
		"pi" : "虎皮下似乎有古怪。\n",
		]));
	room->delete_temp("mark");
        room->delete("exits/down");
	if(!( room1 = find_object(__DIR__"aobai9")) )
        room1 = load_object(__DIR__"aobai9");

    	if(objectp(room1))
    	{
	        room1->delete("exits/up");
		message("vision","只听乒地一声，铁板门自动关了起来。\n", room1);
                message("vision","你脑海中闪过一个念头：坏了！出不去了！\n" ,room1);
	}
        message("vision","你脑海中闪过一个念头：哎哟！又进不去了！\n" , room );
}
