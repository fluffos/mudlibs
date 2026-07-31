// learn.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
	"说道：您太客气了，这怎么敢当？\n",
	"像是受宠若惊一样，说道：请教？这怎么敢当？\n",
	"笑着说道：您见笑了，我这点雕虫小技怎够资格「指点」您什么？\n",
});

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string skill, teacher, master, skill_name;
	object ob;
	int master_skill, my_skill, jing_cost, times, pertimes,intx;

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");
	if ( skill == "jiuyin-zhengong" ||
	     skill == "jiuyin-shenzhua" ||
	     skill == "jiuyin-shenzhang" ||
	     skill == "dafumo-quan" ||
	     skill == "jiuyin-shenfa" ||
	     skill == "xuanyin-jian" ||
	     skill == "yinlong-bian" ||
	     skill == "taixuan-gong" ||
	     skill == "shenzhao-jing" ||
	     skill == "daode-jing" )
		return notify_fail("这样武功不能学的。\n");
if (ob->query_temp("no_kill") || userp(ob))
{
	if (skill == "magic-fire" ||
	     skill == "magic-ice" ||
	     skill == "magic-water" ||
	     skill == "magic-earth" ||
	     skill == "magic-light" ||
	     skill == "magic-dark" ||
	     skill == "spells" )
		return notify_fail("这样武功不能学的。\n");
}
	if(!arg || (sscanf(arg, "%s %s %d", teacher, skill, times)!=3 ))
		return notify_fail("指令格式：learn|xue <某人> <技能> <次数>\n");

	if (times < 1 || times > 600)
		return notify_fail("学习次数最少一次，最多也不能超过三百次。\n");

	if( me->is_fighting() )
		return notify_fail("临阵磨枪？来不及啦。\n");

	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		return notify_fail("你要向谁求教？\n");

	if( !living(ob) )
		return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");

	if( !me->is_apprentice_of(ob) && !(ob->recognize_apprentice(me)) ) {
//		if( (string)me->query("family/family_name") != (string)ob->query("family/family_name")
//		||	(int)ob->query("family/privs") != -1 ) {
		return	notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
//			if( !(ob->recognize_apprentice(me)) ) return 0;
//		}
	}

	if( !master_skill = ob->query_skill(skill, 1) )
		return notify_fail("这项技能你恐怕必须找别人学了。\n");

//	notify_fail(ob->name() + "不愿意教你这项技能。\n");
	if ( skill == "jiuyin-zhengong" ||
	     skill == "jiuyin-shenzhua" ||
	     skill == "jiuyin-shenzhang" ||
	     skill == "dafumo-quan" ||
	     skill == "jiuyin-shenfa" ||
	     skill == "xuanyin-jian" ||
	     skill == "yinlong-bian" ||
	     skill == "taixuan-gong" ||
	     skill == "shenzhao-jing" ||
	     skill == "daode-jing" )
		return notify_fail("这样武功不能学的。\n");
if (ob->query_temp("no_kill") || userp(ob))
{
	if (skill == "magic-fire" ||
	     skill == "magic-ice" ||
	     skill == "magic-water" ||
	     skill == "magic-earth" ||
	     skill == "magic-light" ||
	     skill == "magic-dark" ||
	     skill == "spells" )
		return notify_fail("这样武功不能学的。\n");
}	if( ob->prevent_learn(me, skill) )
		return 0;

	my_skill = me->query_skill(skill, 1);
	if( my_skill >= master_skill )
		return notify_fail("这项技能你的程度已经不输你师父了。\n");

	if( my_skill >= (int)(master_skill - me->query("betrayer")*20))
		return notify_fail(ob->name() + "皱了皱眉头，不禁想起你过去的叛师经历。\n");

	notify_fail("依你目前的能力，没有办法学习这种技能。\n");
        if (!me) return 0;
	if( !SKILL_D(skill)->valid_learn(me) ) return 0;
intx=(int)me->query_int();
if (intx >=150) intx=150;
	jing_cost = 150 / intx;
