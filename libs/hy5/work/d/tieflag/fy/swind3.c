#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "南风大街");
        set("long", @LONG
一个闪亮的银钩挂在大街西面一座巨宅的飞檐下，将日光折射开来，洒向整条
街，就象在汉白玉的路面上铺上了一层银粉，闪闪发光，这就是风云城中最豪华的
银钩赌坊。银钩赌坊的对面是一品居茶座。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"swind4",
  "north" : __DIR__"swind2",
  "east" : __DIR__"yitea",
  "west" : "/d/tieflag/yingou/yingou",
]));  
    set("outdoors", "fengyun");
    set("coor/x",0);
        set("coor/y",-30);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
