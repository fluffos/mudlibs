// Room: /d/huanggong/dafotang.c

inherit ROOM;

void create()
{
	set("short", "大佛堂");
	set("long", @LONG
这是慈宁宫后的大佛堂。堂里供着一尊如来佛像，佛像前是一张供
桌。桌上点着盏油灯。佛像后好像有一窗暗门。
LONG );
	set("exits", ([
  		"south" : __DIR__"cininggong",
	]));
	set("objects", ([
  		__DIR__"npc/maodongzhu": 1,
  		__DIR__"npc/liuyan": 1,
	]));
	set("coor/x", -220);
	set("coor/y", 5272);
	set("coor/z", 0);
	setup();
	//replace_program(ROOM);
}

void init()
{
	add_action("do_open", "open");
	add_action("do_open", "unlock");
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"neishi")) )
		room = load_object(__DIR__"neishi");
	if(objectp(room))
	{
		delete("exits/north");
		message("vision","只听乒地一声，暗门自动关了起来。\n", this_object());

	}
}

int do_open(string arg)
{
	object room,ob;

	if (query("exits/north"))
		return notify_fail("暗门已经是开着了。\n");

	if (!arg || (arg != "door" && arg != "south"))
		return notify_fail("你要开什么？\n");

	if (!(ob = present("hg key", this_player())))
		return notify_fail("你不会撬锁。\n");

	if(!( room = find_object(__DIR__"neishi")) )
		room = load_object(__DIR__"neishi");
       if(ob) destruct(ob);
	if(objectp(room))
	{
		set("exits/north", __DIR__"neishi");
		message_vision("$N使劲把暗门打了开来。\n",this_player());
		message("vision","里面有人把暗门打开了。\n",room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}
int valid_leave(object me, string dir)
{
	if ( objectp(present("mao dongzhu", environment(me))) && 
		dir == "north")
		return notify_fail("毛东珠拦住了你的去路。\n");

	if ( objectp(present("liu yan", environment(me))) && 
		dir == "north")
		return notify_fail("柳燕拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}