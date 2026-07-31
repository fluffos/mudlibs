//changlang3.c 长廊
inherit ROOM;
#include <ansi.h>
void create()
{
            set("short", HIY"东厢长廊"NOR);
            set("long",@LONG
这是东厢走廊尽头，东面通向书房，一般外派弟子到这里就止步，没有公
孙谷主的命令，外派弟子不能进书房。
LONG
    );

            set("exits",([
                "east": __DIR__"shufang",
                "west": __DIR__"lang2",
            ]));             
	    setup();
}

int valid_leave(object me, string dir)
{
        if ( !me->query_temp("gsz_agree")
           && dir =="east")
	return notify_fail("这里是绝情谷的禁地，没有庄主的命令，外派弟子不能进入！！\n");
        return ::valid_leave(me, dir); 
}
