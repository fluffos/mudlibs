// Npc: /d/tianshan/npc/lanjian.c
// By Linux
inherit NPC;

void create()
{
	set_name("兰剑", ({ "lan jian", "lan"}));
	set("long",
	    "这是个容貌姣好的女子, 瓜子脸蛋,\n"+
	    "眼如点漆, 清秀绝俗.\n"+
	    "你总觉得在哪见过她.\n");
	set("gender", "女性");
	set("age", 18);
	set("per",27);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 20);
        set("int", 25);
        set("con", 30);
        set("dex", 30);
	set("unique", 1);

        set("qi", 2500);
        set("max_qi", 2500);
        set("jing", 2500);
        set("max_jing", 2500);
        set("neili", 3500);
        set("max_neili", 3000);
        set("eff_jingli", 2500);
        set("jiali", 60);

        set("combat_exp", 1000000);
        set("score", 2000);

        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("hand",200);
        set_skill("strike", 200);
        set_skill("sword",200);

        set_skill("tianshan-jianfa",200);
        set_skill("zhemei-shou",200);
        set_skill("liuyang-zhang",200);
        set_skill("pinxu-lingfeng",200);
        set_skill("bahuang-gong", 200);
        set_skill("literate", 130);

        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "pinxu-lingfeng");
        map_skill("hand", "zhemei-shou");
        map_skill("parry", "liuyang-zhang");
        map_skill("sword", "tianshan-jianfa");
	prepare_skill("hand", "zhemei-shou");
	prepare_skill("strike", "liuyang-zhang");

        create_family("灵鹫宫",3,"弟子");
        setup();
        carry_object(__DIR__"obj/qingyi")->wear();
        carry_object(BINGQI_D("changjian"))->wield();
        add_money("silver",20+random(20));
}

#include "npc.h";
