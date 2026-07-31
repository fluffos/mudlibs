 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji34",
	"north" : __DIR__"zhongji32",
	"east" : __DIR__"zhongji22",
	"west" : __DIR__"zhongji40",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}