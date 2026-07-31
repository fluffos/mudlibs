// /area/jiangbei/wudang/nanyan.c 大圣南岩宫
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"大圣南岩宫"NOR);
        set("long", @LONG
南岩，又名“紫霄岩”，因它朝向南方，故称做南岩。它的全称是大圣南
岩宫。据记载，在唐朝，八仙之一的吕洞宾就曾在南岩修道，这里还留有他作
的一首诗。史书盛赞南岩是“分列殿庭，晨钟夕灯，山鸣谷震”。到了晚上，
这里的灯火成了别具特色的景观。        
LONG
        );

        set("exits", ([
                "south" : __DIR__"gchang",
                "northdown" : __DIR__"zixia",
        ]));

        set("no_clean_up", 0);

        set("objects",([
                CLASS_D("wudang")+ "/chenyun" : 1,
               __DIR__"npc/daotong" : 2,
        ]));

        set("outdoors", "武当");

        setup();
}
