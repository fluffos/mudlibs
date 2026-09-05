
//这个命令是用来防止机器人，鼓励手动的。
//15分钟可以执行一次，如果正确的回答了图形密码，可以恢复全部气血精神内力精力
//而机器人由于不能识别图片(至少目前如此)，他们在战斗中的攻防将会逐渐下降。
#include <ansi.h>
void answer_code(string input,object me);

int main(object me,string arg)
{
	string* info;
	int val = 0;
	if(me->is_busy() || me->is_fighting() || me->is_ghost())
	{
		return notify_fail("你正忙着呢。\r\n");
	}

	if(!arg || strwidth(arg) == 0)
	{
        if(time() - me->query("antirobot/last_full_time") < 0)
        {
            me->delete("antirobot/last_full_time");
        }
        
		if(time() - me->query("antirobot/last_full_time") < 900 )
		{
			val = 900 - time() + me->query("antirobot/last_full_time");
            
			return notify_fail(sprintf("你刚刚用过这个命令不久，还要%d分钟%d秒才能再用。\r\n",(val)/60,val%60));
		}

			if(!environment(me)) return 0;

			if(strsrch(file_name(environment(me)),"/d/reborn") != -1&& strsrch(file_name(environment(me)),"/d/reborn/jinyong/") == -1)
			{
				return notify_fail("你正在经受出师的考验，不能使用这超自然的力量。\r\n");
			}



		if(me->query("antirobot/deactivity") < 1)
		{
			write("赞，你是一个很勤奋的玩家！\r\n");
		}
		else if(me->query("antirobot/deactivity") < 2)
		{
			write("赞，这个频率也是不错的。\r\n");
		}
		else if(me->query("antirobot/deactivity") < 3)
		{
			write("嗯，该执行了，否则过半个小时就要被判为机器人了。\r\n");
		}
		else
		{
			write("你现在才来呀，不过总比不来好。\r\n");
		}


		info = ANTIROBOT_D->mxpantirobot(me);
		me->set_temp("antirobot/code",info[0]);

		me->set("antirobot/last_full_time",time());
        
		write("请输入你看到的图片上的内容。如果感觉难以识别，可以刷新一下再看看。\r\n");
		write("还是用这个命令，指令格式: " + HIR + BNK + "fullme 验证码\r\n" + NOR);
	}
	else
	{
		if(!me->query_temp("antirobot/code"))
		{
			return notify_fail("你没有请求 fullme 。\r\n");
		}
		answer_code(arg,me);
	}
	return 1;
}


void answer_code(string input,object me)
{
	if(strwidth(input) == 0 || !userp(me)) return;
	input = replace_string(input," ","");
	if(lower_case(me->query_temp("antirobot/code")) == lower_case(input))
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

        if (time()-me->query("antirobot/last_full_time") >= 900)
        {
            tell_object(me, HIR"太遗憾了，验证码的时效已过，你的活跃度补充失败。\r\n"NOR);
            me->delete_temp("antirobot/trytimes");
            me->delete_temp("antirobot/code");
            return;
        }
        else
        {
          ANTIROBOT_D->last_fullme(time());
            tell_object(me, "也许是上天垂青于你的勤奋和努力吧，一个小时之内你不用担心被判为机器人。\r\n");
        }
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
        TOPTEN_D->topten_checkonetype(me, "fullme");

		me->delete_temp("antirobot/trytimes");
		me->delete_temp("antirobot/code");
	}
	else
	{
		me->add_temp("antirobot/trytimes",1);
		if(me->query_temp("antirobot/trytimes") < 3)
		{
			tell_object(me,"好像什么都没有发生，但是又好像有什么事情做错了。再来一次试试！\r\n");
		}
		else
		{
			me->delete_temp("antirobot/trytimes");
			me->delete_temp("antirobot/code");
			tell_object(me,"太遗憾了。\r\n");
		}
	}
}

int help(object me)
{
	write(@HELP
指令格式 : fullme
用这个指令把你的精气神全部加满，内力加倍，条件是你可以证明自己不是机器人。
这是给手动玩家的一点奖励。每十五分钟可以用一次。执行fullme后，会显示一副
图片让你输入上面的文字，注意图片里只有字母，没有数字。用fullme 文字来回答
如果你不小心认错了没有关系，可以再试两次。

如果你长时间不使用这个指令，一些主要任务的奖励将会降低很多。系统会在适当的时候提示你应该执行
此命令了。
如果你长期挂机做领悟，打坐，读书，舞剑，配药等非战斗任务，不用管这个命令。

另外，如果你使用网页方式查看图片，请在三分钟内完成，否则图片无法打开。

再外，这个命令会下载图片到你的机器，你可以删除它们。比如zmud 721,位于images目录下。凡是那种
长长的数字做文件名的都可以删除。

HELP
);
        return 1;
}