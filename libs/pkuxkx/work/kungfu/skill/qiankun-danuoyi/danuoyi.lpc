// 寻瑕抵隙
// created by Zine new明教
//超级 buff，7层一天2次，其他一天1次
#include <ansi.h>
#include "/kungfu/skill/shenghuo-lingfa/shenghuo.h"
inherit F_SSERVER;

string* valid_weapon()
{
    return ({ "all" });
}

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "self";
}

int remove_effect(object me, int point,int cnt)
{
    if (objectp(me))
    {
        me->add_temp("apply/dodge", -point);
        me->add_temp("apply/parry", -point);
        me->add_temp("apply/attack", -point / cnt);
        me->add_temp("apply/damage", -point / cnt);
        me->add_temp("apply/strength", -point / 6);
        me->delete_temp("active_buffer/qiankun-danuoyi.danuoyi");
        message_vision("$N收回了「乾坤大挪移」心法，气息回复平常。\n", me);
    }
}
int allow_times(object me)
{
	int res=0;
	int xishu;
	if (me->query("mingjiao/skill/danuoyi/level")==7) res=4;
	if (me->query("mingjiao/skill/danuoyi/level")==6) res=2;
	if (me->query("mingjiao/skill/danuoyi/level")==5) res=1;
	if (me->query("safari_skill/mj_dny")&&me->query("family/family_name")=="明教") 
	{
		xishu=me->query_skill("guangming-shenghuogong", 1)/160;
		if (xishu > 12)
		{
			xishu = 12;
		}
		res*=xishu;
		if (me->query("chushi/done"))
		{
			res/=2;
		}
		if (me->query("betrayer"))
		{
			res/=2;
		}
	}
	return res;
}
int period_coe(object me)
{
	int res;
	if (me->query("mingjiao/skill/danuoyi/level")==7) res=42+random(3);
	if (me->query("mingjiao/skill/danuoyi/level")==6) res=40;
	if (me->query("mingjiao/skill/danuoyi/level")==5) res=38;
	return res;
}

int lasttime_cal(object me)
{
	int last_time;
	if (me->query("safari_skill/mj_dny") && me->query("family/family_name")=="明教") 
	{
		if (me->query("mingjiao/skill/danuoyi/level")==7) last_time=90+random(6);
		if (me->query("mingjiao/skill/danuoyi/level")==6) last_time=75+random(11);
		if (me->query("mingjiao/skill/danuoyi/level")==5) last_time=55+random(11);
	}
	else
	{
		last_time = 120;
	}
	if (me->query("chushi/done")||me->query("betrayer"))
		{
			last_time = last_time*2/3;
		}	
//	write("缩减时间:"+last_time+"\n");

return last_time;
}

int cd(object me)
{
	if (!me->query("safari_skill/mj_dny")) return 600;
	return me->query("mingjiao/skill/danuoyi/level")*(period_coe(me)+15);
}
int perform(object me)
{
    int pure = pure_degree(me), skill,period_coe;
	int last_time,cnt;

    string color, msg;
    mixed tm = localtime(time());
    string day = sprintf("%d-%d-%d", tm[5], tm[4] + 1, tm[3]);
	last_time=120;
    if (me->query_skill("qiankun-danuoyi", 1) < 300)
        return notify_fail("你的乾坤大挪移级别太低，无法使用「大挪移」绝技。\n");

    if (me->query("mingjiao/skill/danuoyi/level") < 5 && pure_degree(me) <= 100)
        return notify_fail("你的乾坤大挪移层级太低，无法使用乾坤大挪移的「大挪移」绝技。\n");

    if (me->query("mingjiao/skill/danuoyi/level") < 4)
        return notify_fail("你的乾坤大挪移层级太低，无法使用乾坤大挪移的「大挪移」绝技。\n");

    if (me->query("mingjiao/skill/danuoyi/dny_day") != day)
    {
        me->set("mingjiao/skill/danuoyi/dny_day", day);
        me->set("mingjiao/skill/danuoyi/dny_times", 0);
    }

    if (me->query("mingjiao/skill/danuoyi/dny_times") > allow_times(me))
        return notify_fail("你今天已经多次使用过「大挪移」绝技，气血不定，无法继续。\n");

    if (me->query_temp("active_buffer/qiankun-danuoyi.danuoyi"))
        return notify_fail("你正在使用「大挪移」绝技。\n");
	if (time()-me->query("mingjiao/skill/danuoyi/dny_usetime")<cd(me))
		return notify_fail("你刚刚用完「大挪移」绝技不久，气血翻腾不定。\n");
    me->add("mingjiao/skill/danuoyi/dny_times", 1);
    color = custom_color_dny(me);
    msg = color + "$N" + color + "默运「乾坤大挪移」心法，将全身潜力逼出。\n" + NOR;
    message_vision(msg, me);
    skill = (me->query_skill("qiankun-danuoyi", 1) + me->query("guangming-shenghuogong", 1)) / 2;
    skill = skill / 2 + random(skill / 2);
    skill = skill * (7 + me->query("mingjiao/skill/danuoyi/level")) / 9;
	cnt=4;
	if (me->query("safari_skill/mj_dny")) 
	{
		last_time=lasttime_cal(me);
		if (me->query("family/family_name")=="明教"&&me->query("chushi/done")==0&&me->query("betrayer")==0 || wizardp(me))
		{
			cnt=3;
		}
	}
    me->add_temp("apply/dodge", skill);
    me->add_temp("apply/parry", skill);
    me->add_temp("apply/attack", skill / cnt);
    me->add_temp("apply/damage", skill / cnt);
    me->add_temp("apply/strength", skill / 6);
    me->set_temp("active_buffer/family", "明教");
	last_time *= me->query("mingjiao/skill/danuoyi/level");
    me->set_temp("active_buffer/qiankun-danuoyi.danuoyi/name", "大挪移");                              //buff名称
    me->set_temp("active_buffer/qiankun-danuoyi.danuoyi/last_time", time() + last_time);                //持续时间
    me->set_temp("active_buffer/qiankun-danuoyi.danuoyi/effect1", "轻功技能+" + (skill)+"级");       //效果描述1
    me->set_temp("active_buffer/qiankun-danuoyi.danuoyi/effect2", "招架技能+" + (skill)+"级");       //效果描述2
    me->set_temp("active_buffer/qiankun-danuoyi.danuoyi/effect3", "攻击命中+" + (skill / cnt) + "点");       //效果描述3
    me->set_temp("active_buffer/qiankun-danuoyi.danuoyi/effect4", "伤害加成+" + (skill / cnt) + "点");       //效果描述4
    me->set_temp("active_buffer/qiankun-danuoyi.danuoyi/effect5", "臂力加成+" + (skill / 6) + "点");       //效果描述5
    call_out("remove_effect", last_time, me, skill, cnt);
    return 1;
}

