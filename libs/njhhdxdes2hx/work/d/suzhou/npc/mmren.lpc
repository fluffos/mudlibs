// Created by tlang
// data: 1997.12.4
               
#include <ansi.h> 
inherit NPC; 

void create()
{                    
	set_name("蒙面人", ({ "mosheng ren" , "ren"  }));
	switch( random(2) ){
	case 0:
		set("long",
		"你以前肯定没见过这个人，他蒙着面孔，只勉强看出是个男人。\n");
		set("gender", "男性");
		break;
	default:
		set("long",
		"你以前肯定没见过这个人，他蒙着面孔，只勉强看出是个女人。\n");
		set("gender", "女性");
		break;
	}
	set("age", 12+random(48));
	set("attitude", "peaceful");
	set("combat_exp", random((int)this_object()->query("age")*300));
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
		"蒙面人忽然奸笑起来：嘿嘿。。。。。。。。",
        }) );
	set_skill("sword", 100);       
	set_skill("force", 100);
	set_skill("kuihua-shengong", 100);
	set_skill("pixie-jian", 100);
	set_skill("dodge", 100);
	map_skill("dodge", "pixie-jian");
	map_skill("sword", "pixie-jian");
	map_skill("force", "kuihua-shengong");
	set("max_neili", 1000);
	set("neili", 1000);
	set("jiali", 30);  
	set("chat_chance_combat", 80);
	set("chat_msg_combat",({
	//	(: perform_action, "sword.shuangda "+me->query("id") :),
		(: exert_function, "recover" :),
		(: exert_function, "kuihua" :),
	}));  

	carry_object(__DIR__"obj/gangjian")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

