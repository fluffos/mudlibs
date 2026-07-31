#include <ansi.h>
inherit NPC;

void create()
{
        set_name(RED"吸血蝙蝠"NOR, ({ "bat", "bianfu" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "生活在阴森山洞中的蝙蝠,以吸血维生。\n");
        set("attitude", "peaceful");

		set("can_speak",0);

        set("str", 26);
        set("cor", 30);
        set("kee", 100);
        set("max_kee",100);
        set("limbs", ({ "尖嘴", "身体", "肉翼", "爪子" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 1000);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        setup();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player())) 
                        	call_out("kill_ob", 1, ob); 
        
}
void die()
{
        object ob;
        message_vision("$N一头栽倒在地,挣扎了几下！$N死了。\n", this_object());
        destruct(this_object());
}
