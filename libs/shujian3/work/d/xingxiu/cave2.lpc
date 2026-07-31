// room: /d/xingxiu/cave2.c
// Modify by Lklv 2001.10.16

inherit ROOM;

int do_use(string arg);
int do_zuan(string arg);

void create()
{
	set("short", "山洞");
	set("long", @LONG
本来是黑黝黝的山洞里，伸手不见五指。只有一丝微光从洞顶的裂缝透进
来，可以勉强看见正中央有一个石棺，散发着浓厚的腐尸气味，微光下更显得
洞内阴森可怕。一个鬼一般的人影坐在石壁边，两只闪着蓝光的眼睛正盯着你
看，山壁上有人工修缮之处。
LONG);
	set("objects", ([
		__DIR__"npc/piaoran" : 1,
		__DIR__"obj/shiguan" : 1,
		__DIR__"obj/muding" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_use", "use");
	add_action("do_zuan", "zuan");
}

int do_use(string arg)
{
	object me = this_player();

	if( !arg || arg=="" ) return 0;
	if (me->is_busy() || me->is_fighting()) return 0;
	if (!present("fire", me))  return 0;
	if(arg=="fire") {
		write("你点燃了火折，发现东面石壁上的一道裂缝可以钻(zuan)出去。\n");
		me->set_temp("marks/钻", 1);
		me->start_busy(2);
		return 1;
	}
}

int do_zuan(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting()) return 0;
	if(me->query_temp("marks/钻") ) {
		message("vision", me->name() + "滋溜一下不知从什么地方钻出去了。\n", environment(me), ({me}) );
		me->move(__DIR__"cave");
		message("vision", me->name() + "不知从什么地方钻了出来。\n", environment(me), ({me}) );
		me->set_temp("marks/钻", 0);
		return 1;
	}
	else {
		write("你想往哪儿钻?!\n");
		return 1;
	}
}
