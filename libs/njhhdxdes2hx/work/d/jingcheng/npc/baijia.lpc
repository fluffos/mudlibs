// Created by lysh
// data: 1997.10.17
              
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("败家子", ({ "baijia zi" , "zi" }));
	set("title",HIC"游手好闲"NOR);
	set("long",
	"一个整天无所实事的败家子。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "peaceful");
	set("combat_exp", 100);
	setup();
        set("chat_chance", 10);
        carry_object(__DIR__"obj/shaizi");  
        carry_object(__DIR__"obj/cloth")->wear();

}

