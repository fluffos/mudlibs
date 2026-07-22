// /d/mr/npc/tang.c 唐光雄
// update 1997.6.23 by beyond
// Modify by looklove 2001.9.20

#include <ansi.h>
inherit NPC;
string ask_1();

void create()
{
	set_name("唐光雄", ({ "tang guangxiong", "tang" }));
	set("gender", "男性");
	set("age", 20);
	set("unique", 1);
	set("str", 25);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	set("combat_exp", 30000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("max_qi",2000);
	set("max_jing",2000);
	set("neili",2000);
        set("max_neili",2000);
	set("jiali",0);
	set("score", 8000);

	set_skill("cuff", 60);
	set_skill("parry",60);
	set_skill("dodge", 70);
	set_skill("force",70);
	set_skill("shenyuan-gong",70);

	map_skill("force","shenyuan-gong");

	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);

	setup();
	set("inquiry", ([
		"秘密" : (: ask_1 :),
		"rumors" : (: ask_1 :),
	]));
        set("chat_chance",10);
        set("chat_msg",({
                "唐光雄道：“快救我出去，我告诉你一个秘密！！！\n",

        }) );
}
string ask_1()
{
		return "后花园的树藤里面有古怪！\n";
}
