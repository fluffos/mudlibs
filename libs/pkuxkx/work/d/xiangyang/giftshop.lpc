inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"礼品店"NOR);
        set("long", 
"这里是个奇特的店铺，老板是个神秘的人物，传说是天界
上派下来的人，这个店铺平常不卖东西，只有在传统节日
的时候才会卖一些有特殊功效的节日礼物。更奇怪的是所
有的礼物只能用一次，如果用了第二次就会适得其反，可
能是为了惩罚贪心的人吧。店里挂着个大横幅：

                "BRED""HIY"┏━━━━━━━━┓"NOR"        
                "BRED""HIY"┃   中 秋 快 乐  ┃"NOR" 
                "BRED""HIY"┗━━━━━━━━┛"NOR"  
");
        set("no_fight",1);
        set("no_spells",1);
        set("no_beg",1);
        set("exits", ([ /* sizeof() == 4 */
			"west" : __DIR__"xynorth2",
]));

        set("objects", ([
//              __DIR__"npc/giftowner" : 1,
//     __DIR__"npc/04zq_gift_dispatcher":1,
                        ]) );
        setup();
        replace_program(ROOM);
}
