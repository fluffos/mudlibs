// /d/emei/liba.c 峨嵋派 篱笆
// create by host dec,20 1997
inherit ROOM;

void create()
{
	set("short", "篱笆");
	set("long", @LONG
这里是桃林深处，在你面前有一栏低矮竹篱笆挡住了去路，在正中有
扇竹门半开着(men)。在竹篱后面有一座小茅草屋。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([ 
		"south" : __DIR__"maocaowu",
                "north" : __DIR__"taolin", 
		]));
	set("objects", ([ 
	]));

	setup();
	replace_program(ROOM);
}
