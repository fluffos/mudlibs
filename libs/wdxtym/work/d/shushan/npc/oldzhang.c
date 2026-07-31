//shushan2 by yushu@SHXY 2000.12
inherit NPC;
int max_tea = 20;
void create()
{
	set_name("张大爷", ({"old zhang", "zhang"}));
	set("gender", "男性" );
	set("age", 70);
	set("long", "一个送茶的大爷他姓张。\n");
	set("combat_exp", 10000);
	set("attitude", "peaceful");
	set("title", "茶仙");
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
       set("per", 20);
	set("max_qi", 200);
	setup();
        carry_object("/clone/cloth/cloth")->wear();
}