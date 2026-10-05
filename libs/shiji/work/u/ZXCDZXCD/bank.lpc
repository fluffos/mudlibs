#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "兽族大银行" NOR);
        set("long", @LONG
这一家银行不知道是哪个时候开始经营的,只知道它的年代已经
很久了,它是以极好的信誉一直在兽族为当地的百姓服务着.
里面的掌柜不停的拨弄古老的算盘,口中念念有词
在墙上的有块模糊不清的黑板(heiban),上面写着银行的利率.
LONG );
        set("exits", ([
            "west" : __DIR__"wangshougu",
        ]));
        set("item_desc", ([
                "heiban" : @TEXT
       本银行提供以下服务：
       转帐      zhuanzhang <某人> <电子货币数量>
TEXT
        ]) );
        set("objects", ([
         __DIR__"npc/banker" : 1
        ]));
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("no_beg", 1);
        setup();
}
