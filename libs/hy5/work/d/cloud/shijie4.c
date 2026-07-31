
// Room: /u/cloud/shijie4.c

inherit ROOM;

void create()
{
        set("coor",({4100,-950,0}));
	set("short", "石阶");
        set("long",
"走了大半天,终于看到了这条青石板路的尽头!还不快些走啊?!\n"
"可还有一段路噢!\n"
);
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"shijie5",
  "south" : __DIR__"shijie3",
]));
        set("outdoors", "cloud");
        setup();
        replace_program(ROOM);
}

