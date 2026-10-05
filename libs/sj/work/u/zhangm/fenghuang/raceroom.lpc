// Room: raceroom.c
inherit ROOM;
void create()
{
        set("short", "凤凰游乐场");
        set("long", @LONG
这里玩的游戏是猜谁是赛跑的冠军...要在游乐场内玩必须要有筹码喔...
这里有一位服务亲切的小姐喔...
LONG
        );
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/xrace" : 1,
        ]));
        set("exits", ([
                "up": __DIR__"mjroom",
                "down": __DIR__"diceroom",
            ]));
        set("light", 1);
        setup();
        replace_program(ROOM);
}

