// Room: /d/xueting/wstreet2.c

inherit ROOM;

void create()
{
	set("short", "雪亭街道");
	set("long", @LONG
这里是雪亭镇西边的街道，北边是雪亭镇的乡校。平时常常会
有一些镇上的长者在这里谈论镇上的时事，县里若有公爷来这里断
事，也是在这里设的公堂。从这里往西不远处就是出镇的官道，街
道南边是一家糕饼铺。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : __DIR__"court",
	//"west" : "/d/snow/sroad3",
	"east" : __DIR__"wstreet1",
]));
	set("objects", ([ /* sizeof() == 1 */
	//"/d/snow/npc/farmer" : 2,
	__DIR__"npc/dog":2,
	]));
	set("no_clean_up", 0);
	set("outdoors","xueting");
	setup();
	replace_program(ROOM);
}
