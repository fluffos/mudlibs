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
	set("str", 135);
	set("int", 130);
	set("con", 130);
	set("dex", 138);
	set("per", 136);
	
	set("max_qi", 64000);
	set("max_jing", 63000);
	set("neili", 64000);
	set("max_neili", 64000);
	set("jiali", 100);
	set("combat_exp", 6500000);
	set("score", 400000);

        set_skill("force", 1000);
	set_skill("hunyuan-yiqi", 1350);
	set_skill("shenlong-xinfa", 1300);
        set_skill("dodge", 980);
	set_skill("yixingbu", 360);
        set_skill("unarmed", 1300);
	set_skill("shenlong-bashi", 1300);
        set_skill("parry", 1150);
        set_skill("staff", 1300);
	set_skill("shedao-qigong", 980);
	set_skill("literate", 1000);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong-bashi");
	map_skill("parry", "shedao-qigong");
        map_skill("staff", "shedao-qigong");
       set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2500);
	setup();
        carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}


