// Npc : beijinyi.c 贝锦仪
// Made by Jackie
// 12345...上山打老虎....


#include "sujia.h"
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("贝锦仪", ({ "bei jinyi", "bei", "jinyi" }));
        set("long", 
                "她是峨嵋派俗家弟子贝锦仪。\n"
                "她生就一副贤妻良母像，性子温柔和顺。\n"
        );
        set("gender", "女性");
        set("age", 30);
        set("attitude", "friendly");
         set("unique", 1);
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);     
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 20);
        set("combat_exp", 400000);

	set_skill("dacheng-fofa", 80);
        set_skill("linji-zhuang", 80);
	set_skill("huifeng-jian", 85);
	set_skill("sword", 90);
	set_skill("literate", 90);
	set_skill("parry", 90);
	set_skill("dodge", 80);
	set_skill("force", 100);
	set_skill("anying-fuxiang", 90);

	map_skill("force", "linji-zhuang");
	map_skill("sword", "huifeng-jian");
	map_skill("parry", "huifeng-jian");
	map_skill("dodge", "anying-fuxiang");
        create_family("峨嵋派", 4, "弟子");
        setup();
	carry_object("/d/emei/obj/changjian")->wield();
	carry_object("/d/emei/obj/shoes")->wear();
	carry_object("/d/emei/obj/cloth")->wear();

}

