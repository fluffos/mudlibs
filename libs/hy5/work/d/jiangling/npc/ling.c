//Edited by fandog, 01/31/2000

inherit NPC;

void create ()
{
	set_name("凌退思", ({"ling tuisi","ling"}));
	set("title", "江陵知府");
	set("long", "
一位中年汉子，衣饰华贵，一脸精悍之色，他就是江陵知府大人，人称“凌翰林”。\n");
	set("gender", "男性");
	set("age", 45);
	set("combat_exp", 10000000);
	set("str", 125);
	set("int", 125);
	set("con", 125);
	set("dex", 125);
	set("per", 125);
	set_skill("force", 220);
	set_skill("dodge", 220);
	set_skill("sword", 220);
	set_skill("parry", 220);
	set_skill("feixian-steps", 220);
	set("max_qi",10000);
	set("max_jing",10000);
	set("max_neili",30000);
	set("qi",10000);
	set("jing",10000);
	set("neili",30000);

	set_skill("liancheng-jian", 320);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ci" :),
                (: perform_action, "sword.erguang" :),
                (: perform_action, "sword.gan" :),
                (: perform_action, "sword.qian" :),
                (: perform_action, "sword.qu" :),
                (: perform_action, "sword.zhai" :),
                (: perform_action, "sword.zhu" :),
        
        }) );
 
	map_skill("dodge", "feixian-steps");
	map_skill("parry", "liancheng-jian");
	map_skill("sword", "liancheng-jian");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/male-cloth")->wear();
}


int accept_kill(object me)
{
        command("say 光天化日之下竟敢在翰林府中行凶，没王法了吗？\n");
            me->apply_condition("killer", 20);
        kill_ob(me);
        return 1;
}
