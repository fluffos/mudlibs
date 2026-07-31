// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "小巷");
    set("long",@LONG
一条用青砖埔成的小巷，和外面比起来，这里显得安静了许多。
从这里往南，是一片墓志林立的碑林。
LONG
);
        set("outdoors","changan");
    set("exits", ([
       "north":__DIR__"ca18",
       "south":__DIR__"ca16",
]));
    setup();
    replace_program(ROOM);
}
