// Write By Yanyang@SJ 2001.9.26
// Room: /d/changan/wanhonglou.c

inherit ROOM;

void create()
{
        set("short", "万红楼");
        set("long", @LONG
万红楼是长安城首屈一指的大妓院。这里不是普通人能来的地方，如果你
没有腰缠万贯，根本别想进这个门。楼中雇的打手个个高大威猛，没钱没势的
见了这场面早就绕了开去。
LONG
        );
	set("exits", ([
		"south" : __DIR__"eastjie1",
	]));
	set("objects", ([
                __DIR__"npc/guinu" : 1,
                __DIR__"npc/xuexianer" : 1,
                __DIR__"npc/dashou" : 1,
                __DIR__"npc/piaoke" : 1,
                __DIR__"npc/gongzi" : 1,
        ]));
	set("incity",1);
	setup();
}