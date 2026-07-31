// 楚州胯下桥 /d/city/chuzhou/kuaxiaqiao.c
// by lala, 1997-12-03

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", WHT"胯下桥"NOR);
    set("long", @LONG
胯下桥位于镇淮楼以南，当汉初三杰之一的韩信少时，一屠户恶少欺凌他，
叫他从跨下钻过，不然就一决雌雄，韩信忍辱负重，“熟视良久，俯出胯下”，
后人为纪念他的大将风度，特在当年的这个地方立“胯下桥”的牌坊。
    这里东面是东市，南面是南市，过往的行人很多，人声鼎沸。
LONG
    );
    set("outdoors", "yangzhou");
    set("no_kill",  "yangzhou");
    set("exits", ([
        "south"     : __DIR__"nanshi",
        "east"      : __DIR__"dongshi",
    ]));
    set("objects", ([
    ]));
    setup();
}
