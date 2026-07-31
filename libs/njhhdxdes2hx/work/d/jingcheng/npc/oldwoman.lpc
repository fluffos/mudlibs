// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("妇人", ({ "woman", "hu ren" }));
	set("title","雍容华贵");
	set("long",
	"一个穿金戴玉的商人妻子，丈夫出远门经商去了，留下她一人在家。\n");
	set("gender", "女性");
	set("age", 33);
	set("attitude", "peaceful");
	set("str", 15);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("per", 30);
	set("combat_exp", 1000);
	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		"老夫人大声喊叫：“救命啊！！有强盗，光天化日下入室杀人啦。”\n",                
        }) );
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}
