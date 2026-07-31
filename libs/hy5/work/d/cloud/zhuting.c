
// Room: /u/cloud/zhuting.c

inherit ROOM;

void create()
{
	set("short", "竹亭");
	set("long",
"这是一个竹亭,显然已经建了很久了,显得有些破旧。为了去上香的信徒和游客的方便，就有\n"
"善人捐建了这个亭子，供路人歇歇脚。亭子里正有人在休息呢，还有几个小贩子。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shijie3",
]));
	set("objects", ([
                __DIR__"npc/tea_vendor": 1,
	]) );
        set("outdoors", "cloud");

	setup();
	replace_program(ROOM);
}
