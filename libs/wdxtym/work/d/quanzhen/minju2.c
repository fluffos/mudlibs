// minju2.c 民居
// By Lgg,1998.10

inherit ROOM;

void create()
{
	set("short", "神器坊");
	set("long", @LONG
不知是何时出现在武功镇上的一幢房子，来源不清，但是镇上的人都闭口不谈，听闻传说，江湖上有一怪人，能为
神器附加属性，但是要付出心头血，难道。。。。。。
LONG
	);
	set("exits", ([
		"south" : __DIR__"xijie",
	]));

	set("objects", ([
		__DIR__"npc/tiejiang" : 1,
	]));
	set("no_clean_up", 0);
	setup();
}
