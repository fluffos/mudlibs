inherit ROOM;
void create()
{
	set("short", "东大街");
	set("long", @LONG
你走在东大街上，踩着坚实的青石板地面。东边是东大街的延伸，南面是
苏州城里一个老字号的当铺，北面是一条小胡同，西北方向是沧浪亭，西南方
向是宝带桥。
LONG
	);
        set("outdoors", "苏州");
        set("objects",([
		NPC_D("youke") : 2,
        ]));
	set("exits", ([
		"east" : __DIR__"dongdajie2",
		"southwest" : __DIR__"baodaiqiao",
		"northwest" : __DIR__"canglangting",
		"north" : __DIR__"hutong",
		"south" : __DIR__"baoheji",
	]));
	set("incity",1);
	setup();
}

