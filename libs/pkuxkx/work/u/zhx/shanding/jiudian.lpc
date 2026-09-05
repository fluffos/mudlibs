// Room: /xiaocun2/jiudian.c
// zhx 2006/12/27
// Rewrote by iszt@pkuxkx, 2007-02-11
// Modified by zhx, 2009.8.25

inherit ROOM;

void create()
{
    set("short", "酒店");
    set("long", @LONG
这是一个神秘的酒店，就连这里的老板都透着几分神秘。这里坐满了客人，
每人都看起来身手不凡，还是赶紧打尖走人为妙。
LONG
    );
    set("exits", ([
        "west" : __DIR__"guangchang",
    ]));
    set("objects", ([
        __DIR__"npc/xiaoer": 1,
    ]));
    setup();
    replace_program(ROOM);
}
