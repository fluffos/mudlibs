// zhudanchen.c 朱丹臣

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void upgrade_title(object me,string arg);
string clear_title(string arg);
int ask_me();
void create()
{
	set_name("朱丹臣", ({ "zhu danchen", "zhu" }));
	set("title",  "大理护卫" );
	set("long", "他是大理国四大护卫之一。一副书生酸溜溜的打扮行头。\n");
	set("gender", "男性");
	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 30);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 350000);
	set("score", 110000);

        set_skill("force", 55);
        set_skill("dodge", 50);
        set_skill("parry", 55);
        set_skill("cuff", 50);
        set_skill("staff", 50);
        set_skill("sword", 55);
        set_skill("staff", 55);
	set_skill("kurong-changong", 55);
        set_skill("tiannan-step", 50);
        set_skill("yiyang-zhi", 50);
        set_skill("jinyu-quan", 50);
        set_skill("duanjia-sword", 55);
	set_skill("literate", 90);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");

	set("inquiry", ([
		"指点武功" : (: ask_me :),
	]));
	setup();
	carry_object("/d/dali/npc/obj/junfu")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 10);

	create_family("大理段家",19,"护卫");
}

#include "/kungfu/class/dali/weishi.h"; 
