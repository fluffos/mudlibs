// animal: snake.c
#include <ansi.h>
inherit NPC;
#include "/d/baituo/npc/snake2.h"

void create()
{
        set_name(RED"火蛇"NOR, ({ "snake", "she" }) );
         set("race", "蛇类");
        set("age", 4);
        set("long", "一条红色的火蛇，口中嘶嘶作响，边向你扑来！\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 1000);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);
        set("shen_type",-1);
set("score",200);
setup();
        carry_object(__DIR__"obj/shedan");
}

