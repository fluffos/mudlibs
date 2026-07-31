// liumang.c 流氓

inherit NPC;

void create()
{
	int name_no = random(3); 
	string *name_string = ({"‘臭嘴’韩乔牲", "‘臭鞋’戚无胜", "‘黑哨’国产裁判"});

	set_name("流氓", ({ "liu mang", "liu" }));
	set("gender", "男性");
	set("age", 19);
	set("long", "他是一个成天游手好闲的流氓，长得倒是白白胖胖的，也许以前有过钱。\n");
	
	set("combat_exp", 1000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	set("inquiry", ([
		"name" : "大爷我就是" + name_string[name_no] + "，虽然猪球在下一窍不通，可照样在道上混，你又能把我怎么样！",
		"rumors" : "听说天下英雄比武大会的擂台就在城隍庙里面，真是奇怪呀。",
		"here" : "这里是扬州呀，去看地图吧。",
	]));
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 6);
}
