#include <weapon.h>
#include <ansi.h>

inherit STAFF;

#include <combat_msg.h>
void create()
{
	set_name("怪蛇杖" NOR, ({ "guaishe zhang", "shezhang", "zhang"}));
	set_weight(15000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "一根顶部有条怪蛇的蛇杖，蛇头处有机关，咬起人来厉害无比！\n");
		set("value", 500);
		set("material", "steel");
                set("poisoned", "bt_poison");
                set("poison_number", 290);
	}
	init_staff(75);
	setup();
}

void init()
{
        add_action("do_zhua","yao");
        add_action("do_zhua","咬");
}

object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

int do_zhua(string str)
{
	object me, target;
        string msg, *limbs, limb;
	int j, damage;
	
        me = this_player();

        if (str && !objectp(target = present(str, environment(me)))) 
                  return notify_fail("这里没有这个人。\n");
        
        if( !target ) target = offensive_target(me);
        
        if( !target
         || !target->is_character()
         || !living(target)
         || !me->is_fighting(target) )
                return notify_fail("你只能在战斗中使用。\n");

        if (me->is_busy()) 
                return notify_fail("你现在正忙着呢。\n");
	
        if( !this_object()->query("equipped") )
		return notify_fail("你是想咬人？佩服！佩服！\n");
		
        if (me->query_skill_prepared("strike") != "hamagong" ||
            me->query_skill_mapped("strike") != "hamagong" ||
            me->query_skill_mapped("force") != "hamagong")
                return notify_fail("没有熟练蛤蟆功，你根本无法使用怪蛇杖！\n"); 
       
        if( (int)me->query_skill("hamagong",1) < 150 )
                return notify_fail("你的蛤蟆功功力不够，使用不了怪蛇杖！\n");
        if( (int)me->query_skill("poison",1) < 150 )
                return notify_fail("你的毒技不够，使用不了怪蛇杖！\n");

	if( (int)me->query_skill("baituo-shezhang",1) < 150 )
                return notify_fail("你的杖技不够，使用不了怪蛇杖！\n");

        if( (int)me->query("jingli") < 500 )
                return notify_fail("你目前精力涣散，还是先注意注意自己吧！\n");
       
        if( (int)me->query("neili") < 800 )
                return notify_fail("你目前内力不凝，还是先注意注意自己吧！\n");

        if(me->query("combat_exp") < (int)target->query("combat_exp")/2 )
                return notify_fail("哎呦，对方比你高明不知多少呢，你找死啊？\n"); 

	target->add_temp("hmg_bite", 1);
        message_vision(HIB "\n$N"HIB"突然纵上，双手一拧怪蛇杖尾，张牙咧爪对着$n一阵乱挥！\n" NOR, me, target);

        if(random(me->query("combat_exp")) < (int)target->query("combat_exp")/2 ||
                random(target->query_temp("hmg_bite")) > 2){
                msg = "$n大吃一惊，知道厉害，急忙飞退开去，大口大口喘着气！\n\n" NOR;
                me->start_busy(1);
                if(!target->is_busy())
                        target->start_busy(1);
                } 
        else {
                me->start_busy(2);
                if(!target->is_busy())
                        target->start_busy(2);
                msg = "$p怎想到$N这杖里的乾坤，只见杖头的蛇头忽然一动，一口咬在了$p身上！";
                if( query("poison_number") > 0 ){
                	msg += "只见伤口马上流出了黑色的毒血！";
                	add("poison_number", -10);
                	target->apply_condition("bt_poison", target->query_condition("bt_poison") + random(20));
                }
                limbs = target->query("limbs");
                limb = limbs[random(sizeof(limbs))];
                damage = me->query_skill("hamagong", 1) + me->query_skill("baituo-shezhang", 1);
                if( target->query("neili") > me->query("neili")/3*2){
                	msg += "\n$n急中内力猛地一震，脱出蛇口，倒退了几步！\n";
                	damage += random(damage);
                	target->receive_damage("qi", damage, me);
        		target->receive_wound("qi", damage/4, me);
        		j = (int)target->query("qi")*100/(int)target->query("max_qi");
        		msg += damage_msg(damage, "抓伤")+"( $n"+eff_status_msg(j)+" )\n"; 
        		msg = replace_string( msg, "$l", limb );
                } 
                else {
                	msg += HIR"\n$n退避不及，"+ limb + "处被咬下了一大块血肉！\n"NOR;
                	damage *= 2;
                	damage += me->query_str() * 10;
                	
                	target->receive_damage("qi", damage, me);
        		target->receive_wound("qi", damage/2, me);
        		j = (int)target->query("qi")*100/(int)target->query("max_qi");
        		msg += "( $n"+eff_status_msg(j)+" )\n"; 
                } 
        }
        message_vision(msg, me, target);
        me->add("neili", -200);
        return 1;
}

