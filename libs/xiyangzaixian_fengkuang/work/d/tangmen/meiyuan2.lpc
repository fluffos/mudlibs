// Room: /d/tangmen/meiyuan2.c

inherit ROOM;

void create()
{
	set("short", "梅园");
	set("long", @LONG
	这是唐门中的一大片梅林，每逢满园梅花绽放，幽香袭人，令人觉得神清气
爽。园中有一排梅树的断桩，也组成梅花状。桩顶十分平滑，好象常有人在上面跳跃
(tiao)。
LONG
	);
	
set("outdoors", "tangmen");
	set("exits", ([
		
		"west" : __DIR__"meiyuan1",
		"east" : __DIR__"zhanmeige",
	]));

	setup();
}

void init()
{
	add_action("do_tiao", "tiao");
	
}


int do_tiao(string arg)
{
	object me;

	me = this_player();

	if ( !arg || ( arg != "zhuang" ) )
		return notify_fail("你又不是猴子，乱蹦乱跳的干什么？\n");
		
	me->receive_damage("qi", 20);

	message_vision("$N纵身一跃，跳上梅花桩。\n", me);

	if ( (int)me->query_skill("dodge", 1) < 60)
	{
		me->improve_skill("dodge", me->query("int"));
		write("你在梅花桩上游走了一圈，觉得对轻身功夫有了些了解。\n");
		return 1;
	}

	write("你再跳也没用了。\n");

	return 1;
}
