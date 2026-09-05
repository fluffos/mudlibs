//ROM guangchang.c
#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "广场");
        set("long",
             "这里是一块不小的广场，广场上堆着农家晒的谷物。往北方就是\n"
         GRN"白驼山庄"NOR"了。广场的东面有间小农舍，西边有一块不小的菜地，东南\n"
         "方是一座小竹桥。\n"
        );
        set("outdoors", "baituo");
        set("exits", ([
                "east" : __DIR__"nongshe",
                "west" : __DIR__"caidi",
                "northup" : __DIR__"shijie",
                "northwest" : __DIR__"shanlu",
                "southeast" : __DIR__"bridge",
        ]));
        set("objects",([
                __DIR__"npc/kid" : 2,
        ]));
        setup();
        replace_program(ROOM);
}
