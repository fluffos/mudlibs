// /d/jiaxing/dating.c 大厅
// by shang 97/6

inherit ROOM;

void create()
{
        set("short", "大厅");
	set("long", @LONG
厅内古色古香, 案上放着许多古董。墙壁上挂满了字画。
然墙上一空处有九个血手印, 庄主陆立鼎坐在椅中，望著血
手印呆呆出神。
LONG
	);

	set("exits", ([
                "south" : __DIR__"yuan",
                "out" : __DIR__"tianjing",
	]));

        set("objects", ([
                 __DIR__"npc/lu-liding" : 1,
        ]));
	setup();
	replace_program(ROOM);
}

