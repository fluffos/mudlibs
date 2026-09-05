// Room: /d/taishan/fefe5.c
// Date: ERIC 96/9/23

inherit ROOM;

void create()
{
	set("short", "茅屋");
	set("long", @LONG
这里是茅屋的大厅，摆设一般，墙上有一幅女子的画像，画中人
花容月貌，亭亭玉立，惊若天人。旁边有一所茅厕(maoce)，可以进
去(enter)解决问题。
LONG
	);

	set("objects",([
		__DIR__"npc/fefeman" : 1,
	]));

	set("exits", ([
		"north" : __DIR__"fefe2",
		"east" : __DIR__"fefe6",
		"south" : __DIR__"fefe8",
		"west" : __DIR__"fefe4",
	]));

	setup();
}

void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="maoce" ) 
	{
		message("vision",
			me->name() + "一掀布帘进了茅厕，布帘还没有完全落下，已经传出来哗哗的声音。\n",
			environment(me), ({me}) );
                me->move("/d/taishan/fefe_maoce");
                message("vision",
			me->name() + "急急忙忙地从外面走了进来，把裤带解开，……\n",
                	environment(me), ({me}) );
		return 1;
	}

}	

