// eba.c
//by dwolf

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"南天霸"NOR, ({ "nan tian ba", "nan" }));
	set("gender", "男性");
	set("age", 40);
	set("long",
        	RED"他衣着华丽，面目凶恶，看见你在看它，狠狠地瞪了你一眼。\n"NOR);

	set("attitude", "peaceful");

	set("str", 26);
	set("int", 25);

	set("combat_exp", 300000);
        	
	set("count", 1);
	
	set("chat_chance", 10);
	set("chat_msg", ({
		YEL"南天霸陶醉地低声唱道，“一呀摸，摸到妹妹的头发边……”。 \n"NOR,
		YEL"南天霸对着女孩发出了阵阵的浪笑，色眯眯的小眼死定着女孩的大腿。\n"NOR,
	}) );
	
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 5);

	set_skill("dodge", 60);
	set_skill("blade", 60);
	set_skill("parry", 60);
	set_skill("force", 60);
	set_skill("unarmed", 60);
	
	setup();
        carry_object(__DIR__"obj/cloth")->wear();    
 	carry_object(__DIR__"obj/dblade");
     }
