// Npc: /d/tianshan/npc/chengqs.c
// By Linux

inherit NPC;

void create()
{
        set_name("程青霜", ({ "cheng qingshuang", "cheng"}));
        set("long",
	    "她是「灵鹫宫」九天九部中钧天部的副首领.\n");
	set("title", "钧天部副首领");
	set("gender", "女性");
	set("per",25);
        set("age", 30);
        set("shen_type",1);
        set("attitude", "peaceful");
        set("unique", 1);

        set("qi", 2500);
        set("max_qi", 2500);
        set("jing", 2500);
        set("max_jing", 2500);
        set("neili", 3500);
        set("max_neili", 3000);
        set("eff_jingli", 2500);
        set("jiali", 60);

        set("combat_exp", 800000);
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
	if(!random(3))
		carry_object(BINGQI_D("changjian"))->wield();
        add_money("silver",20+random(20));
}

#include "npc.h";
