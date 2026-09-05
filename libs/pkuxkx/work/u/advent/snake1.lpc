// animal: snake.c
#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIC"眼镜蛇"NOR, ({ "snake", "she" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "一条眼镜蛇，口中嘶嘶作响，边向你扑来！\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);
        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 1200);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        setup();
}
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                random(ob->query_kar() + ob->query_per()) < 30) {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }
}
void die()
{
object ob,me,player;
me = this_object();
ob = new(__DIR__"obj/shedan");
if( objectp(player = me->query_temp("last_damage_from"))) 
{
ob->move(player);
}
::die();
        destruct(this_object());
}
