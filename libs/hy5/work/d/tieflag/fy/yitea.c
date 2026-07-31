 inherit ROOM;
void create()
{
        set("short", "一品居");
        set("long", @LONG
卖的是各地的名茶，冲茶的水是从枫叶泉专程汲来，冲茶的壶是名贵的紫砂壶，
冲茶的方法也是最讲究的：每壶茶的第一杯是用来养壶的。所以这里冲出的茶都有
一种纯厚的香气。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"swind3",
  "up" :   __DIR__"yitea2",
]));
        set("objects", ([
        __DIR__"npc/teawaiter" : 1,
                        ]) ); 
        set("coor/x",10);
        set("coor/y",-30);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
