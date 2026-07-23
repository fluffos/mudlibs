// wolf.c
// Date: Sep.22 1997
#include <ansi.h>[D
inherit NPC;

void create()
{
        set_name(HIW"雪狼"NOR, ({ "wolf", "lang" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只独行的狼，半张着的大嘴里露着几颗獠牙。\n");
//        set("attitude", "aggressive");
        set("attitude", "peace");
        set("shen_type", -1);

        set("limbs", ({ "狼头", "狼身", "前爪", "后抓", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 200000);
        set_temp("apply/attack", 700);
        set_temp("apply/defense", 500);
        set_temp("apply/armor", 300);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "雪狼耷邋着尾巴，突然抬头，冲你发出一声凄厉的长嚎。\n",
                "雪狼闪着"+HIG" 绿幽幽的眼光"+NOR"冲你瞄了瞄，血盆巨口里答答滴着哈喇子。\n",
        }) );
}

void die()
{
        int a;
        object ob,me=this_player();
        a=me->query_temp("marks/bing");
        a=a|1;
        me->set_temp("marks/bing",a);
        ob = new(__DIR__"obj/langpi");
        ob->move(environment(this_object()));
        destruct(this_object());
}

        
