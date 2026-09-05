// animal: snake.c
// Modified by iszt@pkuxkx, 2007-03-22, added ::die()

#include <ansi.h>
inherit NPC;
#include "/d/baituo/npc/snake2.h"

void create()
{
        set_name(RED"巨蟒"NOR, ({ "ju mang", "ju" }) );
         set("race", "蛇类");
        set("age", 4);
        set("long", "一条巨蟒口吐芯子，嘶嘶作响，边向你扑来！\n");
        set("attitude", "peaceful");

        set("str", 50);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 100000);

        set_temp("apply/attack", 20);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 20);

        set("shen_type",-1);
set("score",200);
setup();
}

void die()
{
        object ob = new(__DIR__"obj/shedan1");
        ob->move(environment(this_object()));
        message_vision("$N「啪」的一声，断成了两截！\n", this_object());
        ::die();
}
