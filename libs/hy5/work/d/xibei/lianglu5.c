//lianglu5.c

inherit ROOM;

void create()
{
        set("short", "沙砾路");
        set("long", @LONG
你已经进入著名的河西走廊，向东越过乌鞘岭就是通往兰州的官道，你将进入中原
在西南你能看见祁连山巍峨的群山,山峰映在蔚蓝的天空下，你感到胸怀为之一宽。虽然
这里被称为走廊，但实际上是一片非常宽阔的平原，祁连山雪蜂的积雪融化后流入这片
土地，灌溉了这里的万顷良田。
LONG
        );
        set("exits", ([ 
                "southeast"     :       __DIR__ "wuqiao",            
                "northwest"     :       __DIR__ "lianglu6",
                ])
        );
//      replace_program(ROOM);
        setup();
}

