// /area/jiangbei/wudang/jindian.c 金殿
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIY"金殿"NOR);
        set("long", @LONG
金殿建在天柱峰顶端，是武当山的象征，也是武当道教在皇室扶持下走向
鼎盛的结果。铜铸鎏金的金殿为重檐庑殿式仿木结构，仅面饰鎏金就耗黄金千
两，是武当山等级最高的古建筑。金殿的面阔进深均为三间，立柱上叠架着额、
枋及斗拱，正脊两端龙吻对峙，殿顶翼角飞举，上饰龙凤、天马、等灵禽瑞兽
栩栩如生。 
LONG
        );

        set("exits", ([
                "east" : __DIR__"taihe",
        ]));

        set("no_clean_up", 0);

        set("objects",([
                __DIR__"npc/jxk" : 1,
        ]));

        setup();
}
