#include <ansi.h>
#include <combat.h>
inherit NPC;
void do_summon();
void create()
{
        string *names = ({"幽灵狼王"}); 
        set_name( names[random(sizeof(names))], ({ "wolf king","wolf"}));
        set("vendetta_mark","wolf");
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 1000);
        set("long", "\n");
      
        set("str", 80);
        set("con", 120);
        set("cps", 22); 
        set("fle",100);
        set("resistance/qi",60);
        set("max_qi", 500);
        set("max_jing", 500);
        set("max_neili", 1000);
        set("attitude", "peaceful");

        set("chat_chance_combat", 80);
		    set("chat_msg_combat", ({
		                (: do_summon() :),
		    }) ); 

        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) ); 
                set("combat_exp", 6000000);
                set("bellicosity", 5 );
        
        set_temp("apply/attack", 50);
        set_temp("apply/dodge", 50);
        set_temp("apply/parry", 50);
        set_temp("apply/unarmed_damage", 70);
        setup();
				carry_object("/clone/drug/badan")->set_amount(1);
        carry_object(__DIR__"obj/wolf_eye");
} 

mixed hit_ob(object me, object victim, int damage_bonus)
{
        victim->receive_damage("qi",40+random(40), me);
        victim->receive_wound("qi",30+random(30), me);
        message_combatd(HIW"\n$N"+HIW"锋利的爪子在$n"+HIW"身上留下一道血淋淋的伤口！"NOR,me,victim);
        return;
}   

void do_summon() {
	object wolf,me,enemy,enemies;
	me = this_object();
	
	message_vision(HIB "\n$N仰天狼嚎“呜～嗷～～，呜～嗷”，顿时漫山遍野群狼齐哮。\n" NOR, me); 
	seteuid(getuid());   
	wolf = new(__DIR__"wolf_summon");
	wolf->move(environment(me));
	enemies = me->query_enemy();
	foreach(enemy in enemies) {
	        wolf->kill_ob(enemy);
	        enemy->kill_ob(wolf);
	} 
        message_vision( "\n\n$N恶狠狠地扑了上来。\n" , wolf);
        call_out("leave", 20+random(10), wolf);
        start_busy(2);
}

void leave(object wolf){
        if (! wolf) return;
        message_combatd("\n$N突然消失了。\n",wolf);
        destruct(wolf);
}
