

#include <ansi.h>

inherit NPC;
inherit F_CLEAN_UP;

                                    
void create()
{
	set_name("阿黄", ({ "huang",  }) );
	set("title", "驿站车夫");
	set("gender", "男性" );
	set("shen_type", 1);
	set("age", 30);
	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);

	set("no_clean_up",1);

	set("long",
		"这是整天笑咪咪的车老板，虽然功夫不高，却也过得自在。\n" );

	set("combat_exp", 5000);
	set("attitude", "peaceful");
	set("chat_chance", 1);
	set("chat_msg", ({
		"阿黄说道: 这位客官，您想坐车赶路吗 ?\n",
	}) );

	set("max_qi", 300);
	set("max_jing", 200);
	set("neili", 100);
	set("max_neili", 100);
	set("jiali", 10);
	set("shen_type", 1);
                              
	set_skill("force", 30); 
	set_skill("unarmed", 30);
        set_skill("dodge", 30);
	set_skill("parry", 30);
	
	setup();
	

	carry_object("d/city/obj/cloth")->wear();
}


int accept_object(object who, object ob)
{	
	if (ob->query("money_id") && ob->value() >= 1000) 
	{
		tell_object(who, "车夫笑眯眯地说道:请稍等一会,我这就为你准备马车。\n");
		who->set_temp("shangche",1);
		return 1;
	}

	return 0;
}

