#include <ansi.h>
#include <combat.h>
inherit SSERVER;
inherit F_CLEAN_UP;

void remove_effect(object me)
{
	if( me )
	{
		me->delete_temp("pfm_action");
		me->delete_temp("sea_wuliang");
		me->set_temp("sea_wuliang_end",time());
		tell_object(me,HIR"你内气运行一周天，足底涌泉穴的热感减减消失。\n"NOR);
	}
}

varargs void dhwl(object me,object target,object weapon,int damage)
{
	string str,*msg;
	
        if( !me ) 
                return;
	if( !weapon || weapon!=me->query_temp("weapon") )
		weapon = me->query_temp("weapon");
	if( !weapon 
    	 || ( weapon->query("skill_type") != "fork" 
    	   && weapon->query("use_apply_skill") != "fork" ) )
	{
		remove_effect(me);
		return;
	}                
	if( !target )  target = offensive_target(me);
	if( !target
 	 || !target->is_character()
 	 || target->is_corpse()
 	 || target==me 
 	 || !me->is_fighting(target) 
 	 || !living(me) )
		return; 
	me->add_temp("sea_wuliang",-1);		
	if( me->query_temp("sea_wuliang")<=0 )
	{
		remove_effect(me);
		return;
	}
	if( time()<me->query_temp("last_pfm_action")+2 )
		return;
	me->set_temp("last_pfm_action",time());		
	msg = ({
		HIG"$N"HIG"运起龙神心法，转瞬间突然周身骨骼格格做响，面上浮现出阵阵青气。",
		HIG"$N"HIG"面上的青气渐渐淡了，目中却精光大盛，脚心涌泉穴热力滚滚，直往上冲。",
		HIG"$N"HIG"收敛心神，把脚底热气运至膝间跳环，但觉内力运转间身轻无比。",
		HIG"$N"HIG"默念龙神心法，四肢不动而意在脾，人虽未动，却只觉内力沉于丹田，力量倍增。",
		HIG"$N"HIG"将沉于丹田之力带行全身，身上啪啪连响，运转自如直冲任督，忍不住纵声长啸。",
		HIG"$N"HIG"想起龙神心法所言：舌不吟而神在心。连忙收声运气，但觉得心灵中一片空灵。",
		HIG"$N"HIG"屏住气息，运转内力于肺间。呼吸均匀悠长，以然达到了鼻不香而魄在肺的境界。",
		HIG"$N"HIG"心平气静，对外界的嘈杂亦不听不想；耳不闻而精在肾，沉身运气，内力更高了一层。",
		HIG"$N"HIG"突觉内力运转周身无法突破，不禁闭目沉思，就在闭目的一瞬间意识到眼不视而魂在肝的道理。",
		HIG"$N"HIG"运气一周天，浑身充满强霸的力道。突然间脑际灵光一闪，气化为神，神化为虚直冲头顶。",
    	});
  	str = "\n"+msg[random(sizeof(msg))]+"\n"NOR;
  	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_QUICK,str);
} 

int perform(object me, object target)
{
	int p;
        object weapon;

	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");
        if( me->query("family/family_name") != "东海龙宫" )
                return notify_fail("「大海无量」是龙宫不传之密！\n"); 
	if((string)me->query_skill_mapped("force")!="dragonforce")
                return notify_fail("「大海无量」必须以龙神心功为底子。\n");
	if( time()<me->query_temp("sea_wuliang_end")+6 )
		return notify_fail("这招不能频繁使用。\n");
	if( me->query_temp("sea_wuliang")>0 )
		return notify_fail("你现在已经「大海无量」了。\n");
	if( me->query_skill("fengbo-cha",1)<200 ) 
        	return notify_fail("你的风波十二叉还不够纯熟！\n");
	if( me->query_skill("dragonforce",1)<200 ) 
        	return notify_fail("你的龙神心法还不够纯熟！\n");
	if( (int)me->query_skill("dragonstep", 1) < 200 ) 
        	return notify_fail("你的修为不够深，还使不出这一招！\n");
	if( me->query("force")<500 )
        	return notify_fail("你的内力不足，无法照路数舞叉。\n");
	if( me->query("kee")<300 )
        	return notify_fail("你的气血不足，无法照路数舞叉。\n");			
        weapon = me->query_temp("weapon");
        if( !weapon 
	 || (weapon->query("skill_type")!="fork"
	  && weapon->query("use_apply_skill")!="fork") )
		return notify_fail("没叉你怎么舞？\n");
	p = me->query_skill("fork")/60;
	p = p/2+random(p/2);
	message_vision(HIC"$N"HIC"把内功心法在心中默念一遍，一股热气从足底涌泉穴慢慢升起。。。\n"NOR,me,target);
	me->add("force",-200);
	me->set_temp("sea_wuliang",p);
	me->set_temp("pfm_action","lg_dhwl");
        return 1;
}

int help(object me)
{
string str;     
if( !me )      return 0;
str = @LONG
        外功名称：大海无量
        外功所属：风波十二叉
        外功效果：一定时期内使自身处于大海无量状态
        	  此状态下，战斗中会出现追击
        	  不支持其他类型的武器	
                  状态结束后冷却6秒
        外功条件：
                  龙宫弟子
        	  人物等级20级	
                  内力500点，消耗200点，每次「破甲」消耗50点
                  基本内功200级并激发龙神心法
                  风波十二叉200级并激发

LONG;
me->start_more(str);
return 1;
}

void remove()
{
	int i;
	object me,*usr = users();
	if( i=sizeof(usr)>0 )
	{
		while(i--)
		{
			if( !usr[i] || !environment(usr[i])
			 || !objectp(usr[i]) )
				continue;
			if( usr[i]->query_temp("sea_wuliang") )
			{
				me = usr[i];
				me->delete_temp("pfm_action");
				me->delete_temp("sea_wuliang");
				me->set_temp("sea_wuliang_end",time());
				tell_object(me,HIR"你内气运行一周天，足底涌泉穴的热感减减消失。\n"NOR);
			}
		}
	}
}