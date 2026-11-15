// Room: /d/xiangyang/huafang.c  花房
// Date: Jan. 28 2002 by Pound

inherit ROOM;


void create()
{
	set("short", "花房");
	set("long", @LONG
这是培植花草的花房，种着各种各样的花草。花草虽美，香味虽浓，
但慑于药王的威名，令人始终不敢乱动。靠窗口的桌子上放着几个花盆，
看上去有几个花盆还没播种，正好可以用来种花（zhonghua）。
LONG );

	set("exits", ([
	    "north" : __DIR__"maoshe",
	]));

	set("objects", ([
	    __DIR__"obj/tihuxiang" : 1,
	    __DIR__"obj/shuitong"  : 1,
	]));

	setup();
//      //replace_program(ROOM);
}
void init()
{
	object me, ob;
	me = this_player();

	if (! objectp(ob = present("qixin haitang", me)) && me->query("yaowang/qxht/have"))
	    me->delete("yaowang/qxht");
	if (! objectp(ob = present("haitang candle", me)) && me->query("yaowang/candle/using"))
	    me->delete("yaowang/candle");
}