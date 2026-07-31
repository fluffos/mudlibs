 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "寒潭");
        set("long", @LONG
潭面成不规则状，深绿色的潭水看不到底，潭边寒气刺骨，一缕缕雾气从水面
升起，潭上笼罩着一层薄薄的白色雾气。潭边的石头滑不留人，石缝中长着一些不
知名的植物。
LONG
        );
        set("exits", ([ 
                "down" : __DIR__"jiulong",
        ]));
    set("outdoors", "huangshan");
    set("coor/x",-560);
    set("coor/y",-470);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}  
