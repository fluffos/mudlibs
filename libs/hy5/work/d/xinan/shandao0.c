#include <room.h>
inherit ROOM;


void create()
{
        set("short", "山道");
        set("long", @LONG
大理国境内多山，全境十成倒有九成多是山林，长期人兽踏出的小道两边都
是华盖一般的参天大树，还有同样高大的古藤。地上的土红红的，潮湿的很，踏
上去象能汪出水来；一群群蚊虫在你耳边飞舞，“嗡嗡”的声音吵得你心烦。
    南边出山有一块平地，几幢小屋依林而建。
LONG
        );
        set("exits", ([
                "southdown"     : __DIR__"xiao_shancun",
                "northup"      : __DIR__"baicao_ling1",
        ]));
        set("outdoors","xinan");
        setup();
}
