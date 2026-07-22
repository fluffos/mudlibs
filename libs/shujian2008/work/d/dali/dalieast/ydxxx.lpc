// Room: /d/dali/ydxxx.c
// bbb 1997/06/10 
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "观景楼");
	set("long", @LONG
观景楼依石壁而造，如西蜀栈道，奇巧、艰险。观景楼，曾几经修葺。新
修后的观景楼，朱檐瓦，画栋雕梁，画幅多以动物花草以及历史故事为题村，
采用写意笔法，寥寥数笔，就勾勒出一个栩栩如生的形象。楼台之中设有茶室、
小卖部，游人可一面在此静坐休息，一面观赏周围风光。
LONG
	);
        set("outdoors", "大理");

	set("objects", ([
		NPC_D("tiao-fu") : 1,
	]));

	set("exits", ([
		"west" : __DIR__"ydxx",
		"east" : __DIR__"ydxxxx",
	]));

	setup();
}
