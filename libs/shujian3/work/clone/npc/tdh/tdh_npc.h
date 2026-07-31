// tdh_npc.h
// Creat by Lklv , include for 天地会各堂香主 NPC

#include <ansi.h>
#include <get_place.h>
#include "place.h"
#include "skill.h"

void heart_beat()
{
	::heart_beat();

	clear_conditions_by_type("poison");
	if( !is_fighting() && living(this_object()))
	{
		reincarnate();
		remove_all_killer();
	}
}

string ask_fail()
{
	object me= this_player();
	if ( !me->query_temp("tdhjob"))
		return "你又没领过任务，放弃什么啊？";
	if ( me->query_temp("天地会job/lost"))
		return "你又没领过任务，放弃什么呀？";
	if ( me->query_temp("天地会job/get_name"))
		return "你已经与"+ me->query_temp("天地会job/get_name")+"联系上了，还是快点去和"+me->query_temp("天地会job/target_1")+"会合吧！";
	me->delete_temp("天地会job");
	me->delete_temp("tdhjob");
	log_file("job/tiandi", sprintf("%8s%-10s第%4d次任务放弃，现经验：%d。",
		me->name(), "("+me->query("id")+")", me->query("job_time/天地会")+1, me->query("combat_exp")), me);
	return "既然你做不了，也就算了。";
}

int ask_join()
{
	object me=this_player();

	if (me->query_temp("asktimes") > 10) {
		command("say 你到这里胡乱打听什么？是不是朝廷派来的探子！");
		return 1;
	}
	if (me->query("天地会")) {
		command("whisper "+me->query("id")+" 这里人多嘴杂，不要泄漏了我们的身份。");
		return 1;
	}
	command("say 原来"+RANK_D->query_respect(me)+"也知道万大哥的名号，是想入会嘛？");
	command("look "+me->query("id"));
	me->set_temp("天地会join",1);
	me->add_temp("asktimes",1);
	return 1;
}

int ask_tdh()
{
	object me=this_player();

	if (me->query_temp("asktimes") > 10) {
		command("say 你到这里胡乱打听什么？是不是朝廷派来的探子！");
		return 1;
	}
	if (me->query_temp("天地会join")==2) {
		command("say "+RANK_D->query_respect(me)+"既然没有诚意，那就算了。");
		me->add_temp("asktimes",1);
		return 1;
	}
	if (me->query_temp("天地会join")==1) {
		command("look "+me->query("id"));
		command("whisper "+me->query("id")+" 你可知道我们做的是什么事？");
		me->set_temp("天地会join", 2);
		me->add_temp("asktimes",1);
		return 1;
	}
	if (!me->query("天地会")){
		command("look "+me->query("id"));
		me->add_temp("asktimes",1);
		command("say 据说那是一个地下帮会，宗旨是反清复明，朝廷现在正在到处缉拿他们。");
		return 1;
	}
	command("shutup "+me->query("id"));
	command("whisper "+me->query("id")+" 这里人多嘴杂，不要泄漏了我们的身份。");
	return 1;
}

int ask_fq()
{
	string tk, tname;
	object me=this_player();
	object ob=this_object();

	tk = ob->query("天地会/tangkou");
	tname = ob->query("天地会/title");

	if (me->query_temp("asktimes") > 10) {
		command("say 你到这里胡乱打听什么？是不是朝廷派来的探子！");
		ob->kill_ob(me);
		return 1;
	}

	if (me->query_temp("天地会join")==2) {
		command("touch "+me->query("id"));
		command("say 欢迎加入天地会"+tk+"。");
		command("say 以后大家就是自己人了，我是"+tk+tname+"。");
		me->delete_temp("天地会join");
		me->delete_temp("asktimes");
		me->set("天地会/tangkou", tk);
		me->set("天地会/title", "会众");
		// 临时title
		me->set_temp("title", HIR"天地会"+tk+"会众"NOR);
		ob->set_temp("title", HIR"天地会"+ob->query("天地会/tangkou")+ob->query("天地会/title")+NOR);
		ob->set("joined", me->query("id"));
		return 1;
	}
	if (!me->query("天地会")) {
		command("fear "+me->query("id"));
		command("say 不要乱说，那可是要掉脑袋的！");
		me->add_temp("asktimes",1);
		return 1;
	}
	command("agree "+me->query("id"));
	return 1;
}

string ask_chen()
{
	object me=this_player();
	if (me->query_temp("asktimes") > 10)
		return"胡乱打听什么？就不怕我们总舵主的凝血神爪？\n";
	message_vision(CYN"$N对$n道：常听人说‘平生不识陈近南，就称英雄也枉然。’不知老兄可识得陈总舵主否？"NOR"\n", me, this_object());
	if (!me->query("天地会"))
		return "总舵主岂是你随便见的。\n";
	return "我也很想见总舵主一面，不过不知道他老人家在哪里。\n";
}

