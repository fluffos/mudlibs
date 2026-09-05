// animal: snake.c
// Modified by iszt@pkuxkx, 2007-03-22, added ::die()

#include <ansi.h>
inherit NPC;
#include "/d/baituo/npc/snake2.h"

void create()
{
        set_name(HBWHT+BLK"七寸子蛇"NOR, ({ "snake", "she" }) );
         set("race", "蛇类");
        set("age", 4);
        set("long", "一条七寸子蛇，口中嘶嘶作响，边向你扑来！\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 2000);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 7);
        set_temp("apply/armor", 4);

        set("shen_type",-1);
set("score",200);
setup();
}

void die()
{
        object ob = new(__DIR__"obj/shedan");
        ob->move(environment(this_object()));
        message_vision("$N「啪」的一声，断成了两截！\n", this_object());
        ::die();
}
