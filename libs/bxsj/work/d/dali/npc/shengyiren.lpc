// shengyiren.c

inherit NPC;

void create()
{
	set_name("生意人", ({ "shengyi ren", "ren" }));
	set("gender", "男性");
	set("age", random(10) + 20);
        set("str", 20);
	set("dex", 20);
	set("long", "这是个走南闯北的生意人，他好象正在找着什么东西。\n");
	set("combat_exp", 30000);
	set("shen_type", 1);
        set("unique", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 50);
	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 25);

        set("max_qi", 250); 
        set("qi", 250); 
	set("chat_chance", 3);
        set("chat_msg", ({
	"生意人叫道：哪个该死的偷了我的钱啊！\n",
	       (: random_move :)
        }));
	setup();
	carry_object("/clone/armor/cloth")->wear();	
        add_money("silver", 10);

}
