// Room: /d/xiangyang/jiekou2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "大街口");
	set("long", @LONG
因为这儿是十字街口，所以非常热闹。小商小贩们在向行人吆喝着，
兜售他们的商品。虽然襄阳饱受蒙古军侵扰，但这儿看不出人们有丝毫的
紧张，好象他们已司空见惯、习以为常了。北面和东面是小弄，许多襄阳
城的老百姓住在里面，南面和西面是青石铺就的大街。
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east"  : __DIR__"xiaorong1",
		"south" : __DIR__"eastroad2",
		"west"  : __DIR__"northroad2",
		"north" : __DIR__"xiaorong2",
	]));
	set("objects", ([
		__DIR__"npc/kid" : 1,
		"/d/village/npc/seller" : 1,
            "/clone/npc/walker" : 1,
	]));
	setup();
	replace_program(ROOM);
}

