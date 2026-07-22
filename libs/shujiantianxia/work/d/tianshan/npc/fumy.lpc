// Npc: /d/tianshan/npc/fumy.c
// By Linux

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("符敏仪", ({ "fu mingyi", "fu"}));
	set("long",
	    "她是「灵鹫宫」九天九部中阳天部的首领.\n"+
	    "她号称「针神」.\n");
	set("title", "阳天部首领");
	set("gender", "女性");
	set("nickname", HIR "针神" NOR);
	set("per",25);
        set("age", 30);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 20);
        set("int", 25);
        set("con", 30);
        set("dex", 30);

        set("qi", 2000);
        set("max_qi", 2000);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);

        set("combat_exp", 100000);
        set("score", 10000);
        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("hand",100);
        set_skill("strike", 100);
        set_skill("sword",100);

	set_skill("tianshan-jianfa",100);
        set_skill("zhemei-shou",100);
        set_skill("liuyang-zhang",100);
        set_skill("pinxu-lingfeng",100);
        set_skill("bahuang-gong", 100);

        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "pinxu-lingfeng");
        map_skill("unarmed", "liuyang-zhang");
        map_skill("hand", "zhemei-shou");
        map_skill("parry", "liuyang-zhang");
        map_skill("sword", "tianshan-jianfa");
        create_family("灵鹫宫",3,"弟子");
        setup();
        carry_object(__DIR__"obj/qingyi")->wear();
        carry_object(BINGQI_D("changjian"))->wield();
        add_money("silver",20+random(20));
}

#include "npc.h";
