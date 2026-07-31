// cow.c 大黄牛
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(YEL"大黄牛"NOR, ({ "da huangniu", "huangniu", "cow" }));
        set("long","一头瘦骨嶙峋的大黄牛，不知是谁家的，正低头认真地吃着草。\n");
        set("race", "野兽");
        set("age", 5);
        set("int", 30);
        set("can_ride",1);
        set_temp("no_return",1);
        set("unique", 1);
        set("qi", 300);
        set("max_qi", 300);
        set("jing", 100);
        set("max_jing", 700);
        set("combat_exp",50000);
        set("attitude", "peaceful");

        set("limbs", ({ "头部", "腹部", "尾巴","后腿","前腿" }) );
        set("verbs", ({ "bite","hoof" }) );
        set_temp("apply/attack", 50);
        set_temp("apply/armor", 15);
        set_temp("apply/damage", 25);

        set("chat_chance", 2);
        set("chat_msg", ({
        "大黄牛无辜的看着你，好象在乞求些什么。\n",
        "大黄牛口中喘着粗气。\n",
        }) ); 

        setup();
}
