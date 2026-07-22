// Room: /d/putian/jingshi.c 静室
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "静室");
        set("long", @LONG
小小一间静室，少林寺方丈天虹禅师端坐在禅床上，身前有张小几，几上
小香炉中檀香青烟袅袅上升，对面壁上挂着一幅白描的寒山拾得图，寥寥不多
几笔，却画得两位高僧神采栩栩。
LONG
        );

        set("exits", ([
                "north" : __DIR__"jcyuan",
        ]));

        set("objects",([
                CLASS_D("putian") + "/tian-hong" : 1,
        ]));

        setup();
}
