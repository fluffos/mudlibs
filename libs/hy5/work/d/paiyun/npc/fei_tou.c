// fei_tou.c

inherit NPC;

int is_paiyun() { return 1;}

void create()
{
	set_name("山匪头目", ({ "shanfei toumu" }) );
	set("long", "这是一位山匪小头目。\n");

	set("max_qi", 5000);
	set("max_jing", 5500);
	set("max_sen", 5000);
	set("max_neili",5500);
	set("neili",5500);
	set("force_factor",60);
	set("str", 40);
	set("cor", 30);
	set("kar", 35);
	set("combat_exp", 2000000);

	set_skill("blade", 300);
	set_skill("liuhe-dao",320);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 220);

	map_skill("blade","liuhe-dao");
	map_skill("parry","liuhe-dao");

	setup();

	carry_object(__DIR__"obj/armor")->wear();
	carry_object(__DIR__"obj/blade")->wield();
}

int accept_kill(object me)
{
	object *obs;

	if(!environment())
		return 0;

	say("山匪头目狠狠的说道：爷这两天没吃人肉，嘴都淡出鸟了！\n");

	obs = filter_array(all_inventory(environment()) - ({this_object()}),(: $1->is_paiyun() :));

	if(sizeof(obs))
		obs->kill_ob(me);
	return 1;
}

int accept_fight(object me)
{
	object *obs;

	if(!environment())
		return 0;

	say("山匪头目狠狠的说道：爷这两天没吃人肉，嘴都淡出鸟了！\n");

	obs = filter_array(all_inventory(environment()) - ({this_object()}),(: $1->is_paiyun() :));

	if(sizeof(obs))
		obs->kill_ob(me);
	kill_ob(me);
	return 1;
}
