//xjkx by deng 2001
#include <ansi.h>#include "quest/guojob/zzzjob.c"
inherit NPC;

int ask_job();
int ask_job_gb();
void job_running_2();
int ask_job_time();
void job_running();
void job_starting();
void no_job();
int ask_finish();

void create()
{
	set_name("郭靖", ({"guo jing", "guo", "jing"}));
	set("nickname", HIY"北侠"NOR);
	set("gender", "男性");
	set("age", 40);
	set("long", "他就是威振天下的大侠郭靖，第二次华山论剑后号称“北侠”。\n");
        set("attitude", "friendly");
	set("str", 50);
	set("int", 10);
	set("con", 50);
	set("dex", 25);
	set("unique", 1);
	set("no_get", 1);

	set("max_qi", 9000);
	set("max_jing", 8000);
	set("neili", 18000);
	set("max_neili", 15000);
	set("jiali", 100);
	set("eff_jingli",9000);
	set("combat_exp", 3500000);

	set_skill("force", 300);
	set_skill("finger",300);
	set_skill("tanzhi-shentong",300);
	set_skill("yiyang-zhi",300);
	set_skill("claw",300);
	set_skill("huntian-qigong", 300);
	set_skill("strike", 300);
	set_skill("xianglong-zhang", 320);
	set_skill("dodge", 300);
	set_skill("jinyan-gong", 300);
	set_skill("parry", 300);

	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("dodge", "jinyan-gong");
        map_skill("parry", "xianglong-zhang");
	map_skill("finger","tanzhi-shentong");
prepare_skill("strike", "xianglong-zhang");

	set("inquiry", ([
		"守城": (: ask_job :),
		"功劳": (: ask_job_time :),
		"工作": (: ask_job_gb :),
		"完成": (: ask_finish :),
	]) );

	set_temp("apply/damage",100);
	set_temp("apply/defence",100);
	set_temp("double_attack",1);

	set("start",1);
	set("thjob",5);
	set("gbjob",5);
	set("gmjob",5);
	set("emjob",5);
	set("job",5);
	set("finish",0);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "strike.xiao" :),
		(: perform_action, "strike.paiyun" :),
		(: perform_action, "strike.kanglong" :),
	}));
	create_family("丐帮", 18, "帮主亲传弟子");
	setup();

	
}

void kill_ob(object me)
{
	if (userp(me)) me->apply_condition("kill_guo", 200);
	::kill_ob(me);
}


void die()
{
	command("chat 蓉....蓉儿，我先走...一步了！");
	command("chat 盼你完成屠龙刀....和....和倚.....");
	::die();
}

int ask_job_time()
{
	object me = this_player();
	int i;
	if(!intp(i = me->query("xy/job")) || i <= 1 )
	{
		command("say 你从来没帮忙吧？");
		return 1;
	}
	message_vision("$N对$n说道：你已帮忙守城" + chinese_number(i) + "次。\n", this_object(), me);
	command("courage " + me->query("id"));
	return 1;
}


int ask_job()
{
	object me = this_player();
	object ob = this_object();

	if (me->query("combat_exp")<800000)
	{
		command("say 多谢好意，但是这里对你来说太危险了。");
		return 1;
	}
        if( me->query_condition("kill_guo") > 0)
        { 
               command("kick "+ me->query("id"));
               command("say 你这个卖国贼，竟敢杀我，还想守城？");
               command("kill "+ me->query("id"));
               return 1;
        }
	if (ob->query_temp("xy/nojob"))
	{
		command("say 蒙古兵受到重挫，暂时不会攻击了。");
		command("say 你别心急，先下去休息吧。");
		me->start_busy(5);
		return 1;
	}
	if (me->query_temp("xy/job"))
	{
		command("say 快去你的指定地点吧。");
		command("push " + me->query("id"));
		return 1;
	}
	if (query("start")>0)
	{
		 command("chat 蒙古兵就要攻城了，请各位小心！");
		 command("chat 不相干的人等，请不要接近城门！");
		 set("start",0);
		 set("finish",0);
		 call_out("job_starting",120);
	}
	if ((me->query("family/family_name") == "桃花岛")&&(query("thjob")>1))
	{
		command("say 原来是岳父的弟子，请到东门帮助那边的桃花弟子。");
		command("say 你们要在东门用阵法牵制敌人，多多小心。");
		me->set_temp("xy/job",1);
		me->apply_condition("guo_job",20);
		add("thjob",-1);
		return 1;
	}
	else if ((me->query("family/family_name") == "丐帮")&&(query("gbjob")>1))
	{
		command("say 是师父的徒弟？多谢相助。请在这里帮我。");
		command("say 这里是北门，首当蒙古兵的攻击，你要多小心。");
		me->set_temp("xy/job",1);
		me->apply_condition("guo_job",20);
		add("gbjob",-1);
		return 1;
	}
	else if ((me->query("family/family_name") == "峨嵋派")&&(query("emjob")>1))
	{
		command("say 是我小女儿的弟子？请到城中心帮忙她。");
		command("say 记得你们要居中应变，并且救护伤者。");
		command("say 城中可能早已有伏兵，你们要小心警戒。");
		me->set_temp("xy/job",1);
		me->apply_condition("guo_job",20);
		add("emjob", -1);
		return 1;
	}
	else  if ((me->query("family/family_name") == "古墓派")&&(query("gmjob")>1))
	{
		command("say 原来是过儿的帮手？请到西门帮忙我的徒弟们。");
		command("say 他们武功勉强过得去，你请多费心了。");
		me->set_temp("xy/job",1);
		me->apply_condition("guo_job",20);
		add("gmjob",-1);
		return 1;
	}
	else if (query("job")>1)
	{
		command("say 那么，请到南门帮忙我的女儿女婿吧。");
		command("say 虽然那里远离战场，还是要小心蒙古兵突然出现。");
		me->set_temp("xy/job",1);
		me->apply_condition("guo_job",20);
		add("job",-1);
		return 1;
	}
	command("say 多谢好意，我们人手已经足够了。");
	command("thank "+me->query("id"));
	return 1;
}


