// /d/xiangyang/npc/haoke.c

inherit NPC;
void create()
{
        set_name("江湖豪客", ({ "hao ke", "haoke", "ke" }) );
        set("gender", "男性" );
        set("age", 30+random(15));
        set("long", "一个虎背熊腰，满面扎须的汉子。\n");
        set("attitude", "friendly");

        set("shen_type", 1);
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);

        set("max_qi", 2500);
        set("max_jing", 2500);
	set("eff_jingli", 1500);
        set("neili", 2500);
        set("max_neili", 2000);
        set("jiali", 100);
        set("shen", 5);
        set("combat_exp", 240000);

        set_skill("force", 120);
        set_skill("strike", 120);
        set_skill("blade", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("huntian-qigong", 120);
        set_skill("literate", 140);
        set_skill("lianhua-zhang", 120);
        set_skill("liuhe-daofa", 120);
        set_skill("xiaoyaoyou", 120);

        map_skill("force", "huntian-qigong");
        map_skill("blade","liuhe-daofa");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("strike", "lianhua-zhang");
        map_skill("parry", "liuhe-daofa");
        prepare_skill("strike", "lianhua-zhang");

        set("chat_msg_combat", ({
                (: perform_action, "blade.sancai" :)
        }));

        set("chat_chance", 3);
        set("chat_msg", ({
                "江湖豪客伸手摸了摸挂在腰间钢刀的刀鞘。\n",
        }) );

	set("inquiry", ([
		"name" : "江湖豪客用力一拍桌子，大声道：“凭你，还不配知道大爷我的名字！”\n",
		"rumors" : "前一阵子听说他们在五霸冈上聚会，为了一个叫令狐冲的少年英雄。\n",
	]));

        setup();

        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        carry_object(BINGQI_D("blade"))->wield();
}
