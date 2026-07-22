//changan city
// Cracked by 凌惊雪 1-3-2003

#include <ansi.h>
inherit BANK;

void create ()
{
        set ("short", "百川钱庄");
        set ("long", @LONG
洛阳金刀王家，家财万贯，产业不可胜数。此间钱庄黑匾红字，
正是金刀王家产业之一。百川钱庄的银票信誉极好，大江南北都可
兑现。钱庄中央有一红木柜台，半人多高，上有牌(paizi)一块。

LONG);
        set("item_desc", ([
                "paizi": @TEXT
这里是钱庄，目前我们提供的服务有：

account         查帐。
deposit         存款。
withdraw        取款。
convert         兑换钱币。

TEXT
        ]) );
        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"chengyun1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/fugui" : 1,
        ]));
        set("outdoors", "luoyang");
	set("no_clean_up", 0);
        setup();

}