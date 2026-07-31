// Room: /d/paiyun/ting.c

inherit ROOM;

void create()
{
	set("short", "松岗亭");
	set("long", @LONG
这是一处探出石台的小亭子，亭子外面是万丈悬崖，白云在
脚下流动，没想到土匪窝里还有这么一处好景致。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lu6",
]));
        set("objects", ([
                "/kungfu/class/taohua/lu2" : 1,
        ]));
	set("outdoors", "paiyun");

	setup();
	replace_program(ROOM);
}
