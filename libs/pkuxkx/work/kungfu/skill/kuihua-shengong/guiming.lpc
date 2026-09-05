// guiming.c  葵花宝典.归冥，日月大招
//create by yhzzyahoo@pkuxkx, 2017-4-25


#include <ansi.h>
#include <char.h>
//inherit F_SSERVER;
inherit F_CLEAN_UP;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="self" ;
}


int exert(object me, object target)
{
    int damage,cd_time,dur_time,eff1,eff2,eff;
	int xt_int,xt_dex;
    string msg;
    object weapon;


    if ( !me->query("safari_skill/riyue_kuihua") ) 
		return 0;

//    if( !target ) target = offensive_target(me);

    if ( !me->is_fighting() ) 
		return notify_fail("你只能在战斗中才能进入葵花神功的『归冥』状态。\n");
	if ( me->query("family/family_name")!="日月神教")
	{
		return notify_fail("你不是神教弟子,无法体会舍身『归冥』的状态。\n");
	}
	if(me->query("chushi/done") || me->query("betrayer"))
	{
		return notify_fail("你不是真正的神教弟子,无法体会舍身『归冥』的状态。\n");
	}

  //  if( target != me )
	//	return notify_fail("你只能对自身使用『归冥』效果。\n");
    if( (int)me->query("neili") < 500  )
		return notify_fail("你的内力不够。\n");
    if( (int)me->query_temp("kuihua.guiming") )
        return notify_fail("你已经在运功中了。\n");	
    if( (int)me->query_skill("kuihua-shengong", 1) < 500 )
        return notify_fail("你的葵花神功等级不够，无法进入归冥。\n");

	xt_int = me->query("con");
	eff1 = 50 - xt_int;
	if (me->query_skill("kuihua-shengong",1)<2000)
	{
		eff2 = (int)(40-me->query_skill("kuihua-shengong",1)/50);
	}
	else
	{
		eff2=0;
	}


	if (eff1 > eff2)
	{
		cd_time = eff1;
	}
	else
	{
		cd_time = eff2;
	}
	if (cd_time < 1)
	{
		cd_time =1;
	}
	/*if (me->query("chushi/done") || me->query("betrayer"))
	{
		cd_time*=3;
	}*/
     if( (time() - (int)me->query_temp("kuihua.guiming_start_time")) < cd_time )
                return notify_fail("你刚才归冥状态中恢复，精力尚未平复。\n");	
   	if (me->query("zyhb"))
			return notify_fail("你会左右互博，无法体验归冥状态。\n");
	if (me->query_skill("shenghuo-lingfa",1) || me->query_skill("liumai-shenjian",1))
			return notify_fail("你身怀古怪武功，无法体验归冥状态。\n");
    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("id") != "xiuhua zhen")
        return notify_fail("你右手没拿绣花针,无法进入归冥！!\n");
    msg = HIW "$N身形一黑，四周犹如处处都有$N的身影，犹如鬼魅！\n" NOR;
	xt_dex = me->query("dex");
	eff1 = (int)((me->query_skill("kuihua-shengong",1)-300)/5);
	eff2 = (xt_dex - 10)*10;
	if (eff1 > eff2)
	{
		eff = eff2;
	}
	else
	{
		eff = eff1;
	}
//	write("eff1:"+eff1+"\n");
//	write("eff2:"+eff2+"\n");
//	write("eff:"+eff+"\n");
	if (eff > 300)
		eff = 300;//最高加成到3
	if (xt_dex > 49)
		eff = 400;//身法50的特殊加成
	if (eff<0)
		eff=0;
	eff1 = xt_int * 10 - 100;
	eff2 = (int)(me->query_skill("kuihua-shengong",1)/20);
	if (eff1 > eff2)
	{
		dur_time = eff2;
	}
	else
	{
		dur_time = eff1;
	}
	if (xt_int > 49)
	{
		dur_time = 1000;
	}
	if (me->query("chushi/done") || me->query("betrayer"))
	{
		dur_time/=2;
	}
	if (dur_time < 10)
	{
		dur_time = 10;
	}
//	dur_time = 30;
    me->add("neili", -250-random(250));
	me->set_temp("kuihua.guiming_start_time",time());
    me->set_temp("active_buffer/kuihua.guiming/name", "归冥");                  //buff名称
    me->set_temp("active_buffer/kuihua.guiming/last_time", time() + dur_time );               //持续时间
	me->set_temp("active_buffer/kuihua.guiming/effect1", "攻击速度+"+eff+"%");   //效果描述1
	me->set_temp("kuihua.guiming",1);
	me->add_temp("apply/attack_speed", eff);
	call_out("check_guiming",4,me,eff);
	call_out("remove_gm_eff", dur_time, me, eff); 
    message_vision(msg, me, target);
    me->start_busy(2);
    return 1;
}

void check_guiming(object me,int count)
{	mapping sk_map=([]);
    /*object weapon;
	if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "blade")
	{
		call_out("remove_dl_eff", 1, me, count); 
		return;
	}*/
	sk_map = me->query_skill_map();
	if (sk_map["sword"]!="pixie-jian")
	{
		call_out("remove_gm_eff", 1, me, count);
		return;
	}
	if (me->query_temp("kuihua.guiming"))
	{
		call_out("check_guiming",4,me,count);
	}
}



void remove_gm_eff(object me, int amount)
{	
    if( me->query_temp("kuihua.guiming")) 
	{
		me->delete_temp("kuihua.guiming");
		me->delete_temp("apply/attack_speed", amount);
        me->delete_temp("active_buffer/kuihua.guiming");
        message_vision(CYN "$N从归冥状态中退出，攻势立刻缓了下来。\n"NOR,me);
	}
//	remove_call_out();
}


