inherit  NPC;

void  do_something();

void  create()
{
	set_name("女赌客",  ({"du ke",  "ke"}));
	set("age",  32);
	set("gender",  "女性");
	set("per",  20);
	set("long",  "一位女性赌客，身上挂着一把剑，不知道什么来头。\n");
	set("attitude",  "friendly");

	set("combat_exp",  40000);
	set("max_neili",  400);
	set("neili",  400);
	set("force_factor",  5);
        set_skill("force",  60);
	set_skill("unarmed",  60);
	set_skill("dodge",  90);
	set_skill("yueying-wubu",  120);
	set_skill("parry",  60);
	set_skill("literate",  90);
	set_skill("sword",  90);
	set_skill("changhen-jian",  90);

	map_skill("sword", "changhen-jian");
	map_skill("dodge", "yueying-wubu");
	set("inquiry",  ([
		"here"  :  "嘿嘿...天下美景不胜数，鹿鼎公府最繁华。\n",
		"妓院"  :  "大胆！此乃天子脚下，竟敢出此伤风败俗之言！\n",
		"妓女"  :  "大胆！此乃天子脚下，竟敢出此伤风败俗之言！\n",
		"嫖妓"  :  "大胆！此乃天子脚下，竟敢出此伤风败俗之言！\n",
		"青楼"  :  "大胆！此乃天子脚下，竟敢出此伤风败俗之言！\n",
	])  );

	set("shen_type",1);set("score",200);setup();
	carry_object(__DIR__"obj/skirt")->wear();
	carry_object(__DIR__"obj/shoes")->wear();
	carry_object(__DIR__"obj/snow_sword")->wield();
	add_money("silver",  200);
}

void  do_something()
{
	command(sprintf("bet  %d  silver",  1+random(5)));
	call_out  ("do_something",  120);
}


void  init()
{
	::init();

	remove_call_out("do_something");
	call_out  ("do_something",  120);
}




