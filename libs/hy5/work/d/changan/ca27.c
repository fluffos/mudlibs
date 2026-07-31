// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "山路");
    set("long", @LONG
一眼往去，前面一片辽阔，长满了各种杂草，似乎暗藏杀机。
LONG
);
        set("outdoors","changan");
    set("exits", ([
       "westup":__DIR__"ca26",
       "east":__DIR__"boshulin1",
]));
    setup();
    replace_program(ROOM);
}
