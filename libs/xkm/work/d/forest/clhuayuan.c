//Cracked by Roath
// changle/clhuayuan.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "花园");
        set("long", @LONG
这个花园是典型的江南风格，精巧细致。园中花卉虽没有什么名贵
品种，也是争奇斗妍。正中一条石子铺就的小路，上面遍布青苔，甚是
湿滑。向东是一条甬道。
LONG );

        set("exits", ([
		"south" : __DIR__"clbajiaoting",
		"west" : __DIR__"clzoulang2",
		"east" :  __DIR__"clyongdao",
                "north" :  __DIR__"dating2",
        ]));

        set("cost", 0);

        setup();

//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
           if( !wizardp(me)&&dir=="north" && me->query_temp("bangs/pos")!= "龙灵堂" &&me->query_temp("bangs/pos")!="狮敏堂" &&me->query_temp("bangs/pos") !="熊威堂" &&
              me->query_temp("bangs/pos") !="豹捷堂" && me->query_temp("bangs/pos")!="虎啸堂" && me->query_temp("bangs/pos") !="凤翼堂") 
                   return notify_fail("那里只有香主才能进去。\n");
           return ::valid_leave(me, dir);
}
