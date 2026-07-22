// 白金丝手套
// by snowman@SJ 13/06/99

#include <ansi.h>
#include <armor.h>
inherit F_UNIQUE;
inherit HANDS;

void create()
{
        set_name(HIW"白金丝手套"NOR, ({"baijin shoutao", "shoutao", "gloves"}));
        set_weight(600);
	if (clonep())
		set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("unique", 1);
                set("long", "这是一双以极细的白金丝织成的手套，刀枪不入，是古墓派四绝之一。\n");
                set("value", 2000000);
                set("material", "gold");
                set("armor_prop/parry", 5);
                set("treasure", 1);
                set("female_only", 1);
                set("wear_msg", HIW "$N将白金丝手套拿出，轻轻抖开，戴在手上。\n" NOR);
		set("remove_msg", HIW "只见$N在双手手指上轻轻拉扯，将白金丝手套褪了下来。\n" NOR);
        }
        setup();
}

void init()
{
        add_action("do_zhua","zhua");
        add_action("do_zhua","抓");
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
	object me, target, weapon;
        string msg;

        me = this_player();

        if (str && !objectp(target = present(str, environment(me)))) 
                  return notify_fail("这里没有这个人。\n");
        
        if( !target ) target = offensive_target(me);
        
        if( !target
         || !target->is_character()
         || !living(target)
         || !me->is_fighting(target) )
                return notify_fail("你只能在战斗中的抓对手的兵器用。\n");

        if (me->is_busy()) 
                return notify_fail("你现在正忙着呢。\n");

        if( me->query_temp("weapon") )
		return notify_fail("你如果想空手入白刃，必须先放下手中的武器！\n");
	
        if( !this_object()->query("equipped") )
		return notify_fail("你是想拧着白金丝手套然后真的空手入白刃？佩服！佩服！\n");
		
        if (me->query_skill_prepared("cuff") != "meinu-quanfa" ||
            me->query_skill_mapped("cuff") != "meinu-quanfa" ||
            me->query_skill_mapped("force") != "yunu-xinjing")
                return notify_fail("没有熟练的玉女心经和美女拳法的相互配合，你根本无法使用白金丝手套！\n"); 
       
        if( (int)me->query_skill("yunu-xinjing",1) < 150 )
                return notify_fail("你的玉女心经功力不够，使用不了白金丝手套！\n");
        if( (int)me->query_skill("meinu-quanfa",1) < 150 )
                return notify_fail("你的美女拳法功力不够，使用不了白金丝手套！\n");

        if( (int)me->query_dex() < 32 )
                return notify_fail("你虽然戴着白金丝手套，但这空手入白刃的功夫却是需要极高的身法的！\n");

        if( (int)me->query("jingli") < 500 )
                return notify_fail("你目前精力涣散，还是先注意注意自己吧！\n");
       
        if( (int)me->query("neili") < 800 )
                return notify_fail("你目前内力不凝，还是先注意注意自己吧！\n");

        if(me->query("combat_exp") < (int)target->query("combat_exp")/2 )
                return notify_fail("哎呦，对方比你高明不知多少呢，你找死啊？\n"); 

        if(!objectp(weapon = target->query_temp("weapon")))
                return notify_fail("这...对方双手空空，你抓什么呢？\n"); 

        target->add_temp("ynxj_shoutao", 1);
        
        message_vision(HIW "\n$N"HIW"突地飘身而上，亮出戴于双手的白金丝手套，抓拿点拍，竟无视$n"HIW"手中武器！\n" NOR, me, target);
        if( (int)me->query("combat_exp") < (int)target->query("combat_exp")/2 ){
        	msg = "不料$n胸有成竹，哈哈一笑将手中"+weapon->name()+"横拍，正好打在$N手肘大穴之上，疼得$P半天抬不起手臂来！\n\n";
        	me->start_busy(3);
        	}
        else if(random(me->query("combat_exp")) < (int)target->query("combat_exp")/2 ||
                random(target->query_temp("ynxj_shoutao")) > 2){
                msg = "$n大感吃惊，急忙抽身后退，脱开了$N的手网，两眼瞪地比铜铃还大！\n\n" NOR;
                me->start_busy(1);
                if(!target->is_busy())
                        target->start_busy(1);
                } 
        else {
                me->start_busy(2);
                if(!target->is_busy())
                        target->start_busy(2);
                msg = "$p怎想到$N的手套虽然轻柔软薄，却是刀枪不入，"+weapon->name()+"被$N蓦地抓住，";
                if( target->query("neili") > me->query("neili")/3*2){
                	msg += "\n$n急中生智猛地一抽，总算没被$P抓去，但却噔噔噔倒退了数步！\n\n";
                	target->receive_damage("jingli", me->query_skill("yunu-xinjing",1)*2, me);
                	} 
                else if( weapon->query("rigidity") <= 1 
                        && target->query("neili") < me->query("neili")/2){
                	msg += "随即以巧劲折断！\n\n";
                	weapon->broken("折断的");
	        }
		else {
			msg += "一把夺了过来！\n\n";
			weapon->unequip();
		        weapon->move(me);
		        target->reset_action();
                        }
                }
        message_vision(msg, me, target);
        me->add("neili", -200);
        return 1;
}
