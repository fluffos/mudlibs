// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("小童", ({ "xiao tong", "xiao" ,"tong" }));
	set("title",GRN"将军府"NOR);
	set("long",
	"将军府府的小童都是自小就打好了武功根底，个个手下都有点功夫。\n");
	set("gender", "男性");
	set("age", 7);
	set("attitude", "heroism");
	set("str", 15);
	set("int", 15);
	set("con", 15);
	set("dex", 15);
	set("combat_exp", 200);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"小童一边练武一边喊道：“嗨！哈！”\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
