//by caiji@SJ

#include <ansi.h>
#include <command.h>

inherit F_SSERVER;

mapping default_dirs = ([
        "north":        "北",
        "south":        "南",
        "east":         "东",
        "west":         "西",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
        "northeast":    "东北方",
        "northwest":    "西北方",
        "southeast":    "东南方",
        "southwest":    "西南方",
        "up":           "上面",
        "down":         "下面",
        "out":          "外面",
        "enter":        "里面",
]);

int exert(object me, object target)
{
	object env, obj;
	int cost=50+random(100), i, n;
	int success, ap, dp,bool,bool2;
	string msg;
	string *dirs, target_dir, dest;
	mapping exit;

	seteuid(getuid());
	
	bool=(me->query("env/xiaoguo")) ? 1:0;

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要如何施展「毒雾」？\n");
                
        bool2=(userp(target))?me->query_skill("poison",1):0;
        
        if( !objectp(target) || target->query("id") == "mu ren" )
                return notify_fail("对这种东西你要要用「毒雾」？\n");
        
        if( !living(target) || ! target->query("can_speak"))
                return notify_fail("对这种东西你要要用「毒雾」？\n");

	if( !me->is_fighting(target))
		return notify_fail("你没有和"+target->query("name")+"进行战斗，不能施展「毒雾」！\n");

	if(me->is_busy())
		return notify_fail("你现在正自顾不暇，哪有时间施展「毒雾」！\n");

	if((int)me->query_skill("huagong-dafa") < 60 || (int)me->query_skill("force", 1) < 60)
		return notify_fail("你的内功等级不够，不能施展「毒雾」。\n");

        if( me->query("neili") < cost )
                return notify_fail("你的内力不够。\n");

	if((int)me->query("qi") < 50 )
                return notify_fail("你的气血太少，体内没有足够毒素散出「毒雾」！\n");

	env = environment(me);
	exit = env->query("exits");

	if( !mapp(exit)){
	if(bool) return notify_fail("这里没有出口，你想将"+target->query("name")+"引到那儿去？\n");
	else return notify_fail("这里没有出口，你想逃到那儿去？\n");
	}

	dirs = keys(exit);
	n = sizeof(exit);
	i = random(n);
	dest = exit[dirs[i]];

	if( !undefinedp(default_dirs[dirs[i]]) )
                target_dir = default_dirs[dirs[i]];
        else
                target_dir = dirs[i];

	if(!(obj = load_object(dest)) )
		return notify_fail("无法走！\n");

	me->add("neili", -cost);
	me->receive_damage("qi", 10);

	msg = HIB "$N挥了挥衣袖，一阵风吹过，这里瞬间布满了毒雾。\n" NOR;

	success = 1;
        ap = me->query_skill("force") + me->query_skill("huagong-dafa") + me->query_kar()+bool2;
        dp = me->query_skill("force") + me->query_skill("dodge") + target->query_kar();   
        ap *= me->query("combat_exp")*120/100000;
        dp *= target->query("combat_exp")/1000;    

        if( random(ap) < dp/3 ) success = 0;

	message_vision(msg, me, target);

	if(success==1) {
		if(bool){
		     if(!GO_CMD->main(target, dirs[i], 0)) success=0;
		}
		else if(!GO_CMD->main(me, dirs[i], 0)) success=0;// failed to go.
	}

	if(success == 1)
		if(bool){
			msg = HIC "烟雾中只见一条人影向" + target_dir + "逃去。\n" NOR;
                        msg += HIY +target->name()+"向" + target_dir + "追去。\n" NOR;
                }
                else
                msg = HIR "$N散出的「毒雾」好象对$n不起什么作用。\n" NOR;
        
	//add by caiji for add other function next time
	else {
//		if(bool)
		msg = HIR "$N散出的「毒雾」好象对$n不起什么作用。\n" NOR;
//		else msg = HIC "烟雾中只见一条人影向" + target_dir + "逃去。\n" NOR;
	}
	message_vision(msg, me, target);

	if(success == 1){
		if(bool){
		msg = HIR "只见"+target->name()+"跑了进来，四处张望，却什么都没发现。\n" NOR;
               	message( "vision", msg, environment(target), ({target}));
		tell_object(target,"你急急忙忙跑了过来，四处张望，却什么都没发现。\n");
		target->start_busy(1+random(2));
//		me->start_busy(1);
		return 1;
        	}else{
	        msg = HIR "只见"+me->name()+"气喘吁吁的跑了进来。\n" NOR;
               	message( "vision", msg, environment(me), ({me}));
		tell_object(me,"你借着「毒雾」的隐蔽，急急忙忙跑了过来，。\n");
		target->start_busy(1+random(2));
               	return 1;}
        }
        else {
//		me->start_busy(1);
		return 1;
	}
}
