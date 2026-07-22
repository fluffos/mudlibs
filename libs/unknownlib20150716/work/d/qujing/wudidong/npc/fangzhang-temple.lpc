// fangzhang.c
// created by mes, updated 6-21-97 pickle
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("圆清",({"yuan qing", "yuan", "qing", "fang zhang", "monk", "yuanqing"}));
  	set("title","方丈");
  	set("gender", "男性");
  	set("age", 80);
  	set("long","一个白白胖胖的老和尚，和昔日牢房那模样简直是判若两人。\n");
  	set_level(60);
  	set("attitude", "peaceful");
  	set("inquiry", ([
		"name" : "老纳是这里的主持，法号圆清。\n",
		"井" : "不知为和，院里那口井有时发出“咕咚咕咚”的怪声音，寺里没人会水，所以也无法下去看个明白。",
		"石井" : "不知为何，院里那口井有时发出“咕咚咕咚”的怪声音，寺里没人会水，所以也无法下去看个明白。",
	]));
  	set("chat_chance",22);
  	set("chat_msg",({
    		"圆清自言自语，说道：“院里的石井中了邪了。”\n",
 	}));
  	setup();
  	carry_object("/obj/cloth")->wear();
}
