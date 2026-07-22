// Room: /d/putian/jnlwdian.c
// Lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"紧那罗王殿"NOR);
        set("long", @LONG
这是紧那罗王殿，殿中供奉着佛家禅宗的紧那罗王金身塑像。四周的墙壁
上绘满了西方胜境，四十八愿，二十四尊天的壁画，壁画的线条流畅，画工精
细，俨然出于名家之手。一个小沙弥在扫地。
LONG
        );

        set("exits", ([
                "north" : __DIR__"xiaoyuan5",
        ]));

        set("objects",([
                __DIR__"npc/shami" : 1,
                CLASS_D("putian") + "/yuannu" : 1,
        ]));

        setup();
}

