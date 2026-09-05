#include <room.h>
inherit ROOM;
void create ()
{
    set ("short", "石室");
    set ("long", @LONG
一个黑洞洞的石室，你凭着微弱的灯光看到四壁岩石打磨得甚是
光滑，石壁上刻满了无数径长尺许的圆圈，每个圈中都刻了各种各样
的图形，有的是人像，有的是兽形，有的是残缺不全的文字，更有些
只是记号和线条，圆圈旁注着“甲一”、“甲二”、“子一”、“子
二”等数字，圆圈之数若不逾千，至少也有八九百个，一时却哪里看
得周全？
LONG
        );
    set("no_sleep_room",1);
    set("no_fight", 1);
    set("item_desc", ([ /* sizeof() == 1 */
                "picture" : "这些图案似乎是灵鹫宫的武功！\n",
                ]));
    set("exits", ([
            "out": __DIR__"midao11",
            ]));
    setup();
}

void init()
{
    add_action("do_study", "study");
    add_action("do_study", "read");
}

int do_study(string arg)
{   
    object me=this_player();
    int gain,jing_cost;

    if( !arg || (arg != "picture"))
        return notify_fail("你要学什么？\n");
    if( me->is_busy() )
        return notify_fail("你忙的很，哪有功夫去看石壁！\n");
    if (!me->query_temp("use_fire"))
        return notify_fail("这里的光线太暗,你什么都看不见!\n");
    if( (int)me->query_skill("literate", 1) < 150)
        return notify_fail("你看了半天也看不懂上面画的是什么！\n");
    if( (int)me->query_skill("bahuang-gong", 1)+(int)me->query_skill("force",1)/2 < 150)
    {
        write ("你看了石壁上的图画，只觉得气血翻涌，无法抑制！\n");
        me->unconcious();
        return 1;
    }
    if( (int)me->query_skill("zhemei-shou", 1) < 150 || (int)me->query_skill("liuyang-zhang",1) < 150)
        return notify_fail("你功夫太浅，难于理解图上的内容。\n");
    if( (int)me->query_skill("zhemei-shou", 1) >= 300 
        && (int)me->query_skill("liuyang-zhang",1) >=300
        && (int)me->query_skill("bahuang-gong",1)>=300 )
        return notify_fail("你定睛看了会，你已经全部领悟到了。\n");    
    if( (int)me->query("eff_qi") < 1000)
        return notify_fail("你底气不足，练不了这么高深的功夫。\n");

    jing_cost = 80 - (int)me->query("int");
    if( (int)me->query("jing") < jing_cost )
        return notify_fail("你现在头晕脑胀，该休息休息了。\n");
    me->add("jing", -jing_cost);

    gain = (int)me->query("int")/2 + (int)me->query("con")/2 + random(10);
    if( (int)me->query_skill("zhemei-shou", 1) < 300)
        me->improve_skill("zhemei-shou", gain/2);
    if ((int)me->query_skill("liuyang-zhang",1) <300)
        me->improve_skill("liuyang-zhang",gain/2);
    if ((int)me->query_skill("bahuang-gong",1) <300)
        me->improve_skill("bahuang-gong",gain/2);
    write("你照着石壁上的图案比划，对灵鹫宫的功夫又有所了解。\n");

    tell_room( environment(me), me->name() + "两眼凝视石壁上的图案，双手还不时挥来挥去，不知在比划什么。\n", ({me}));

    return 1;
}

