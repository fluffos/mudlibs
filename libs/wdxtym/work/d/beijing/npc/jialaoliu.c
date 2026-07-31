// jialaoliu.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("贾老六", ({ "jia laoliu", "jia" }));
	set("title", HIR "天地会"HIG"青木堂"NOR"会众");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 35);
	set("long",
		"\n他是天地会青木堂会众，当年在扬州之时，曾大骂盐枭，\n"+
		"骂他们不敢杀官造反，只会走私漏税，做没胆子的小生意，\n"+
		"结果得罪了青龙帮，遭人追杀，茅十八也因此和青龙帮结仇。\n");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("chat_chance", 3);

	set("chat_msg", ({
		"贾老六忽然说：扬州盐贩子真可恶。\n",
		"贾老六说: 江湖威望很重要，威望值高大有好处啊。\n",
		"贾老六突然说道: 忠义堂前兄弟在，城中点将百万兵。\n",
	}));

	set("inquiry", ([
		"陈近南" : "想见总舵主可不容易啊。",
		"天地会" : "只要是英雄好汉，都可以入我天地会。",
		"反清复明" : "去棺材店和回春堂仔细瞧瞧吧！",
		"暗号" : "敲三下！",
		"切口" : "敲三下！",
	]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
