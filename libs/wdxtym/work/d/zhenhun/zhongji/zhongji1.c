 

inherit ROOM;

void create()
{
	set("short", "中级区");
	set("long", @LONG
中级区
LONG
	);
	set("exits", ([
	"south" : __DIR__"zhongji",
	"north" : __DIR__"zhongji4",
	"east" : __DIR__"zhongji2",
	"west" : __DIR__"zhongji3",
	]));
	set("objects", ([
	"/d/zhenhun/npc/qiutu2" : 3,
	]));
	setup();
}