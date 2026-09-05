//by icer 
//功夫口诀全谱-2008圣诞及新年礼物
//玩家第一次得到时随机选取其身上的功夫之一作为本书的skill
//选取功夫的标准是：
//	1、如果选取的功夫在100级以上，则就取此功夫
//	2、如果选取的功夫在100级以下，则寻找其师傅，看师傅是否有此功夫，如果有，则取此功夫，没有则重新选择
//选取功夫之后set书的name为相应功夫，max_skill为玩家当前等级+30+random(70)
//然后将skillname,name,和max_skill都设置到玩家身上/gift/2008xmas下
//如果玩家不是第一次得到本书，则直接根据/gift/2008xmas下的属性设置本书属性
//2009年1月3日后本书失效。
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"功夫口诀全谱"NOR, ({ "koujue book", "book","koujue"}));
        set_weight(600);
                set("unit", "本");
                set("long","");
                set("value", 100);
                set("material", "paper");
				set("creat_time",time());
                set("skill", ([
                        "name":  "literate", 
                        "jing_cost":      30,                           
                        "difficulty":   30,                            
                		"max_skill": 100, 
                                                                               
                ]) );
}
void set_book(string skill,int level)
{
	object ob = this_object();
	ob->set("name",HIW + CHINESE_D->chinese(skill) + "口诀" + NOR);
	ob->set("skill/name",skill);
	ob->set("skill/max_skill",level);
	ob->set("long","这是一本有关" + CHINESE_D->chinese(skill) + "的口诀宝典。有了它你可以将" 
		+ CHINESE_D->chinese(skill) + "读到" + CHINESE_D->chinese_number(level) + "级！\n");
	return;
}
void dest()
{
	destruct(this_object());
}
void init()
{
	object me,ob,teacher;
	string skill;
	mapping skills;
	int level,i,reset;
	
	me = this_player();
	ob = this_object();
	
	if (!living(environment(ob)))
		return;
	if (time() > ob->query("creat_time")+3600)	//09年1月3日晚24点失效
	{
		write("本礼物已失效！\n");
		me->delete("gift/2008xmas");
		call_out("dest",1);
		return;
	}
	if (me->query("combat_exp") < 1000)
	{
		write("你的经验低于1000，不适合读这本口诀。\n");
		call_out("dest",1);
		return;
	}
	
	if (me->query("gift/2008xmas/skill_name"))	//不是第一次得到本书
	{
		skill = me->query("gift/2008xmas/skill_name");
		level = me->query("gift/2008xmas/max_skill");
		set_book(skill,level);
		if (me->query("gift/2008xmas/family_name") != me->query("family/family_name"))
		{
			write("你已经改门换派，不适合再读这本口诀了。\n");
			call_out("dest",1);
			return;
		}
		return;
	}
	reset = 0;
	//第一次得到本书
	skills = me->query_skills();
	if (!skills || sizeof(skills)==0)	//没功夫，直接给他本literate
	{
		set_book("literate",100);
		me->set("gift/2008xmas/skill_name","literate");
		me->set("gift/2008xmas/max_skill",100);
		me->set("gift/2008xmas/old_skill",0);
		if (!me->query("gift/2008xmas/times")) me->set("gift/2008xmas/times",1);
		me->set("gift/2008xmas/family_name",me->query("family/family_name"));
		log_file("2008xmas",me->name() + "得到了能读到" + me->query("gift/2008xmas/max_skill") + "级的" + CHINESE_D->chinese(me->query("gift/2008xmas/skill_name"))+"秘籍\n");
		return;
	}
	else while (reset < 5)	//如果所选功夫不满足条件，还有四次重选，都不满足只好放弃
	{
		reset++;
		i = random(sizeof(skills));
		skill = keys(skills)[i];
		level = values(skills)[i];
		if (level >= 100)	//取这个功夫
		{
			me->set("gift/2008xmas/old_skill",level);
			level += 30+random(70);
			set_book(skill,level);
			me->set("gift/2008xmas/skill_name",skill);
			me->set("gift/2008xmas/max_skill",level);
			if (!me->query("gift/2008xmas/times")) me->set("gift/2008xmas/times",1);
			me->set("gift/2008xmas/family_name",me->query("family/family_name"));
			log_file("2008xmas",me->name() + "得到了能读到" + me->query("gift/2008xmas/max_skill") + "级的" + CHINESE_D->chinese(me->query("gift/2008xmas/skill_name"))+"秘籍\n");
			return;
		}
		if (me->query("family/master_id"))	//有师傅
		{
			teacher = find_living(me->query("family/master_id"));
			if (teacher)
			{
				if (teacher->query_skill(skill,1) > 0)	//师傅有这个功夫，可以读
				{
					me->set("gift/2008xmas/old_skill",level);
					level += 30+random(70);
					set_book(skill,level);
					me->set("gift/2008xmas/skill_name",skill);
					me->set("gift/2008xmas/max_skill",level);
					if (!me->query("gift/2008xmas/times")) me->set("gift/2008xmas/times",1);
					me->set("gift/2008xmas/family_name",me->query("family/family_name"));
					log_file("2008xmas",me->name() + "得到了能读到" + me->query("gift/2008xmas/max_skill") + "级的" + CHINESE_D->chinese(me->query("gift/2008xmas/skill_name"))+"秘籍\n");
					return;
				}
			}
		}
	}
	set_book("literate",100);
	ob->set("desting",1);
	call_out("dest",1);
}
