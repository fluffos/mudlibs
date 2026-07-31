// /d/wudang/shijie4.c 
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",CYN"石阶"NOR);
        set("long", @LONG
你走在一条古朴的石阶上，不时地有进香客从你的身边走过。远处的撞钟
声清晰可闻。抬头隐约可见笼罩在云雾中的天柱峰，你知道快到山顶了，一兴
奋顿时忘了浑身的疲倦。
LONG
        );
        set("exits", ([
                "southup" : __DIR__"gsdao5",
                "northdown" :__DIR__"gsdao4",
        ]));

        set("objects",([
                __DIR__"npc/jxk" : random(2)+1,
        ]));
        set("outdoors","武当");
        setup();
}
