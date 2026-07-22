// /area/jiangbei/wudang/mozhen.c 磨针井
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIG"磨针井"NOR);
        set("long", @LONG
建筑居高临下，每天太阳初升，这里首先接纳到纯一的阳气，故又称“纯
阳宫”。相传玄武是净乐国太子，十五岁入武当山修道。在深山老林中修了几
十年大道未成，心灰意冷，决意弃道还俗，走到这里，遇到女神紫气元君化做
老太婆用铁杵磨针点化他。使他悟出“铁杵磨成针，功到自然成”的道理，遂
又返回深山修炼。
LONG
        );

        set("exits", ([
                "southup" : __DIR__"wangbei",
                "eastup" : __DIR__"yuxuyan",
                "northdown" : __DIR__"yuxu",
        ]));
        set("objects",([
               __DIR__"npc/youke" : 1,
        ]));

        set("no_clean_up", 0);

        set("outdoors", "武当");

        setup();
}
