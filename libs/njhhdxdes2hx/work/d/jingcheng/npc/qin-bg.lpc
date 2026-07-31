// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("秦报国", ({ "qin baoguo", "qin" ,"baoguo" }));
	set("title",GRN"将军府管家"NOR);
	set("long",
	"秦报国是将军府的管家，负责训练秦府弟子的入门武功和礼仪。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "heroism");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 50000);
	set_skill("dodge",50);
	set_skill("unarmed", 50);
	set_skill("sword", 50);
	set_temp("apply/defense", 40);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"秦报国对你说道：“来来来！练武强身才能报国。”\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
