inherit NPC;

void create()
{
	set_name("兰儿", ({ "laner", "yahuan" }));
	set("gender", "女性");
	set("age", 16);
   
	set("combat_exp", 1000); 
	set("nickname","丫鬟");
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);
    set("chat_chance", 7);
	set("chat_msg", ({
		"小姐昨晚去池塘边赏月,回来就不见那簪了!\n",
       }));
	setup();
	add_money("silver",10);
	carry_object(__DIR__"obj/shiliuqun")->wear();
}
