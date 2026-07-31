//Room: xiaojia-qianyuan.c

inherit ROOM;
void create ()
{
	set ("short", "萧家前院");
	set ("long", @LONG
没想好呢!呵呵!
LONG);
	set("exits", 
	([ //sizeof() == 2
		"west" : __DIR__"liande-dadao5",
		"east" : __DIR__"xiaojiadt",
	]));
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/guanjia" : 1,
	]));

	set("outdoors", "changan");
	setup();
}
