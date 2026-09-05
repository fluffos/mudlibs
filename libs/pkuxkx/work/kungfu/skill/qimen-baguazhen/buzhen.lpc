// guiming.c  奇门八卦阵，桃花岛大招
//create by yhzzyahoo@pkuxkx, 2017-5-18
//调整下参数，加强！！！by yhzzyahoo@2018-5-8


#include <ansi.h>
#include <char.h>
inherit F_SSERVER;
//inherit F_CLEAN_UP;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="self" ;
}


int perform(object me, object target)
{
    int first_time,cd_time,dur_time,eff1_time,eff;
	int xt_int;
    string msg;
    object env;


    if ( !me->query("safari_skill/thd_buzhen") ) 
		return 0;

//    if( !target ) target = offensive_target(me);

    if ( !me->is_fighting() ) 
		return notify_fail("你只能在战斗中才能布阵。\n");
	if ( me->query("family/family_name")!="桃花岛")
	{
		return notify_fail("你不是桃花岛弟子，无法布下如此复杂的阵式。\n");
	}
	env=environment(me);
	if(env->query("no_buzhen"))
	{
		return notify_fail("在这种地方你没法布阵。\n");
	}

  //  if( target != me )
	//	return notify_fail("你只能对自身使用『归冥』效果。\n");
    if( (int)me->query("neili") < 800  )
		return notify_fail("你的内力不够。\n");
    if( (int)me->query_temp("active_buffer/qimen-baguazhen.buzhen") || (int)me->query_temp("thd/maze"))
        return notify_fail("你周围已经布满了阵法，无法再布下另外一座阵式了。\n");	
    if( (int)me->query_skill("bihai-shengong", 1) < 500 || (int)me->query_skill("qimen-baguazhen",1) < 400 
		||(int)me->query_skill("qimen-bagua",1) < 400)
  //  if( (int)me->query_skill("bihai-shengong", 1) < 500 || (int)me->query_skill("qimen-baguazhen",1) < 400 )

        return notify_fail("你的功夫等级不够，无法布下如此复杂的阵式。\n");
     if( (time() < (int)me->query_temp("qmbgz.buzhen_cdtime")) )
                return notify_fail("你距离上次布阵时间太短，精力尚未平复。\n");	
	 if (me->query("chushi/done") || me->query("betrayer"))
	{
		 eff = 1;
	}
	else
	{
		eff = 0;
	}

	if (me->query_skill("qimen-baguazhen",1) > 800)
	{
//		first_time = 3;		
		first_time = 2;		

	}
	else
	{
//		first_time = 11 - (int)(me->query_skill("qimen-baguazhen",1)/100);
		first_time = 10 - (int)(me->query_skill("qimen-baguazhen",1)/100);
	}
	//出师判师启动时间+1秒；
	first_time += eff;
	xt_int = me->query("int");
	if (xt_int > 25)
	{
		dur_time = xt_int - 10;
	}
	else
	{
		dur_time = 15;
	}
	if (dur_time > 35)
	{
		dur_time = 35;
	}
	
	if (me->query_skill("bihai-shengong",1)<1800)
	{
		cd_time = 120 - (int)(me->query_skill("bihai-shengong",1)/30);	
	}
	else
	{
		cd_time = 60;
	}
	//调试
//	cd_time = 35;	eff1_time = 4;
	//出师判师加3秒阵法发动时间
//	eff1_time = 4+(eff*3);
	eff1_time = 3+(eff*3);
    msg = HIW "$N身形连动，手连连挥动，扔出了一把小旗，四面八方到处都是！\n" NOR;
//	write("开始布阵,时间"+time()+",首次时间："+first_time+",间隔时间："+eff1_time+"\n");
//    me->add("neili", -450-random(350));
    me->add("neili", -350-random(300));
	me->set_temp("qmbgz.buzhen_cdtime",time()+cd_time);

	me->delete_temp("qmbgz.huoxin_done");//清理掉标志位
	me->delete_temp("qmbgz.shangshen_done");


	call_out("first_start",first_time,me,target,dur_time,eff1_time);
	call_out("remove_buzhen", dur_time+first_time, me, target); 
    message_vision(msg, me, target);
    return 1;
}

