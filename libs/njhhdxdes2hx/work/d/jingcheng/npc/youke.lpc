// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("游客", ({ "you ke", "you" , "ke" }));
	set("long",
	"这是一位来长安城的外地游客，风尘朴朴。\n");
	set("gender", "男性");
	set("age", random(50));
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", random(3000));
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
		(: random_move :),
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
	add_money("silver", 50);
}