int ask_job_gb()
{
	object me = this_player();

	if(!me->query_temp("xy/job"))
	{
		  command("say 你是要帮忙守城么？");
		  return 1;
	}
	if (me->query("family/family_name") != "丐帮")
	{
		  command("say 你快去指定的地点吧，看来蒙古兵就要攻城了！");
		  command("push");
		  return 1;
	}
	command("nod");
	command("say 看来再过一会蒙古兵就要开始攻击了，你快准备一下吧。");
	me->set_temp("xy/job",2);
	return 1;
}

void job_starting()
{
	if (query("gbjob")+query("thjob")+query("emjob")+query("gmjob")<18) {
		command("chat 蒙古兵开始攻击了，大家好好守住襄阳！");
		command("chat 城中也出现了敌军的奸细，大家不要乱了阵脚！");
		call_out("job_running", 20);
		call_out("no_job", 1800+random(600));
		this_object()->set_temp("xy/nojob",1);
	} else {
		command("chat 蒙古兵似乎突然退却了，请各位休息一下吧。");
		set("start",1);
		set("finish",0);
		set_temp("xy/nojob",1);
		call_out("no_job", 600+random(120));
	}
}

void job_running()
{
	object ob, tmp, room = load_object("/d/xiangyang/qinglongmen");
	int i;

	set("start",1);
	set_temp("xy/nojob",1);
	ob = new("/d/xiangyang/npc/wushi");
	ob->move(room);
	if (tmp = present("cheng ying", room)) {
		ob->kill_ob(tmp);
		tmp->kill_ob(ob);
	}
	if (tmp = present("feng mofeng", room)) {
		ob->kill_ob(tmp);
		tmp->kill_ob(ob);
	}
	if (tmp = present("wu tianfeng", room)) {
		ob->kill_ob(tmp);
		tmp->kill_ob(ob);
	}
	for(i = 0; i < (7-query("thjob")); i++)
	{
		ob = new("/d/xiangyang/npc/bing");
		ob->move(room);
		if (tmp = present("cheng ying", room)) {
			ob->kill_ob(tmp);
			tmp->kill_ob(ob);
		}
		if (tmp = present("feng mofeng", room)) {
			ob->kill_ob(tmp);
			tmp->kill_ob(ob);
		}
		if (tmp = present("wu tianfeng", room)) {
			ob->kill_ob(tmp);
			tmp->kill_ob(ob);
		}
	}
	room = load_object("/d/xiangyang/xuanwumen");
	for(i = 0; i < (7-query("gbjob")); i++)
	{
		ob = new("/d/xiangyang/npc/wushi");
		ob->move(room);
		if (tmp = present("guo jing", room)) {
			ob->kill_ob(tmp);
			tmp->kill_ob(ob);
		}
		if (tmp = present("dizi", room)) {
			ob->kill_ob(tmp);
			tmp->kill_ob(ob);
		}
		if (tmp = present("dizi 2", room)) {
			ob->kill_ob(tmp);
			tmp->kill_ob(ob);
		}
		if (tmp = present("dizi 3", room)) {
			ob->kill_ob(tmp);
			tmp->kill_ob(ob);
		}
	}
	room = load_object("/d/xiangyang/baihumen");
	for(i = 0; i < (9-query("gmjob")); i++)
	{
		ob = new("/d/xiangyang/npc/bing");
		ob->move(room);
		ob->set("combat_exp",800000);
		if (tmp = present("wu xiuwen", room)) {
			ob->kill_ob(tmp);
			tmp->kill_ob(ob);
		}
		if (tmp = present("wu dunru", room)) {
			ob->kill_ob(tmp);
			tmp->kill_ob(ob);
		}
		if (tmp = present("wanyan ping", room)) {
			ob->kill_ob(tmp);
			tmp->kill_ob(ob);
		}
		if (tmp = present("yelv yan", room)) {
			ob->kill_ob(tmp);
			tmp->kill_ob(ob);
		}
	}
	room = load_object("/d/xiangyang/cross2");
	for(i = 0; i < (7-query("emjob")); i++)
	{
		ob = new("/d/xiangyang/npc/bing");
		ob->move(room);
		ob->set_name("奸细", ({ "spy" }));
		if (tmp = present("guo xiang", room)) {
			ob->kill_ob(tmp);
			tmp->kill_ob(ob);
		}
		if (tmp = present("dizi", room)) {
			ob->kill_ob(tmp);
			tmp->kill_ob(ob);
		}
		if (tmp = present("dizi 2", room)) {
			ob->kill_ob(tmp);
			tmp->kill_ob(ob);
		}
		if (tmp = present("dizi 3", room)) {
			ob->kill_ob(tmp);
			tmp->kill_ob(ob);
		}
	}
	call_out("job_running_2",120);
}

