//by zhx

inherit ROOM;

void create()
{
    set("short", "哨卡");
    set("long", @LONG
这是一个哨卡，有几个大宋兵丁在一个将军的带领下在
此站岗，严防倭寇的侵犯。
LONG
    );

    set("outdoors", "xiaodao");
    set("no_clean_up", 0);

    set("exits",([
    "south" : __DIR__"shanlu14",
]));
    set("objects", ([
        __DIR__"npc/qbing" : 4,
        __DIR__"npc/qjiang1" : 1,
        ]));

    setup();
    replace_program(ROOM);
}
