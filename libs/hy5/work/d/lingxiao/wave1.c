//LUCAS 2000-6-18
// Room: wave1.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","冰洞");
        set("long",@LONG 
这是一个巨大的天然冰洞。做梦也没想到，这温泉水潭下，
竟然有这样一个天造地设的洞天福地。站在这里，仿佛置身于水
晶宝库一般，四周全是晶莹剔透的冰块，四面八方都是自己的倒
影，清可鉴发。
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "up"  : __DIR__"water", 
            "west" : __DIR__"wave2", 
        ]));
        if(random(6)>3)
        set("objects", ([
                "/quest/skills2/wakuang/kuang/kuangmai" : 3,
        ])); 
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}