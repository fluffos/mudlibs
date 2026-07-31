// yaoshi.c 药师
// Created by Numa 1999-12-16

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

string do_heal();
int do_give();

void create()
{
	set_name("药师", ({ "yao shi", "yao", "shi" }) );
	set("gender", "男性" );
	set("age", 40);
	set("long","这是一位年长的老者,对医术相当精通。\n");
	set("combat_exp", 100000);
	set("unique", 1); 
	set("no_get","药师对你而言太重了。\n");
        set("attitude", "peaceful");
	create_family("嵩山派", 6, "弟子");

	set("vendor_goods", ({
		([ "name":MEDICINE_D("huiyang"), "number":3 ]),
		([ "name":MEDICINE_D("jinchuang"), "number":5 ])
	}));

	set("inquiry", ([
		"name":	"我的医术可是数一数二的。",
		"疗伤":	(: do_heal :),
		"丹药": (: do_give :),
	]));
	set("have_dan",5);
	setup();
	carry_object(ARMOR_D("changpao1"))->wear();
}

void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment()) return;
	command("say 这位"+RANK_D->query_respect(ob)+"请了，请问要用些什么药？");
}

string do_heal()
{
	object me = this_player();
	object ob = this_object();
//	int hurt;

	if (!me->query_temp("ss/ready_heal"))
		return "这位"+ RANK_D->query_respect(me) +"，您总得意思意思吧？";

	if (ob->query_temp("busy"))
		return "这位"+ RANK_D->query_respect(me) +"，我正忙着呢！";

/*
	if (ob->query_temp("last") == me->query("id"))
		return "这位"+ RANK_D->query_respect(me) +"，我刚给你治疗过，你再等等吧！";
*/

//	hurt = me->query("max_qi") / me->query("eff_qi");

	if (me->query("eff_qi") >= me->query("max_qi"))
		return "这位"+ RANK_D->query_respect(me) +"，你好象没什么伤吧！";

	if (me->query("eff_qi")+me->query_temp("apply/qi") < (me->query("max_qi") + me->query_temp("apply/qi")) / 4)
		return "这位"+ RANK_D->query_respect(me) +"，你伤势过重，还是去准备后事吧！";

	me->delete_temp("ss/ready_heal");
	ob->set_temp("last",me->query("id"));
	ob->set_temp("busy",1);
	command("nod");
	message_vision(HIR"\n$n把了把脉，迅速的点了$N周身的几处大穴，紧接着双掌抵向$N后心传输真气。\n"NOR,me,ob);
	message_vision(HIW"只见$N的血渐渐止住，伤势也大为好转。\n"NOR,me,ob);
	me->set("eff_qi", me->query("max_qi"));
//	ob->receive_curing("qi", 100+random(500-hurt));
	remove_call_out("finish");
	call_out("finish", 20, ob);
	return "恩，好了，你自己再去修养下吧。";
}

int finish(object ob)
{
	if (!ob)
		return 1;
	ob->delete_temp("busy");
	return 1;
}

int accept_object(object who, object ob)
{
	int hurt;
	
	if (!who->query("family") || who->query("family/family_name") != "嵩山派") {
		command("say 这位"+ RANK_D->query_respect(who) +"，你好象跟我派并没有什么来往吧！");
		return 0;
	}
	if (ob->query("money_id")) {
		hurt = (who->query("eff_qi")/who->query("max_qi"))*10;
		hurt = 10-hurt;
		if ( hurt < 1) hurt = 1;
		if (ob->value() >= hurt*10000) {
			command("hehe");
			command("say 这位"+ RANK_D->query_respect(who) +"，您准备好，我来给您疗伤(Ask shi about 疗伤)。");
			who->set_temp("ss/ready_heal",1);
			return 1;
		}
		else {
			command("hmm " + who->query("id"));
			command("say 这位"+ RANK_D->query_respect(who) +"，这点也太少了吧？！");
			return 0;
		}
	}
	else {
		command("say 这是什么破烂玩意，你还是自己留着吧！");
		return 0;
	}
}

int do_give()
{
	object me = this_object();
	object ob = this_player();
	object obj;
	
	if (!ob->query("family") || ob->query("family/family_name") != "嵩山派") {
		command("say 这位"+ RANK_D->query_respect(ob) +"，你好象跟我派并没有什么来往吧！");
		return 1;
	}
/*
	if (!ob->query_temp("ss/give_dan")) {
		command("shake");
		command("say 未经左掌门允许，我可不敢擅自将丹药发给你！");
		return 1;
	}
*/
	if (ob->query_condition("medicine")) {
		command("say 这位"+ RANK_D->query_respect(ob) +"，你刚吃过灵药，还是再等等吧！");
		return 1;
	}
	
	if (!me->query("have_dan") < 1) {
		me->set("have_dan",0);
		command("say 丹药已经发完了。");
		return 1;
	}
	
	if (!(obj=load_object("/clone/medicine/songyang-dan"))) {
		command("say 这位"+ RANK_D->query_respect(ob) +"，丹药还没有练制出来！");
		return 1;
	}
	
	message_vision("$n递给$N一颗嵩阳丹。\n",ob,me);
	obj->move(ob);
	message_vision("$n对着$N说道：这可是我们嵩山的灵药，您可要小心使用！\n",ob,me);
	me->add("have_dan",-1);
	return 1;
}
