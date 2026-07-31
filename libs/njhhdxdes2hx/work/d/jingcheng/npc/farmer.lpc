// Created by lysh
// data: 1997.10.17
              
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("农民", ({ "nong min" , "min" }));
	set("long",
	"一个求雨的农民。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("combat_exp", 50);
	setup();
        set("chat_chance", 10);
	set("chat_msg", ({
        	"农民虔诚的祈求：“龙王爷显显灵吧，庄稼快要干死了！\n",	
                "农民发誓：“龙王爷要是给我来场及时雨，我就给他修金身。\n",   
        }) );
        carry_object(__DIR__"obj/suoyi")->wear();

}

