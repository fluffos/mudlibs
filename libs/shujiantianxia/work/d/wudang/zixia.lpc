// /area/jiangbei/wudang/zixia.c 紫霄宫
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"紫霄宫"NOR);
        set("long", @LONG
规模宏大，气势磅礴的紫霄宫，座落在武当山展旗峰下。这里群峰山岭环
绕，松林翠柏幽深，环境优雅，气候宜人，历来被视为“紫霄福地”。紫霄宫
初建于宋宣和年间。宋徽宗赵佶一次做梦，梦见了“火神”，有一方士为他圆
梦，说要派水神到南方压镇，才能无忧。于是选中了七十二福地之一的武当山，
在展旗峰下为水神玄武建造了这座宫殿，并赐额“紫霄元圣宫”。 
LONG
        );

        set("exits", ([
                "out" : __DIR__"zxgdamen",
                "southup" : __DIR__"nanyan",
        ]));

        set("no_clean_up", 0);

        set("objects",([
                CLASS_D("wudang")+ "/wanqing" : 1,
                __DIR__"npc/daotong" :2,
        ]));

        set("outdoors", "武当");

        setup();
}
