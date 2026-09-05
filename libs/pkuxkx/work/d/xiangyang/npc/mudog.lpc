#include <ansi.h>
inherit NPC;
void create()  
{	set_name(RED"牧羊犬"NOR, ({ "muyang quan","dog" }));
	set("gender", "男性");
	set("age", 5);
	set("str", 20);
	set("dex", 16);
	set("long", "它们是牧民们忠实的牧羊犬，草原上放牧可不能没有它们。\n");
	set("combat_exp", 5000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 40);
	
	set("neili", 100); 
	set("max_neili", 100);
        set("chat_chance", 10);
        set("chat_msg", ({
       GRN"牧羊犬一会跑到你身边，汪汪地叫着，一会又跑远了.\n"NOR,
                }) );

        setup();
//	carry_object(ne/weapon/fangtianji")->wield();
//	carry_object(__DIR__"obj/yangbian")->wear();

}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

