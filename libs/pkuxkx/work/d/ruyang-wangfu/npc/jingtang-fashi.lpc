//jingtang-fashi.c -- 汝阳王府经堂法师
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <ansi.h>

inherit NPC;

void create()
{
  set_name("讲经法师", ({ "jiangjing fashi", "jing", "fashi" }));
  set("long", "他是西藏大轮寺有道的高僧，这次是专门来汝阳王府为王爷、王妃讲经说法的。\n");
	
	set("gender", "男性");
	set("age", 65);
	set("attitude", "peaceful");
		
	set("shen_type", -1);
	set("shen", 10000);
  set("attitude", "peaceful");
  
	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	set("per", 15);
	
  set("combat_exp", 10000);
  		set_skill("unarmed",100);
      set_skill("force", 100);
      set_skill("parry", 100);
      set_skill("dodge", 100);
      set_temp("apply/attack", 100);
      set_temp("apply/defense", 100);
			set_temp("apply/damage",  100);      

	setup();
	carry_object(__DIR__"obj/zihong-jiasha")->wear();
}
