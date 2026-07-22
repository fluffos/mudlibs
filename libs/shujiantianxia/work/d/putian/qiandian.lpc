// Room: /d/putian/qiandian.c 前殿
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"前殿"NOR);
        set("long", @LONG
这是寺中的前殿，殿中面积很大很宽阔，地上铺了一层青色的方砖，个别
地方的方砖有些不平，仔细看能看见有象脚印形状的凹陷。北面是高大的大雄
宝殿，琉璃的尖顶在阳光下闪着光。南面是中殿，一条石板路通向后院。
LONG
        );

        set("exits", ([
                "northup" : __DIR__"dxb-dian",
                "south" : __DIR__"zhongdian",

        ]));
        set("objects",([
        	__DIR__"npc/wuseng" : 1,
        ]));

        setup();
}
