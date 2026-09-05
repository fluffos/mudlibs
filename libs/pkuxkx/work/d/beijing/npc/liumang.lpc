// liumang.c 流氓

inherit NPC;

void create()
{
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

        set("inquiry", ([  //add by iszt, 2006-08-14
                "name" : "大爷我姓甚名谁关你什么事？走开，别烦我！",
                "rumors" : "嘿，我们老大昨天把丽春院的姑娘们都看了一遍，挑了最风骚的，那叫一个爽！！",
        ]) );

	setup();
	carry_object(__DIR__"items/cloth1")->wear();
}
