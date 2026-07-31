// Created by ysg
// data: 1997.10.17
//wig               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("神父", ({ "shen fu" , "fu" }));
	set("title",YEL"上帝保佑"NOR);
	set("long",
	"一个黄毛绿眼的神父，脸上布满皱纹，一双饱经风霜的手，他正用一明亮的眼睛看着你。\n");
	set("gender", "男性");
	set("age", 65);
	set("attitude", "peaceful");
	set("combat_exp", 5000);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"神父说：“信仰上帝吧，上帝会保佑他的子民的。”\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}

