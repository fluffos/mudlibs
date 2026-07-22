// NPC: /d/mr/npc/wang.c 王语嫣
// update by Lklv 2001.9.21
// LinuX@SJ 2004/02/28

#include <ansi.h>
#include <job_mul.h>
inherit NPC;

void create()
{
	set_name("王语嫣", ({ "wang yuyan", "wang" }));
	set("long", "她生得极为美貌,一双眼睛顾盼生辉.\n");
	set("nickname", "天下无不知");
	set("title","曼佗罗山庄庄主之女");
	set("gender", "女性");
	set("unique", 1);
	set("age", 20);
	set("attitude","friendly");
	set("str", 30);
	set("dex", 30);
	set("con", 30);
	set("int", 30);
	set("per", 30);
	set("max_qi", 5000);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);

	setup();
	carry_object(__DIR__"obj/skirt1")->wear();
	carry_object(__DIR__"obj/shoe")->wear();
	carry_object(__DIR__"obj/green_silk")->wear();
}

void init()
{
	add_action("lingwu","ask");
}

string *valid_type = ({
"force",	"parry",	"unarmed",	"claw",		"axe",
"brush",	"finger",	"strike",	"hand",		"leg",
"sword",	"blade",	"dagger",	"cuff",		"whip",
"staff",	"stick",	"throwing",	"hook",		"club",		
"spear",	"dodge",	"hammer",
});

int lingwu(string arg)
{
	object me=this_player();
	object where = environment(me);
	string special;
	int bl,sl;
	string name;
	mapping skills = me->query_skills();
	int i, j;

	if (!arg) return 0;
	if (!sscanf(arg, "%s about %s", name, arg)) return 0;
	if (!id(name)) return 0;

	if (!me->query("luohan_winner"))
		return notify_fail("你的十八罗汉大阵还没过，不能向王姑娘领悟武功。\n");
	write( "你向王语嫣请教关于「" + to_chinese(arg) + "」的疑问。\n");
	if (me->is_busy() || me->is_fighting()) {
		command("say 你正忙着呢。");
		return 1;
	}
	if(where->query("lingwu") != 1 )
		return notify_fail("你只能在娘缳玉洞向王姑娘领悟武功。\n");
	if (!(special=me->query_skill_mapped(arg))) {
		if (arg == to_chinese(arg))
			command("say 「" + arg + "」是什么武功？怎么我没听说过？");
		else
			command("say 我只能从你的特殊技能中给你指点。");
		me->add_busy(1);
		return 1;
	}
	if (!me->query_skill(arg,1)) {
		command("say 你不会这种技能。");
		me->add_busy(1);
		return 1;
	}
	if (arg == "force" && (int)me->query_skill("force",1)<200) {
		command("shake");
		command("say 你目前修为尚浅，不宜自己领悟基本内功。");
		me->add_busy(1);
		return 1;
	}
	if (me->query("potential") < 1) {
		write("你从实战中得到的潜能已经用完了。\n");
		me->add_busy(1);
		return 1;
	}
	bl=me->query_skill(arg,1);
	if (bl > me->query("jing") || me->query("jing")*100/me->query("max_jing") < 50) {
		me->receive_damage("jing",bl/2);
		command("say " + RANK_D->query_respect(me) + "先休息一下吧。");
		me->add_busy(1);
		return 1;
	}
	sl=me->query_skill(special,1);
	if (bl > sl) {
		command("say " + RANK_D->query_respect(me) + "的"+to_chinese(special)+"造诣不够，我不能指点你更深一层的"+to_chinese(arg)+"。");
		me->add_busy(1);
		return 1;
	}
	write("你听了" + name() + "的指点，对"+to_chinese(arg)+"的体会又深了一层。\n");
	
	if (me->query("registered") ==3 && me->query_temp("ggs/started") && me->query("ggs/started") ){
			if (!random(5))
			write("你参照自己在"HIG"鬼谷算术"NOR"上的修为，运神通数，觉得自己领悟起来事半功倍。\n");
			if (!random(10))
			tell_room(environment(me), me->name() + "正在参照"HIG"鬼谷算术"NOR"上的修为，运神通数，向王姑娘领悟武功。\n", ({ me }));
	}
		
	i = me->query_int(1);

	foreach (string skill in keys(skills))
		if (member_array(skill, valid_type) != -1 && me->query_skill(skill, 1) > me->query("max_pot") - 105)
			j++;

	if ( j < 5 ) j = 5;

	me->receive_damage("jing", bl*2/5);
	me->add("potential", -random(2));
	if(me->query("potential")>0) me->add("potential", -random(2));
	i = i *3/2; //增加pot消耗 增加尾数 by Ciwei
	i = i *3/2;
	if (me->query("age") < 30)
		i += 30-me->query("age");
	if (me->query("age") > 60)
		i += me->query("age") - 60;
	j = to_int( i * j/5.0);
	
	/*奖励控制开始*/
        if (me->query("registered")==3)
        {
		j = j * MR_LINGWU_MUL * VIP_LINGWU_MUL /10000;
        }
        else
        {
		j = j * MR_LINGWU_MUL /100;
        }
        /*奖励控制结束*/ 
        //工匠学武控制
        if(me->worker_skill("highest")>350) j = j*7/10;
	else if(me->worker_skill("highest")>220) j = j*8/10;
	if(me->worker_skill("limit")>600) j = j*8/10;
	//控制结束       
        if (me->query("registered") ==3 && me->query_temp("ggs/started") && me->query("ggs/started") )
		me->improve_skill(arg, j*2);
	else
		me->improve_skill(arg, j);

	if (wizardp(me) && me->query("env/test"))
	write (sprintf("测试信息：鬼谷术增加 %d 点，其他增加 %d 点\n",j*2,j));
	
	return 1;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	command("peace " + ob->query("id"));
}
