
// Room: /u/cloud/shijie5.c


inherit ROOM;

void create()
{
        set("coor",({4100,-900,0}));
	set("short", "石阶");
        set("long",
"终于走到了青石板路的尽头了,。\n"
);
        set("outdoors", "cloud");
        set("exits", ([ /* sizeof() == 3 */
"north" : __DIR__"shillfoot",
  "south" : __DIR__"shijie4",
]));
        setup();
//        replace_program(ROOM);
}
