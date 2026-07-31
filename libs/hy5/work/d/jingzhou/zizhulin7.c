// Room: zizhulin
// congw 980829
inherit ROOM;

void create()
{
	set("short", "紫竹林");
	set("long", @LONG
你眼前突然一遍光明，你来到了一座有许多紫竹搭成的花园（xiaoyuan）
面前，里面飘出阵阵花香，四周紫竹环抱，说不出的诗情画意。隐约看到里面
种有些花卉。
LONG
	);
        set("outdoors", "jingzhou");

	set("exits", ([
	"north" : __DIR__"zizhulin6",
	"enter" : __DIR__"xiaoyuan",
	]));
        set("item_desc", ([
                "xiaoyuan": "看来是一处种花的好地方，隐约可以看到里面种有许许多多的花卉，由许多的紫竹搭建而成\n"
        ]) );


	setup();
	replace_program(ROOM);
}

