inherit NPC;
#include <ansi.h>
void create()
{
		int i=random(2);
        set_name("小孩",({"xiao hai","hai","kid"}));
        set("shen_type", 1);

        set("str", 10);
        set("gender", i?"男性":"女性");
        set("age", random(5)+2);
		set("long",i?"他":"她");
		set("long",query("long")+"是家住建康府附近的一个小孩，和家人来逛街市。\n");
        set("combat_exp", 80);
        set("attitude", "friendly");
		set("chat_chance", 1);
		set("chat_msg", ({
		(: random_move :),
        (: random_move :),
		}) );
        set("sinan","yes");
		set("random_npc",1);
        setup();
		carry_object("/clone/cloth/cloth")->wear();
}

