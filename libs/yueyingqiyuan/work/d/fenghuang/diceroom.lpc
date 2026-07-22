inherit ROOM;

void create()
{
        set("short", "凤凰游乐场");
        set("long", @LONG
这里是玩骰子猜大小的房间..要在游乐场内玩必须要有筹码喔...
这里有一位服务亲切的小姐喔...
LONG
        );
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/xdice" : 1,
        ]));

        set("exits", ([
                "up": __DIR__"raceroom",
                "down": __DIR__"playroom",
            ]));

        set("light", 1);
        setup();
        replace_program(ROOM);
}

