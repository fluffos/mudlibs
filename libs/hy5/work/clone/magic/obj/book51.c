// 暗黑核融术卷轴

#include <ansi.h>
inherit ITEM;
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

void create()
{
        set_name(HIR"暗黑核融术卷轴"NOR, ({ "nuclea axes", "51axes" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一个魔法卷轴可以使用(spell id)上面的魔法。\n") ;

                set("unit", "个");
                set("value", 150000);
                set("zhen", 3);
        }
        setup();
}

void init()
{
        add_action("do_shot","spell");
}

int do_shot(string arg)
{
        object me,ob,target;
        int myskill , tgskill;
        int mylev ,damage;
        int damagic;
        string msg;
        object weapon;
        me = this_player();

 	if (!id(arg))
	return notify_fail("你无法使用这个卷轴!\n");
        if( !arg ) return notify_fail("你想对谁使用暗黑核融术卷轴？\n");

      if( !target ) target = offensive_target(me);

      if( !target || !target->is_character() || !me->is_fighting(target) )
              return notify_fail("暗黑核融术卷轴只能对战斗中的对手使用。\n");

        if( !target->is_character() || target->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

        if( me->query("combat_exp")< 500000)
        return notify_fail("你的经验太少用不了！\n");


	if((int)me->query_skill("magic-dark",1))
damage = (int)me->query_skill("magic-dark", 1);
else damage = 100+random(300);

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
        if(me->is_busy() )
                return notify_fail("你正忙着哪。\n");

        if( this_object()->query("zhen") < 1 ) {
        message_vision(HIR"\n$N"HIR"上的魔法力量用完了!  $N"HIR"消失了。\n"NOR,this_object(),target);
        destruct(this_object());
return 1;
                }

        if( !objectp(ob = present("nuclea axes", me)) )
                return notify_fail("你没有这种东西。\n");

if (target->is_busy())
return notify_fail("现在正是用攻击敌人的时候啊！\n");
                me->start_busy(1);
        message_vision(HIR"\n$N"HIR"突然发光  暗黑核融术卷轴!!  \n"NOR,this_object(),target);
        this_object()->add("zhen", -1);
        msg = RED"$N"RED"大叫一声  暗黑核融术!!  ,$n"HIR"附近发生了核爆！\n"NOR;
       if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
//对暗属性目标无作用
       if ((int)target->query("magicgift")==5)
{
target->start_busy(2);
damagic=damage;
                target->receive_damage("qi", damagic);
damagic=damage;
                target->receive_wound("qi", damagic);
}
//对光属性目标强大
else  if ((int)target->query("magicgift")==6)
{
target->start_busy(5);
damagic=damage*2;
                target->receive_damage("qi", damagic);
damagic=damage;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=damage;
target->receive_damage("qi", damage);
target->receive_wound("qi", damage);
target->start_busy(3);
}

        msg += HIR"$n"HIR"大吃一惊，给炸上了天!!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIY"$n"HIY"飞身跃起，逃过了一难。\n"NOR;
		message_combatd(msg, me, target);
                me->start_busy(3);
        }
if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);
        return 1;
}
