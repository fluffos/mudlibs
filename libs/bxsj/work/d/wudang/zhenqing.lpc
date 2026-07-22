// /area/jiangbei/wudang/zhenqing.c 天乙真庆宫
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"天乙真庆宫"NOR);
        set("long", @LONG
在南岩，最负盛名的建筑是一座石殿，叫“天乙真庆宫”。传说，玄武大
帝修练升天后，在天上的住所就叫“天乙真庆宫”。显然，这座石殿就是信徒
们在人间为玄武大帝而建造的。真庆宫的石壁上还有一排排的铁铸饰金人像，
人称五百灵官。  
LONG
        );

        set("exits", ([
                "southup" : __DIR__"gsdao4",
                "enter" : __DIR__"sanqing",
                "southwest" : __DIR__"feisheng",
                "north" : __DIR__"gchang",
        ]));

        set("no_clean_up", 0);

        set("objects",([
              CLASS_D("wudang")+"/moshenggu" : 1,
              __DIR__"npc/daotong" :2,
        ]));

        set("outdoors", "武当");

        setup();
}
