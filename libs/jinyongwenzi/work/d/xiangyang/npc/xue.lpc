// xuemuhua.c 薛慕华
// Creat By Looklove for a quest y2k 4.20
// Looklove fix hubei at 2000.8.23
// Looklove Modify at 2000.10.8

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

int ask_me();
int ask_quest();
int ask_help(object);
int ask_teach();
int do_teach(string arg);

void create()
{
	set_name("薛慕华", ({ "xue muhua", "xue" }));
	set("long", 
		"他就是号称阎王敌的神医——薛慕华，据说他精通医理，可以起死回生。\n");
	set("gender", "男性");
	set("nickname",HIC"阎王敌"NOR);
	set("title",HIG"函谷八友"NOR);
	set("attitude","friendly");
	set("age", 42);
	set("str", 30);
	set("int", 30);
	set("con", 25);
	set("dex", 30);
	set("shen_type", 1);
	set("unique",1);
	set("no_get","薛神医太重了，你背不起来。\n");

	set("vendor_goods", ({
		([ "name":MEDICINE_D("huiyang"), "number": 3 ]),
		([ "name":MEDICINE_D("jinchuang"), "number": 5 ]),
		([ "name":MEDICINE_D("jingmai/jingmai-book2"), "number": 1 ])
	}));

	set("max_jing", 1700);
	set("eff_jing",1700);
	set("max_jingli",2000);
	set("eff_jingli",2000);
	set("jiali", 100);
	set("max_qi", 3500);
	set("neili", 8000);
	set("max_neili", 5000);
	set("combat_exp", 1200000);

	set_skill("force", 229);
	set_skill("dodge", 229);
	set_skill("hand",229);
	set_skill("strike",229);
	set_skill("parry", 229);
	set_skill("lingbo-weibu",229);
	set_skill("beiming-shengong",229);
	set_skill("zhemei-shou",229);
	set_skill("liuyang-zhang",229);
	set_skill("literate",240);
	set_skill("jingmai-xue",180);
	set_skill("medicine",180);
	set_skill("art",180);
		
	map_skill("force", "beiming-shengong");
	map_skill("parry", "zhemei-shou");
	map_skill("dodge", "lingbo-weibu");
	map_skill("hand", "zhemei-shou");
	map_skill("strike", "liuyang-zhang");
	
	prepare_skill("hand", "zhemei-shou");

	set("inquiry", ([
		"针灸": "针灸的学问可是很深奥啊。",
		"疗伤" : (:ask_me:),
		"学问" : (:ask_quest:),
		"武功" : (:ask_teach:),
		"救人" : (:ask_help:),
	]) );

	setup();
	add_money("gold", 5);
	carry_object(ARMOR_D("cloth"))->wear();
}

int ask_me()
{
	object ob;
	ob=this_player();

	if (ob->query("xue/teach")<5) {
	    command("hehe");
	    command("say 阁下武功是否能指导我一些？");
	    return 1;
	}
	if (ob->query("eff_qi") >= ob->query("max_qi")
	&& ob->query("eff_jing") >= ob->query("max_jing"))
	{
		command("? "+ob->query("id"));     
		command("say 你根本没受伤，跑我这里添乱！\n");
		command("knock "+ob->query("id"));
		return 1;
	}
	else
	{
		message_vision("薛神医拿出一根银针轻轻捻入$N受伤部位附近的穴道，$N感觉舒服多了。\n", ob);
		ob->start_busy(3);
		call_out("recover", 5, ob);
		ob->delete("xue/teach");
		return 1;
	}
}

void recover(object ob)
{
	if (!ob || !present(ob)) return;
	ob->set("eff_qi", (int)ob->query("max_qi"));
	ob->set("eff_jing", (int)ob->query("max_jing"));  
	message_vision("一柱香的工夫过去了，$N觉得伤势已经基本痊愈了。\n",ob);
	command("say 江湖险恶,不小心的话，下次你就没这么幸运了。\n");
	command("pat "+ob->query("id"));
}

int ask_teach()
{
	object me = this_player();
	
	if (me->query("combat_exp")<500000) {
	   command("say 你的功夫太差，我可没兴趣。");
	   return 1;
	} else {
	   command("thank");
	   command("say 多谢，我会好好报答的。请使用 teach xue <skill> 来指导我。");
	   return 1;
	}
}

