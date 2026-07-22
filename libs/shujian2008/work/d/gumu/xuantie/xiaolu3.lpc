// By River@sj 99.5.24
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", YEL"山路"NOR);
    set("long", @LONG
这里是瀑布西面的一条崎岖的山路，路面上夹杂着一些泥沙。齐膝的野草
几乎把路给掩盖了，开出来的野花飘着阵阵花香。四周不时传来一阵阵的野兽
叫声, 头顶有一些不知名的小鸟在跳来跳去。
LONG
    );

    set("outdoors", "襄阳");

    set("exits", ([
        "east" : __DIR__"pubu",
        "northwest" : __DIR__"dongkou",
        "southdown" : __DIR__"xiaolu2",
    ]));

    setup();
}
