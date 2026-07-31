// laozhe.c

inherit NPC;

void create()
{
	set_name("老者", ({"old man"}));
        set("long", "这是一位瘦小枯干的老者，从外表看好像
随时都会断气，但偶尔而一抬头，眼睛里
却透露出只有内功好手才会有的精光。\n");
        set("gender","男性");

        set("age",50);
        set("con",30);
        set("str",30);
	set("kar",30);
	set("cor",35);



	set("max_atman",2000);
	set("atman",2000);
	set("max_mana",2000);
	set("mana",2000);
	set("max_kee",1500);
	set("max_gin",1500);
	set("max_sen",1500);
	set("max_force",3000);
	set("force",3000);
	set("force_factor",50);

	set("attitude","peaceful");
	set("no_exp_gain",1);

	set("chat_chance_combat",20);
	set("chat_msg_combat",({
		(: perform_action, "unarmed.zui" :),
}));

        set("combat_exp",1500);

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

