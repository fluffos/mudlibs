// Room: shijie.c
// congw 980829
inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这里是一排石阶，往北是萧湘书院，往南是一片翠绿的竹林。
LONG
	);
        set("outdoors", "jingzhou");

	set("exits", ([
	"southdown" : __DIR__"zizhulin",
	"north" : __DIR__"shuyuan1",
	]));
	setup();
	replace_program(ROOM);
}

