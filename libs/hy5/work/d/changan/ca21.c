// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "驿道");
    set("long",@LONG
一条青石铺就的驿道向北延伸，道旁种满了树木。往南就是长安
城了。
LONG
);
        set("outdoors","changan");
    set("exits", ([
       "south":__DIR__"ca9",
       "north":__DIR__"ca28",
       "eastup":__DIR__"ca24",
       "west":__DIR__"ca22",
]));
    setup();
    replace_program(ROOM);
}
