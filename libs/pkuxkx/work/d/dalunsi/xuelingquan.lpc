// 大轮寺
//by kiden

inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
        set("short", HIW"雪"+HIG"灵"+HIC"泉"NOR);
        set("long", @LONG
这是由雪山积雪融化汇流而成的一条小溪，流到这里，地势平坦，蓄成了一汪
泉水(spring)，清澈甘冽，冰凉透骨。
真是：
    水穷行到处，云起坐看时。
    千山遮不住，毕竟东流去。
    水远，怎知流水外，却是乱山更远。
LONG 
        );

        set("exits", ([
                "southdown" : __DIR__"fengjiantai",
                "northeast" : __DIR__"xuejigudao1",
        ]));
        set("item_desc", ([
                "spring" : HIG"一汪好清澈的泉水，你都忍不住要喝一口了！\n泉水汇集在一个小池中，里面有几条鱼儿游来游去，或许你也可以下去洗个澡吧。\n"NOR,
        ]) );
        set("objects", ([
//                __DIR__"npc/baoxiang" : 1,

        ]));
        set("outdoors", "dalunsi");
        set("no_clean_up", 0);
        setup();
//        replace_program(ROOM);
}
void init()
{
add_action("do_drink","drink"); 
add_action("do_tiao","tiao"); 
add_action("do_tiao","jump"); 
}
int do_drink()
{       object me=this_player();
        if ((int)me->query("water")>((int)me->query("str")+10)*10)
        return notify_fail("灌了一肚子水，你也不难受呀？\n");
        
        me->set("water",450);
        message_vision("$N蹲下身掬起一捧泉水喝了下去，只觉得一股凉气直透心田。\n",me);
        return 1;
}

int do_tiao(string arg)
{
        object ob;
        ob = this_player();

        if( arg != "spring" ) 
             return notify_fail("你要往那里跳？\n");

        message_vision(HIW"$N纵身往泉水中跳了下去。\n"NOR,ob);
        ob->move(__DIR__"quanshuizhong");
        return 1;
}

