// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("丫鬟", ({ "ya huan", "ya" , "huan" }));
	set("title","古怪精灵");
	set("long",
	"一个大户人家的小丫鬟，长着一双勾魂摄魄的眼睛。\n");
	set("gender", "女性");
	set("age", 13);
	set("attitude", "peaceful");
	set("str", 10);
	set("int", 10);
	set("con", 10);
	set("dex", 10);
	set("per", 30);
	set("combat_exp", 500);
	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		"小丫鬟大声哭道：“救命啊！杀人啦！.”\n",                
        }) );
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}