void job_running_2()
{
	object ob, tmp, room = load_object("/d/xiangyang/zhuquemen");
	int i;

	command("chat 我方得到的消息正确！南门出现了大批人马！");
	command("chat 各人把附近敌军收拾完后火速到南门支援！");
	for(i = 0; i < (10-query("job")); i++)
	{
		ob = new("/d/xiangyang/npc/wushi");
		ob->move(room);
		if (tmp = present("guo fu", room)) {
			ob->kill_ob(tmp);
			tmp->kill_ob(ob);
		}
		if (tmp = present("yelv qi", room)) {
			ob->kill_ob(tmp);
			tmp->kill_ob(ob);
		}
	}
	set("finish",1);
}

int ask_finish()
{
	object me = this_player();
	int exp, pot;

	if (me->query_temp("xy/job") < 3)
	{
		command("say 你又没出什么力！");
		command("kick " + me->query("id"));
		return 1;
	}
	if (query("finish")!=1)
	{
		command("say 现在战况紧急，多留意敌人动向吧！");
		return 1;
	}
	command("admire " + me->query("id"));
	command("say 在下代表襄阳城的百姓向你道谢。");
	me->add("xy/job",1);
	exp=random(me->query("xy/job")/5 )+ (me->query_temp("xy/job")-2)*50 + 300 + random(200);
	if(exp > 1500) exp = 1300 + random(300);
	if (exp < 500) exp = 400 + random(100);
	pot = exp/5 +random(exp/4);
	me->add("combat_exp",exp);
	if(me->query("potential") + pot > me->query("max_pot"))
		me->set("potential", me->query("max_pot"));
	else me->add("potential", pot);
	message_vision(HIW"$N获得了"+CHINESE_D->chinese_number(exp)+
		"点经验，"+ CHINESE_D->chinese_number(pot)+
		"点潜能的奖励。\n"NOR, me);
        if (me->query("family/family_name") != "桃花岛" &&
            me->query("family/family_name") != "姑苏幕容" &&
            me->query("family/family_name") != "丐帮" &&
            me->query("family/family_name") != "古墓" ){
		me->add("shen",exp*10);
		message_vision(HIW"$N的侠义正气上升了！\n"NOR,me);
	}
	me->delete_temp("xy/job");
	log_file("job/xyjob", sprintf("%s %s(%s)%d次守城得到经验%d，潜能%d。\n",
		ctime(time())[4..19],me->name(1),me->query("id"),(int)me->query("xy/job"),exp,pot));
	return 1;
}

void no_job()
{
	delete_temp("xy/nojob");
	set("thjob",5);
	set("gbjob",5);
	set("gmjob",5);
	set("job",5);
	set("emjob",5);
}

int hit = 0;

int hit_ob(object me, object ob, int damage)
{
        hit+=2;
        if (damage > 800) return (800-damage);
        return 0;
}

int ob_hit(object me, object ob, int damage)
{
        if (!hit) return -damage*8/10;
        hit--;
        return 0;
}
