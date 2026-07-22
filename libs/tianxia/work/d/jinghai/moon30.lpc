// Room: /d/jinghai/moon30.c

inherit ROOM;

void create()
{
	set("short", "牢房甬道");
	set("long", @LONG
这里是一条狭窄的过道，它是通向各个牢房得通道。四壁用
大块的青石砌成。甬道内只有墙壁上的小油灯，格外昏暗。偶尔
会听见还有滴答滴答的流水声音。四周不时传来大声得喊叫。令
人毛骨悚然。顶上盖着一个大铁闸。
LONG
	);

       set("item_desc", ([ 
       "铁闸" : "这是一个坚固大铁闸，铁闸旁边有一个钥匙孔。\n",
]));
       set("exits", ([ 
       "east" : __DIR__"moon31",
       "north" : __DIR__"moon34",
]));

      setup();
}

void init()
{
      add_action("do_open", "open");
}

int do_open(string arg)
{
	object me,room;

	me= this_player();
	if( !arg && arg != "铁闸" && arg != "zha")
		return notify_fail("要打开什么？\n");

	if( !objectp(present("tie key", me)) ) 
		return notify_fail("铁闸锁着呢，不用钥匙恐怕打不开。\n");

	if(!room = find_object(__DIR__"moon29"))
		room = load_object(__DIR__"moon29");
	if(!room)
		return notify_fail("铁闸无法打开。\n");

	if(!room->query("exits/down"))
	{
		room->set("exits/down",__FILE__);
		tell_room(room,"只听喀嚓一声，铁闸慢慢升起，露出了向下的出口。\n");
	}
	set("exits/up", __DIR__"moon29");

	tell_room(__FILE__,"只听喀嚓一声，铁闸慢慢升起，露出了向上的出口。\n");
	call_out("close",5);
	return 1;
}

void close()
{
	object room = find_object(__DIR__"moon29");

	if(query("exits/up"))
	{
		tell_room(__FILE__,"只听喀啦喀啦几声巨响铁闸自动关闭了。\n");
		delete("exits/up");
	}

	if(!room)
		room = load_object(__DIR__"moon29");

	if(room && room->query("exits/down"))
	{
		room->delete("exits/down");
		tell_room(room,"只听喀啦喀啦几声巨响铁闸缓缓地关闭了。\n");
	}

}
