inherit ROOM;

void create()
{
        set("short", "柴院");
        set("long", @LONG     
这里是五毒教的柴院，地方不大，略显凌乱，东面的墙角边堆满了劈
好的柴火，院子中央是个老大的树桩，上面插着几把大斧头。西面是厨房
的侧门，南边是一排栅栏，栅栏外面就是密密的柴林，紧贴着栅栏是一堆
尚未劈好的树桩，平时常有五毒在弟子这里劈柴．
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                 "west" : "/d/wudujiao/chufang", 
]));        

        setup();
        replace_program(ROOM);
}
