// Room: /d/city/dongdajie1.c

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
你走在东大街上，踩着坚实的青石板地面。东边是打铁铺和武器店，不时
传来敲敲打打的金属撞击声，与西边朗朗的读书声混杂在一起。北边是一家老
字号的药铺，南边是家寄卖店。
LONG
	);
        set("outdoors", "扬州");
	set("objects", ([
		__DIR__"npc/suanming": 1,
	]) );

	set("exits", ([
		"east" : __DIR__"dongdajie0",
		"south" : "/d/zhiye/jimaidian1",
		"west" : __DIR__"dongdajie2",
		"north" : __DIR__"yaopu",
        	"southeast" : __DIR__"yltw",
	]));

	set("incity",1);
	setup();
}

