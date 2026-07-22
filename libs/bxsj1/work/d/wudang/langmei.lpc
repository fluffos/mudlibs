// /area/jiangbei/wudang/langmei.c 榔梅祠
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIG"榔梅祠"NOR);
        set("long", @LONG
榔梅祠位于通往金顶的路上，武当榔梅开花结果，道士往往将榔梅果贡献
朝庭，得到了皇帝赏赐。皇帝认为，榔梅结果是个“瑞兆”，是玄武大帝对他
登基即位的赞美。玄武大帝修练时，曾折下一段梅枝插在榔树上，说：“吾若
道成，开花结果”。后来，他果然得道成功，梅枝在榔树上也插栽成活。
LONG
        );

        set("exits", ([
                "westup" : __DIR__"qtguan",
                "northwest" : __DIR__"yxyan",
                "east" : __DIR__"shanlu2",
                "northdown" : __DIR__"gsdao5",
        ]));

        set("no_clean_up", 0);

        set("objects",([
                __DIR__"npc/youke" : 1,
        ]));

        set("outdoors", "武当");

        setup();
}
