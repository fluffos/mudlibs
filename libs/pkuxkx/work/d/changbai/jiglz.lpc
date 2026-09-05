
// Room: jiglz.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "鸡冠砬子");
	set("long", @LONG
这里是一片连绵起伏的山岭，远看犹如鸡冠子一样。这里已经接近顶峰
了。纵目向下望去，白色的山岭错落有秩，乘槎河象一条银色的玉带，穿行
于其中。这里的风势更大了，吹得人站不住身子。据说在这周围的杂草之中
就生长着人参，不知道搜索一下能否有所发现。
LONG	);
	set("exits", ([
              "westdown" : __DIR__"tieby",
              "eastup" : __DIR__"lumf",
        ]));

	set("objects", ([
            "/d/changbai/npc/yan" : 1
	]));
        set("outdoors", "changbai");

        set("count", random(3) + 1);
        set("beast", random(5) + 1);

	setup();
}
