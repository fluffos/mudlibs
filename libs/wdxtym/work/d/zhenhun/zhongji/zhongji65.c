 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji64",
	"north" : __DIR__"zhongji66",
	"east" : __DIR__"zhongji80",
	"west" : __DIR__"zhongji62",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	"/d/zhenhun/npc/qiutu2b" : 1 + random(3),
	]));
	setup();
}