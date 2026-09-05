inherit NPC;
#include <ansi.h>
void create()
{
		int i=random(2);
        set_name("游客",({"you ke","ke","tourist"}));
        set("shen_type", 1);
        set("gender", i?"男性":"女性");
        set("age", random(20)+15);
        set("long",i?"他":"她");
		set("long",query("long")+"是来镇江赏玩的外地游客。\n");
        set("combat_exp", 800);
        set("attitude", "friendly");
		set("chat_chance", 1);
		set("chat_msg", ({
		(: random_move :),
		}) );
        set("sinan","yes");
        set("random_npc",1);
        setup();
		carry_object("/clone/cloth/cloth")->wear();
}

