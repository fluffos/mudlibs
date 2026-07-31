// /d/hmy/houdian.c

inherit ROOM;

void create()
{
	set("short", "后殿");
	set("long", @LONG
殿中无窗，殿口点着明晃晃的蜡烛，当中摆放一张大长桌，两旁摆满了各
式椅子，一看就知道这里是教中重要人物议事谋策的地方。
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"changlang6",
		"west" : __DIR__"changlang5",
	]));

	set("objects", ([ 
		__DIR__"npc/zhou" : 1,
		__DIR__"npc/wu" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_push",({"tui","push"}));
}

void close_passage(object me)
{
	if (!query("exits/east")) return;
	message_vision("墙壁突然缓缓的合拢，将东面的出口挡住了。\n",me);
	delete("exits/east");
	return;
}

int do_push(string arg)
{
	object me = this_player();
	object ob = this_object();
	object obj1,obj2;

	if (!arg || arg == "")
		return notify_fail("你要推什么？\n");
	if (arg == "wall") {
		if ( me->query("neili") < 1000)
			return notify_fail("你用尽全力想将墙壁推向两边，无奈内力不够。\n");
		if (!query("exits/east")) {
			message_vision("$N用尽全力将墙壁向两边推去。\n",me);
			obj1 = present("wu baiying",ob);
			obj2 = present("zhou gutong",ob);
			if (objectp(obj1)) {
				message_vision(obj1->name() + "伸手把$N拦住，叫道：“干什么！”\n",me);
				return 1;
			}
			if (objectp(obj2)) {
				message_vision(obj2->name() + "伸手把$N拦住，叫道：“干什么！”\n",me);
				return 1;
			}
			message_vision("墙壁突然向两边缓缓移动，露出了一个向东的出口。\n",me);
			me->add("neili",-500);
			me->start_busy(random(2) + 1);
			set("exits/east", __DIR__"andao1");
			call_out("close_passage", 5 , me);
			return 1;
		}
		else {
			message_vision("$N用尽全力去推墙壁，可是墙壁却纹丝不动。\n",me);
			me->add("neili",-500);
			me->start_busy(random(2) + 1);
			return 1;
		}
	}
	else return notify_fail("什么？\n");
}
