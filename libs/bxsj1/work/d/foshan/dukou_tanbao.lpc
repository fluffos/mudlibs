#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "老渡口");
        set("long", @LONG
你迎着阵阵海风来到了渡口，这里是一个已经被废弃了很久的渡口。
这个渡口曾经繁荣过一段很长的时间，因为古时皇帝为了得到长生不老就
从这里出发向传说中的蓬莱航行，一块破旧的牌子(sign)，上面写着几个
字。
LONG);
        set("outdoors", "佛山");
        set("exits",([
                "north" : __DIR__"caomeidi",          
        ]));   
        set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("valid_startroom", 1); // 此两条分别为：非连线房间 及 起始房间
        set("item_desc", ([
                        "sign":
                    "┌──────────────"+HIG" 南海探宝须知 "NOR+"──────────────┐\n"
                        "│ 一：在可以使用(ask man about 南海探宝)来开始探宝                     │ \n"
                        "│ 二：在探宝途中可以使用(game over)来结束探宝                          │ \n"
                        "│ 三：请用(help job tanbao)来查询具体说明。                            │ \n"
                        "└───────────────────────────────────┘ \n\n"
                        ]) ); 
	set("objects", ([
            __DIR__"npc/tanbao_npc" : 1,
	]));
        setup();
}
