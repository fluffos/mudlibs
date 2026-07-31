//Cracked by Roath

//fear 2002 1 31

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
这是一条断断续续的碎石小路，两旁长满了各式各样的杂草。往西南
边望去似乎有一个小山壁。南边可以通向海岸，东边则是一条山路。
LONG
        );
        set("exits", ([
                "southwest" : __DIR__"cave1",
				 "east" : __DIR__"shanlu",
				 "south" : __DIR__"haian",
        ]));

	set("outdoors", "lingshedao");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

