// hook.c

#include <ansi.h>
#include <weapon.h>

inherit HOOK;
inherit F_UNIQUE;

int exercising(object me);
int halt_exercise(object me);

void create()
{
    set_name(HIW"寒玉钩"NOR, ({ "hanyu gou", "gou", "hanyu", "hook" }));
	set_weight(18000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
set("long", "这是一把用千年寒玉所制的宽边护手钩，除了威力巨大带有奇毒外，还是疗伤(liaoshang)的宝物。\n");
		set("value", 300000);
		set("material", "yade");
		set("poisoned", "cold_poison");
                set("poison_number", 1000);
		set("unique", 1);
                set("rigidity", 4);
                set("sharpness", 2);
                set("weapon_prop/parry", 5);
                set("treasure",1);
                set("wield_neili", 500);
                set("wield_maxneili", 2500);
                set("wield_str", 25);
		set("wield_msg", HIW"$N将裹布展开，抽出$n"HIW"握在手中，挥出一道雪白的光华！\n"NOR);
		set("unwield_msg", "$N转过身去，用帆布将$n紧紧包好背在背上。\n");
	}
	init_hook(120);
	setup();
}

void init()
{
        add_action("do_heal", "liaoshang");
}

int do_heal()
{
	mapping msg;
	string force;
	object me = this_player();
	
        if(me->query("family/family_name") != "星宿派")
                return notify_fail("你非星宿弟子，不会使用寒玉钩疗伤。\n");

        if( me->is_busy() )
                return notify_fail("你正忙着呢。\n");
        
        if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？\n");
		
        if ((int)me->query_skill("force") < 260)
                return notify_fail("你的内功修为还不够，无法熟练运用寒玉钩。\n");
                
        if( (int)me->query("max_neili") < 3000 )
                return notify_fail("你的内力修为不够，无法熟练运用寒玉钩。\n");
                
        if( (int)me->query("eff_qi") >= (int)me->query("max_qi") )
                return notify_fail("你现在并没有受伤啊！\n");
                
	if(!stringp(force = me->query_skill_mapped("force")) || me->query_skill(force, 1) < 160)
		return notify_fail("你的特殊内功还不能支持你运用寒玉钩！\n");
	
	if((int)me->query("neili") < 50 )
                return notify_fail("你的真气不够了。\n");
	
	message_vision(HIY"$N将双手平放在寒玉钩上，只见寒玉钩渐渐放出一丝柔和的光芒......\n"NOR,me);
	msg = SKILL_D(force)->exercise_msg(me);
      	if (!msg || undefinedp(msg["heal_msg"]))
           	message_vision(HIW"$N盘膝坐下，开始运功疗伤。\n"NOR,me);
      	else 	message_vision(msg["heal_msg"],me);

	me->set_temp("pending/qi_heal", 1);
      	me->set_temp("period", 1);
      	me->start_busy((: exercising :), (:halt_exercise:));
        return 1;
}

int exercising(object me)
{
	int period = (int)me->query_temp("period");
        int skill;
	int eff = me->query("eff_qi");
	int max = me->query("max_qi");
        string force;
        
        if(!living(me) || !(force = me->query_skill_mapped("force"))){
        	me->delete_temp("pending/qi_heal");
        	me->delete_temp("period");
       	        return 0;
        }
        
	if(me->query("family/family_name") == "星宿派")
		skill = 180;
	else skill = 120;
        skill = (skill+random(skill))/4;
        skill += me->query_skill(force)/5;
        skill += random(me->query_con());
        
        if(me->query("jing") < 1 || me->query("jingli") < 1){
        	me->delete_temp("pending/qi_heal");
        	me->delete_temp("period");
        	me->unconcious();
        	return 0;
                }
        
        if( eff >= max ){
        	write("良久，你感觉自己在寒玉钩的帮助下，身上的伤势已经全好了。\n");
                message_vision(HIW"$N看上去气色饱满，两眼一开，缩回了放在寒玉钩上的双掌，一点也没有受过伤的样子。\n"NOR,me);
        	me->delete_temp("pending/qi_heal");
        	me->delete_temp("period");
        	return 0;
        	}
        if( (int)me->query("neili") < 50 ){
        	write("你正在运功疗伤，却发现自己所剩的内力不够了。\n");
        	if(eff < max)
        	     write(HIY"你呼出一口气站了起来，可惜伤势还没有完全恢复。\n"NOR);
        	message_vision(HIY"$N运功完毕，缓缓缩回了放在寒玉钩上的双掌，脸色看起来好了许多。\n"NOR,me);
        	me->delete_temp("pending/qi_heal");
        	me->delete_temp("period");
        	return 0;
        	}
        me->receive_curing("qi", skill);
        me->receive_damage("neili", 50);
	switch(period) {
        case 5:
                write(YEL"你不停地催动内息，明显感觉到寒玉钩只中有种气息在帮你疗伤。\n"NOR);
                break;
        case 20:
                message_vision(YEL"$N缓缓呼出一口气，脸色看起来好多了。\n"NOR,me);
                break;
        case 40:
                write(YEL"你的内息缓缓运转，牵引着寒玉钩的气息通行于全身伤脉。\n"NOR);
                break;
        case 80:
                write(YEL"寒玉钩的气息在你体内轮回运转，你感到全身舒坦极了。\n"NOR);
                me->improve_skill("force", 5+random(5));
                break;
        case 110:
        case 120:
        case 140:
                write(YEL"渐渐的，你全身的力气在寒玉钩的帮助下在迅速地恢复着！\n"NOR);
                me->improve_skill("force", 5);
                break;
        case 160:
        case 190:
                write(YEL"你全身已无大碍，渐渐暂停了引导寒玉钩的气息。\n\n"NOR);
                me->improve_skill("force", 1);
                break;
        }
        period++;
        me->set_temp("period", period);
        return 1; 
}

int halt_exercise(object me)
{
	me->delete_temp("pending/qi_heal");
        me->delete_temp("period");
	me->receive_damage("jing", 50);
	me->receive_damage("jingli", 50);
	tell_object(me, "你心头一动，急忙吐气纳息，硬生生将寒玉钩的气息引导出去。\n");
	message_vision("$N眉头一皱，将双掌收回，拿着寒玉钩站了起来。\n", me);    
        me->start_busy(1+random(5));
	return 1;
}

