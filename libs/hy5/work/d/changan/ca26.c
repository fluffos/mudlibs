// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "山路");
    set("long",@LONG
这是一条下山的小路。
LONG
);
        set("outdoors","changan");
    set("exits", ([
       "westup":__DIR__"ca25",
       "eastdown":__DIR__"ca27",
]));
    setup();
    replace_program(ROOM);
}
