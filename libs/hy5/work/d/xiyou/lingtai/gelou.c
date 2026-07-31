// Room: some place in 西牛贺洲
// gelou.c

inherit ROOM;

void create()
{
        set ("short", "阁楼");
        set ("long", @LONG

这里是经阁的阁楼，内设十分简朴，一张木桌，两张藤椅
南墙下一张檀木床罗帐轻垂，木桌上摆放着一些道家典籍
LONG);
        set("exits", ([ /* sizeof() == 4 */
                "down": __DIR__"lou",
        ]));
        set("objects", ([
                __DIR__"npc/sanxing": 1 ]) );

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

