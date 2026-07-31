#include <room.h>
inherit ROOM;


void create()
{
        set("short", "大渡河边");
        set("long", @LONG
这里已经是川蜀平原的边缘，西边是直插云霄的高大山脉，山顶上多是终年
白雪皑皑，人迹罕至；南面是一望无际的崇山峻岭，密林蔽日，山高谷幽；大渡
河从西面雪山之中流出，至此与岷江汇合再向东流去。往南越过瘟疫横行的大森
林就是大理国境了。
LONG
        );
        set("exits", ([
                "southwest"     : __DIR__"shanlu11",
                "northeast"     : __DIR__"leshan",
        ]));
        setup();
        set("outdoors","xinan");
}

