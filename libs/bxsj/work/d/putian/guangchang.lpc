// Room: /d/putian/guangchang.c 广场
// lklv 2001.7.21

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"广场"NOR);
        set("long", @LONG
这是寺中的广场，广场面积很大很宽阔，地上铺了一层青色的方砖，个别
地方的方砖有些不平，仔细看能看见有象脚印形状的凹陷。北面是高大的慈悲
殿，南面是威严的大雄宝殿，琉璃的尖顶在阳光下闪着光。
LONG
        );

        set("exits", ([
                "north" : __DIR__"cb-dian",
                "east" : __DIR__"xiaoyuan4",
                "west" : __DIR__"xiaoyuan5",
                "southup" : __DIR__"dxb-dian",

        ]));
        set("objects",([
        	__DIR__"npc/jxiang-ke" : 2,
        	__DIR__"npc/seng-bing" : 2,
        ]));

        set("outdoors", "福州");
        setup();
}
