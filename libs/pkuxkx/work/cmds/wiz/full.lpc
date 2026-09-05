#include <ansi.h>
inherit F_CLEAN_UP;

string *gifts=({ "qi","jing" });
string *gifts1=({"jingli","neili" });

int main(object me, string str)
{
    int i;
    object obj;

    if( !str || str == "" || wiz_level(me) <= 2)
        obj = me;
    else if ( !obj = present(str,environment(me)))
        return notify_fail("对象错误: 找不到"+str+"\n");
    
	if (obj==me)
	{
	
		me->fullme();
		//内力加倍
		if(me->query("neili") < 2*me->query("max_neili"))
		{
			me->set("neili",2*me->query("max_neili"));
			me->set("eff_neili",2*me->query("max_neili"));
		}
		//精力加倍
		if(me->query("jingli") < 2*me->query("max_jingli"))
		{
			me->set("jingli",2*me->query("max_jingli"));
			me->set("eff_jingli",2*me->query("max_jingli"));
		}

		tell_object(me, HIG"你突然感到精神一振，浑身似乎又充满了力量！\r\n"NOR);

		ANTIROBOT_D->last_fullme(time());
		tell_object(me, "也许是上天垂青于你的勤奋和努力吧，一个小时之内你不用担心被判为机器人。\r\n");
		
		//0表示活跃，每三十分钟增加1，增加到3就开始影响战斗。
		if ((int)me->query("combat_exp")-(int)me->query("statistics/fullme/last_fullme_exp")>1000)
		{
			me->add("statistics/fullme/total_fullme_times",1);
		}
		me->set("statistics/fullme/last_fullme_exp",(int)me->query("combat_exp"));
		me->set("antirobot/deactivity",0);
		me->set("antirobot/last_deactivity_time",time());

		if (me->query("antirobot/deactivity")>=4 || !me->query("antirobot/seg_first_activity_time"))
		{
			me->set("antirobot/seg_first_activity_time",time());
		}
		if (time()-me->query("antirobot/last_activity_time")>3600*5)
		{
			me->set("antirobot/total_activity_time", 0);
			me->set("antirobot/pic_fullme_times", 0);
			me->set("antirobot/hand_fullme_times", 0);
		}
		if (time()-me->query("antirobot/last_activity_time")>3600*5 || !me->query("antirobot/first_activity_time"))
		{
			me->set("antirobot/first_activity_time", time());
			me->set("antirobot/first_activity_exp", me->query("combat_exp"));
		}
		me->set("antirobot/last_activity_time", time());
		me->add("antirobot/hand_fullme_times", 1);

		me->delete_temp("antirobot/trytimes");
		me->delete_temp("antirobot/code");
	}
	else
	{
		if(obj->query("neili") < 2*obj->query("max_neili"))
		{
			obj->set("neili",2*obj->query("max_neili"));
			obj->set("eff_neili",2*obj->query("max_neili"));
		}
		if(obj->query("jingli") < 2*obj->query("max_jingli"))
		{
			obj->set("jingli",2*obj->query("max_jingli"));
			obj->set("eff_jingli",2*obj->query("max_jingli"));
		}
		tell_object(obj, HIG"你突然感到精神一振，浑身似乎又充满了力量！\r\n"NOR);

	}
    return 1;
}

int help(object obj)
{
  write(@HELP
指令格式 : full <对象>

利用此指令可完全恢复生物的状态并清除一切condition。
HELP
    );
    return 1;
}
