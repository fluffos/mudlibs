#include <ansi.h>
inherit NPC;
void create()  
{       set_name(WHT"绵羊"NOR, ({ "sheep"}));
	set("gender", "男性");
	set("age", 5);
	set("str", 10);
	set("dex", 16);
	set("long", "暖风吹拂下，它们在草原上宁静地吃着草。\n");
	set("combat_exp", 500);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 10);
	
	set("neili", 100); 
	set("max_neili", 100);
        set("chat_chance", 10);
        set("chat_msg", ({
       WHT"羊儿咩咩地叫着。\n"NOR,
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

