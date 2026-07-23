// 寒冰弹卷轴

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
        set_name(HIW"寒冰弹卷轴"NOR, ({ "wball axes", "22axes" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一个魔法卷轴可以使用(spell id)上面的魔法。\n") ;

                set("unit", "个");
                set("value", 140000);
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
        if( !arg ) return notify_fail("你想对谁使用寒冰弹卷轴？\n");

      if( !target ) target = offensive_target(me);

      if( !target || !target->is_character() || !me->is_fighting(target) )
              return notify_fail("寒冰弹卷轴只能对战斗中的对手使用。\n");

        if( !target->is_character() || target->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

        if( me->query("combat_exp")< 500000)
        return notify_fail("你的经验太少用不了！\n");


	if((int)me->query_skill("magic-water",1))
damage = (int)me->query_skill("magic-water", 1);
else damage = 200+random(500);
if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
        if(me->is_busy() )
                return notify_fail("你正忙着哪。\n");

        if( this_object()->query("zhen") < 1 ) {
        message_vision(HIW"\n$N"HIW"上的魔法力量用完了!  $N"HIW"消失了。\n"NOR,this_object(),target);
        destruct(this_object());
return 1;
                }

        if( !objectp(ob = present("wball axes", me)) )
                return notify_fail("你没有这种东西。\n");

        message_vision(HIW"\n$N"HIW"突然发光  寒冰弹卷轴!!  一个寒冰弹打向$n。\n"NOR,this_object(),target);
        this_object()->add("zhen", -1);
        msg = HIW"$N"HIW"扬起了手,不知不觉中已对准了$n"HIW"，$n"HIW"看到漫天寒气，抽身后跃，\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
       if ((int)target->query("magicgift")==2)
{
damagic=100+damage;
                target->receive_damage("qi", damagic);
damagic=50+damage;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
}
else  if ((int)target->query("magicgift")==1)
{
damagic=500+damage*4;
                target->receive_damage("qi", damagic);
damagic=500+damage*2;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
}
else 
{
damagic=250+damage;
target->receive_damage("qi", 250+damage*2);
target->receive_wound("qi", 250+damage);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
}

        msg += HIW"$n"HIW"根本没法躲避，一个巨大的寒冰弹,端端正\n"NOR;
        msg += HIW"正打在$n"HIW"的身上！$n"HIW"全身都冻住了!!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIW"可是$p"HIW"轻轻一笑，侧身右转.\n"NOR;
        msg += HIW"寒冰弹在$p"HIW"身侧划过，毫发无伤。\n"NOR;
		message_combatd(msg, me, target);
        }
if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);
                me->start_busy(2);
        return 1;
}