jing_cost = jing_cost+2;
	if( !my_skill ) {
		jing_cost *= 2;
		me->set_skill(skill,0);
	}

	if( (me->query("potential") - me->query("learned_points")) < times )
		return notify_fail("你的潜能不够学习这么多次了。\n");

        if( (int)me->query("potential") < 1 )
		return notify_fail("你的潜能已经用完了，没有办法再成长了。\n");


		if( (string)SKILL_D(skill)->type()=="martial"
		&& my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") )

			return notify_fail("也许是缺乏实战经验，你对"+ob->name()+"的回答总是无法领会。\n");

	if( (int)me->query("jing") < jing_cost * times && (me->query("zhuanshen") || me->query("combat_exp",1) > 12000000))
{
                //me->start_busy(1);
	        return notify_fail("你的精不够你学了。\n");
}
	printf(HIC"你向%s请教了"+chinese_number(times)+"句有关「%s」的疑问。\n"NOR, ob->name(), to_chinese(skill));

	if( ob->query("env/no_teach") )
		return notify_fail("但是" + ob->name() + "现在并不准备回答你的问题。\n");

	tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n",
		me->name(), to_chinese(skill)));

	if( (int)ob->query("jing") > jing_cost*times/5 + 1 )
	{
		if( userp(ob) ) ob->receive_damage("jing", jing_cost/5 + 1);
	} else
	{
	//me->start_busy(1);
		write("但是" + ob->name() + "显然太累了，没有办法教你什麽。\n");
		tell_object(ob, "但是你太累了，没有办法教" + me->name() + "。\n");
		return 1;
	}
		
	if( (int)me->query("jing") > jing_cost * times || (!me->query("zhuanshen") && me->query("combat_exp",1) < 12000000))
	{
		if( (string)SKILL_D(skill)->type()=="knowledge"  && (skill != "literate")
		&& my_skill/ 10 * my_skill * my_skill  > (int)me->query("combat_exp") )
		{
			tell_object(ob, "也许是缺乏经验，你对"+ob->name()+"的回答可能无法领会。\n");
			//return notify_fail("也许是缺乏经验，你对"+ob->name()+"的回答总是无法领会。\n");
		} 

		if( (string)SKILL_D(skill)->type()=="martial"
		&& my_skill/ 10 * my_skill * my_skill  > (int)me->query("combat_exp") )
		{
	//me->start_busy(1);
			return notify_fail("也许是缺乏实战经验，你对"+ob->name()+"的回答总是无法领会。\n");
		} else
		{
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
	 			printf("你听了%s的指导，对「%s」这一招似乎有些心得。\n", ob->name(),
					skill_name);
			else
				printf("你听了%s的指导，似乎有些心得。\n", ob->name());
if(present("learn emblem",me)) intx=intx*2;
			//for (pertimes = 1; pertimes <= times ; pertimes ++)
			//{
				me->add("learned_points", (1*times));
				me->improve_skill(skill, (random(intx)*times));
if ((!me->query("zhuanshen") && !me->query("guard/flag") && !me->query("zhuanbest") && !me->query("4zhuan") && !me->query("5zhuan")) && me->query("combat_exp",1) < 12000000) 
me->improve_skill(skill, (random(intx)*times));
			//}
		}
	} else
	{
		if (jing_cost > me->query("jing"))
			jing_cost = me->query("jing");
	//me->start_busy(1);
		return notify_fail("你今天太累了，结果什么也没有学到。\n");
	}
	if(!present("study emblem",me)) 
{	
if (me->query("zhuanshen") || me->query("combat_exp",1) > 12000000)
	me->receive_damage("jing", jing_cost * times );
}
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : learn|xue <某人> <技能> <次数>
 
这个指令可以让你向别人请教有关某一种技能的疑难问题，当然，你请教的对象在这
项技能上的造诣必须比你高，而你经由这种方式学习得来的技能也不可能高於你所请
教的人，然而因为这种学习方式相当於一种「经验的传承」，因此学习可以说是熟悉
一种新技能最快的方法。

此外学习也需要消耗一些精力，而消耗的精力跟你自己、与你学习对象的悟性有关。

其他相关指令 : apprentice, practice, skills, study
HELP
        );
        return 1;
}
