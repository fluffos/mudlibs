// Room: /d/snow/lane1.c
inherit ROOM;
void create()
{
        set("short", "僻静小巷");
        set("long", @LONG
这里是条僻静小巷的转角处，小巷往北可以通往溪边，从这里
就可以听到溪流潺潺的声音，东边是一栋破旧的大宅院，门口的一
的破匾写著「长乐侯府」，不过里面已经是断垣残璧了，小巷南边
有一座小土地庙。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                "east" : __DIR__"ruin1",
                "west" : __DIR__"epath",
                "north" : __DIR__"lane2",
]));
//        set("objects", ([ /* sizeof() == 1 */
//                "/d/daomeng/npc/daotong" : 1,
//                "/d/daomeng/npc/daoke" : 1,
//        ]));
        set("outdoors", "xueting");
        setup();
        replace_program(ROOM);
}
