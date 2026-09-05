// Room: /d/village/shack.c
#include <ansi.h>
inherit ROOM;

void fainting(object, object);
void create()
{
        set("short", "草棚");
        set("long", @LONG
这是一个简单的草棚，地上摆著一堆堆的货物，上山的游客可以在这
    买些上山用品。草棚的墙上贴着个牌子，是个价目表(sign)。
    奇怪的是地上不知什么时候多了张草帘(caolian)，小贩也不知什么地方去了。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"eroad1",
]));
//        set("objects", ([
//                __DIR__"npc/seller": 1 ]) );
        set("item_desc", ([ /* sizeof() == 1 */
"sign" : "牌子上写道：
        手杖(stick)     一百文
        麻鞋(shoes)     一百五十文
        水壶(bottle)    一百文
                兼售 皮蛋(egg) 五十文，茶水(not yet) xx。 \n",
"caolian":"看起来这草帘很杂乱，不知下面有什么东西，不妨掀起来(move)看一看。\n",
]));
        set_temp("available",1);
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_move", "move");
}
int do_move(string arg)
{
        string dir;
        object me,ob,ob2;
        if( !arg || arg=="" || !query_temp("available") ) return 0;
        if( arg=="caolian" && query_temp("available")) {
                write("你试著把草帘一掀，突然发现下面有人 !\n\n");
                delete_temp("available");
        }
        
        return 1;
}
void fainting(object me, object ob)
{
            message_vision("小贩脑袋一颤，垂了下去......",ob);
            me->die();
return;
}
