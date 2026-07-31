//xiao-tong2.c 小僮
inherit NPC;
#include <ansi.h>
string ask_tea();
string ask_food();
void create()
{
	set_name("小沙弥", ({ "xiao shami", "xiao","shami" }));
	set("gender", "男性");
	set("age", 19);
	set("long", "他是一个小沙弥。\n");
	
	set("combat_exp", 30000);
	set("shen_type", 100);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	set("inquiry", ([
		"茶" : (: ask_tea :),
		"食物" : (:ask_food:),
	]));

	setup();
	carry_object("/d/shaolin/obj/qing-cloth")->wear();
}

void init()
{       
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say(CYN"小沙弥阿弥陀佛道：这位" + RANK_D->query_respect(ob) + "请了，来这里用膳吧。\n"NOR);
}

string ask_tea()
{
	object ob, me = this_player();

	if ((me->query("water")*10/me->max_water_capacity())>8)
		return "你怎么喝饱了还想要？";
	if ( present("xiang cha", this_player()))
		return "先喝完了我给你的再说吧。";
	if ( present("xiang cha",  environment(me)) )
		return "那不是有吗？先喝完了再说。";
	ob=new(FOOD_D("cha"));
	ob->move(environment(this_object()));
	return "这杯香茶给你吧，慢点喝哟。";
}

string ask_food()
{
	object ob, me =this_player();

	if ((me->query("food")*10/me->max_water_capacity())>8)
		return "你怎么吃饱了还想要？";
	if ( present("mi fan", this_player()))
		return "先吃完了我给你的再说吧。";
	if ( present("mi fan",  environment(me)) )
		return "那不是有吗？先吃完了再说。";
	ob=new(FOOD_D("rice"));
	ob->move(environment(this_object()));
	return "这碗米饭给你吧，慢点吃哟。";
}
