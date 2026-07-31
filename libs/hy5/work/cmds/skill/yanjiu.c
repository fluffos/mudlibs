// research.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string skill, skill_name;
        object where = environment(me);
	int my_skill, jing_cost, times, pertimes,intx;

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if (!where->query("sleep_room"))
             return notify_fail("这里太纷杂，你没法做研究。\n");

	if(!arg || (sscanf(arg, "%s %d", skill, times)!=2 ))
		return notify_fail("指令格式：research|yanjiu <技能> <次数>\n");

	if (times < 1 || times > 600)
		return notify_fail("研究次数最少一次，最多也不能超过六百次。\n");

	if( me->is_fighting() )
		return notify_fail("临阵磨枪？来不及啦。\n");

	if( !my_skill = me->query_skill(skill, 1) )
		return notify_fail("这项技能你恐怕没法研究了。\n");

//	if( skill == "taixuan-gong" )
//		return notify_fail("太玄不能研究。\n");

	if ( skill == "jiuyin-zhengong" ||
	     skill == "jiuyin-shenzhua" ||
	     skill == "jiuyin-shenzhang" ||
	     skill == "dafumo-quan" ||
	     skill == "jiuyin-shenfa" ||
	     skill == "xuanyin-jian" ||
	     skill == "yinlong-bian" ||
	     skill == "shenzhao-jing" ||
	     skill == "daode-jing" )
		return notify_fail("这样武功不能研究。\n");
	if ( skill == "magic-fire" ||
	     skill == "magic-ice" ||
	     skill == "magic-water" ||
	     skill == "magic-earth" ||
	     skill == "magic-light" ||
	     skill == "magic-dark" ||
	     skill == "spells" )
		return notify_fail("魔法不能研究。\n");
	if( (string)SKILL_D(skill)->type()=="knowledge")
		return notify_fail(to_chinese(skill)+"只能靠你学习才能提高的。\n");

	notify_fail("依你目前的能力，没有办法研究这种技能。\n");

    if ( !me->query("zhuanshen") || !(string)SKILL_D(skill)->exert_function_file())
{
    if( !SKILL_D(skill)->valid_learn(me) && my_skill < 200) return 0;
}

    if ( me->query("zhuanshen"))
{
    if( my_skill < 99) return 0;
}
intx=(int)me->query_int();
if (intx >=150) intx=150;
	jing_cost = 380 / intx;
	jing_cost = jing_cost+2;
	if( !my_skill ) {
		jing_cost *= 2;
		me->set_skill(skill,0);
	}

	if( (me->query("potential") - me->query("learned_points")) < times )
		return notify_fail("你的潜能不够研究这么多次了。\n");

	if( (int)me->query("jing") < jing_cost * times )
{
                me->start_busy(1);
	        return notify_fail("你的精不够用了。\n");
}

	my_skill = me->query_skill(skill, 1);

       if( (string)SKILL_D(skill)->type()=="martial"
	&& my_skill/ 10 * my_skill * my_skill  > (int)me->query("combat_exp") )
		return notify_fail("也许是缺乏实战经验，你没法研究"+to_chinese(skill)+"的问题了。\n");

	printf(HIM"你研究了"+chinese_number(times)+"次有关「%s」的疑问。\n"NOR, to_chinese(skill));

	if( (int)me->query("jing") > jing_cost * times )
	{
		if( (string)SKILL_D(skill)->type()=="martial"
		&& my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") )
		{
	me->start_busy(1);
			return notify_fail("也许是缺乏实战经验，你没法研究"+to_chinese(skill)+"的问题了。\n");
		} else
		{
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
			printf("你研究了一会，对「%s」这一招似乎想通了些什么。\n", skill_name);
			else
			printf("你研究了一会，似乎对"+to_chinese(skill)+"有些新的领悟。\n");
			if(present("learn emblem",me)) intx=intx*2;
			//for (pertimes = 1; pertimes <= times ; pertimes ++)
			//{
				me->add("learned_points", 1*times);
				me->improve_skill(skill, random(intx/2)*times);
			if(present("learn emblem",me)) me->improve_skill(skill, random(intx/2)*times);
			//}
		}
	} else
	{
	me->start_busy(1);
		jing_cost = me->query("jing");
		return notify_fail("你今天太累了，结果什么也没有研究成。\n");
	}
	if(!present("study emblem",me)) me->receive_damage("jing", times * jing_cost );
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : research | yanjiu <技能> <次数>
 
这个指令可以让你研究一种技能的疑难问题，当你师傅这项技能的级
别不如你的时候，可以通过研究自己来提高，当然进步的速度是不如
向师傅学的了。

此外研究也需要消耗一些精力，而消耗的精力跟你自己的悟性有关。

其他相关指令 : apprentice, practice, skills, study, learn
HELP
        );
        return 1;
}
