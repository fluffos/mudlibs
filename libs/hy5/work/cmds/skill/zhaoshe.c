#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object soldier;
	int zhaosheshu,yangsheshu, exp, MAX_GUARD;
        if ( me->is_busy() )
        return notify_fail("你现在正忙，无法呼唤附近的蛇。\n");
        if( !me->is_fighting() )
        return notify_fail("好象没有人要杀你！\n");
	if((int)me->query("neili")< 50)
	return notify_fail("你的内力太差了！\n");
	if((int)me->query("combat_exp")< 100000)
	return notify_fail("你的经验不够！\n");
        if( me->is_busy() )
        return notify_fail("你正忙着呢！\n");   
	zhaosheshu = (int)me->query_skill("zhaosheshu");
	yangsheshu = (int)me->query_skill("yangsheshu");
	exp = (int)me->query("combat_exp");
	if(zhaosheshu < 10 || yangsheshu < 10)
	return notify_fail("你招蛇之术和养蛇之技太差了，没有蛇过来！\n");	
	MAX_GUARD = zhaosheshu * yangsheshu / 5000 + 1;
        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("你刚招过蛇.\n");

	if( me->query_temp("max_guard") > 30 )
                return notify_fail("以你现在的能力，你已经没有能力控制更多的蛇了！\n");
	seteuid(getuid());
        me->add("neili",-50);
	soldier= new("clone/misc/jinshe");
	soldier->move(environment(me));
        soldier->invocation(me, (zhaosheshu+yangsheshu));
        soldier->set("possessed", me);
        soldier->set("combat_exp",me->query("combat_exp")/2);
        soldier->set("str",me->query("str"));
        soldier->set("dex",me->query("dex"));
        soldier->set("max_qi",me->query("max_qi"));
        soldier->set("qi",me->query("max_qi"));
        soldier->set("eff_qi",me->query("max_qi"));
        soldier->set("neili",me->query("max_qi"));
        soldier->set("max_neili",me->query("max_qi"));
        soldier->set("eff_jing",me->query("max_jing")/2);
        soldier->set("max_jing",me->query("max_jing")/2);
        soldier->set("jing",me->query("max_qi")/2);
        soldier->set_skill("unarmed",zhaosheshu);
        soldier->set_skill("parry",yangsheshu);
        soldier->set_skill("dodge",zhaosheshu);
        soldier->set("apply/attack",zhaosheshu/2);
        soldier->set("apply/defense",yangsheshu/2);
        soldier->set("apply/damage",zhaosheshu);
        soldier->set("apply/armor",yangsheshu);
        me->add_temp("max_guard",1);
//        me->remove_all_killer();
	me->apply_condition("zdizi_busy",3);
	message_vision(HIR "\n$N发出一声怪叫 ！\n" NOR, me);	
	message_vision(HIR "\n$N从附近钻了出来！\n" NOR, soldier);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：alert
 
这个指令让会用蛇的弟子呼唤所养的金蛇来保护自己。
能否招呼出金蛇，呼出金蛇水平的高低就要看自己
的水平了。
 
HELP
    );
    return 1;
}
