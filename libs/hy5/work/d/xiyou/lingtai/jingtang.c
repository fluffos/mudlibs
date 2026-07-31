// Room: some place in 西牛贺洲
// jingtang.c

inherit ROOM;

void create ()
{
        set ("short", "讲经堂");
        set ("long", @LONG

这里是三星洞的讲经堂，平时道士们便在这里讲经说法。若是
有什么大事，也在这里集会商议。左右整整齐齐地放着四五十
个软垫，也坐了一二十个道士。
LONG);

        set("exits", ([ /* sizeof() == 4 */
                "north" : __DIR__"houlang1.c",
                "southdown" : __DIR__"inside1.c",
                "east" : __DIR__"siyuan.c",
        ]));
        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/xiao" : 2,
        ]));
        setup();
}

