// Room: /d/shaolin/muwu.c

inherit ROOM;

void create()
{
    set("short", "大帐");
    set("long", @LONG
这是抗倭英雄戚继光的大帐，帐内戚继光和几个将军在
商讨抗倭大计。
LONG
    );

    set("no_clean_up", 0);

    set("exits",([
    "north" : "/d/quanzhou2/haigang",
]));
    set("objects", ([
        __DIR__"npc/qijiguang" : 1,
        __DIR__"npc/qjiang" : 4,
        ]));

    setup();
    replace_program(ROOM);
}
