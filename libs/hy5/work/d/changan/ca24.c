// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "山路");
    set("long", @LONG
这里是一条上山的小路向西分出一条岔道。北边是
LONG
);
        set("outdoors","changan");
    set("exits", ([
       "westdown":__DIR__"ca21",
       "northup":__DIR__"ca25",
]));
    setup();
    replace_program(ROOM);
}
