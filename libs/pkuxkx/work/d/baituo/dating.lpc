//ROM /d/baituo/dating
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "大厅");
        set("long",
             "这是"HIG"『白驼山庄』"NOR"的大厅，内部摆设极尽豪华，当中一张黑色檀\n"
         "木条案，上面陈放着精美的花瓶和一些珍贵的瓷器，四壁挂满名家的\n"
         "字画。难道说“老毒物”也喜欢这个么？\n"
        );
        set("valid_startroom",1);
        set("exits", ([
                "north" : __DIR__"liangong",
                "southdown" : __DIR__"yuanzi",
        ]));
        set("objects",([
             CLASS_D("btshan") + "/ouyangfeng" : 1,
//             "/kungfu/class/btshan/ouyangfeng":1,
                "/clone/npc/camel1": 0,
                __DIR__"npc/yahuan" : 2,
        ]));
        set("no_clean_up", 0);
        setup();
        "/clone/board/baituo_b"->foo();
        replace_program(ROOM);
}
