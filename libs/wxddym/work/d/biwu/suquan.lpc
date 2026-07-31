// suquan.c 苏荃

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_skills(string arg);
int do_join(string arg);

void create()
{
	set_name("苏荃", ({ "su-quan", "su" }));
	set("title",  "神龙教教主夫人" );
	set("long", "一个千娇百媚、明艳不可方物的少妇。\n");
	set("gender", "女性");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	set("per", 36);
	
	set("max_qi", 14000);
	set("max_jing", 13000);
	set("neili", 14000);
	set("max_neili", 14000);
	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 400000);

        set_skill("force", 200);
	set_skill("hunyuan-yiqi", 350);
	set_skill("shenlong-xinfa", 300);
        set_skill("dodge", 380);
	set_skill("yixingbu", 360);
        set_skill("unarmed", 300);
	set_skill("shenlong-bashi", 300);
        set_skill("parry", 150);
        set_skill("staff", 300);
	set_skill("shedao-qigong", 380);
	set_skill("literate", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong-bashi");
	map_skill("parry", "shedao-qigong");
        map_skill("staff", "shedao-qigong");
       set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);
	setup();
        carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}


