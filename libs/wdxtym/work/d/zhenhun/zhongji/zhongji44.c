 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji43",
	"north" : __DIR__"zhongji45",
	"east" : __DIR__"zhongji29",
	"west" : __DIR__"zhongji47"
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	"/d/zhenhun/npc/qiutu2b" : 1 + random(3),
	]));
	setup();
}