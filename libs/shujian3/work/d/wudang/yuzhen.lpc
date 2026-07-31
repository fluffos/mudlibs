// /d/wudang/yuzhengong.c 遇真宫
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIW"遇真宫"NOR);
        set("long", @LONG
这里是进香客进香还愿的遇真宫，乃武当山的第一道宫宇。宽敞无比，香
火鼎盛。宫中供着张三丰真人像。由于张真人闭关已久，外人不知其是否尚在
人间，民间传说他已得道仙逝，因此立像膜拜。
LONG
        );
        set("exits", ([
                "westup" : __DIR__"wdbolin",
                "northdown" : __DIR__"gsdao2",
        ]));

        set("outdoors","武当");

        set("objects",([
                CLASS_D("wudang")+"/zhike" : 1,
                __DIR__"obj/gdxiang" : 1,
        ]));
        setup();

}
