// Write By Yanyang@SJ 2001.9.20
// NPC: /d/changan/npc/zhanggui.c

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>

void create()
{
	set_name("酒楼掌柜",({ "jiulou zhanggui", "zhanggui" }) );
	set("long", "这是聚豪酒楼的掌柜。酒楼里大大小小的事情都由他负责。\n"+
		"你可以向他打听宴席的事情来预定酒宴。\n");

	set("shen_type", 1);
	set("str", 20);
	set("unique", 1);
	set("gender", "男性");
	set("age", 45);
	set("combat_exp", 35000);
	set("qi", 300);
	set("max_qi", 300);
	set("attitude", "friendly");

	set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);

	set("vendor_goods", ({
		(["name":FOOD_D("hdjiudai"),"number":20]),
		(["name":FOOD_D("jitui"),"number":20]),
		(["name":FOOD_D("kaoya"),"number":15]),
	}));

	set("inquiry", ([
		"宴席" : "本酒楼包办两种酒席：婚庆宴、群豪宴，客官要“ding”哪一种啊？",
	]));

	setup();

	carry_object(ARMOR_D("cloth"))->wear();
	add_money("silver", 50);
}

void init()
{        
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_ding","ding");
}

int do_ding(string arg)
{
	object me = this_player();
	mixed *ob_list;
	int max,i;
	object obj;
//	object room;

	if(!arg) {
		command("say 你要定“婚庆宴”和“群豪宴”的哪一种酒席？");
		return 1;
	}
	if(arg != "婚庆宴" && arg != "群豪宴") {
		command("say 你要定“婚庆宴”和“群豪宴”的哪一种酒席？");
		return 1;
	}
	if(me->query_temp("zhubanren"))  {
		command("say 客官，您的"+ me->query_temp("宴席") +"已经准备好了，请上楼用“start”吩咐我们开宴！");
		return 1;
	}
          
	ob_list = filter_array(children(USER_OB), (: clonep($1) && !wizardp($1) :));
	max=sizeof(ob_list);

	for(i=0;i<max;i++) {
		obj = ob_list[i];
		if (obj->query_temp("zhubanren")) {
			command("say 抱歉，现在正在操办" + obj->query("name") +"("+capitalize(obj->query("id"))+")的"+ obj->query_temp("宴席",1)+"呢！");
			return 1;
		}
	}

	if (! me->query_temp("宴席")){
		switch (arg){
			case "婚庆宴":	me->set_temp("宴席", arg);	break;
			case "群豪宴":	me->set_temp("宴席", arg);	break;
			default:	return notify_fail("没有这种宴席。\n");
		}
		command("say 好的！那请这位"+RANK_D->query_respect(me)+"交黄金五百两，就可以了。");
		return 1;
	}
	command("say 嗯？这位客馆不是已经预定了"+me->query_temp("宴席")+"了么？");
	return 1;
}

int accept_object(object me, object ob)
{
	if( ob->query("money_id")) {
		if ( me->query_temp("宴席") && ob->value() >= 5000000) {
			if (!me->query_temp("zhubanren")) {
				command("smile");
				command("say 好的！我们这就操办，客官楼上请，用“start”吩咐我们开宴！");
				me->set_temp("zhubanren",1);
				return 1;
			}
			command("? "+me->query("id"));
			command("say 这位客官的钱太多了？");
			return 0;
		}
		command("? "+me->query("id"));
		command("say 这位客官的钱太多了？");
		return 0;
	}
	command("? "+ me->query("id"));
	command("say 这位"+RANK_D->query_respect(me)+"，给我这"+ob->query("unit")+ob->query("name")+CYN"干吗啊？"NOR);
	return 0;
}
