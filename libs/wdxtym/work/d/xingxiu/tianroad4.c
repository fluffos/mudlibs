// room: /d/xingxiu/tianroad4.c
inherit ROOM;

void init();
int do_jump(string arg);

void create()
{
	set("short", "天山山路");
	set("long", @LONG
这里是天山东麓，山风从山上吹来，你冷得瑟瑟发抖。路边是一片针叶
林。石壁上盛开着一朵洁白的天山雪莲，一个采药人正在采药。东面一条深
涧(valley)挡住了下山的路。
LONG );
	set("exits", ([
	    "westup" : __DIR__"tianroad5"
	]));
	set("objects", ([
		__DIR__"npc/caiyaoren"  : 1,
		__DIR__"obj/xuelian" : 1
	]));

	set("item_desc", ([
		"【深涧】" : "深涧有三丈多宽，不知道能不能跳(jump)过去。\n"
		ZJOBACTS2"跳过去:jump valley\n",
	]) );
	set("outdoors", "xingxiu");

	setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="valley" ) {
	       message("vision", me->name() + 
			  "一提气，双足点地跳过了深涧。\n",
	       environment(me), ({me}) );
	       me->move("/d/xingxiu/tianroad3");
	       message("vision", me->name() + 
			  "从深涧上面跳了下来。\n",
	       environment(me), ({me}) );
	       return 1;
       }
}
