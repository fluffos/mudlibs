//yuebingfang.c 月饼坊
// By icer

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "月饼坊");
        set("long", @LONG
这里是中秋月饼的制作作坊，糕点师傅正在忙前忙后地赶制月饼，满足大家的节日需求。
LONG
        );

        set("exits", ([
                  "northwest" : "/d/city/guangchang",
                "north" : __DIR__"duchang",
        ]));

        set("objects",([
                            __DIR__"npc/gaodianshifu" : 1,

        ]));

        setup();
}

void init()
{
	tell_object(this_player(),BNK+HIR+"×××××××××××××××××××××××注意×××××××××××××××××××××××\n"+NOR+HIR+"有关国庆、中秋礼物的用法，请仔细看说明 http://www.pkuxkx.net/forum/thread-8974-1-1.html ，说明里有的问题不再回答，\n由于不仔细看说明引起的奖励损失不管。\n"+NOR);
}

