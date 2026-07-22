// Room: /d/quanzhou/zahuopu.c
// Date: May 7, 96   Jay
inherit ROOM;
void create()
{
    set("short", "杂货铺");
    set("long", @LONG
这里是一家专卖女人用的东西的小铺子。
LONG
    );
    set("exits", ([
                "east" : __DIR__"xijie",
             "enter" : "/job/merchant/chaomai/xz_shop",
    ]));
    set("objects", ([
                 __DIR__"npc/chen" : 1,
    ]) );
    set("outdoors", "quanzhou");
    setup();
    replace_program(ROOM);
}
