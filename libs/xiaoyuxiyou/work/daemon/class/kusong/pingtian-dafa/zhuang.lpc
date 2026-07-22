#include <ansi.h>
#include <combat.h>
inherit SSERVER;
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
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":           "上",
        "down":         "下",
        "out":          "外",
        "enter":        "里",
]);



int cast(object me, object target)
{
	string msg,succ_msg,succ_msg2;
        int damage,fail=0;
	object env,obj;
	string *dirs, target_dir, dest,tmp;
	mapping exit;
	
	if( me->query_level()<35 )
		return notify_fail("你的人物等级不够。\n");
        if((int)me->query_skill("pingtian-dafa", 1) < 350 )
                return notify_fail("你的平天大法火候不够，哪里施展的出！\n");
	if(me->query("family/family_name")!="火云洞")
  		return notify_fail("只有火云洞门人才可以用！\n");
        if((int)me->query("mana") < 500 )
		return notify_fail("你的法力不够，恐怕没有什么用！\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("你现在神智不清，别把自己撞伤了！\n");
  		
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
                return notify_fail("你要现真身去撞谁？\n");

	env=environment(me);
	exit=env->query("exits");
	if( exit && mapp(exit) )
	{
		dirs = keys(exit);
		if( dirs && arrayp(dirs) )
		{
			target_dir = dirs[random(sizeof(dirs))];
			if( target_dir )
			{
				if( undefinedp(default_dirs[target_dir]) )
					tmp = target_dir;
				else	tmp = default_dirs[target_dir];	
				if( env->valid_leave(target,target_dir) )
				{	
					dest = exit[target_dir];
					if( dest )
					{	
						if( obj=load_object(dest) )
						{
							fail = 1;
							succ_msg2 = HIC "$n"HIC"在空中手舞足蹈，被撞的径直朝"+tmp+"飞去！\n"NOR;
						}	
					}
				}	
			}	
		}	
	}

        me->add("mana", -300);
        me->receive_damage("sen", 200);
        if( !target->is_killing(me->query("id")) )
        	target->kill_ob(me);
        msg = HIC "\n$N"HIC"将身一摇，化作一头巨牛，猛然退后两步，一低头，呼地就向$n"HIC"撞去！\n" NOR;
        succ_msg = HIR"只见$n"HIR"惨叫一声，象捆稻草般的飞了过来！\n"NOR;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,msg,succ_msg);
	me->set_temp("pfm_msg",0);

	if( damage<1 )
		message_combatd(HIC"但是被$n"HIC"躲开了。\n"NOR,me,target);
	else
	{
		if( fail>0 && obj )
		{
			message_combatd(succ_msg2,me,target);
			if( target->move(obj) )
				message("vision",HIR"\n只见"+target->name()+"象捆稻草般的飞了过来！\n" NOR, environment(target),({target}));
		}
	}		
	me->start_busy(3);
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：撞字咒
        法术所属：平天大法
        法术效果：化身巨牛撞击对方已造成法术伤害
                  撞击成功后会可能将对方撞离此区域 
		  自身busy 3 秒
        法术条件：
                  火云洞弟子
        	  人物等级35级
                  法力500点，消耗300点
                  精神300点，消耗200点
                  平天大法 350 级
                  
STR;
        me->start_more(str);
        return 1;
}