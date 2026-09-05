// hongniang.c 红娘

inherit NPC;

void create()
{
	set_name("红娘", ({ "hong niang", "hong" }));
	set("long", 
		"她是一个长得很好看的小姑娘。\n"
		"因为被关在此处，脸上露出一丝倦容。\n");
	set("gender", "女性");
	set("age", 16);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("combat_exp", 3000);
	set("shen_type", 1);
        set("inquiry", ([
                "救人" : "救又能救到哪去……",
                "小姐" : "我家小姐的心事，唉……",
                "name" : "我没名字，从小大家都叫我红娘。",
                "崔莺莺" : "我家小姐就住在西厢房。",
                "心事" : "这不是你能帮的上忙的，多谢好意了。",
                "帮忙" : "这不是你能帮的上忙的，多谢好意了。",
                "逃跑" : "逃又能逃到哪去……",
                "亲热" : "你好坏……",
        ]));

	setup();
}
