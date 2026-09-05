
// Room: longmf.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "龙门峰");
	set("long", @LONG
此峰为长白主峰之一，在乘槎河两岸，与天壑峰相对，因形状如门，故
名龙门。所传，大禹治水时曾到过这里，旁边有蝌蚪行石柱，名为神碑。由
此看乘槎河犹如一把银色的利剑，直插崇山峻岭之间。据说在这周围的杂草
之中就生长着人参，不知道搜索一下能否有所发现。
LONG	);
	set("exits", ([
              "westdown" : __DIR__"tianchi",
              "northwest" : __DIR__"baiyf",
              "northeast" : __DIR__"damen",
              "southwest" : __DIR__"tiyf",
              "east" : __DIR__"tianhuo",
        ]));

        set("outdoors", "changbai");

        set("count", random(3) + 1);
        set("beast", random(5) + 1);

	setup();
}
