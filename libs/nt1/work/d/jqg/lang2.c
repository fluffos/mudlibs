//changlang2.c 长廊
inherit ROOM;
#include <ansi.h>
void create()
{
            set("short", HIY"东厢长廊"NOR);
            set("long",@LONG
步入东厢长廊，扑面而来的就是一股药草的气味，原来是从北面的丹房散
发出来的，那是主人最喜爱的地方，平时很少有人敢擅入。南面传来阵阵的吆
喝声，这便是绝情谷弟子练功房了。
LONG
    );

            set("exits",([
                "north": __DIR__"danfang",
                "south": __DIR__"lgf",
                "east": __DIR__"lang3",
                "west": __DIR__"lang1",
            ]));            

	    setup();
}

int valid_leave(object me, string dir)
{
        if ( !me->query_temp("gsz_agree")
           && ( dir =="north" || dir=="south"))
        return notify_fail("这里是绝情谷的禁地，没有庄主的命令，外派弟子不能进入！！\n");
        return ::valid_leave(me, dir); 
}