string ask_zheng()
{
	object me=this_player();

	if (me->query("天地会")) {
		command("nod "+me->query("id"));
		return "国姓爷是当世第一英雄，第二嘛，就要数我们总舵主了。\n";
	}
	return "他老人家是当世第一英雄。\n";
}


int ask_qk()
{
	object me=this_player();

	if (me->query_temp("asktimes") > 10) {
		command("say 你到这里胡乱打听什么？是不是朝廷派来的探子！");
		return 1;
	}
	if (!me->query("天地会")) {
		me->add_temp("asktimes",1);
		command("dunno ");
		return 1;
	}
	command("say 地振高冈，一派溪山千古秀。");
	return 1;
}

int ask_sandian()
{
	object me=this_player();

	if (!me->query("天地会")) {
		command("dunno "+me->query("id"));
		return 1;
	}
	if (!me->query_temp("天地会job")){
		command("look "+me->query("id"));
		return 1;
	}
	command("say 三点暗藏革命宗，入我洪门莫通风。养成锐势从仇日，誓灭清朝一扫空。");
	return 1;
}

int ask_job()
{
	int i, j, p;
	string tk, ttitle, str, str2, where;
	object me, ob, target, *living, fname, troom;

	me = this_player();
	ob = this_object();
	// 其中一个暂时没有用到, tk
	tk = me->query("天地会/tangkou");
	ttitle = me->query("天地会/title");
	str2 = me->query_temp("天地会job/start_place");

	if ((!me->query("天地会") && !wizardp(me))
	|| me->is_fighting() || me->is_busy() ) {
		command("bored "+me->query("id"));
		return 1;
	}
	if (me->query_temp("天地会job/start_place") && !wizardp(me)){
		command("whisper "+me->query("id")+" 速去"+ str2 +"。");
		return 1;
	}
	if ( me->query_temp("tdhjob") || me->query_condition("job_busy")){
		command("say 你还在做任务呢！");
		return 1;
	}
	if ( me->query("job_name") == "天地会" && !wizardp(me)){
		command("say 你刚完成任务，还是去休息会吧。");
		return 1;
	}

	message_vision(CYN"$N对$n躬身道：香主，在下想为帮会尽些微薄绵力，请吩咐。"NOR"\n", me,ob);

	if ( me->query("menggu")){
		message_vision(CYN"$N脸色一沉：“$n，前两天有人看见你投靠了蒙古鞑子，你认不认罪？”"NOR"\n", ob, me);
		command("say 不要等我发火，马上在我眼前消失！不然兄弟都没的做！");
		remove_call_out("check_killer");
		call_out("check_killer", 5, me, this_object());
		return 1;
	}
	else if ( me->query_temp("guanfu_jiebang") ){
		message_vision(CYN"$N脸色一沉：“$n，前两天有人看见你去官府揭榜，是也不是？”"NOR"\n", ob, me);
		command("consider "+me->query("id"));
		command("say 不要等我发火，马上在我眼前消失！不然兄弟都没的做！");
		remove_call_out("check_killer");
		call_out("check_killer", 5, me, this_object());
		return 1;
	}
	if ( me->query("combat_exp") < 100000 ){
		command("say " + RANK_D->query_respect(me) + "你武功未成，以后再说吧！");
		return 1;
	}

	p = me->query("job_time/天地会");

	if ( p > 1000 && ! me->query("quest/ningxue/time")) {
		if ( p % 50 == 0) {
			command("say 听说陈总舵主有事找你，你还是先去找总舵主询问吧。");
			me->set("quest/ningxue/meet", 1);
			return 1;
		}
	}

	(random(4)>1) ? command("consider"):command("ok "+me->query("id"));

	// 产生第一个npc target_1
	living = livings();
	for (i=0 ;i < sizeof(living); i++){
		j = random(sizeof(living));
		if (!j || j == sizeof(living) -1) continue;
		if(check(living[j]) ){
			fname = living[j];
			troom = environment(fname);
			str = troom->query("short");
			if (!sizeof(troom->query("exits"))
			|| str == "武僧堂"
			|| str == "西门"
			|| str == "东门"
			|| str == "南门"
			|| str == "北门"
			|| str == "城门"
			|| str == "衙门"
			|| str == "兵营"
			|| str == "客栈"
			|| str == HIR"心禅堂"NOR
			|| str == "金刚伏魔圈" ) continue;
			if (get_place(base_name(troom)) == get_place(base_name(environment(ob)))) continue;
			if( get_place(base_name(environment(fname))) != "" ) break;
		}
	}

	if( !fname ) {
		command("say 暂时没有事情需要做，以后再说吧。");
		return 1;
	}

	target = new(__DIR__"man1");
	target->set("天地会jober", me->query("id"));
	target->move(troom);

	for (i=0; i < 5; i++)
		target->random_move();

	if (environment(target)->query("no_fight"))
		target->random_move();

	copy_npc(me, target, 110);

	if (strsrch(file_name(environment(target)), "/d/zhiye/") >= 0 
	 || strsrch(file_name(environment(target)), "/d/group/") >= 0){
	 	if ( environment(target)->query("outdoors"))
			where =  environment(target)->query("outdoors")+environment(target)->query("short");
	 	else if ( environment(target)->query("indoors"))
			where =  environment(target)->query("indoors")+environment(target)->query("short");
		else where =  environment(target)->query("short");
	}
	else where = get_place(base_name(environment(target)))+environment(target)->query("short");

	log_file("job/tiandi",sprintf("%8s%-10s开始第%4d次任务，目标：%s的%s，目前经验：%d。\n",
		me->name(),"("+me->query("id")+")", me->query("job_time/天地会")+1, where,target->query("name"), me->query("combat_exp")), me);

	if (!stringp(ttitle)) ttitle = "会众";
	me->set_temp("title", HIR"天地会"+tk+ttitle+NOR);
	me->delete_temp("asked");

	me->set_temp("tdhjob", 1);
	me->set_temp("天地会job/start_place", where);
	me->set_temp("天地会job/target_1", target->name());
	me->set_temp("天地会job/target_1id", target->query("id"));
	me->set_temp("天地会job/time", uptime());
	me->apply_condition("job_busy", 10);
	command("whisper "+ me->query("id") +" 你马上去"HIC+ where +GRN "联络一个会里的兄弟。");
	command("whisper "+ me->query("id") +" 他的名字叫"HIW+target->query("name")+GRN"，你路上小心。");
	return 1;
}

