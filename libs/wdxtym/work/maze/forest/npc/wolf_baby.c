#include <ansi.h>
inherit NPC;
void create()
{
        string *names = ({"灰毛恶狼","黄毛恶狼","白毛恶狼"}); 
        set_name( names[random(sizeof(names))], ({ "wolf"}));
        set("vendetta_mark","wolf");
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 20);
        set("long", "这是一只残忍的恶狼。\n");
      
        set("str", 40);
        set("cor", 100);
        set("cps", 22); 
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("max_neili", 5000);
        set("attitude", "peaceful");
        set("chat_chance", 2);

        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("combat_exp", 1000000);
        set("bellicosity", 5 );
        
        set_temp("apply/attack", 60);
        set_temp("apply/dodge", 80);
        set_temp("apply/parry", 80);
        set_temp("apply/unarmed_damage", 30);
        setup();
        carry_object(__DIR__"obj/wolf_skin");
} 

mixed hit_ob(object me, object victim, int damage_bonus)
{
        victim->receive_damage("qi",300+random(300), me);
        victim->receive_wound("qi",200+random(200), me);
        message_combatd(HIW"\n$N"+HIW"锋利的爪子在$n"+HIW"身上留下一道血淋淋的伤口！"NOR,me,victim);
        return;
}      
