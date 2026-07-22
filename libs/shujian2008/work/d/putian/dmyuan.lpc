// Room: /d/putian/dmyuan.c 达摩院
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"达摩院"NOR);
        set("long", @LONG
这里是达摩院，大殿两旁摆满了供桌、香炉、蒲团。因为是寺中重地，所
以平常这里很少有外人可以进入，达摩院的武僧平常也念经焚香，同时他们负
有巡逻、警戒寺中各处要地的责任。
LONG
        );

        set("exits", ([
                "west" : __DIR__"mf-dian",
        ]));

        set("objects",([
                CLASS_D("putian") + "/tian-jing" : 1,
                __DIR__"npc/wuseng" : 4,
        ]));

        setup();
}
