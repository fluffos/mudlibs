// learn.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int can_learn(object me, string skill);

string *reject_msg = ({
	"说道：您太客气了，这怎么敢当？\n",
	"像是受宠若惊一样，说道：请教？这怎么敢当？\n",
	"笑着说道：您见笑了，我这点雕虫小技怎够资格「指点」您什么？\n",
});

void create() { seteuid(getuid()); }

void auto_learn(object me, string teacher,string skill,int times)
{
	if(!me||!me->query_temp("pending/auto_learn")||!present(teacher,environment(me)))
		return;

	if(me->is_busy())
		call_out("auto_learn",1,me,teacher,skill,times);

	else if(me->query("neili")<302 && me->query("max_neili")>400)
	{
		if(me->present("huiling dan",me))
			me->force_me("use huiling dan");
        else me->force_me("use huxin dan");
        me->force_me("exert regenerate");
		me->force_me("dazuo "+me->query("max_qi")/2);
		call_out("auto_learn",10,me,teacher,skill,times);
	}

	else if( (int)me->query("jing") < me->query("eff_jing"))
	{
		if (SKILL_D("force/regenerate")->exert(me, me))
		{
			if( (int)me->query("jing") < me->query("eff_jing"))
			{
				//tell_object(me,"精神不足，等待恢复中。。。\n");
				call_out("auto_learn",10,me,teacher,skill,times);
			}
			else
			{
				call_out("auto_learn",1,me,teacher,skill,times);
			}
		}
		else
		{
			//tell_object(me,"精神不足，等待恢复中。。。\n");
			call_out("auto_learn",10,me,teacher,skill,times);
		}
	}
	else
	{
		//tell_object(me,"托管中，继续请教。。。。。。\n");
		tell_object(me,ZJFORCECMD("learn "+teacher+" "+skill+" "+times));
	}
}

