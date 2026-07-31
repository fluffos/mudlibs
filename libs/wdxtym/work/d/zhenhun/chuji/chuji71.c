 

inherit ROOM;

void create()
{
	set("short", "初级区");
	set("long", @LONG
初级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"chuji70",
	"north" : __DIR__"chuji72",
	"east" : __DIR__"chuji74",
	"west" : __DIR__"chuji56",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu1" : 3,
	"/d/zhenhun/npc/qiutu1b" : 1 + random(3),
	]));
	setup();
}