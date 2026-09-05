// x_chuan.c 小船
// cgbii 96.10.3

inherit ROOM;

void create()
{
        set("short", "乌篷船");
        set("long", @LONG
这是一艘很小的乌篷船，细小的船身令人怀疑它能不能抵挡的
住风浪，向东去可以离开码头出到大海了。
LONG
        );

        set("exits", ([
                "out" : __DIR__"matou",
                "east" : __DIR__"dahai_1",
        ]));

     
        set("outdoors", "quanzhou");
        setup();
        replace_program(ROOM);
}
