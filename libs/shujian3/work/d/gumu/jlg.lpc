// Room: /u/xdd/gumu/jlg.c
// Modify By River 98/08
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"金莲阁"NOR);
        set("long", @LONG
金莲阁是全真教为武林人士和进香香客准备茶水和膳食的地方，可供登山
者稍作休憩。此阁建于北宋初年，由于近年全真的鼎盛香火，已修茸一新，阁
心一朵七彩金莲，卓然生辉。
LONG);

        set("outdoors","古墓");

        set("exits", ([
                "northup" : __DIR__"ztm",
                "southup" : __DIR__"ryy",
        ]));

        set("objects", ([
                __DIR__"qqll/mayu" : 1,
        ]));
        set("coor/x",0);
        set("coor/y",-20);
        set("coor/z",30);
//        set("objects", ([
//                "/d/gumu/npc/mayu" : 1,
//        ]));
        setup();
}
