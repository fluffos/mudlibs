#include <room.h>
inherit ROOM;


void create()
{
        set("short", "小山村");
        set("long", @LONG
山村地处群山间的谷地平原，方圆几里大的平地上到处都是水田，种着大米
和其他作物。林子边有一片房舍，大多是用竹子搭起的小楼，屋底用巨竹支在半
空，以防毒蛇毒虫进去。
    西边的林子非常茂密。北边远山渐高，似乎有一条路通入山谷之中。
LONG
        );
        set("exits", ([
                "west"     : __DIR__"milin3",
                "northup"      : __DIR__"shandao0",
        ]));
        set("outdoors","xinan");
        setup();
}
