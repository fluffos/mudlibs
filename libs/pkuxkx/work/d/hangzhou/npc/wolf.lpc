// animal: wolf.c
// by hubo

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW"恶狼"NOR, ({"wolf"}) );
         set("race", "野兽");
        set("age", 4);
        set("long", "一条白毛恶狼，看上去好几天没吃东西了，一边舔着舌头，一边向你扑来！\n");
        set("attitude", "aggressive");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100000);

        set_temp("apply/attack", 50);
        set_temp("apply/damage", 50);
        set_temp("apply/armor", 20);
        setup();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && living(this_object()) ) 
                {
                   remove_call_out("kill_ob");
                   call_out("kill_ob", 1, ob); 
                }       
}

