// zhengting.c 正厅
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_sleep(string arg);

void create()
{
        set("short", "正厅");
        set("long", @LONG
这里是古墓的正厅，本来应该停放灵柩棺木之类的东西，却不知
道被人般到哪里去了。厅正中端坐着一位白衣少女，厅角上摆放着一
张石头做成的大床(chuang)，厅中横系着一条绳子，不知道做什么用
的，除此之外，别无摆设。
LONG
        );

        set("exits", ([
                "west" : __DIR__"liangong",
                "north" : __DIR__"xiaoting",
                "south" : __DIR__"houting",
        ]));

	set("roomif","$botten#训蜂任务|刺杀任务|放弃训蜂|放弃刺杀:ask long about job|ask yang about job|ask long about 失败|ask yang about 失败$#");	 

        set("objects", ([
                "quest/menpaijob/gumu/zf/longnv" : 1,
                "/d/biwu/champion_gm":1,
                "quest/menpaijob/gumu/yangguo":1
        ]));
        set("valid_startroom",1);

        set("item_desc", ([
        "chuang": "这是一张用"+HIB"千年寒玉"NOR+"雕成的寒玉床。\n"
        ]) );
        setup();
        "/clone/board/gumu_b"->foo();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
        object me=this_player();
        int lvl_force, c_exp, c_skill;

        if( !arg || arg == "" ) {
                return notify_fail("你要睡在哪儿？\n");
        }

        lvl_force=(int)me->query_skill("force",1);
        if(lvl_force>150) //force 大于 150
                {
                message_vision("$N躺上了寒玉床，开始潜运内功，使内息遍行大小周天。\n",this_player());
                if (random(20)>12) {
                        message_vision("$N调息完毕，只觉得精神健旺，内息充沛欲奔腾而出。\n", this_player());
                        c_exp=me->query("combat_exp");
                        c_skill=me->query_skill("force",1);
                        if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<250))
                        {
                                me->improve_skill("force", random(lvl_force));
                        }
                        me->receive_damage("qi",random(lvl_force/3));
                }
                else
                        message_vision("$N调息完毕，站起身来，提了提内力，好象没什么长进。\n", this_player());
                }
        else
                message_vision("$N躺上寒玉床，只觉得冰冷刺骨，‘啊’的一声狼狈不堪地跳了起来。\n", this_player());
        return 1;
}
