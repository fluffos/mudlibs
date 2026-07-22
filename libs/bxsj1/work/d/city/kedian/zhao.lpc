#include <ansi.h>
#include <job_mul.h>

inherit NPC;
int ask_job();
int ask_finish();
int ask_quit();
int ask_cure();
object ppl;

void create()
{
	set_name("赵敏", ({ "zhao min", "zhao", "min" }));
	set("gender", "女性");
	set("long", "这是蒙古汝阳王的长女赵敏。\n");
	set("age", 18);
	set("str", 20);
	set("int",35);
	set("con",20);
	set("dex",30);
	set("per",45);
	set("no_get", 1);
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("max_qi",2000);
	set("max_jing",1000);
	set("neili",2000);
	set("max_neili",2000);
	set("qi",2000);
	set("jing",1000);
	set("jingli",1000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("literate", 300);

	set("inquiry", ([
		"工作": (: ask_job :),
		"完成": (: ask_finish :),
		"退出": (: ask_quit :),
		"解药": (: ask_cure :),
	]) );

	setup();
	carry_object(ARMOR_D("wcloth"))->wear();
	carry_object(ARMOR_D("pixue"))->wear();
}

void init()
{
	::init();
	add_action("do_quit", "abandon");
}

int ask_job()
{
	object me = this_player();
	int  exp;
	object where, target, *list;

	exp = me->query("combat_exp");
	if (me->query_temp("zhao")){
		command("say 快去找人呀！");
		return 1;
	}
	if (exp < 500000) {
		command("say 你武功太差啦。\n");
		return 1;
	}
	if (me->query("potential") > me->query("max_pot")){
		command("say 请先去发掘你的潜能吧，如此才能事半功倍。");
		command("giggle");
		return 1;
	}
	if( me->query_condition("job_busy")){
		command("say 暂时我没有什么有兴趣的武功。\n");
		return 1;
	}
	ppl = me;
	list = filter_array(users(), (:
    	    $1->query("combat_exp")/3 > ppl->query("combat_exp")/4
    	 && $1->query("combat_exp")/5 < ppl->query("combat_exp")/4
    	 && !wizardp($1)
    	 && $1->query_temp("user_type") != "worker"
    	 && query_idle($1)<120
    	 && !$1->query("menggu")
    	 && environment($1)
    	 && !$1->query_temp("caught")
    	 && !$1->query_temp("pigging_seat")
    	 && $1->query("duanzhi")<10
    	 && !$1->query_condition("ruanjin_poison")
    	 && $1->query("family")
    	 && query_ip_number($1) != query_ip_number(ppl)
   	 && !$1->query_condition("relax")
    	 && !$1->query_condition("wuguan_job")
	 && !$1->query_condition("killer")
    	:));
	list -= ({me,0});

	if(sizeof(list) < random(10)+1) {
		command("say 现在没什么高手，算了吧。\n");
		return 1;
	}

	target = list[random(sizeof(list))];
	if (target->query_temp("zm_job_time") > uptime()) {
		command("say 现在没什么高手，算了吧。\n");
		return 1;
	}
	target->set_temp("zm_job_time", uptime() + 3600);
	where = environment(target);
	me->set_temp("zhao/target",target->query("name"));
	me->set_temp("zhao/targetid",target->query("id"));
	me->apply_condition("job_busy", 4 + random(2));
	command("say 我想学点" + target->query("family/family_name") + "的武功，你帮我去抓个人来好吗？");
	command("wink");
	command("whisper " + me->query("id") + " 请到" HIR+ where->query("short") + CYN"带"HIW
	+ target->query("name") + HIY"(" + target->query("id") + ")"GRN"来这里。");
	command("say 这包十香软筋散你拿去吧。");
	command("say 假如无法劝降(quanxiang)，就让他服(fu)下这个。");
	new(__DIR__"letter")->move(me);
	new(__DIR__"ruanjin")->move(me);
	message_vision(HIY"$N得到了一小包十香软筋散与一封书信。\n"NOR,me);
	return 1;
}

int ask_finish()
{
	object me, ob;
	int exp, pot;
	string ob_id;

	me = this_player();
	if (!me->query_temp("zhao")){
		command("?");
		return 1;
	}
	ob_id = me->query_temp("zhao/targetid");
	ob = present(ob_id, environment(me));
	if (!ob){
		command("say 人呢？");
		command("angry");
		return 1;
	}
	if (sizeof(filter_array(deep_inventory(ob), (:userp:)))) {
		command("hmm");
		command("whisper "+me->query("id")+ " 这家伙怎么还背着个人啊？");
		return 1;
	}
	if( !ob->query_condition("ruanjin_poison")
	 && (!ob->query_temp("convinced"))) {
		command("hmm");
		command("whisper "+me->query("id")+ " 你怎么没把这家伙“处理”一下呀？");
		return 1;
	}
	command("hehe "+ob->query("id"));
	ob->apply_condition("wuguan_job",10+random(ob->query_kar()));
	message_vision("赵敏召来两个士兵，把$N带走了。\n",ob);
	ob->move(__DIR__"jail");
	command("smile "+me->query("id"));
	command("say 这里没你的事情了，请下去休息吧。");
	exp = random(4)+2;
	pot = me->query("combat_exp",1)/100000;
	pot += 100 + random(20) + me->query("job_time/赵敏");
	if (me->query("menggu")) pot += 30 + random(10);
	
       	/*奖励控制开始*/
        if (me->query("registered")==3){
			exp = exp * ZM_JOB_MUL * VIP_MUL /10000;
            		pot = pot * ZM_JOB_MUL * VIP_MUL /10000;
		}
		else
		{
			exp = exp * ZM_JOB_MUL /100;
           		pot = pot * ZM_JOB_MUL /100;
		}
		/*奖励控制结束*/ 	
	
	
	me->add("combat_exp",exp);
	me->add("potential",pot);
	if (me->query("menggu")) me->add("balance", exp*10000);
	me->add("job_time/赵敏",1);
	log_file("job/zhaomin", sprintf("%8s%-10s第%4d次抓人得到经验%2d，潜能%4d，现经验%d。\n",
		me->name(1),"("+me->query("id")+")",(int)me->query("job_time/赵敏"),exp,pot, me->query("combat_exp")), me);

	me->delete_temp("zhao");
	message_vision(HIW"$N得到了 "HIM+exp+HIW" 点经验，"
		HIG+pot+HIW" 点潜能！$N总共已抓了 "HIR+me->query("job_time/赵敏")+HIW" 个人。\n" NOR, me);
	GIFT_D->check_count(me,this_object(),"赵敏");
	me->apply_condition("job_busy", 5 + random(3));
	return 1;
}

int do_quit()
{
	object me = this_player();
	object ob;

	if (ob = present("shixiang ruanjinsan", me)) {
		command("look " + me->query("id"));
		destruct(ob);
		command("kick3 " + me->query("id"));
		me->delete_temp("zhao");
		me->add_condition("job_busy", 6 + random(4));
		return 1;
	}
	return 0;
}

int ask_quit()
{
	object me = this_player();

	if (me->query("menggu")) {
		command("sneer");
		command("say 我们也不需要你这种反复无常的家伙。");
		me->set("potential",0);
		me->add("combat_exp",-me->query("combat_exp")/100);
		message_vision(BLINK+HIR"$N因为反复无常，经验，潜能都降低了。\n"NOR,me);
		me->delete("menggu");
		return 1;
	}
	return 0;
}

int accept_object(object who, object ob)
{
	if (who->query("gender") != "男性") {
		command("idle " +who->query("id"));
		return 0;
	}
	if (ob->query("money_id") && ob->value() >= 500000) {
		if (!wizardp(who)) {
			command("en");
			return 1;
		}
		else {
			command("blush");
			command("remove all");
			command("lean "+who->query("id"));
			command("sweat "+who->query("id"));
			command("wear all ");
		}
		return 1;
	}
	return 0;
}

int ask_cure()
{
	object me = this_player();
	if (!me->query("menggu")) {
		command("en "+me->query("id"));
		return 1;
	}
//	else {
//		if (me->query("job_time/赵敏")/25 > me->query("zhaocure")) {
			command("ok zhao min");
			new(__DIR__"cure")->move(me);
			me->add("zhaocure",1);
			message_vision(HIG"$N得到了一包药粉。\n",me);
			return 1;
//		}
/*		else {
			command("en");
			command("say 你再帮忙我多作点事吧。");
			return 1;
		}
	}
*/
}

void kill_ob(object me)
{
	object ob;
	command("sneer " + me->query("id"));
	ob = present("lu zhangke",environment(me));
	if (ob) {
		ob->force_me("guard zhao min");
		ob->kill_ob(me);
	}
	ob = present("he biweng",environment(me));
	if (ob) {
		ob->force_me("guard zhao min");
		ob->kill_ob(me);
	}
	remove_all_enemy();
}
