 

inherit ROOM;

void create()
{
	set("short", "高级区");
	set("long", @LONG
高级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"gaoji64",
	"north" : __DIR__"gaoji66",
	"east" : __DIR__"gaoji80",
	"west" : __DIR__"gaoji62",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu3" : 3,
	"/d/zhenhun/npc/qiutu3b" : 1 + random(3),
	]));
	setup();
}