// Npc: /d/tianshan/npc/yupopo.c
// By Linux

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("余婆婆", ({ "yu popo", "yu", "popo" }));
        set("long",
            "她是「灵鹫宫」九天九部中昊天部的首领.\n"+
            "她跟随童姥多年, 出生入死,饱经风霜.\n");
        set("title", "昊天部首领");
        set("gender", "女性");
	set("per",15);
        set("age", 60);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 20);
        set("int", 25);
        set("con", 30);
        set("dex", 30);
        set("unique", 1);

        set("qi", 3500);
        set("max_qi", 3500);
        set("jing", 2900);
        set("max_jing", 2500);
        set("neili", 3500);
        set("max_neili", 3000);
        set("eff_jingli", 4500);
        set("jiali", 100);

        set("combat_exp", 2000000);
        set("score", 5000);

        set_skill("force", 260);
        set_skill("dodge", 260);
        set_skill("parry", 260);
        set_skill("hand",260);
        set_skill("strike", 260);
        set_skill("sword",260);

        set_skill("tianshan-jianfa",260);
        set_skill("zhemei-shou",260);
        set_skill("liuyang-zhang",260);
        set_skill("pinxu-lingfeng",260);
        set_skill("bahuang-gong", 260);
        set_skill("literate", 150);

        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "pinxu-lingfeng");
        map_skill("hand", "zhemei-shou");
        map_skill("parry", "liuyang-zhang");
        map_skill("sword", "tianshan-jianfa");
        prepare_skill("hand", "zhemei-shou");
        prepare_skill("strike", "liuyang-zhang");

        create_family("灵鹫宫",2,"弟子");
        setup();
        carry_object(__DIR__"obj/qingyi")->wear();
        if(!random(3)) 
		carry_object(BINGQI_D("changjian"))->wield();
        add_money("silver",20+random(20));
}

#include "npc.h";