int ask_target()
{
	string str;
	object me=this_player();

	if (!me->query("天地会")) return 0;
	if (!me->query_temp("天地会job/start_place")){
		command("say 我们一直在联络各地的反清志士。\n");
		return 1;
	}

	str = me->query_temp("天地会job/start_place");
	command("whisper "+me->query("id")+" 速去"+ str +"，快去快回。");
	return 1;
}

void init()
{
	object ob = this_player();

	::init();

	if ( interactive(ob) && userp(ob) && living(ob)) {
		if ( ob->query_temp("天地会job/lost") ) {
			remove_call_out("lost_job");
			call_out("lost_job", 0, ob);
		}
		else if ( stringp(ob->query_temp("kill_tdhnpc")) ) {
			remove_call_out("check_killer");
			call_out("check_killer", 0, ob, this_object());
		}
	}
}

void lost_job(object me)
{
	string target;

	if (!me || !present(me, environment(this_object())))
		return;

	target = me->query_temp("天地会job/lost");

	if (!target) return;

	if ( me->query_temp("天地会job/lost") ) {
		command("sigh "+me->query("id"));
		command("say 探子回报，"+target+"已经遇害了。");
		me->delete_temp("天地会job");
		me->delete_temp("tdhjob");
		return;
	}
}

void check_killer(object me, object ob)
{
	string target;

	if ( !ob) return;

	if (!me	 || !present(me, environment(ob)))
		return;

	if ( stringp (target = me->query_temp("kill_tdhnpc")) ) {
		message_vision(HIR"\n$N对$n大喝道：探子回报，你对我天地会兄弟"+target+"行凶，拿命来吧！"NOR"\n", ob, me);
		command("stare "+me->query("id"));
	}
	else {
		message_vision(HIR"\n$N双眼通红，突然对$n大喝道：你拿命来吧！"NOR"\n", ob, me);
	}
	ob->kill_ob(me);
	return;
}

void die()
{
	object killer;

	if ( objectp(killer = query_temp("last_damage_from")) && userp(killer)){
		killer->add("shen", -3000);
		killer->set_temp("kill_tdhnpc", this_object()->name());
	}
	command("say 鞑子的走狗！不得好死！");
	::die();
}

string ask_times()
{
	object me= this_player();
	int i;

	i = (int)me->query("job_time/天地会");

	if ( !me->query("天地会"))
		return "你不是天地会的人，我和你没什么好说的。";
	if ( !i ) return "你目前一次功劳也没有。";
	return "你目前已经积功"+chinese_number(i)+"次。";
}
