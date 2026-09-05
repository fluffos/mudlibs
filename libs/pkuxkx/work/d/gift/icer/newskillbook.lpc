//by yhzzyahoo
//功夫口诀全谱-2008圣诞及新年礼物
//玩家第一次得到时随机选取其身上的功夫之一作为本书的skill
//选取功夫的标准是：
//	1、如果选取的功夫在100级以上，则就取此功夫
//	2、如果选取的功夫在100级以下，则寻找其师傅，看师傅是否有此功夫，如果有，则取此功夫，没有则重新选择
//选取功夫之后set书的name为相应功夫，max_skill为玩家当前等级+30+random(70)
//然后将skillname,name,和max_skill都设置到玩家身上/gift/2016newyear下
//如果玩家不是第一次得到本书，则直接根据/gift/2016newyear下的属性设置本书属性
//2009年1月3日后本书失效。
#include <ansi.h>
inherit ITEM;
//void set_book();
void create()
{		object me,ob;
	string skill;
	mapping skills;
	int level,i,add_temp;
	me = this_player();
	ob = this_object();
        set_name(HIW"功夫口诀全谱"NOR, ({ "koujue book","book","koujue"}));
        set_weight(600);
                set("unit", "本");
                set("long","");
                set("value", 100);
          //      set("material", "paper");
                set("creat_time", time());
                /*set("skill", ([
                        "name":  "literate", 
                        "jing_cost":      30,                           
                        "difficulty":   30,                            
                		"max_skill": 100, 
                                                                               
                ])
					);*/
	skills = me->query_skills();
	if (!skills || sizeof(skills)==0)	//没功夫，直接给他本literate
	{
	//	set_book("literate",20);

	//	log_file("2016newyear",me->name() + "得到了能读到20级的读书写字秘籍\n");
	//	return;
		write("你都没有技能，来混啥混啊！");

	}
	else 
	{
		i = random(sizeof(skills));
		skill = keys(skills)[i];
		level = values(skills)[i];
		if (level >= 100)	//取这个功夫
		{
			  add_temp = 1+random(3);
			  if ( !intp(skills[skill]) )
			  {
				skill="force"; 
			  } //多层技能的不奖励等级
			  
			  if(skill == "tianmo-jieti") 
			  {
				skill="force"; 
				  };//不奖励天魔解体
			  
			  if(skill == "business") 
			  {
				skill="force"; 
			  };//不奖励经商之道
			  if (SKILL_D(skill)->professional())
			  {
				  skill="force";
			  };//不奖励专业技能
			  if (!me->query("chushi") && !me->query("betrayer"))
			  {
				  add_temp += 1;
			  }
			  if (skill == "zui-quan")
			  {
				  add_temp = 1;
			  }
			level += add_temp;
		ob->set("name",HIW + CHINESE_D->chinese(skill) + "口诀" + NOR);
		ob->set("skill/name",skill);
		ob->set("skill/max_skill",level);
		ob->set("long","这是一本有关" + CHINESE_D->chinese(skill) + "的口诀宝典。有了它你可以将" 
			+ CHINESE_D->chinese(skill) + "读(yuedu)到" + CHINESE_D->chinese_number(level) + "级！\n");

		//	set_book(skill,level);
			log_file("2016newyear",me->name() + "得到了能读到" + level + "级的" + CHINESE_D->chinese(skill)+"秘籍\n");
		//	return;
		}
	}
				

}
/*void set_book(string skill,int level)
{
	object ob = this_object();
	ob->set("name",HIW + CHINESE_D->chinese(skill) + "口诀" + NOR);
	ob->set("skill/name",skill);
	ob->set("skill/max_skill",level);
	ob->set("long","这是一本有关" + CHINESE_D->chinese(skill) + "的口诀宝典。有了它你可以将" 
		+ CHINESE_D->chinese(skill) + "读(yuedu)到" + CHINESE_D->chinese_number(level) + "级！\n");
	return;
}*/
void dest()
{
	destruct(this_object());
}

int do_yuedu()
{
    object ob=this_object();
    object me=this_player();
	if (time() > ob->query("creat_time")+7200 || time() > 1456283990)	//创造出来2小时失效,正月十五以后失效
	{
		write("本礼物已失效！\n");
	//	me->delete("gift/2016newyear");
		call_out("dest",1);
		return;
	}

    if (this_object()->query("owner")!=me->query("id"))
    {
        tell_object(me,"你翻了翻这本秘籍，却觉得过于晦涩难懂。\n");
        return 1;
    }
	if (me->query("combat_exp") < 100000)
	{
		write("你的经验低于100000，不适合读这本口诀。\n");
		call_out("dest",1);
		return;
	}
    if (me->query("gift/2016newbook")>1)
    {
        tell_object(me,"你已经读过这种秘籍了，就不要贪心了。\n");
        return 1;
    }

    message_vision("$N开始认真研读$n，武学造诣更深了一层！\n"NOR, me,this_object());
    me->add("gift/2016newbook",1);
	me->set_skill(ob->query("skill/name"),ob->query("skill/max_skill"));
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}

void init()
{
	object me,ob;
	string skill;
	mapping skills;
	int level,i,reset,add_temp;
	me = this_player();
	ob = this_object();
	add_action("do_yuedu", "yuedu");
	add_action("do_du","yuedu");
	if (!living(environment(ob)))
	
	if (time() > ob->query("creat_time")+7200)	//创造出来2小时失效
	{
		write("本礼物已失效！\n");
	//	me->delete("gift/2016newyear");
		call_out("dest",1);
		return;
	}

	/*reset = 0;
	//第一次得到本书
	skills = me->query_skills();
	if (!skills || sizeof(skills)==0)	//没功夫，直接给他本literate
	{
		set_book("literate",20);

		log_file("2016newyear",me->name() + "得到了能读到20级的读书写字秘籍\n");
		return;
	}
	else 
		//while (reset < 5)	//如果所选功夫不满足条件，还有四次重选，都不满足只好放弃
	{
	//	reset++;
		i = random(sizeof(skills));
		skill = keys(skills)[i];
		level = values(skills)[i];
		if (level >= 100)	//取这个功夫
		{
		//	me->set("gift/2016newyear/old_skill",level);
			  add_temp = 1+random(3);
			  if ( !intp(skills[skill]) )
			  {
				skill="force"; 
				continue;
			  } //多层技能的不奖励等级
			  
			  if(skill == "tianmo-jieti") 
			  {
				skill="force"; 
				continue;
			  };//不奖励天魔解体
			  
			  if(skill == "business") 
			  {
				skill="force"; 
				continue;
			  };//不奖励经商之道
			  if (SKILL_D(skill)->professional())
			  {
				  skill="force";
				  continue;
			  };//不奖励专业技能
			  if (!me->query("chushi") && !me->query("betrayer"))
			  {
				  add_temp += 1;
			  }
			  if (skill == "zui-quan")
			  {
				  add_temp = 1;
			  }
			level += add_temp;
			set_book(skill,level);
			log_file("2016newyear",me->name() + "得到了能读到" + level + "级的" + CHINESE_D->chinese(skill)+"秘籍\n");
			return;
		}
	}
	set_book("literate",20);
	ob->set("desting",1);
	call_out("dest",1);*/
}
