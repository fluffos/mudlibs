#include <room.h>
inherit ROOM;


void create()
{
        set("short", "山谷");
        set("long", @LONG
山谷中流着潺潺的溪水。踏着碎石，沿着谷底逆水而上，一路上野花芬芳，
空气清新，令人心旷神怡。两边都是岩石山崖，缝隙中生长着一株株小树，岩顶
上大树遮天蔽日，挡住了阳光。
    北面下山去，是一片开阔的平原，是大理国的统治中心。
LONG
        );
        set("exits", ([
                "south"     : __DIR__"jiangbian",
                "northdown"  : __DIR__"bazi1",
        ]));
//        set("item_desc", ([
//                "down":  "大江南流的波涛巨响震得脚下的大地都颤动起来。\n",
//        ]));
        setup();
}
