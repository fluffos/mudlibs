#include <ansi.h>;
inherit "/kungfu/class/generate/chinese";

string *names = ({
	"西夏卫兵","西夏探子","西夏武士","西夏刺客","西夏高手","副指挥使","指挥使","军主",
});

void create()
{
	string *fams;

	set_name("西夏武士", ({"xixia wushi",}));
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");

	setup();
	fams = keys(init_family);
	setup_family(fams[random(sizeof(fams))]);
}

int accept_fight(object me)
{
	tell_object(me,"既然来挑战就放开手脚，别畏手畏脚的！\n");
	return 0;
}

void init_data(int level)
{
	object me = this_object();
	mapping smap = me->query_skills();
	int lvl,i;
	string *skills;

	set_name(names[level-1], ({"xixia bing",}));

	//西夏武士的等级与副本env等级关联
	lvl = 100+level*50;

	skills = keys(smap);
	for(i=0;i<sizeof(skills);i++)
	{
		me->set_skill(skills[i],lvl);
	}

	//修为，气血，附加伤害力等与等级关联
	me->set("combat_exp",lvl*lvl/10*lvl+10000);
	me->set_temp("apply/damage",lvl*2);
	me->set("jiali",lvl*2);
	me->set("qi",lvl*30);
	me->set("eff_qi",lvl*30);
	me->set("max_qi",lvl*30);
	me->set("jing",lvl*20);
	me->set("eff_jing",lvl*20);
	me->set("max_jing",lvl*20);
	me->set("neili",lvl*30);
	me->set("max_neili",lvl*30);
}

void die()
{
	int sllv,i,pot,exp;
	object weap,bo,me = this_object();
	object ob,obj;
	string *items,str;
	mapping give;

	//西夏sllv:1-8
	sllv = environment()->query("sllv");

	//随机掉落物品奖励及概率列表掉落概率跟副本等级有关
	give =  ([
		"/clone/vip/putao" : (10-sllv)*2,
	]);

	items = keys(give);
	for(i=0;i<sizeof(items);i++)
	{
		if(random(give[items[i]])==0)
		{
			obj = new(items[i]);
			obj->move(environment(this_object()));
		}
	}

	if (objectp(ob = query_last_damage_from()))
	{
		//获得修为和实战，跟副本等级有关
		exp = ob->improve_experience(sllv*50);
		pot = ob->improve_potential(sllv*50);

		tell_object(ob, sprintf(HIG "你击败"+query("name")+"，获得了%s点潜能、%s点实战体会。"NOR"\n",
				chinese_number(pot),chinese_number(exp)));

	}
	destruct(me);
}
