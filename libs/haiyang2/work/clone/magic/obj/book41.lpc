// 回城术

#include <ansi.h>
inherit ITEM;

int thunderspell(object me, object target)
{
	int	kee, damage, spells;
	string msg;
	int extra;
	int i;
	object weapon;
        int damagic;

	spells = me->query_skill("spells");
	if((int)me->query("neili")< 500)
	return notify_fail("你的法力太差了！\n");

        msg = HIC"   $N身影在$n面前消失了!  \n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp"))
        {

        msg += HIC"$n"HIC"突然发现$N不见了，只好停下了攻势!!\n"NOR;
                target->remove_all_enemy();
                me->remove_all_enemy();
		message_combatd(msg, me, target);
//		COMBAT_D->report_status(target);
        } else
        {
        msg += HIC"$n"HIC"双目一闪，识破了你的隐身术!\n"NOR;
		message_combatd(msg, me, target);
        }
me->add("neili",-150);

	return 1;
	
}
void create()
{
        set_name(HIC"隐身术卷轴"NOR, ({ "invisibe axes", "41axes" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一个魔法卷轴可以使用(spell id)上面的魔法。\n") ;

                set("unit", "个");
                set("value", 140000);
                set("zhen", 1);
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
	string 	msg;
	object	env;
	object	*inv;
	int	i;
        me = this_player();

 	if (!id(arg))
	return notify_fail("你无法使用这个卷轴!\n");

        if(me->is_busy() )
                return notify_fail("你正忙着哪。\n");
        if( me->query("combat_exp")< 500000)
        return notify_fail("你的经验太少用不了！\n");

        if (me->query("neili") < 400)
        return notify_fail("你的法力不足！\n");

        if (me->is_busy()) 
        return notify_fail("你正忙着呢!\n");

	if((int)me->query("neili")< 500)
	return notify_fail("你的法力太差了！\n");
	

        if( this_object()->query("zhen") < 1 ) {
        message_vision(HIC"\n$N"HIC"上的魔法力量用完了!  $N"HIC"消失了。\n"NOR,this_object(),me);
        destruct(this_object());
return 1;
                }

        if( !objectp(ob = present("invisibe axes", me)) )
                return notify_fail("你没有这种东西。\n");

	msg = HIC "$N"HIC"身形一闪，口中喃喃地念著咒文，\n" NOR;
       msg += HIC"$N的动作突然变的慢了下来，在天蓝色的光芒下, $N的身体慢慢变透明起来！\n"NOR;
       msg += HIC"  「隐身术」 \n"NOR;
	message_vision(msg, me,target);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( !inv[i]->is_fighting(me) ) continue;
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
	me->start_busy(3);
        if( this_object()->query("zhen") < 1 ) {
        message_vision(HIC"\n$N"HIC"上的魔法力量用完了!  $N"HIC"消失了。\n"NOR,this_object(),me);
        destruct(this_object());
return 1;
                }

        return 1;
}
