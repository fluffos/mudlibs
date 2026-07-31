// xiaowu3.c 孙婆婆小屋
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "小屋");
        set("long", @LONG
这里是远离正厅的一间小屋，收拾得整整洁洁一尘不染。摆设就
如普通人家一般，红木的桌椅，细磁的杯壶，沉香的大床。你简直想
象不到这幽深的古墓之中还有这等摆设。
LONG
        );

        set("exits", ([
                "west" : __DIR__"xiaowu2",
        ]));

        set("objects", ([
                __DIR__"npc/sun" : 1,
                __DIR__"obj/ping" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
