// Room: /d/putian/cbdian.c
// Lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"慈悲殿"NOR);
        set("long", @LONG
这里是慈悲殿，是莆田少林寺的几座重要建筑其中之一。殿中宽阔，很安
静，两旁立着一些金身佛像，气氛庄严肃穆。几个身穿青布僧衣的小沙弥在忙
碌地擦拭着案上的灰尘。
LONG
        );

        set("exits", ([
                "north" : __DIR__"qianyuan",
                "south" : __DIR__"guangchang",
        ]));
        set("objects",([
                CLASS_D("putian") + "/yuanjue" : 1,
                __DIR__"npc/shami" : 2,
        ]));

        setup();
}

