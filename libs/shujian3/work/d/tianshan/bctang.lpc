// Room: /d/tianshan/bctang.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "百草堂");
	set("long", @LONG
这里是灵鹫宫的药房，室中摆放着各种不同的配药的用具和一些已经配好
了的药。
LONG);
	set("exits", ([
		"south" : __DIR__"zoulang3",
        ]));
	set("objects", ([
		__DIR__"npc/f-dizi" : 1,
	]));  

	setup();
}

void init()
{
	add_action("do_move", "search");
}

int do_move(string arg)
{
	object me = this_player();
	object ob;
	
	if (!arg || arg != "yaofang") 
		return 0;
	
	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if ( me->query_temp("ljg/book"))
		return notify_fail("你找了半天，发现这里什么也没有。\n");

	if (random(me->query("kar")) > 20) {
		ob = unew(MEDICINE_D("m-book10"));
		if(!clonep(ob)) return notify_fail("你找了半天，发现这里什么也没有。\n");
		if(clonep(ob) && ob->violate_unique()){
			destruct(ob);
			return notify_fail("你找了半天，发现这里什么也没有。\n");
		}
		message_vision("$N发现在药房的角落里，放着一本古色古香的书。\n", me);
		ob->move(me);
		me->set_temp("ljg/book", 1);
		return 1;
	}
	me->set_temp("ljg/book", 1);
	return notify_fail("你找了半天，发现这里什么也没有。\n");
}
