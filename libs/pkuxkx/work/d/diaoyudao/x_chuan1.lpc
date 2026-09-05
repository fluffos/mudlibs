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
                "out" : __DIR__"matou1",
                "east" : __DIR__"dahai_1",
        ]));

     
        set("outdoors", "quanzhou");
        setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "out") me->delete_temp("航1");
	return ::valid_leave(me, dir);
}