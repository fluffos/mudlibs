
// judge_guard.c

inherit NPC;

void create()
{
	set_name("衙役", ({ "judge guard","guard" }) );
	set("gender", "男性" );
	set("age", 24);
	set("str", 18);
	set("cor", 18);
	set("cps", 21);
	set("int", 25);
	set("per", 27);
	set("long", @LONG
   衙役是四大名捕调教出来的高徒. 
LONG
);
	set("combat_exp", 8000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"衙役说道：你当这里是什么地方，敢来这里骚扰？\n",
		"衙役说道：你要是再无理取闹，当心捕头把你抓去坐牢!\n",
		"衙役手中的刀越砍越快，让你应接不暇。\n",
		"衙役说道：衙门岂是你放肆的地方？！\n"
	}) );

	set_skill("blade", 40);
	set_skill("parry", 30);
        set_skill("dodge", 50);
	


	setup();
	
    carry_object("/clone/weapon/gangdao")->wield();
    carry_object("/clone/misc/cloth")->wear();
}

