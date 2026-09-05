// shusheng.c 发月饼的NPC

inherit NPC;

#include "duishi.h"

void create()
{
	set_name("书生", ({ "shu sheng", "sheng" }) );
	set("gender", "男性" );
	set("age", 22);
	set("per",50);
	set("int", 28);
	set("long",
		"这是个年轻的书生，身着一袭长衫，背着一个书袋，正在念念有词地吟诗作对。\n");

	set("attitude", "peaceful");
	set_skill("literate", 40);
	set("shen_type",1);
	set("score",200);
	new_test();
	set("gender","男性");
	set("chat_chance",50);
	set("chat_msg",({ask,ask,ask,ask,ask,ask,ask,ask,(: random_move :),}));
	setup();
	carry_object("/d/huashan/npc/obj/huishan")->wear();
	call_out("do_come",2);
	call_out("do_dest",120);
}
