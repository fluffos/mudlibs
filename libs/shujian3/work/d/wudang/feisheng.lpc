// /area/jiangbei/wudang/feisheng.c 飞升崖
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", CYN"飞升崖"NOR);
        set("long", @LONG
飞升崖一峰突起，三面绝壁，山脊上有一条小路直达峰巅，跃顶眺望，武
当七十二峰朝大顶的胜景尽收眼帘。相传，玄武大帝年轻时就在此修练，他面
壁数十年，心如古井，坐如盘松，甚至鸟儿在头上筑巢都纹丝不动。后人依据
玄武大帝在此修练和飞升的传说，在这建起了“梳妆台”。
LONG
        );

        set("exits", ([
                "northeast" : __DIR__"zhenqing",
        ]));

        set("no_clean_up", 0);

        set("objects",([
                __DIR__"npc/youke" : random(2) + 1,
        ]));

        set("outdoors", "武当");

        setup();
}
