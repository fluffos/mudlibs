// This is a room made by roommaker.
// Rewrote by iszt@pkuxkx, 2007-02-11
// Modified by zhx, 2009.8.25

inherit ROOM;

void create()
{
    set("short", "小广场");
    set("long", @LONG
这里是片空地，到处是熙熙攘攘的武林人物。东面是一间小酒屋，
西边是一个小小的土地庙，早已破败不堪，南北各是一条小路。
LONG);
    set("exits", ([
        "east"  : __DIR__"jiudian",
        "west"  : __DIR__"tudimiao",
        "south" : __DIR__"xuedi6",
        "north" : __DIR__"xuedi4",
    ]));

    setup();
    replace_program(ROOM);
}
