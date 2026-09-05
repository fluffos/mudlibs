// Room: /city/datiepu.c
// YZC 1995/12/04

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "打铁铺");
        set("long", @LONG
这是一家简陋的打铁铺，中心摆着一个火炉，炉火把四周照得一片通红，你
一走进去就感到浑身火热。墙角堆满了已完工和未完工的菜刀、铁锤、铁棍、匕
首、盔甲等物。一位铁匠满头大汗挥舞着铁锤，专心致志地在打铁。
LONG);
        set("exits", ([
                "north" : __DIR__"dongdajie2",
                "south" : __DIR__"datiepu2",
        ]));
        set("objects", ([
                "/adm/npc/wang":1,
        ]));
        set("work", ([
                "gift" : "strength",
                "gift_name" : "后天膂力",
                "boss" : "wang tiejiang",
                "msg_num" : 2,
                "msg0" : CYN"$N满头大汗的推拉着风箱。\n"NOR,
                "msg1" : CYN"$N从后屋搬来一堆零零碎碎的铁家伙。\n"NOR,
        ]));
        setup();
//      replace_program(ROOM);
}