int ask_quest()
{
	object me = this_player();
	
	if (me->query("combat_exp")<500000) {
		command("say 你的功夫太差了。");
		return 1;
	}
	if (me->query_int() < 30) {
		command("say 你还是好好修修学问吧，做学问可不是件容易的事。");
		return 1;}
	if (me->query_skill("jingmai-xue",1)>150) {
		command("say 看来阁下也是个医道高手，我得向你多讨教。");
		return 1;}
	if (me->query("xue/teach")<20) {
		command("say 听说阁下武功不错。。。");
		command("wink");
		return 1;}
	if (me->query_skill("jingmai-xue",1)>=140) {
		command("say 学医者要有任道之心，你是否愿意帮我去救个人？");
		return 1;}
	if (me->query_skill("jingmai-xue",1)<120) {
		command("say 我看以你的天分，你能有现在的经脉学修为已经不错了。");
		return 1;}
	else {
		command("say 拿去好好研究吧。");
		command("addoil");
		message_vision(HIY"薛神医给$N一本针灸概论。\n"NOR, me);
		new(MEDICINE_D("jingmai/jingmai-book4"))->move(me);
	return 1;
    } 
}

int ask_help(object me)
{
   	int i;
    	object *list;
    	object where, target;
    	object potion;
	
	if (this_player()) me = this_player();
	if (!me) return 0;
    	if (me->query_temp("count")>10) {
		command("say 现在似乎没什么人需要救援。");
		me->delete_temp("count");
		return 1;
	}
    	if (me->query("combat_exp")< 500000 ) {
		command("say 你经验太低，学了也没用。");
		return 1;
	}
    	if (me->query_skill("jingmai-xue",1)<140) {
		command("say 你经脉学技巧太低。");
		return 1;
	}
    	if (me->query_skill("jingmai-xue",1)>=150) {
		command("say 你实习的够多了，应该再去找书更进一步研究。");
		return 1;
	}
    	if (query("waiting")) {
		command("say 你等等吧，我在等人呢。"); 
		return 1;
	}
    	list = filter_array(users(), (: $1->query("combat_exp")>=500000 :));
    	target = list[random(sizeof(list))];
    	i = target->query("combat_exp")/5;
    	where = environment(target);
    	
    	if ((!environment(target)) ||
	(wizardp(target) || target->query("env/invisibility")) ||
	(!interactive(target)) ||
	(target->query("combat_exp")<me->query("combat_exp")-i*2) ||
	(target->query("combat_exp")>me->query("combat_exp")+i*2) ||
	(query_idle(target) > 2000) ||
	(target->query("id") == me->query("id"))){
		me->add_temp("count",1);
		call_out("ask_help", 1, me);
		return 1;
	} 
	else {
		command("say 听说有人被星宿派的恶贼下了慢性毒药，自己却不知。");
		command("say 请找到"+HIR+target->query("name")+HIW+"("+target->query("id")+")"+CYN"。");
		command("say 你去"+HIG+where->query("short")+CYN+"找找看。");
		command("thank");
		command("say 用这瓶药水，heal <"+target->query("id")+"> 就可以了。");
		potion = new(__DIR__"obj/potion");
		potion->set("target",target->query("id"));
		potion->move(me);
		set("waiting",1);
		return 1;
    	}
}

int do_teach(string arg)
{
	object me = this_player();
	string ob, skill;
	object target;

	if (me->query("combat_exp")<500000) {
		command("say 你的功夫太差了。");
		return 1;
	}
	if(!arg || sscanf(arg,"%s %s",ob,skill)!=2)
		return notify_fail("你要做什么？\n"); 
	target = present(ob);
	if (!target) return notify_fail("这里没有这个人。\n");
	if (target != this_object())
		return notify_fail("你想利用 BUG 么？\n");
	if (me->query_skill(skill,1)<100)
		return notify_fail("你的这个技能太差了，薛神医可没兴趣。\n");
	if (target->query_skill(skill,1)>=50)
		return notify_fail("薛神医的这个技能已经不能再进步了。\n");
	target->set_skill(skill, target->query_skill(skill, 1)+10);
	message_vision("$N向$n仔细地解说。\n",me, target);
	me->add("xue/teach",1);
	return 1;
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_teach","teach");
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if(!ob || environment(ob) != environment()) return;
	if(ob->query_temp("xue_finish")) {
		command("ah");
		command("say 总算没让那些星宿的恶贼得逞。");
		command("thank");
		command("say 我这本秘藏的脉经你拿去研究研究吧！");
		message_vision(HIY"薛幕华给了$N一本孙思邈千斤方。\n"NOR, ob);
		new(MEDICINE_D("jingmai/jingmai-book5"))->move(ob);
		ob->delete_temp("xue_finish");
		delete("waiting");
		return; 
	}
	command("say 这位"+RANK_D->query_respect(ob)+"请了，请问有什么事么？");
}
