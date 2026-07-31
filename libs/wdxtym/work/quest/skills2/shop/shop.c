// zhujia.c 铸甲房
// 星星lywin 2000/9/2 

#include <ansi.h>
inherit ROOM;

 void create()
{
        set("short", "圣兵器铺");
        set("long", @LONG
这里是全国最好的兵器铺,里面的兵器全是一流的,品种又全。
不过这里的武器全是仿制品,虽说是仿制品,但也是威力具大
用起来得手的.
LONG
        );

        set("exits", ([
                "west" : "d/pingan/dong2",
        ]));
	set("objects", ([
		__DIR__"shopman" : 1,
	])); 

        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
}