void first_start(object me,object target,int dur_time,int buff_time)
{    string msg;

//	write("第一转时间"+time()+",下一转时间间隔："+buff_time+"\n");
    if( !target ) target = offensive_target(me);

    if ( me->is_fighting() ) 
	{
		msg = HIW "$N越转越快，在各小旗中间穿来穿去，小旗渐渐竟然看不清楚起来！\n" NOR;
		me->set_temp("active_buffer/qimen-baguazhen.buzhen/name", "奇门八卦阵");                  //buff名称
		me->set_temp("active_buffer/qimen-baguazhen.buzhen/last_time", time() + dur_time );               //持续时间
		me->set_temp("active_buffer/qimen-baguazhen.buzhen/effect1", "目前奇门八卦阵处于第一转");   //效果描述1
		me->set_temp("active_buffer/qimen-baguazhen.buzhen/cengshu",1);
		if (me->query("safari_skill/thd_huoxin"))
		{
		if( F_KUNGFU->hit_rate( me->query_skill("qimen-baguazhen",1)+me->query_skill("qimen-bagua",1), target->query_skill("dodge",1), 6, me, target) )
			{
				if (!target->is_busy())
				{
					msg +=HIR "$p"HIR"来不及反应，已被阵形卷入深处。\n" NOR;
					F_KUNGFU->hit_busy( "confuse", buff_time, target );
				}
			}
		}
		message_vision(msg, me, target);
		call_out("buzhen_buff_add",buff_time,me,target,buff_time);
	}
	else
	{
		msg = HIW "周边的小旗突然变得清晰起来！\n" NOR;
		message_vision(msg, me, target);
		me->delete_temp("active_buffer/qimen-baguazhen.buzhen");
		remove_call_out("remove_buzhen");
	}
	//return 1;
}


void buzhen_buff_add(object me,object target,int buff_time)
{	string msg;
	if (!me->query_temp("active_buffer/qimen-baguazhen.buzhen"))
	{
		return notify_fail("小旗破碎，阵形顿时无影无踪了。\n");
	}
    if( !target ) target = offensive_target(me);

    if ( me->is_fighting() && me->query_temp("active_buffer/qimen-baguazhen.buzhen/cengshu") < 8) 
	{
		me->add_temp("active_buffer/qimen-baguazhen.buzhen/cengshu",1);
	//	write("目前时间："+time()+",第"+me->query_temp("active_buffer/qimen-baguazhen.buzhen/cengshu")+"转\n");

		msg = HIW "$N越转越快，将阵式压缩的更加紧了！\n" NOR;
		me->set_temp("active_buffer/qimen-baguazhen.buzhen/effect1", 
			"目前奇门八卦阵处于第"+me->query_temp("active_buffer/qimen-baguazhen.buzhen/cengshu")+"转");   //效果描述1
		if (me->query("safari_skill/thd_huoxin"))
		{
		if( F_KUNGFU->hit_rate( me->query_skill("qimen-baguazhen",1)+me->query_skill("qimen-bagua",1), target->query_skill("dodge",1), 5, me, target) )
			{
				if (target->query_busy() < 2)
				{
					msg +=HIR "$p"HIR"来不及反应，已被阵形卷入深处。\n" NOR;
					F_KUNGFU->hit_busy( "confuse", buff_time, target );
				}
			}
		}

		me->delete_temp("qmbgz.huoxin_done");
		me->delete_temp("qmbgz.shangshen_done");
		message_vision(msg, me, target);
		call_out("buzhen_buff_add",buff_time,me,target,buff_time);
	}
	else
	{
		msg = HIW "周边的小旗突然变得清晰起来！\n" NOR;
		message_vision(msg, me, target);
		me->delete_temp("active_buffer/qimen-baguazhen.buzhen");
		remove_call_out("remove_buzhen");
	}
//	return 1;
}



void remove_buzhen(object me, object target)
{	    string msg;
//	write("结束时间"+time()+"\n");
    if( !target ) target = offensive_target(me);
	remove_call_out("buzhen_buff_add");
    msg = HIW "$N布置在周围的小旗渐渐又清晰了起来！\n" NOR;
	me->delete_temp("active_buffer/qimen-baguazhen.buzhen");
    message_vision(msg, me, target);
//	remove_call_out();
}


