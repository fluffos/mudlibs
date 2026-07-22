// /area/jiangbei/wudang/laojun.c 老君岩
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", WHT"老君岩"NOR);
        set("long", @LONG
老君岩石窟正中凿刻老君像一尊。老君像座姿端庄，呈天盘修炼状，为唐
代风格。 在老君岩石窟的左边还有一摩崖石刻群，上面有“太子入武当”、
“蓬莱九仙”等石刻。它当年所营造的是道教最高尊神居住的环境，即元始天
尊、灵宝天尊、道德天尊的寓所，也被称为“三清境”。 
LONG
        );

        set("exits", ([
                "east" : __DIR__"fuzhen",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "武当");

        setup();
}
