// Room: d/fouzhou/bank.c
// Looklove y2k/4/09
// lklv modify 2001.9.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"通宝斋"NOR);
        set("long", @LONG
这是福州的一家钱庄，是有几百年历史的中原钱庄联盟的西南分店。它们
联合发行的银票信誉非常好，通行全国。这里由于地处城东，所以平常往来的
人不是很多。
LONG
        );

        set("exits", ([
                "west" : __DIR__"dongxiang2",
        ]));

        set("objects", ([
                __DIR__"npc/banker" : 1,

        ]));

	setup();
}
