// /area/jiangbei/wudang/fuzhen.c 复真观
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"复真观"NOR);
        set("long", @LONG
复真观又名“太子坡”，相传是净乐国王太子，也就是后来的玄武大帝十
五岁入武当山修炼时最初居住的地方，又因其意志不坚在返回家的途中，被紫
气元君用“铁杵磨针”点化，复又上山修炼，因而得名复真观的。
LONG
        );

        set("exits", ([
                "west" : __DIR__"laojun",
                "westup" : __DIR__"shijie2",
                "northdown" : __DIR__"shibapan",
        ]));

        set("objects",([
               __DIR__"npc/daotong" : 2,
               CLASS_D("wudang") + "/guxu" : 1,
        ]));

        set("no_clean_up", 0);

        set("outdoors", "武当");

        setup();
}
