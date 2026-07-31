#include <ansi.h>

inherit NPC;
inherit F_BANKER;

void create()
{
	set_name("钱老本", ({"qian laoben", "qian", "laoben"}));
	set("title", HIR "天地会"HIG"青木堂"NOR"会众");
	set("gender", "男性");
	set("age", 34);

	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);

	set("qi", 500); 
	set("max_qi", 500);
	set("jing", 100);
	set("max_jing", 100);
	set("shen", 0);

	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);

	set("inquiry", ([
		"陈近南" : "想见总舵主可不容易啊。",
		"天地会" : "只要是英雄好汉，都可以入我天地会。",
		"反清复明" : "去棺材店和回春堂仔细瞧瞧吧！",
		"暗号" : "敲三下！",
		"切口" : "敲三下！",
	]));

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 3);
}
