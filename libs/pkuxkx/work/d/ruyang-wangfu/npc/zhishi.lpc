// zhishi.c -- 王府执事处执事
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <ansi.h>
inherit NPC;

// string ask_finish(); 

void create()
{
	set_name("王府执事", ({ "zhi shi", "zhishi", "zhi"}));
	set("long", "他长的圆圆呼呼的，看不出有多精明，但也不一定有多笨，要不怎么能在王府当执事呢。\n");

	set("gender", "男性");
	set("age", 58);
	set("per", 15);

	set("shen_type", 0);
	set("attitude", "peaceful");

	set("combat_exp", 100000);
  		set_skill("unarmed",100);
      set_skill("force", 100);
      set_skill("parry", 100);
      set_skill("dodge", 100);
      set_temp("apply/attack", 100);
      set_temp("apply/defense", 100);
			set_temp("apply/damage",  100);

	set("chat_chance", 10);
	set("chat_msg", ({
		"王府执事自言自语道：王府的公文就已经忙不过来了，可郡主又吩咐我…… 唉～\n\n",
		"王府执事正伏身于桌案之上，飞快地写着什么……\n\n",
		"王府执事自言自语道：要是有江湖中人能帮忙就好了，可是……谁能帮忙呢？\n\n",		
		(: chat :)
	}) );

	
	set("inquiry", ([
		"郡主" : "这还用问啊？\n",
		"吩咐" : "郡主吩咐我……，你是谁啊，为什么要告诉你这些？不关你的事别打听。\n",
		"帮忙" : "你没看我快忙不过来了么？\n",
		"help" : "你没看我快忙不过来了么？\n",
		"完成" : "完成了！\n",
		"finish" : "完成了！\n",
	]));

	setup();
	carry_object(__DIR__"obj/zhishi-fu")->wear();
}