int main(object me, string arg)
{
	object where = environment(me);
	string *args;
	string skill, teacher, master, skill_name;
	object ob;
	mixed flag;
	int master_skill, my_skill, jing_cost, times, i,up_skill_point, lvl;
	int rand;
	int up_point = 0;
	int t = time();

	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");

	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if (t == me->query_temp("time/learn"))
		return notify_fail("你刚刚才学习过（如果你要连续学习，可以指明学习的次数）。\n");

	if (! arg || (i = sizeof(args = explode(arg, " "))) < 2)
		return notify_fail("指令格式：learn|xue <某人> <技能> <次数>\n");

	i--;
	if (i >= 2 && sscanf(args[i], "%d", times) && times)
		i--;
	else
		return notify_fail(INPUTTXT("请输入学习次数：","learn "+arg+" $txt#")+"\n");
	skill = args[i--];
	if (args[i] == "about" && i >= 1)
		i--;
	teacher = implode(args[0..i], " ");

	if (times < 1 || times > 100)
		return notify_fail("学习次数最少一次，最多也不能超过100次。\n");

	if (me->is_fighting())
		return notify_fail("临阵磨枪？来不及啦。\n");

	if (! (ob = present(teacher, environment(me))) || ! ob->is_character())
		return notify_fail("你要向谁求教？\n");

	if (! living(ob))
		return notify_fail("嗯....你得先把" + ob->name() +"弄醒再说。\n");

	if (! me->is_apprentice_of(ob) &&
	    (me->query("family/family_name") != ob->query("family/family_name") ||
	     me->query("family/generation") > ob->query("family/generation") ||
	     me->query("family/generation") < 1 ||
	     ! ob->can_learn_from() ||
	     playerp(ob)))
	{
		switch (ob->recognize_apprentice(me, skill))
		{
		case 0:
			return notify_fail( ob ->name() +
			       reject_msg[random(sizeof(reject_msg))] );
		case -1:
			return 1;
		}
	}

	if (! master_skill = ob->query_skill(skill, 1))
		return notify_fail("这项技能你恐怕必须找别人学了。\n");

	if (stringp(flag = ob->query("no_teach/" + skill)))
	{
		message_vision(CYN "$N" CYN "摇摇头，说道：" + flag + ""NOR"\n", ob);
		return 1;
	} else
	if (intp(flag) && flag)
	{
		if (flag != -1)
			// show the messaeg if the result was not -1
			write(CYN + ob->name() + CYN "说道：对不起，" + to_chinese(skill) + "可不能随便传授。"NOR"\n");
		return 1;
	}

	if (me->is_apprentice_of(ob) &&
	    SKILL_D(skill)->type() == "martial" &&
	    me->query_skill(skill, 1) >= SKILL_D(skill)->valid_learn_level())
	{
		write(ob->name() + "说：嗯.... 你的" + to_chinese(skill) +
		      "功力已经是非同凡响了，我就不再教你，你自己多研究吧。\n");
		return 1;
	}

	my_skill = me->query_skill(skill, 1);
	if (my_skill >= master_skill)
		return notify_fail("这项技能你的程度已经不输你师父了。\n");

	if (my_skill >= (int)(master_skill - me->query("betrayer/times") * 2))
		return notify_fail(ob->name() + "皱了皱眉头，不禁想起你过去的叛师经历。\n");

	if (! can_learn(me, skill))
		return 0;

	notify_fail("依你目前的能力，没有办法学习这种技能。\n");
	if (! SKILL_D(skill)->valid_learn(me)) return 0;

	//jing_cost = (100 + my_skill * 2) / (int) me->query("int");
	jing_cost = 0;
    lvl = me->query_skill(skill, 1);	
	if (! my_skill)
	{
		jing_cost *= 2;
		me->set_skill(skill,0);
	}
	if (lvl < 180) 
	jing_cost *= 0;
	
	if ((me->query("potential") - me->query("learned_points")) < times)
		return notify_fail("你的潜能不够学习这么多次了。\n");
	//write(sprintf(HIC "你开始向%s请教" + chinese_number(times) + "句有关「%s」的疑问。"NOR"\n",ob->name(),to_chinese(skill)));

	if (ob->query("env/no_teach"))
	{
		write("但是" + ob->name() + "现在并不准备回答你的问题。\n");
		return 1;

	}

	//tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n",me->name(), to_chinese(skill)));

	if (! me->can_improve_skill(skill))
	{
		write("也许是缺乏实战修为，你对" + ob->name() + "的回答总是无法领会。\n");
		return 1;
	}

	if (playerp(ob))
	{
		if ((int)ob->query("jing") > jing_cost * times / 5 + 1)
			ob->receive_damage("jing", jing_cost / 5 + 1);
		else
		{
			//write("但是" + ob->name() + "显然太累了，没有办法教你什麽。\n");
			//tell_object(ob, "但是你太累了，没有办法教" + me->name() + "。\n");
			return 1;
		}
	}

	me->set_temp("pending/auto_learn",1);
	me->set_temp("time/learn", t);
	for (i = 0; i < times && i<800 ; i++)
	{
    		if ((int)me->query("jing") < jing_cost)
		{
			if (SKILL_D("force/regenerate")->exert(me, me))
			{
				//write("你觉得精神好了一些，继续进行学习。\n");
				i--;
				continue;
			}
			else
			{
				me->set("jing", 0);
				break;
			}
		}
		up_skill_point=me->query_int() + my_skill / 4;
		up_skill_point /= 2;
		up_skill_point=5 + random(up_skill_point)*30;//此处为了加快学习在末尾乘以了30
		if (me->query("id")=="z110614_1"){
		up_skill_point=5 + random(up_skill_point)*100;
		}
		up_point += up_skill_point;
		me->improve_skill(skill, up_skill_point);
    		me->receive_damage("jing", jing_cost);
		me->add("learned_points", 2);
	}

	if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
 		printf("你听了%s的指导，对「%s」有了新的领悟。"+HIG"exp + "+up_point+" ↑"+NOR+"\n", ob->name(),skill_name); 
	else
		printf("你听了%s的指导，似乎有些心得。\n【%s】: "+HIG"exp + "+up_point+" ↑"+NOR+"\n", ob->name(),to_chinese(skill));

	if (i == 0 && times==0)
		write("然而你今天太累了，无法再进行任何学习了。\n");
	else if (i >= 0 && i < times)
	{
		call_out("auto_learn",1,me,teacher,skill,times-i);
	}
	return 1;
}

int can_learn(object me, string skill)
{
	string skill_name;
	mapping skills;
	string mskill;
	int tmp;
	int i;

	if (stringp(mskill = SKILL_D(skill)->main_skill()) && mskill != skill && me->query_skill(mskill, 1) > 0)
		return notify_fail("你现在没有必要再单独学习" + to_chinese(skill) + "了。\n");

	skills = me->query_skills();
	if (! mapp(skills))
		return 1;

	if (! SKILL_D(skill)->valid_enable("force") || SKILL_D(skill)->valid_force("*"))
		return 1;

	foreach (skill_name in keys(skills))
	{
		if (file_size(SKILL_D(skill_name) + ".c") == -1)
		{
			continue;
		}

		if (! SKILL_D(skill_name)->valid_enable("force") ||
		    skill_name == skill)
			continue;

		if (! SKILL_D(skill_name)->valid_force(skill))
			return notify_fail("你不散了" + to_chinese(skill_name) + "，怎么学习" + to_chinese(skill) + "？\n");
	}

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : learn|xue <某人> [about] <技能> <次数>
 
这个指令可以让你向别人请教有关某一种技能的疑难问题，当然，你请教的对象在这
项技能上的造诣必须比你高，而你经由这种方式学习得来的技能也不可能高於你所请
教的人，然而因为这种学习方式相当於一种「修为的传承」，因此学习可以说是熟悉
一种新技能最快的方法。

此外学习也需要消耗一些精力，而消耗的精力跟你自己、与你学习对象的悟性有关。

其他相关指令 : apprentice, practice, skills, study
HELP
	);
	return 1;
}
