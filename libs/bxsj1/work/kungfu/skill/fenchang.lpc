// fanchang.c 梵唱

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;


int exert(object me, object target)
{
	object obj, weapon;
	int xf, sp, ap;  

	if( !target ) target = offensive_target(me);

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("id") != "jingang chu")
		return notify_fail("你未执法器，不能凝神梵唱。\n");

	if ((!objectp(obj = present("shisan longxiang", me)) ) || (!obj->query("equipped") )) 
		return notify_fail("你未着法袍，不能凝神梵唱。\n");
        
	if( !objectp(target) || target == me)
		return notify_fail("你想要唱给谁听？\n");

	if( !target->is_character() || target->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if( target->query("race") != "人类")
		return notify_fail(target->query("name") + "听不懂你的咒语！\n");

	if( (int)me->query("neili") < 5000 )
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_skill("xiangfu-lun",1) < 300 )
		return notify_fail("你的降伏法功力不够！\n");

	if( (int)me->query_skill("huanxi-chan", 1) < 200 )
		return notify_fail("你的密宗心法功力不够！\n");

	if( (int)me->query_skill("longxiang-boruo", 1) < 300 )
		return notify_fail("你的龙象般若功功力不够！\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("在这里不能唱。\n");
        
	if( target->query_temp("cursed", 1) || target->query_temp("block_msg/all", 1))
		return notify_fail("此人已被降伏！\n");

	if( (int)me->query_temp("curser") )
		return notify_fail("你降伏着另一各人！\n");

	if ( me->query("no_pk") && userp(target))
		return notify_fail("你已经退出江湖了。\n");

	if ( target->query("no_pk"))
		return notify_fail(target->name(1)+ "已经退出江湖了。\n");

	me->add("neili", - 350);
	me->receive_damage("jingli", 100);
	me->start_exert(3, "梵唱");

	message_vision(HIB "$N摇头晃脑，口中背诵大乘佛经，夹杂以密宗六字咒。声音阴阳顿挫，有起有伏，暗含音律。\n" NOR, me);
	tell_object(target,  "你觉得那密咒比鬼哭还难听，脑袋里一团絮乱，眼前一堆鬼影在乱跳，胸气阻塞，四肢无力，混然欲睡。\n");
                
	xf = (me->query_skill("xiangfu-lun", 1) + me->query_skill("huanxi-chan", 1));
	ap = target->query_skill("parry") + target->query_skill("force") + target->query("con")  + target->query("int") ; 
	sp = me->query_skill("force") + xf * 2;
	sp *= me->query("combat_exp")/1000;
	ap *= target->query("combat_exp")/1000;

	if( random(sp) > ap/2 && !target->query("job_npc")){
		tell_object(target, HIR "你只觉得眼前的一切离你慢慢远去，你的魂魄似要出窍，不再由你主宰。\n" NOR);
		message_vision("你看见" +target->query("name") +"突然开始两眼发直，呆呆地望着前方。\n", me);
		target->remove_all_killer();
		target->set_temp("cursed", 1);
		target->set_temp("block_msg/all", 1);
		me->set_temp("curser", 1);
		if((int)target->query("combat_exp") > me->query("combat_exp")/2 && userp(target)){
			me->improve_skill("force", me->query("int"));
		}
		call_out("del_sung", me->query_skill("huanxi-chan", 1)/5, me, target);
		return 1;
	}
	else {
		me->start_busy(random(7));
		if( !target->is_killing(me)) target->kill_ob(me);      
		return 1;
	}
}

void del_sung(object me, object target)
{
	if ( me && me->query_temp("curser") )
		me->delete_temp("curser");
	if (!target) return;
	if (target->query_temp("cursed", 1))
		target->set_temp("cursed", 0);
	if (target->query_temp("block_msg/all", 1))
		target->set_temp("block_msg/all", 0);
	if (target->query_leader() ) 
		target->set_leader(0);  
	message_vision("$N慢慢地清醒过来，魂魄又回到了自己身体上。\n", target);
}

string exert_name(){ return HIB"梵唱"NOR; }

int help(object me)
{
        write(HIB"\n龙象般若功之「梵唱」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 5000 以上；
                龙象般若功等级 300 以上；
                金刚降伏轮等级 300 以上；
                欢喜禅等级 200 以上；
                必须装备金刚降魔杵为兵器；
                穿着十三龙象袈裟。

HELP
        );
        return 1;
}
