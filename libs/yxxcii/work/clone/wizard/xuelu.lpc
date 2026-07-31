// xuelu.c 雪鹿

#include <command.h>
#include <dbase.h>
#include <origin.h>
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"雪鹿"NOR, ({"xue lu" }));
        set("long",@LONG
这是一头雪鹿，是圣诞老人的坐骑，圣诞老人经常骑
着它攀山越领的去派发礼物！
LONG
);
        set("race", "野兽");
        set("age", 5);
        set("ridable", 1);
        set("int", 30);
        set("qi", 300);
        set("max_qi", 300);
        set("jing", 100);
        set("max_jing", 100);
        set("shen_type", 0);
        set("combat_exp",50000);
        set("attitude", "peaceful");

        set("limbs", ({ "头部", "腹部", "尾巴","后腿","前腿" }) );
        set("verbs", ({ "bite","hoof","head"}) );
        set_temp("apply/attack", 50);
        set_temp("apply/armor", 15);
        set_temp("apply/damage", 25);
        set("chat_chance", 3);
        set("chat_msg", ({
                HIW"雪鹿甩了甩身上的毛发，还用舌头舔舔。\n"NOR,
                HIW"雪鹿用前蹄踢了踢地面，尾巴很不老实的摇来摇去。\n"NOR,
        }) );

        setup();
}
