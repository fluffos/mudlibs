// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "驿站");
    set("long",@LONG
这里是长安驿站。由于各个城市进出长安的物资传送都要通过这里，
因此驿站里人群进进出出，一片忙碌的景象。站前竖着一溜石桩，绑着
一些驿马和大车，几个车夫正在四处招揽生意。
LONG
);
    set("exits", ([
       "east":__DIR__"ca21",
]));
    setup();
    replace_program(ROOM);
}
